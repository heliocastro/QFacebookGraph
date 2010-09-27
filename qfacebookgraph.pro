QT       += network

TARGET = qfacebookgraph
TEMPLATE = lib

DEFINES += QFACEBOOKGRAPH_LIBRARY

SOURCES += qfacebookgrpah.cpp

HEADERS += qfacebookgrpah.h\
        qfacebookgrpah_global.h

PKGCONFIG += QJson
