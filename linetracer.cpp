#include <QDebug>

#include "linetracer.h"

const QString logFifoPath="/tmp/dsp-detector.out.fifo";
const QString cmdFifoPath="/tmp/dsp-detector.in.fifo";

const int speed = 100;
const qreal stopK = 1;
const qreal PK = 0.42;
const qreal IK = 0.006;
const qreal DK = -0.009;
const qreal encC = 1/(334*34); //1 : (num of points of encoder wheel * reductor ratio)

Linetracer::Linetracer(CarPlatform& carPlatform):
  m_logFifo(logFifoPath),
  m_cmdFifo(cmdFifoPath),
  m_carPlatform (carPlatform)
{
    m_logFifo.open();
    m_cmdFifo.open();
    setLineColorData(0, 179, 50,50,30,30);

  qDebug() << "LINETRACER_STARTS";
  connect(&m_logFifo, SIGNAL(lineTargetDataParsed(int, int, int)), this, SLOT(setLineTargetData(int, int, int)));
}

Linetracer::~Linetracer()
{
}

int Linetracer::Regulator(int x)
{
    //range -100..0..100
    //       -40..0..40

    if (x>70)
    {
        return 38;
    }
    if (x<-70)
    {
        return -38;
    }
    return x/(100/40);
}

void Linetracer::setLineColorData(int hue, int hueTol, int sat, int satTol, int val, int valTol)
{
  QString s = QString("hsv %1 %2 %3 %4 %5 %6\n").arg(hue)
                                                .arg(hueTol)
                                                .arg(sat)
                                                .arg(satTol)
                                                .arg(val)
                                                .arg(valTol);
//  qDebug() << s;
  m_cmdFifo.write(s);
}

void Linetracer::setLineTargetData(int x, int angle, int mass)
{
  qDebug("line x, angle, mass: %d, %d, %d", x, angle, mass);

    if (mass>=1)
    {
        if (x>0)
        {
            if (x<50)
            {
                m_carPlatform.SetCar2x4RightMode(Regulator(x));
                m_CarMode = cmCar2x4Right;
            }
            else
            {
                m_carPlatform.SetCar4x4RightMode(Regulator(x));
                m_CarMode = cmCar4x4Right;
            }
        }
        else
        {

            if (x>-50)
            {
                m_carPlatform.SetCar2x4LeftMode(Regulator(-x));
                m_CarMode = cmCar2x4Left;
            }
            else
            {
                m_carPlatform.SetCar4x4LeftMode(Regulator(-x));
                m_CarMode = cmCar4x4Left;
            }
        }

        m_carPlatform.GoFront(100);
    }
    else
    {
        if (m_CarMode == cmCar2x4Left || m_CarMode == cmCar4x4Left)
        {
            m_carPlatform.StopMotors();
            m_carPlatform.SetCircleMode();
            m_carPlatform.GoAntiClockWise(100);
            m_CarMode = cmCircle;
        }
        if (m_CarMode == cmCar2x4Right || m_CarMode == cmCar4x4Right)
        {
            m_carPlatform.StopMotors();
            m_carPlatform.SetCircleMode();
            m_carPlatform.GoClockWise(100);
            m_CarMode = cmCircle;
        }
    }

}

