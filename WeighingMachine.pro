#-------------------------------------------------
#
# Project created by QtCreator 2014-09-10T10:12:36
#
#-------------------------------------------------

QT       += core gui serialport sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

INCLUDEPATH += "c:/boost/boost_1_54_0"

LIBS += "C:/boost_lib/boost/bin.v2/libs/date_time/build/gcc-mingw-4.8.0/release/link-static/threading-multi/libboost_date_time-mgw48-mt-1_54.a"


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
    ConvertError.h \
    EmptyError.h

FORMS    += MainWindow.ui \
    SettingsDialog.ui
