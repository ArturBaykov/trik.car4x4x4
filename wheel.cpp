#include <QDebug>
//#include <QStringList>

#include "wheel.h"
#include "trikControl/motor.h"
#include "trikControl/servoMotor.h"
#include "trikControl/powerMotor.h"

//#include <cmath>

#define gradusCircle 50
#define gradus90 100






Wheel::Wheel(Brick& brick, WheelType wheelType, const QString motor, const QString servomotor) :
    brick(brick),
    wheelType(wheelType),
    motor(brick.motor(motor)),
    servomotor(brick.motor(servomotor))
{
}

Wheel::~Wheel()
{
  //disconnect(&m_logFifo, SIGNAL(fifoRead(QString)), this, SLOT(parseLogFifo(QString)));
}

void Wheel::StopServoMotors()
{
    servomotor->powerOff();
}

void Wheel::StopMotors()
{
    motor->powerOff();
}

//---------------------------------------------------------------------------------------


// Управление обычным режимом
// Повернуть колесо в нормальный режим
void Wheel::WheelSetGeneralMode()
{
    servomotor->setPower(0);
}
// Вперед ехать в нормальном режиме
void Wheel::WheelGoFront(int power)
{
    switch (wheelType)
    {
    case FrontLeft:
        motor->setPower(power);
        break;
    case FrontRight:
        motor->setPower(-power);
        break;
    case BackLeft:
        motor->setPower(power);
        break;
    case BackRight:
        motor->setPower(-power);
        break;
    default:
        break;
    }
    return;
}
// Назад ехать в нормальном режиме
void Wheel::WheelGoBack(int power)
{
    switch (wheelType)
    {
    case FrontLeft:
        motor->setPower(-power);
        break;
    case FrontRight:
        motor->setPower(power);
        break;
    case BackLeft:
        motor->setPower(-power);
        break;
    case BackRight:
        motor->setPower(power);
        break;
    default:
        break;
    }
    return;
}
//---------------------------------------------------------------------------------------


// Управление круговым режимом (машина едет вокруг своей оси)
// Повернуть колесо в режим кругового поворота
void Wheel::WheelSetCircleMode()
{
    switch (wheelType)
    {
    case FrontLeft:
        servomotor->setPower(0+gradusCircle);
        break;
    case FrontRight:
        servomotor->setPower(0-gradusCircle);
        break;
    case BackLeft:
        servomotor->setPower(0-gradusCircle);
        break;
    case BackRight:
        servomotor->setPower(0+gradusCircle);
        break;
    default:
        break;
    }
    return;
}
// Поворачивать по часовой стрелке
void Wheel::WheelGoClockWise(int power)
{
    switch (wheelType)
    {
    case FrontLeft:
        motor->setPower(power);
        break;
    case FrontRight:
        motor->setPower(power);
        break;
    case BackLeft:
        motor->setPower(power);
        break;
    case BackRight:
        motor->setPower(power);
        break;
    default:
        break;
    }
    return;
}
// Поворачивать против часовой стрелки
void Wheel::WheelGoAntiClockWise(int power)
{

    switch (wheelType)
    {
    case FrontLeft:
        motor->setPower(-power);
        break;
    case FrontRight:
        motor->setPower(-power);
        break;
    case BackLeft:
        motor->setPower(-power);
        break;
    case BackRight:
        motor->setPower(-power);
        break;
    default:
        break;
    }
    return;

}
//---------------------------------------------------------------------------------------


// Управление режимом лобстера (машина едет в бок)
// Повернуть колесо в режим лобстера
void Wheel::WheelSetLobsterMose()
{
    switch (wheelType)
    {
    case FrontLeft:
        servomotor->setPower(0+gradus90);
        break;
    case FrontRight:
        servomotor->setPower(0-gradus90);
        break;
    case BackLeft:
        servomotor->setPower(0-gradus90);
        break;
    case BackRight:
        servomotor->setPower(0+gradus90);
        break;
    default:
        break;
    }
    return;
}
// Вправо поехать в режиме лобстера
void Wheel::WheelGoRight(int power)
{
    switch (wheelType)
    {
    case FrontLeft:
        motor->setPower(power);
        break;
    case FrontRight:
        motor->setPower(power);
        break;
    case BackLeft:
        motor->setPower(-power);
        break;
    case BackRight:
        motor->setPower(-power);
        break;
    default:
        break;
    }
    return;
}
// Влево поехать в режиме лобстера
void Wheel::WheelGoLeft(int power)
{

    switch (wheelType)
    {
    case FrontLeft:
        motor->setPower(-power);
        break;
    case FrontRight:
        motor->setPower(-power);
        break;
    case BackLeft:
        motor->setPower(power);
        break;
    case BackRight:
        motor->setPower(power);
        break;
    default:
        break;
    }
    return;
}
//---------------------------------------------------------------------------------------


void Wheel::WheelSetParallelModeLeft(int ugol)
{
    switch (wheelType)
    {
    case FrontLeft:
        servomotor->setPower(0-ugol);
        break;
    case FrontRight:
        servomotor->setPower(0-ugol);
        break;
    case BackLeft:
        servomotor->setPower(0-ugol);
        break;
    case BackRight:
        servomotor->setPower(0-ugol);
        break;
    default:
        break;
    }
    return;
}

void Wheel::WheelSetParallelModeRight(int ugol)
{

    switch (wheelType)
    {
    case FrontLeft:
        servomotor->setPower(0+ugol);
        break;
    case FrontRight:
        servomotor->setPower(0+ugol);
        break;
    case BackLeft:
        servomotor->setPower(0+ugol);
        break;
    case BackRight:
        servomotor->setPower(0+ugol);
        break;
    default:
        break;
    }
    return;



}




void Wheel::WheelSetCar2x4ModeLeft(int ugol)
{
    switch (wheelType)
    {
    case FrontLeft:
        servomotor->setPower(0-ugol);
        break;
    case FrontRight:
        servomotor->setPower(0-ugol);
        break;
    case BackLeft:
        servomotor->setPower(0);
        break;
    case BackRight:
        servomotor->setPower(0);
        break;
    default:
        break;
    }
    return;
}

void Wheel::WheelSetCar2x4ModeRight(int ugol)
{
    switch (wheelType)
    {
    case FrontLeft:
        servomotor->setPower(0+ugol);
        break;
    case FrontRight:
        servomotor->setPower(0+ugol);
        break;
    case BackLeft:
        servomotor->setPower(0);
        break;
    case BackRight:
        servomotor->setPower(0);
        break;
    default:
        break;
    }
    return;
}


void Wheel::WheelSetCar4x4ModeLeft(int ugol)
{
    switch (wheelType)
    {
    case FrontLeft:
        servomotor->setPower(0-ugol);
        break;
    case FrontRight:
        servomotor->setPower(0-ugol);
        break;
    case BackLeft:
        servomotor->setPower(0+ugol);
        break;
    case BackRight:
        servomotor->setPower(0+ugol);
        break;
    default:
        break;
    }
    return;
}



void Wheel::WheelSetCar4x4ModeRight(int ugol)
{
    switch (wheelType)
    {
    case FrontLeft:
        servomotor->setPower(0+ugol);
        break;
    case FrontRight:
        servomotor->setPower(0+ugol);
        break;
    case BackLeft:
        servomotor->setPower(0-ugol);
        break;
    case BackRight:
        servomotor->setPower(0-ugol);
        break;
    default:
        break;
    }
    return;
}


