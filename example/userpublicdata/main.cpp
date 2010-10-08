#include <QtCore/QCoreApplication>
#include <QDebug>

#include <qfacebookgraph.h>
#include <graph/qfacebookgraphuser.h>

#include "userdata.h"

void
Userdata::requestDone( bool ok) {
	if ( ok )
	{
		qDebug() << "Request ok";
		qDebug() << result();
	}
	else
	{
		qDebug() << "Request failed";
	}

	QCoreApplication::quit();
}

Userdata::Userdata()
{
	// Use my own id of Facebook to test :-)
	// This is direct connection. Remember that result is caught by requestDone
	// signal from QFacebookGraph main class
	QUrl url = baseUrl();
	url.setEncodedPath( "613384675" );
    Get( url );
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

	new Userdata();

    return a.exec();
}
