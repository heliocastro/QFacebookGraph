#include <QtCore/QCoreApplication>
#include <QDebug>

#include <qfacebookgraph.h>
#include <graph/qfacebookgraphuser.h>

#include "userdata.h"

void
Userdata::requestDone( bool hora ) {
	if ( hora )
	{
		qDebug() << "Request ok";
		qDebug() << graph->getResult();
	}
	else
	{
		qDebug() << "Request failed";
	}
}

Userdata::Userdata( QObject *parent ) :
	QObject( parent )
{
	graph = new QFacebookGraph();

	// Use my own id of Facebook to test :-)
	// This is direct connection. Remember that result is caught by requestDone
	// signal from QFacebookGraph main class
    graph->Get("/613384675");

	connect( graph, SIGNAL(requestDone( bool )), this, SLOT( requestDone( bool ) ) );
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

	new Userdata();

    return a.exec();
}
