#-------------------------------------------------
#
# Project created by QtCreator 2017-11-28T13:57:42
#
#-------------------------------------------------

QT       += core gui
QT += opengl
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VS
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp

HEADERS  += mainwindow.h \
    glwidget.h

FORMS    += mainwindow.ui
