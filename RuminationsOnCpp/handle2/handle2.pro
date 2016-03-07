TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    handle.cpp \
    point.cpp \
    usecount.cpp

HEADERS += \
    handle.h \
    point.h \
    usecount.h

