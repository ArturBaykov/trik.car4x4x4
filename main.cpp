#include <QtGui/QApplication>
#include <QStringList>
#include <trikControl/brick.h>
#include <unistd.h>
#include <QTime>
#include <QTextStream>

//#include "fifo.h"
#include "car.h"
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
    CarPlatform car(localbrick);




 /*   qDebug()<< "ping1";
    localbrick.motor(FrontLeftMotorName)->setPower(100);
    localbrick.motor(FrontRightMotorName)->setPower(100);
    localbrick.motor(BackLeftMotorName)->setPower(100);
    localbrick.motor(BackRightMotorName)->setPower(100);

    qDebug()<< "ping2";

    QTimer* qtimer = new QTimer();
    qtimer->setInterval(2000);
    qtimer->start;


    qDebug()<< "ping3";
    localbrick.motor(FrontLeftMotorName)->setPower(0);
    localbrick.motor(FrontRightMotorName)->setPower(0);
    localbrick.motor(BackLeftMotorName)->setPower(0);
    localbrick.motor(BackRightMotorName)->setPower(0);


    qDebug()<< "ping4";
    localbrick.motor(FrontLeftServomotorName)->setPower(50);
    localbrick.motor(FrontRightServomotorName)->setPower(-50);
    localbrick.motor(BackLeftServomotorName)->setPower(-50);
    localbrick.motor(BackRightServomotorName)->setPower(50);

    qDebug()<< "ping5";
    delay();

    qDebug()<< "ping6";
    localbrick.motor(FrontLeftServomotorName)->setPower(0);
    localbrick.motor(FrontRightServomotorName)->setPower(0);
    localbrick.motor(BackLeftServomotorName)->setPower(0);
    localbrick.motor(BackRightServomotorName)->setPower(0);
    delay();
    localbrick.motor(FrontLeftServomotorName)->setPower(-50);
    localbrick.motor(FrontRightServomotorName)->setPower(-50);
    localbrick.motor(BackLeftServomotorName)->setPower(-50);
    localbrick.motor(BackRightServomotorName)->setPower(-50);
    delay();
    localbrick.motor(FrontLeftServomotorName)->setPower(0);
    localbrick.motor(FrontRightServomotorName)->setPower(0);
    localbrick.motor(BackLeftServomotorName)->setPower(0);
    localbrick.motor(BackRightServomotorName)->setPower(0);
    delay();
*/
    /*
    car.SetGeneralMode();
    sleep(3000);
    car.SetCircleMode();
    sleep(3000);
    car.SetLobsterMose();
    sleep(3000);
    car.SetGeneralMode();
    */
    //car.SetGeneralMode();

    QTextStream streamIn(stdin);
/*
    streamIn.readLine();
    qDebug()<< "FrontLeftServomotorName";
    localbrick.motor(FrontLeftServomotorName)->setPower(0);
    streamIn.readLine();
    qDebug()<< "FrontRightServomotorName";
    localbrick.motor(FrontRightServomotorName)->setPower(0);
    streamIn.readLine();
    qDebug()<< "BackLeftServomotorName";
    localbrick.motor(BackLeftServomotorName)->setPower(0);
    streamIn.readLine();
    qDebug()<< "BackRightServomotorName";
    localbrick.motor(BackRightServomotorName)->setPower(0);
*/

    streamIn.readLine();
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

    streamIn.readLine();

    return 0;
}



