#-------------------------------------------------
#
# Project created by QtCreator 2015-11-28T12:23:06
#
#-------------------------------------------------

QT       += core gui network qml quick declarative
CONFIG += c++11 mobility
MOBILITY += feedback
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = main
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Network/networkresponceitem.cpp \
    Network/httprequest.cpp \
    Network/qeuerequests.cpp \
    Util/images.cpp \
    Models/standartmodel.cpp \
    Models/imagesmodel.cpp

HEADERS  += mainwindow.h \
    Network/networkresponceitem.h \
    Network/httprequest.h \
    Network/items.h \
    Network/qeuerequests.h \
    Util/images.h \
    Models/standartmodel.h \
    Models/imagesmodel.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc
