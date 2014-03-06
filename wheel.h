#include <QObject>
#include <QTimer>
#include <QMatrix3x3>
#include <QVector2D>
#include <QVector3D>
#include <QStringList>

#include <cmath>

#include <trikControl/brick.h>


enum WheelType{FrontLeft, FrontRight, BackLeft, BackRight};
class Wheel : public QObject
{
    Q_OBJECT
public:
    explicit Wheel(Brick brick, WheelType wheelType, QString motor,  QString servomotor, int servomidle);
    virtual ~Wheel();

    WheelType wheelType;

    // Управление обычным режимом
    void SetGeneralMode(); // Повернуть колесо в нормальный режим
    void GoFront(int power); // Вперед ехать в нормальном режиме
    void GoBack(int power); // Назад ехать в нормальном режиме

    // Управление круговым режимом (машина едет вокруг своей оси)
    void SetCircleMode(); // Повернуть колесо в режим кругового поворота
    void GoClockWise(int power); // Поворачивать по часовой стрелке
    void GoAntiClockWise(int power); // Поворачивать против часовой стрелки

    // Управление режимом лобстера (машина едет в бок)
    void SetLobsterMose(); // Повернуть колесо в режим лобстера
    void GoRight(int power); // Вправо поехать в режиме лобстера
    void GoLeft(int power); // Влево поехать в режиме лобстера

    void SetCar2x4ModeLeft();

    void SetCar2x4ModeRight();

    void SetCar4x4ModeLeft();

    void SetCar4x4ModeRight();



private:
    Brick brick;
    PowerMotor motor;
    ServoMotor servomotor;
    int servomidle;
};
