TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Task.cpp \
    Function.cpp \
    Processor.cpp

DISTFILES += \
    Input.txt

HEADERS += \
    Task.h \
    Function.h \
    Processor.h
