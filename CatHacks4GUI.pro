#-------------------------------------------------
#
# Project created by QtCreator 2018-04-07T15:37:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CatHacks4GUI
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
    creditwidgetitem.cpp \
    classwidgetitem.cpp \
    lunchwidgetitem.cpp \
    avoidwidgetitem.cpp \
    requirewidgetitem.cpp \
    coursewidget.cpp \
    course.cpp \
    sec.cpp \
    sol.cpp

HEADERS += \
        mainwindow.h \
    creditwidgetitem.h \
    classwidgetitem.h \
    lunchwidgetitem.h \
    avoidwidgetitem.h \
    requirewidgetitem.h \
    coursewidget.h \
    course.h \
    sec.h \
    sol.h \
    stime.h

FORMS += \
        mainwindow.ui \
    creditwidgetitem.ui \
    classwidgetitem.ui \
    lunchwidgetitem.ui \
    requirewidgetitem.ui \
    avoidwidgetitem.ui \
    coursewidget.ui

DISTFILES += \
    textout.txt

CONFIG += c++11
