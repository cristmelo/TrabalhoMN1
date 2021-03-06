#-------------------------------------------------
#
# Project created by QtCreator 2014-10-13T19:54:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Metodos
TEMPLATE = app


SOURCES += src/main.cpp \
           src/mainwindow.cpp \
           src/genericMethod.cpp \
           src/listResults.cpp \
           src/methods.cpp \
           src/newtonRaphson.cpp \
           src/secante2.cpp \
           src/comparation.cpp\
           src/plot.cpp \
           src/dialog.cpp

HEADERS  += lib/mainwindow.h \
            lib/imports.h \
            lib/genericMethod.h \
            lib/listResults.h \
            lib/methods.h \
            lib/newtonRaphson.h \
            lib/secante2.h \
            lib/comparation.h \
            lib/comparationStruct.h\
            lib/plot.h \
            lib/dialog.h

FORMS    += UI/mainwindow.ui \
            UI/comparation.ui \
            UI/dialog.ui
