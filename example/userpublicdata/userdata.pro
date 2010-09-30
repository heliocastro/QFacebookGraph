#-------------------------------------------------
#
# Project created by QtCreator 2010-09-27T23:56:02
#
#-------------------------------------------------

QT       += core network
QT       -= gui

INCLUDEPATH += ../..

CONFIG += link_pkgconfig debug
PKGCONFIG += QJson
LIBS += -L../../ -lqfacebookgraph

TARGET = userdata
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app


SOURCES += main.cpp

HEADERS += userdata.h
