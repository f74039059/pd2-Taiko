#-------------------------------------------------
#
# Project created by QtCreator 2016-05-24T10:54:11
#
#-------------------------------------------------

QT       += core gui \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test500
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ball.cpp \
    target.cpp

HEADERS  += mainwindow.h \
    ball.h \
    target.h

RESOURCES += \
    bg.qrc
