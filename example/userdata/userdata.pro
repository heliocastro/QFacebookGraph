#-------------------------------------------------
#
# Project created by QtCreator 2010-09-27T23:56:02
#
#-------------------------------------------------

QT       += core
QT       -= gui

INCLUDEPATH += ../..

CONFIG += link_pkgconfig
PKGCONFIG += QJson
LIBS += -L../../ -lqfacebookgraph

TARGET = userdata
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app


SOURCES += main.cpp
