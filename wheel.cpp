#include <QDebug>
//#include <QStringList>

#include "car.h"
#include "motor.h"

//#include <cmath>

#define 45gradus 50
#define 90gradus 100


Wheel::Wheel(Brick brick, WheelType wheelType, QString motor,  QString servomotor, int servomidle):
{
    this->brick = brick;
    this->motor = brick.motor(motor);
    this->servomotor = brick.motor(servomotor);
    this->servomidle=servomidle;
}

Wheel::~Wheel()
{
  //disconnect(&m_logFifo, SIGNAL(fifoRead(QString)), this, SLOT(parseLogFifo(QString)));
}

//---------------------------------------------------------------------------------------


// Управление обычным режимом
// Повернуть колесо в нормальный режим
void Wheel::SetGeneralMode()
{
    servomotor.setPower(servomidle);
}
// Вперед ехать в нормальном режиме
void Wheel::GoFront(int power)
{
    switch (wheelType)
    {
    case WheelType.FrontLeft:
        motor.setPower(power);
        break;
    case WheelType.FrontRight:
        motor.setPower(-power);
        break;
    case WheelType.BackLeft:
        motor.setPower(power);
        break;
    case WheelType.BackRight:
        motor.setPower(-power);
        break;
    default:
        break;
    }
    return;
}
// Назад ехать в нормальном режиме
void Wheel::GoBack(int power)
{
    switch (wheelType)
    {
    case WheelType.FrontLeft:
        motor.setPower(-power);
        break;
    case WheelType.FrontRight:
        motor.setPower(power);
        break;
    case WheelType.BackLeft:
        motor.setPower(-power);
        break;
    case WheelType.BackRight:
        motor.setPower(power);
        break;
    default:
        break;
    }
    return;
}
//---------------------------------------------------------------------------------------


// Управление круговым режимом (машина едет вокруг своей оси)
// Повернуть колесо в режим кругового поворота
void Wheel::SetCircleMode()
{
    switch (wheelType)
    {
    case WheelType.FrontLeft:
        servomotor.setPower(servomidle+45gradus);
        break;
    case WheelType.FrontRight:
        servomotor.setPower(servomidle-45gradus);
        break;
    case WheelType.BackLeft:
        servomotor.setPower(servomidle-45gradus);
        break;
    case WheelType.BackRight:
        servomotor.setPower(servomidle+45gradus);
        break;
    default:
        break;
    }
    return;
}
// Поворачивать по часовой стрелке
void Wheel::GoClockWise(int power)
{
    switch (wheelType)
    {
    case WheelType.FrontLeft:
        motor.setPower(power);
        break;
    case WheelType.FrontRight:
        motor.setPower(power);
        break;
    case WheelType.BackLeft:
        motor.setPower(power);
        break;
    case WheelType.BackRight:
        motor.setPower(power);
        break;
    default:
        break;
    }
    return;
}
// Поворачивать против часовой стрелки
void Wheel::GoAntiClockWise(int power)
{

    switch (wheelType)
    {
    case WheelType.FrontLeft:
        motor.setPower(-power);
        break;
    case WheelType.FrontRight:
        motor.setPower(-power);
        break;
    case WheelType.BackLeft:
        motor.setPower(-power);
        break;
    case WheelType.BackRight:
        motor.setPower(-power);
        break;
    default:
        break;
    }
    return;

}
//---------------------------------------------------------------------------------------


// Управление режимом лобстера (машина едет в бок)
// Повернуть колесо в режим лобстера
void Wheel::SetLobsterMose()
{
    switch (wheelType)
    {
    case WheelType.FrontLeft:
        servomotor.setPower(servomidle+90gradus);
        break;
    case WheelType.FrontRight:
        servomotor.setPower(servomidle-90gradus);
        break;
    case WheelType.BackLeft:
        servomotor.setPower(servomidle-90gradus);
        break;
    case WheelType.BackRight:
        servomotor.setPower(servomidle+90gradus);
        break;
    default:
        break;
    }
    return;
}
// Вправо поехать в режиме лобстера
void Wheel::GoRight(int power)
{
    switch (wheelType)
    {
    case WheelType.FrontLeft:
        motor.setPower(power);
        break;
    case WheelType.FrontRight:
        motor.setPower(power);
        break;
    case WheelType.BackLeft:
        motor.setPower(-power);
        break;
    case WheelType.BackRight:
        motor.setPower(-power);
        break;
    default:
        break;
    }
    return;
}
// Влево поехать в режиме лобстера
void Wheel::GoLeft(int power)
{

    switch (wheelType)
    {
    case WheelType.FrontLeft:
        motor.setPower(-power);
        break;
    case WheelType.FrontRight:
        motor.setPower(-power);
        break;
    case WheelType.BackLeft:
        motor.setPower(power);
        break;
    case WheelType.BackRight:
        motor.setPower(power);
        break;
    default:
        break;
    }
    return;
}
//---------------------------------------------------------------------------------------





