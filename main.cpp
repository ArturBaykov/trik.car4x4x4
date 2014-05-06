#include <QtGui/QApplication>
#include <QStringList>
#include <trikControl/brick.h>
#include <unistd.h>
#include <QTime>
#include <QTextStream>

//#include "fifo.h"
#include "car.h"
#include "linetracer.h"
#include "gamepadrobot.h"
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
    GamePadRobot game(localbrick, car);
    //Linetracer linetracer(car);
    QTextStream streamIn(stdin);



    qDebug()  <<"mumumumu";
    //streamIn.readLine();

    return app.exec();
}



