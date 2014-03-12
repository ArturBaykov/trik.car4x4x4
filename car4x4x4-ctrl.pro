TRIKCONTROL_BINDIR = ../trikRuntime/bin/arm-release
TRIKCONTROL_DIR = ../trikRuntime/trikControl

QT       += core
QT       += network
QT       += gui
TARGET = trik.car4x4x4
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
           wheel.cpp \
           log_fifo.cpp \
           linetracer.cpp

HEADERS += car.h \
           wheel.h\
           WheelType.h \
           log_fifo.h \
           linetracer.h
