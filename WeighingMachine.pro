#-------------------------------------------------
#
# Project created by QtCreator 2014-09-10T10:12:36
#
#-------------------------------------------------

QT       += core gui serialport sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WeighingMachine
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    Receiver.cpp \
    SettingsDialog.cpp \
    freeFunctions.cpp

HEADERS  += MainWindow.h \
    Receiver.h \
    PortError.h \
    SettingsDialog.h \
    freeFunctions.h \
    IncorrectSize.h \
    LogicError.h \
    ConvertError.h

FORMS    += MainWindow.ui \
    SettingsDialog.ui
