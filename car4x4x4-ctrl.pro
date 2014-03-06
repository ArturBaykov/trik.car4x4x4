TRIKCONTROL_BINDIR = ../trikRuntime/bin/arm-release
TRIKCONTROL_DIR = ../trikRuntime/trikControl

QT       += core
QT       += network
QT       += gui
TARGET = car4x4x4-ctrl
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH = \
        $$PWD \
        $$BOOST_DIR \
        $$TRIKCONTROL_DIR/include \

LIBS += -L$$TRIKCONTROL_BINDIR -ltrikControl

!macx {
        QMAKE_LFLAGS += -Wl,-O1,-rpath,.
}

SOURCES += main.cpp \
           car.cpp \
           wheel.cpp

HEADERS += car.h \
           wheel.h
