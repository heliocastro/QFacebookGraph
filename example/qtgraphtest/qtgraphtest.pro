# -------------------------------------------------
# Project created by QtCreator 2010-08-18T13:07:41
# -------------------------------------------------
QT += core gui network webkit declarative
TARGET = qtgraphtest
TEMPLATE = app
SOURCES += main.cpp \  
    qtgraphtest.cpp
OTHER_FILES += \
    qml/Main.qml
CONFIG += link_pkgconfig debug
PKGCONFIG += QJson
LIBS += -L../../lib -lqfacebookgraph

INCLUDEPATH += ../../src

HEADERS += \
    qtgraphtest.h
