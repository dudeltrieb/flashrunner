QT += core gui

TARGET = flashRunner
TEMPLATE = app

SOURCES += main.cpp \
    runnergui.cpp \
    readingthread.cpp \
    ftd2xxinterface.cpp

HEADERS  += \
    runnergui.h \
    readingthread.h \
    ftd2xxinterface.h

include(ftd2xx.pri)

















