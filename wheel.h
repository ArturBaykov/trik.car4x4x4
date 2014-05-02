#pragma once

#include <QObject>
#include <QTimer>
#include <QMatrix3x3>
#include <QVector2D>
#include <QVector3D>
#include <QStringList>

#include <cmath>

#include <trikControl/brick.h>
#include <trikControl/motor.h>

#include "WheelType.h"


using namespace trikControl;


class Wheel : public QObject
{
    Q_OBJECT
public:
    explicit Wheel(Brick& brick, WheelType wheelType, const QString motor, const QString servomotor);
    virtual ~Wheel();

    WheelType wheelType;

    void StopMotors();
    void StopServoMotors();

    // Управление обычным режимом
    void WheelSetGeneralMode(); // Повернуть колесо в нормальный режим
    void WheelGoFront(int power); // Вперед ехать в нормальном режиме
    void WheelGoBack(int power); // Назад ехать в нормальном режиме

    // Управление круговым режимом (машина едет вокруг своей оси)
    void WheelSetCircleMode(); // Повернуть колесо в режим кругового поворота
    void WheelGoClockWise(int power); // Поворачивать по часовой стрелке
    void WheelGoAntiClockWise(int power); // Поворачивать против часовой стрелки

    // Управление режимом лобстера (машина едет в бок)
    void WheelSetLobsterMose(); // Повернуть колесо в режим лобстера
    void WheelGoRight(int power); // Вправо поехать в режиме лобстера
    void WheelGoLeft(int power); // Влево поехать в режиме лобстера

    void WheelSetParallelModeLeft(int ugol);

    void WheelSetParallelModeRight(int ugol);


    void WheelSetCar2x4ModeLeft(int ugol);

    void WheelSetCar2x4ModeRight(int ugol);

    void WheelSetCar4x4ModeLeft(int ugol);

    void WheelSetCar4x4ModeRight(int ugol);



private:
    Brick& brick;
    Motor* motor;
    Motor* servomotor;
};
