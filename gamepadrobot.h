#include <QtGui/QApplication>
#include <QStringList>
#include <trikControl/brick.h>
#include <unistd.h>
#include <QTime>
#include <QTextStream>

#include <trikControl/gamepad.h>


#include "car.h"


enum GamePadMode
{
    General,        // Обычный режим
    Circle,         // Круговой режим (машина едет вокруг своей оси)
    Lobster,        // Режим Лобстера (машина едет в бок)
    Car2x4,         // Режим "Машина повернула передними колесами"
    Car4x4,         // Режим "Машина повернула передними колесами и задними"
    TornadoTopMode,

    NotCurrent      // Вращение колес свободное
};



class GamePadRobot : public QObject
{
    Q_OBJECT
public:
    explicit GamePadRobot(Brick& brick, CarPlatform& carPlatform);
    virtual ~GamePadRobot();

    //void StartGamepad();
    //void StopGamepad();

public slots:
    void ChangeMod(int button, int pressed); //Button pressed
    void GamepadPad(int pad, int x, int y);  // GamePad pressed
    void GamepadPadUp(int pad);              // GamePad unpressed


private:
    Brick& brick;
    Gamepad& gamepad;
    CarPlatform& carPlatform;
    GamePadMode mode = General;

    int Rangeint(int x);


};
