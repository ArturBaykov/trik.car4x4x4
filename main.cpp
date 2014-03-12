#include <QtGui/QApplication>
#include <QStringList>
#include <trikControl/brick.h>
#include <unistd.h>
#include <QTime>
#include <QTextStream>

//#include "fifo.h"
//#include "car.h"
#include "linetracer.h"
#include <trikControl/brick.h>

const QString FrontLeftMotorName = "JM3";
const QString FrontRightMotorName = "M1";
const QString BackLeftMotorName = "JM2";
const QString BackRightMotorName = "JM1";

const QString FrontLeftServomotorName = "JC3";
const QString FrontRightServomotorName = "JE1";
const QString BackLeftServomotorName = "JC2";
const QString BackRightServomotorName = "JC1";



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Brick localbrick(*(app.thread()), "./");
    //CarPlatform car(localbrick);
    QTextStream streamIn(stdin);


 /*   streamIn.readLine();
    qDebug()  <<"SetGeneralMode and go";
    car.SetGeneralMode();
    car.GoFront(100);

    streamIn.readLine();
    qDebug()  <<"SetCircleMode and GoClockWise";
    car.SetCircleMode();
    car.GoClockWise(100);

    streamIn.readLine();
    qDebug()  <<"GoAntiClockWise";
    car.GoAntiClockWise(100);

    streamIn.readLine();
    qDebug()  <<"Stop and SetGeneralMode";
    streamIn.readLine();
    car.GoAntiClockWise(0);
    car.SetGeneralMode();

    streamIn.readLine();
    qDebug() <<"GoBack";
    car.GoBack(100);

    streamIn.readLine();
    qDebug()  <<"SetLobsterMose and Go left";
    car.SetLobsterMose();
    car.GoLeft(100);

    streamIn.readLine();
    qDebug()  <<"GoRight";
    car.GoRight(100);

    streamIn.readLine();
    qDebug()  <<"GoRight";
    car.GoRight(0);

    streamIn.readLine();
    qDebug()  <<"SetGeneralMode";
    car.SetGeneralMode();

    streamIn.readLine();
    qDebug()  <<"SetLobsterMose";
    car.SetLobsterMose();

    streamIn.readLine();
    qDebug()  <<"SetCircleMode";
    car.SetCircleMode();
*/

/////////////////////////
    car.GoFront(100);
//////////////////////////////////////////////////////////////
    streamIn.readLine();
    qDebug()  <<"SetCar2x4LeftMode(0)";
    car.SetCar2x4LeftMode(0);

    streamIn.readLine();
    qDebug()  <<"SetCar2x4LeftMode(10)";
    car.SetCar2x4LeftMode(10);

    streamIn.readLine();
    qDebug()  <<"SetCar2x4LeftMode(20)";
    car.SetCar2x4LeftMode(20);

    streamIn.readLine();
    qDebug()  <<"SetCar2x4LeftMode(30)";
    car.SetCar2x4LeftMode(30);

    streamIn.readLine();
    qDebug()  <<"SetCar2x4LeftMode(35)";
    car.SetCar2x4LeftMode(35);

    streamIn.readLine();
    qDebug()  <<"SetCar2x4LeftMode(40)";
    car.SetCar2x4LeftMode(40);

    streamIn.readLine();
    qDebug()  <<"SetCar2x4LeftMode(45)";
    car.SetCar2x4LeftMode(45);

    streamIn.readLine();

    streamIn.readLine();
    qDebug()  <<"SetCar2x4RightMode(0)";
    car.SetCar2x4RightMode(0);

    streamIn.readLine();
    qDebug()  <<"SetCar2x4RightMode(10)";
    car.SetCar2x4RightMode(10);

    streamIn.readLine();
    qDebug()  <<"SetCar2x4RightMode(20)";
    car.SetCar2x4RightMode(20);

    streamIn.readLine();
    qDebug()  <<"SetCar2x4RightMode(30)";
    car.SetCar2x4RightMode(30);

    streamIn.readLine();
    qDebug()  <<"SetCar2x4RightMode(35)";
    car.SetCar2x4RightMode(35);

    streamIn.readLine();
    qDebug()  <<"SetCar2x4RightMode(40)";
    car.SetCar2x4RightMode(40);

    streamIn.readLine();
    qDebug()  <<"SetCar2x4RightMode(45)";
    car.SetCar2x4RightMode(45);

    streamIn.readLine();

    streamIn.readLine();

    streamIn.readLine();
    qDebug()  <<"SetCar4x4RightMode(0)";
    car.SetCar4x4RightMode(0);

    streamIn.readLine();
    qDebug()  <<"SetCar4x4RightMode(10)";
    car.SetCar4x4RightMode(10);

    streamIn.readLine();
    qDebug()  <<"SetCar4x4RightMode(20)";
    car.SetCar4x4RightMode(20);

    streamIn.readLine();
    qDebug()  <<"SetCar4x4RightMode(30)";
    car.SetCar4x4RightMode(30);

    streamIn.readLine();
    qDebug()  <<"SetCar4x4RightMode(35)";
    car.SetCar4x4RightMode(35);

    streamIn.readLine();
    qDebug()  <<"SetCar4x4RightMode(40)";
    car.SetCar4x4RightMode(40);

    streamIn.readLine();
    qDebug()  <<"SetCar4x4RightMode(45)";
    car.SetCar4x4RightMode(45);

    streamIn.readLine();

    streamIn.readLine();

    streamIn.readLine();
    qDebug()  <<"SetCar4x4LeftMode(0)";
    car.SetCar4x4LeftMode(0);

    streamIn.readLine();
    qDebug()  <<"SetCar4x4LeftMode(10)";
    car.SetCar4x4LeftMode(10);

    streamIn.readLine();
    qDebug()  <<"SetCar4x4LeftMode(20)";
    car.SetCar4x4LeftMode(20);

    streamIn.readLine();
    qDebug()  <<"SetCar4x4LeftMode(30)";
    car.SetCar4x4LeftMode(30);

    streamIn.readLine();
    qDebug()  <<"SetCar4x4LeftMode(35)";
    car.SetCar4x4LeftMode(35);

    streamIn.readLine();
    qDebug()  <<"SetCar4x4LeftMode(40)";
    car.SetCar4x4LeftMode(40);

    streamIn.readLine();
    qDebug()  <<"SetCar4x4LeftMode(45)";
    car.SetCar4x4LeftMode(45);

    streamIn.readLine();


    return 0;
}



