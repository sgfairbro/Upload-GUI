#-------------------------------------------------
#
# Project created by QtCreator 2016-03-18T12:08:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = upload_gui
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    flightcontroltab.cpp \
    flightplanningtab.cpp

HEADERS  += mainwindow.h \
    flightcontroltab.h \
    flightplanningtab.h

FORMS    += mainwindow.ui \
    flightcontroltab.ui \
    flightplanningtab.ui

DISTFILES += \
    navigation.qml
