#-------------------------------------------------
#
# Project created by QtCreator 2018-02-20T20:36:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PumpEmulator
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    step.cpp \
    pump.cpp \
    dataucs.cpp \
    gaminghandler.cpp \
    game.cpp \
    loaducs.cpp \
    fileio.cpp \
    steppointer.cpp \
    pumpmode.cpp \
    point.cpp

HEADERS += \
        mainwindow.h \
    step.h \
    pump.h \
    dataucs.h \
    gaminghandler.h \
    game.h \
    loaducs.h \
    fileio.h \
    steppointer.h \
    pumpmode.h \
    point.h

FORMS += \
        mainwindow.ui
