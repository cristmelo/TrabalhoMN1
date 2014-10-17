#-------------------------------------------------
#
# Project created by QtCreator 2014-10-13T19:54:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Metodos
TEMPLATE = app


SOURCES += src/mainwindow.cpp \
           src/main.cpp \
           src/genericMethod.cpp \
           src/listResults.cpp \
           src/methods.cpp \
           src/newtonRaphson.cpp \
           src/secante2.cpp \

HEADERS  += lib/mainwindow.h \
            lib/imports.h \
            lib/genericMethod.h \
            lib/listResults.h \
            lib/methods.h \
            lib/newtonRaphson.h \
            lib/secante2.h \

FORMS    += UI/mainwindow.ui
