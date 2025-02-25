#-------------------------------------------------
#
# Project created by QtCreator 2020-07-09T13:59:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 3DPrintmanager
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

incPath = inc
srcPath = src

username     = AlexKrieg
QT_work_dir  = C:/Users/$$username/Documents/QT

CONFIG += c++11
DLL_buildPath = bin/64bit/build-Release
configPath   = $$QT_work_dir/DLL/Config

LIBS+= $$configPath/$$DLL_buildPath/Config.dll

INCLUDEPATH += $$incPath \
               $$configPath

SOURCES += \
        $$srcPath/main.cpp \
        $$srcPath/mainwindow.cpp \
        $$srcPath/printjob.cpp \
    src/infill.cpp \
    src/filament.cpp

HEADERS += \
        $$incPath/mainwindow.h \
        $$incPath/printjob.h \
    inc/infill.h \
    inc/filament.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
