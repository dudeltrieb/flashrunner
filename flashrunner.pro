QT += core gui

TARGET = flashRunner
TEMPLATE = app

SOURCES += main.cpp \
    runnergui.cpp \
    readingthread.cpp \
    ftinterface.cpp

HEADERS  += \
    runnergui.h \
    readingthread.h \
    ftinterface.h

include(ftd2xx.pri)

















