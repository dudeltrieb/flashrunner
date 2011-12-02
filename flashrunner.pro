QT += core gui

TARGET = flashRunner
TEMPLATE = app

SOURCES += main.cpp \
    flashrunnerwidget.cpp \
    ftinterface.cpp

HEADERS  += \
    flashrunnerwidget.h \
    ftinterface.h \

include(ftd2xx.pri)

















