TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    vehicle.cpp \
    road.cpp \
    automobile.cpp \
    aircraft.cpp \
    helicopter.cpp \
    vehiclesurrogate.cpp

HEADERS += \
    vehicle.h \
    road.h \
    automobile.h \
    aircraft.h \
    helicopter.h \
    vehiclesurrogate.h

