#-------------------------------------------------
#
# Project created by QtCreator 2016-05-22T17:24:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = projet1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    expression.cpp \
    controleur.cpp \
    complexe.cpp \
    fraction.cpp \
    entier.cpp \
    reel.cpp \
    atome.cpp \
    pile.cpp \
    maths.cpp \
    programme.cpp \
    numerique.cpp

HEADERS  += mainwindow.h \
    controleur.h \
    expression.h \
    maths.h \
    complexe.h \
    fraction.h \
    entier.h \
    reel.h \
    atome.h \
    pile.h \
    programme.h \
    litteral.h \
    numerique.h

FORMS    += \
    mainwindow.ui
