QT += network core
QT -= gui

TARGET = qfacebookgraph
TEMPLATE = lib
CONFIG += link_pkgconfig debug
DESTDIR = ../lib

DEFINES += QFACEBOOKGRAPH_LIBRARY

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
    graph/qfacebookgraphcheckin.cpp \
    graph/qfacebookgraphapplication.cpp \
    graph/qfacebookgraphalbum.cpp \
    graph/qfacebookgraphconnectionhome.cpp \
    graph/qfacebookgraphconnectionfeed.cpp \
    graph/qfacebookgraphcommoneducationmodel.cpp \
    graph/qfacebookgraphcommonworkmodel.cpp \
    graph/qfacebookgraphcommonfeedmodel.cpp \
    graph/qfacebookgraphconnectiontagged.cpp \
    graph/qfacebookgraphconnectionbase.cpp \
    graph/qfacebookgraphconnectionposts.cpp \
    graph/qfacebookgraphconnectionpicture.cpp \
    graph/qfacebookgraphconnectionfriends.cpp \
    graph/qfacebookgraphcommonmediamodel.cpp \
    graph/qfacebookgraphconnectionmediabase.cpp \
    graph/qfacebookgraphconnectioninterests.cpp \
    graph/qfacebookgraphconnectionbooks.cpp \
    graph/qfacebookgraphconnectionlikes.cpp \
    graph/qfacebookgraphconnectiontelevision.cpp \
    graph/qfacebookgraphconnectionmovies.cpp \
    graph/qfacebookgraphconnectionmusic.cpp

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
    graph/qfacebookgraphcheckin.h \
    graph/qfacebookgraphapplication.h \
    graph/qfacebookgraphalbum.h \
    graph/qfacebookgraphconnectionfeed.h \
    graph/qfacebookgraphcommoneducationmodel.h \
    graph/qfacebookgraphcommonworkmodel.h \
    graph/qfacebookgraphconnectionhome.h \
    graph/qfacebookgraphcommonfeedmodel.h \
    graph/qfacebookgraphconnectiontagged.h \
    graph/qfacebookgraphconnectionbase.h \
    graph/qfacebookgraphconnectionposts.h \
    graph/qfacebookgraphconnectionpicture.h \
    graph/qfacebookgraphconnectionfriends.h \
    graph/qfacebookgraphcommonmediamodel.h \
    graph/qfacebookgraphconnectionmediabase.h \
    graph/qfacebookgraphconnectioninterests.h \
    graph/qfacebookgraphconnectionbooks.h \
    graph/qfacebookgraphconnectionlikes.h \
    graph/qfacebookgraphconnectiontelevision.h \
    graph/qfacebookgraphconnectionmovies.h \
    graph/qfacebookgraphconnectionmusic.h


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
    graph/qfacebookgraphcheckin.h \
    graph/qfacebookgraphapplication.h \
    graph/qfacebookgraphalbum.h \
    graph/qfacebookgraphconnectionbase.h \
    graph/qfacebookgraphconnectionhome.h \
    graph/qfacebookgraphconnectionfeed.h \
    graph/qfacebookgraphconnectiontagged.h \
    graph/qfacebookgraphcommoneducationmodel.h \
    graph/qfacebookgraphcommonfeedmodel.h \
    graph/qfacebookgraphcommonworkmodel.h

graph_headers.path = $$[QT_INSTALL_HEADERS]/QFacebookGraph/graph
INSTALLS += graph_headers
