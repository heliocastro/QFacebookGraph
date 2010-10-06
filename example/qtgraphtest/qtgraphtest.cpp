#include <QDebug>
#include <QUrl>

#include <qfacebookgraph.h>
#include <graph/qfacebookgraphconnectionhome.h>

#include "qtgraphtest.h"

QtGraphTest::QtGraphTest(QObject *parent) :
    QObject(parent)
{
}

void QtGraphTest::requestDone( bool ok )
{
    if (ok)
    {
        qDebug() << "Request ok";
        QMapIterator<QString,QVariant> map( graph->result() );
        while ( map.hasNext() )
        {
            map.next();
            qDebug() << "KEY: " << map.key() << "   Value:" << map.value().typeName();
        }
    }
    else
        qDebug() << "Request failed";
}


void QtGraphTest::testUrl( const QString value )
{
    QString l( value );
    QUrl data( l );

    if( data.hasFragment() )
    {
        data = QUrl( l.replace("#", "?"));
        if( data.hasQueryItem("access_token") )
        {
            graph = new QFacebookGraph( data.queryItemValue( "access_token" ) );
            QFacebookGraphConnectionHome *cm = new QFacebookGraphConnectionHome(graph);

            if( cm )
                cm->update();

            //connect( graph, SIGNAL(requestDone( bool )), this, SLOT( requestDone( bool ) ) );
        }
    }
}
