#pragma once

#include <QObject>
#include <QTimer>
#include <QVector2D>
#include <QStringList>

#include <cmath>

#include "log_fifo.h"
#include "cmd_fifo.h"
#include "car.h"

using namespace trikControl;

class Linetracer : public QObject
{
    Q_OBJECT
public:
    explicit Linetracer(CarPlatform& carPlatform);
    virtual ~Linetracer();

protected:

public slots:

private slots:
  void setLineColorData(int hue, int hueTol, int sat, int satTol, int val, int valTol);
  void setLineTargetData(int x, int angle, int mass);

private:

    int Regulator(int x);

    LogFifo          m_logFifo;
    CmdFifo          m_cmdFifo;
    //Brick            m_brick;
    CarPlatform&     m_carPlatform;

    //target location data
    //int m_tgtX;
    //int m_prevTgtX;
    //int m_tgtAngle;
    //int m_tgtMass;

    CarMode m_CarMode;

    //target HSV data
    //int m_hue;
    //int m_hueTol;
    //int m_sat;
    //int m_satTol;
    //int m_val;
    //int m_valTol;
};
