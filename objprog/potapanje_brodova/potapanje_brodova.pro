#-------------------------------------------------
#
# Project created by QtCreator 2016-05-05T11:17:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = potapanje_brodova
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    polje.cpp \
    tabla.cpp \
    brod.cpp

HEADERS  += mainwindow.h \
    polje.h \
    tabla.h \
    brod.h

FORMS    +=

RESOURCES += \
    resources.qrc
