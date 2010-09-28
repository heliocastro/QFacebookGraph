#include <QtCore/QCoreApplication>

#include <qfacebookgraph.h>
#include <graph/qfacebookgraphuser.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QFacebookGraph *graph = new QFacebookGraph( "token" );
    QFacebookGraphUser *user = new QFacebookGraphUser( graph );

    QVariantMap result = graph->Get("/4");

    return a.exec();
}
