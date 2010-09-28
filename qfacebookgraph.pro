QT += network core
QT -= gui

TARGET = qfacebookgraph
TEMPLATE = lib
CONFIG += link_pkgconfig debug

DEFINES += QFACEBOOKGRAPH_LIBRARY

SOURCES += qfacebookgraph.cpp \
    graph/qfacebookgraphvideo.cpp \
    graph/qfacebookgraphuser.cpp \
    graph/qfacebookgraphsubscription.cpp \
    graph/qfacebookgraphstatusmessage.cpp \
    graph/qfacebookgraphpost.cpp \
    graph/qfacebookgraphphoto.cpp \
    graph/qfacebookgraphpage.cpp \
    graph/qfacebookgraphnote.cpp \
    graph/qfacebookgraphlink.cpp \
    graph/qfacebookgraphgroup.cpp \
    graph/qfacebookgraphevent.cpp \
    graph/qfacebookgraphconnectionhomemodel.cpp \
    graph/qfacebookgraphconnectionfeedmodel.cpp \
    graph/qfacebookgraphcheckin.cpp \
    graph/qfacebookgraphapplication.cpp \
    graph/qfacebookgraphalbum.cpp

HEADERS += qfacebookgraph.h\
        qfacebookgraph_global.h \
    graph/qfacebookgraphvideo.h \
    graph/qfacebookgraphuser.h \
    graph/qfacebookgraphsubscription.h \
    graph/qfacebookgraphstatusmessage.h \
    graph/qfacebookgraphpost.h \
    graph/qfacebookgraphphoto.h \
    graph/qfacebookgraphpage.h \
    graph/qfacebookgraphnote.h \
    graph/qfacebookgraphlink.h \
    graph/qfacebookgraphgroup.h \
    graph/qfacebookgraphevent.h \
    graph/qfacebookgraphconnectionhomemodel.h \
    graph/qfacebookgraphconnectionfeedmodel.h \
    graph/qfacebookgraphcheckin.h \
    graph/qfacebookgraphapplication.h \
    graph/qfacebookgraphalbum.h

PKGCONFIG += QJson
