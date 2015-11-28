#-------------------------------------------------
#
# Project created by QtCreator 2015-11-28T12:23:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = main
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Network/networkresponceitem.cpp \
    Network/httprequest.cpp

HEADERS  += mainwindow.h \
    Network/networkresponceitem.h \
    Network/httprequest.h
FORMS    += mainwindow.ui


RESOURCES += \
    resource.qrc
