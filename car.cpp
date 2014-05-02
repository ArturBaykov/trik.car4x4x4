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


void CarPlatform::StopMotors()
{
    wheelFrontLeft.StopMotors();
    wheelFrontRight.StopMotors();
    wheelBackLeft.StopMotors();
    wheelBackRight.StopMotors();
    return;
}

void CarPlatform::StopServoMotors()
{
    wheelFrontLeft.StopServoMotors();
    wheelFrontRight.StopServoMotors();
    wheelBackLeft.StopServoMotors();
    wheelBackRight.StopServoMotors();
    CurrentCarMode = cmNotCurrent;
    return;
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
    CurrentCarMode = cmGeneral;
    return;
}
// Вперед ехать в нормальном режиме
void CarPlatform::GoFront(int power)
{
    //if (CurrentCarMode ==cmGeneral)
    //{
        wheelFrontLeft.WheelGoFront(power);
        wheelFrontRight.WheelGoFront(power);
        wheelBackLeft.WheelGoFront(power);
        wheelBackRight.WheelGoFront(power);
    //}

    return;
}
// Назад ехать в нормальном режиме
void CarPlatform::GoBack(int power)
{
    //if (CurrentCarMode ==cmGeneral)
    //{
        wheelFrontLeft.WheelGoBack(power);
        wheelFrontRight.WheelGoBack(power);
        wheelBackLeft.WheelGoBack(power);
        wheelBackRight.WheelGoBack(power);
    //}
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
    CurrentCarMode =cmCircle;
    return;
}
// Поворачивать по часовой стрелке
void CarPlatform::GoClockWise(int power)
{
    if (CurrentCarMode ==cmCircle)
    {
        wheelFrontLeft.WheelGoClockWise(power);
        wheelFrontRight.WheelGoClockWise(power);
        wheelBackLeft.WheelGoClockWise(power);
        wheelBackRight.WheelGoClockWise(power);
    }
    return;
}
// Поворачивать против часовой стрелки
void CarPlatform::GoAntiClockWise(int power)
{
    if (CurrentCarMode ==cmCircle)
    {
        wheelFrontLeft.WheelGoAntiClockWise(power);
        wheelFrontRight.WheelGoAntiClockWise(power);
        wheelBackLeft.WheelGoAntiClockWise(power);
        wheelBackRight.WheelGoAntiClockWise(power);
    }
    return;
}
//---------------------------------------------------------------------------------------


// Управление режимом лобстера (машина едет в бок)
// Повернуть колесо в режим лобстера
void CarPlatform::SetLobsterMode()
{
    wheelFrontLeft.WheelSetLobsterMose();
    wheelFrontRight.WheelSetLobsterMose();
    wheelBackLeft.WheelSetLobsterMose();
    wheelBackRight.WheelSetLobsterMose();
    CurrentCarMode = cmLobster;
    return;
}
// Вправо поехать в режиме лобстера
void CarPlatform::GoRight(int power)
{
    if (CurrentCarMode == cmLobster)
    {
        wheelFrontLeft.WheelGoRight(power);
        wheelFrontRight.WheelGoRight(power);
        wheelBackLeft.WheelGoRight(power);
        wheelBackRight.WheelGoRight(power);
    }
    return;
}
// Влево поехать в режиме лобстера
void CarPlatform::GoLeft(int power)
{
    if (CurrentCarMode == cmLobster)
    {
        wheelFrontLeft.WheelGoLeft(power);
        wheelFrontRight.WheelGoLeft(power);
        wheelBackLeft.WheelGoLeft(power);
        wheelBackRight.WheelGoLeft(power);
    }
    return;
}
//---------------------------------------------------------------------------------------



void CarPlatform::SetParallelModeLeft(int ugol)
{
    wheelFrontLeft.WheelSetParallelModeLeft(ugol);
    wheelFrontRight.WheelSetParallelModeLeft(ugol);
    wheelBackLeft.WheelSetParallelModeLeft(ugol);
    wheelBackRight.WheelSetParallelModeLeft(ugol);
    return;
}

void CarPlatform::SetParallelModeRight(int ugol)
{
    wheelFrontLeft.WheelSetParallelModeRight(ugol);
    wheelFrontRight.WheelSetParallelModeRight(ugol);
    wheelBackLeft.WheelSetParallelModeRight(ugol);
    wheelBackRight.WheelSetParallelModeRight(ugol);
    return;
}


void CarPlatform::SetCar2x4LeftMode(int ugol)
{
    wheelFrontLeft.WheelSetCar2x4ModeLeft(ugol);
    wheelFrontRight.WheelSetCar2x4ModeLeft(ugol);
    wheelBackLeft.WheelSetCar2x4ModeLeft(ugol);
    wheelBackRight.WheelSetCar2x4ModeLeft(ugol);
    return;
}

void CarPlatform::SetCar2x4RightMode(int ugol)
{
    wheelFrontLeft.WheelSetCar2x4ModeRight(ugol);
    wheelFrontRight.WheelSetCar2x4ModeRight(ugol);
    wheelBackLeft.WheelSetCar2x4ModeRight(ugol);
    wheelBackRight.WheelSetCar2x4ModeRight(ugol);
    return;
}

void CarPlatform::SetCar4x4LeftMode(int ugol)
{
    wheelFrontLeft.WheelSetCar4x4ModeLeft(ugol);
    wheelFrontRight.WheelSetCar4x4ModeLeft(ugol);
    wheelBackLeft.WheelSetCar4x4ModeLeft(ugol);
    wheelBackRight.WheelSetCar4x4ModeLeft(ugol);
    return;
}

void CarPlatform::SetCar4x4RightMode(int ugol)
{
    wheelFrontLeft.WheelSetCar4x4ModeRight(ugol);
    wheelFrontRight.WheelSetCar4x4ModeRight(ugol);
    wheelBackLeft.WheelSetCar4x4ModeRight(ugol);
    wheelBackRight.WheelSetCar4x4ModeRight(ugol);
    return;
}

