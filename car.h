#pragma once
#include <QObject>
#include <QTimer>
#include <QMatrix3x3>
#include <QVector2D>
#include <QVector3D>
#include <QStringList>

#include <cmath>

#include <trikControl/brick.h>
#include "wheel.h"
//#include "WheelType.h"

using namespace trikControl;

enum CarMode
{
    cmGeneral,        // Обычный режим
    cmCircle,         // Круговой режим (машина едет вокруг своей оси)
    cmLobster,        // Режим Лобстера (машина едет в бок)
    cmCar2x4Left,     // Режим "Машина повернула передними колесами влево"
    cmCar2x4Right,    // Режим "Машина повернула передними колесами вправо"
    cmCar4x4Left,     // Режим "Машина повернула передними колесами влево, задние вправо"
    cmCar4x4Right,    // Режим "Машина повернула передними колесами вправо, задние влево"
    cmTornadoTopMode,
    cmTornadoBottomMode,

    cmNotCurrent      // Вращение колес свободное
};

class CarPlatform : public QObject
{
    Q_OBJECT
public:
    explicit CarPlatform(Brick& brick);
    virtual ~CarPlatform();

    CarMode CurrentCarMode;

    void StopMotors();
    void StopServoMotors();


    // Управление обычным режимом
    void SetGeneralMode(); // Повернуть колесо в нормальный режим
    void GoFront(int power); // Вперед ехать в нормальном режиме
    void GoBack(int power); // Назад ехать в нормальном режиме

    // Управление круговым режимом (машина едет вокруг своей оси)
    void SetCircleMode(); // Повернуть колесо в режим кругового поворота
    void GoClockWise(int power); // Поворачивать по часовой стрелке
    void GoAntiClockWise(int power); // Поворачивать против часовой стрелки

    // Управление режимом лобстера (машина едет в бок)
    void SetLobsterMode(); // Повернуть колесо в режим лобстера
    void GoRight(int power); // Вправо поехать в режиме лобстера
    void GoLeft(int power); // Влево поехать в режиме лобстера



    void SetParallelModeLeft(int ugol);
    void SetParallelModeRight(int ugol);

    void SetCar2x4LeftMode(int ugol);
    void SetCar2x4RightMode(int ugol);

    void SetCar4x4LeftMode(int ugol);
    void SetCar4x4RightMode(int ugol);

    void SetTornadoTopMode();
    void SetTornadoBottomMode();

    void GoClockTornadoTop(int power);
    void GoAntiClocktTornadoTop(int power);
    void GoAntiClockTornadoBottom(int power);
    void GoClockTornadoBottom(int power);



private:
    Brick& brick;
    Wheel wheelFrontLeft;
    Wheel wheelFrontRight;
    Wheel wheelBackLeft;
    Wheel wheelBackRight;
};
