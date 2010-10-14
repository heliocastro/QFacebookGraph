QT += network core
QT -= gui

TARGET = qfacebookgraph
TEMPLATE = lib
CONFIG += link_pkgconfig debug
DESTDIR = ../lib

DEFINES += QFACEBOOKGRAPH_LIBRARY

LIBS += -Wl,--no-undefined

PKGCONFIG += QJson

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
    graph/qfacebookgraphalbum.cpp \
    graph/qfacebookgraphconnectionhome.cpp \
    graph/qfacebookgraphconnectionfeed.cpp \
    graph/qfacebookgraphcommoneducationmodel.cpp \
    graph/qfacebookgraphcommonworkmodel.cpp

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
    graph/qfacebookgraphalbum.h \
    graph/qfacebookgraphconnectionhome.h \
    graph/qfacebookgraphconnectionfeed.h \
    graph/qfacebookgraphcommoneducationmodel.h \
    graph/qfacebookgraphcommonworkmodel.h


target.path = $$[QT_INSTALL_LIBS]
INSTALLS += target

headers.files = qfacebookgraph.h \ 
	qfacebookgraph_global.h
headers.path = $$[QT_INSTALL_HEADERS]/QFacebookGraph
INSTALLS += headers

graph_headers.files += graph/qfacebookgraphvideo.h \
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
    graph/qfacebookgraphalbum.h \
    graph/qfacebookgraphconnectionhome.h \
    graph/qfacebookgraphconnectionfeed.h \
    graph/qfacebookgraphcommoneducationmodel.h \
    graph/qfacebookgraphcommonworkmodel.h

graph_headers.path = $$[QT_INSTALL_HEADERS]/QFacebookGraph/graph
INSTALLS += graph_headers
