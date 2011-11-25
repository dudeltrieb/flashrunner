#-------------------------------------------------
#
# Project created by QtCreator 2011-11-24T10:03:41
#
#-------------------------------------------------

QT       += core gui

TARGET = flashRunner
TEMPLATE = app


SOURCES += main.cpp \
    runnergui.cpp \
    readingthread.cpp \
    comclass.cpp

HEADERS  += \
    runnergui.h \
    readingthread.h \
    comclass.h

LIBS += -L"c:\myLib\i386" -lftd2xx

INCLUDEPATH += c:/myLib

















