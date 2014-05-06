#include "gamepadrobot.h"





GamePadRobot::GamePadRobot(Brick& brick, CarPlatform& carPlatform) :
    brick(brick),
    carPlatform(carPlatform)
{
    qDebug() << "Connect Begin";
    connect(brick.gamepad(), SIGNAL(button(int,int)),        this, SLOT(ChangeMod(int, int)));
    connect(brick.gamepad(), SIGNAL(pad(int,int,int)),       this, SLOT(GamepadPad(int,int,int)));
    connect(brick.gamepad(), SIGNAL(padUp(int)),             this, SLOT(GamepadPadUp(int)));
    //connect(brick.keys(),    SIGNAL(buttonPressed(int,int)), this, SLOT(getButton(int,int)));

    qDebug() << "Connect End";
}
GamePadRobot::~GamePadRobot()
{
  //disconnect(&m_logFifo, SIGNAL(fifoRead(QString)), this, SLOT(parseLogFifo(QString)));
}

GamePadMode mode = General;


void GamePadRobot::ChangeMod(int button, int pressed)
{
    qDebug() << "ChangeMode";
    if (pressed == 0)
    {
        return;
    }

    carPlatform.StopMotors();

    switch (button)
    {
        case 1:
            mode = General;
            qDebug() << "General mode";
            carPlatform.SetGeneralMode();
            break;
        case 2:
            mode = Circle;
            qDebug() << "Circle mode";
            carPlatform.SetCircleMode();
            break;
        case 3:
            mode = Lobster;
            qDebug() << "Lobster mode";
            carPlatform.SetLobsterMode();
            break;
        case 4:
            mode = TornadoTopMode;
            qDebug() << "Tornado Top Mode";
            carPlatform.SetTornadoTopMode();
            break;
        case 5:
            mode = NotCurrent;
            carPlatform.StopMotors();
            carPlatform.StopServoMotors();
            qDebug() << "Not Current mode";
            break;
   }
   return;
}

int GamePadRobot::Rangeint(int x)
{
    //range -100..0..100
    //       -40..0..40
    return x/(100/40);
}

void GamePadRobot::GamepadPad(int pad, int x, int y)
{
    switch (mode)
    {
    case General:
        if (pad == 1)
        {
            if (y>=35)
            {
                carPlatform.SetParallelModeRight(Rangeint(x));
            }
            if (y<35 && y>-35)
            {
                carPlatform.SetCar2x4RightMode(Rangeint(x));
            }
            if (y<=-35)
            {
                carPlatform.SetCar4x4RightMode(Rangeint(x));
            }
            return;
        }
        if (pad == 2)
        {
            carPlatform.GoFront(y);
            return;
        }
        break;
    case Circle:
        if (pad == 1)
        {
            return;
        }
        if (pad == 2)
        {
            carPlatform.GoClockWise(x);
            return;
        }
        break;
    case Lobster:
        if (pad == 1)
        {
            return;
        }
        if (pad == 2)
        {
            carPlatform.GoRight(x);
            return;
        }
        break;
    case TornadoTopMode:
        if (pad == 1)
        {
            return;
        }
        if (pad == 2)
        {
            carPlatform.GoAntiClocktTornadoTop(x);
            return;
        }
        break;
    case NotCurrent:
        if (pad == 1)
        {
            return;
        }
        if (pad == 2)
        {
            return;
        }
        break;
    }
}

void GamePadRobot::GamepadPadUp(int pad)
{
    if (pad ==1)
    {
        switch (mode)
        {
        case General:
            carPlatform.SetCar2x4RightMode(0);
            return;
            break;
        case Circle:
            return;
            break;
        case Lobster:
            return;
            break;
        case TornadoTopMode:
            //carPlatform.SetCar2x4RightMode(0);
            return;
            break;
        case NotCurrent:
            //carPlatform.SetCar2x4RightMode(0);
            return;
            break;
        }
    }

    if (pad ==2)
    {
        carPlatform.StopMotors();
    }
}


