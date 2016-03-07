TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    expr_node.cpp \
    int_node.cpp \
    unary_node.cpp \
    binary_node.cpp \
    expr.cpp \
    ternary_node.cpp

HEADERS += \
    expr_node.h \
    int_node.h \
    unary_node.h \
    binary_node.h \
    expr.h \
    ternary_node.h

