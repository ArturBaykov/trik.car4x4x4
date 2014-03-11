#include <QDebug>
//#include <QStringList>
#include <trikControl/brick.h>
#include "car.h"

//#include <cmath>


const QString FrontLeftMotorName = "JM3";
const QString FrontRightMotorName = "M1";
const QString BackLeftMotorName = "JM2";
const QString BackRightMotorName = "JM1";

const QString FrontLeftServomotorName = "JC3";
const QString FrontRightServomotorName = "JE1";
const QString BackLeftServomotorName = "JC2";
const QString BackRightServomotorName = "JC1";

CarPlatform::CarPlatform(Brick& brick) :
    brick(brick),
    wheelFrontLeft(brick, FrontLeft, FrontLeftMotorName, FrontLeftServomotorName),
    wheelFrontRight(brick, FrontRight, FrontRightMotorName, FrontRightServomotorName),
    wheelBackLeft(brick, BackLeft, BackLeftMotorName, BackLeftServomotorName),
    wheelBackRight(brick, BackRight, BackRightMotorName, BackRightServomotorName)
{

}

CarPlatform::~CarPlatform()
{
  //disconnect(&m_logFifo, SIGNAL(fifoRead(QString)), this, SLOT(parseLogFifo(QString)));
}

//---------------------------------------------------------------------------------------


// Управление обычным режимом
// Повернуть колесо в нормальный режим
void CarPlatform::SetGeneralMode()
{
    wheelFrontLeft.WheelSetGeneralMode();
    wheelFrontRight.WheelSetGeneralMode();
    wheelBackLeft.WheelSetGeneralMode();
    wheelBackRight.WheelSetGeneralMode();
    return;
}
// Вперед ехать в нормальном режиме
void CarPlatform::GoFront(int power)
{
    wheelFrontLeft.WheelGoFront(power);
    wheelFrontRight.WheelGoFront(power);
    wheelBackLeft.WheelGoFront(power);
    wheelBackRight.WheelGoFront(power);
    return;
}
// Назад ехать в нормальном режиме
void CarPlatform::GoBack(int power)
{
    wheelFrontLeft.WheelGoBack(power);
    wheelFrontRight.WheelGoBack(power);
    wheelBackLeft.WheelGoBack(power);
    wheelBackRight.WheelGoBack(power);
    return;
}
//---------------------------------------------------------------------------------------


// Управление круговым режимом (машина едет вокруг своей оси)
// Повернуть колесо в режим кругового поворота
void CarPlatform::SetCircleMode()
{
    wheelFrontLeft.WheelSetCircleMode();
    wheelFrontRight.WheelSetCircleMode();
    wheelBackLeft.WheelSetCircleMode();
    wheelBackRight.WheelSetCircleMode();
    return;
}
// Поворачивать по часовой стрелке
void CarPlatform::GoClockWise(int power)
{
    wheelFrontLeft.WheelGoClockWise(power);
    wheelFrontRight.WheelGoClockWise(power);
    wheelBackLeft.WheelGoClockWise(power);
    wheelBackRight.WheelGoClockWise(power);
    return;
}
// Поворачивать против часовой стрелки
void CarPlatform::GoAntiClockWise(int power)
{
    wheelFrontLeft.WheelGoAntiClockWise(power);
    wheelFrontRight.WheelGoAntiClockWise(power);
    wheelBackLeft.WheelGoAntiClockWise(power);
    wheelBackRight.WheelGoAntiClockWise(power);
    return;
}
//---------------------------------------------------------------------------------------


// Управление режимом лобстера (машина едет в бок)
// Повернуть колесо в режим лобстера
void CarPlatform::SetLobsterMose()
{
    wheelFrontLeft.WheelSetLobsterMose();
    wheelFrontRight.WheelSetLobsterMose();
    wheelBackLeft.WheelSetLobsterMose();
    wheelBackRight.WheelSetLobsterMose();
    return;
}
// Вправо поехать в режиме лобстера
void CarPlatform::GoRight(int power)
{
    wheelFrontLeft.WheelGoRight(power);
    wheelFrontRight.WheelGoRight(power);
    wheelBackLeft.WheelGoRight(power);
    wheelBackRight.WheelGoRight(power);
    return;
}
// Влево поехать в режиме лобстера
void CarPlatform::GoLeft(int power)
{
    wheelFrontLeft.WheelGoLeft(power);
    wheelFrontRight.WheelGoLeft(power);
    wheelBackLeft.WheelGoLeft(power);
    wheelBackRight.WheelGoLeft(power);
    return;
}
//---------------------------------------------------------------------------------------





