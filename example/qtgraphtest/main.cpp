#include <QtGui/QApplication>
#include <QtDeclarative/QDeclarativeView>
#include <QtDeclarative/QDeclarativeEngine>
#include <QtDeclarative/QDeclarativeContext>
#include "qtgraphtest.h"



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QDeclarativeView view;
    view.rootContext()->setContextProperty( "test", new QtGraphTest );
    view.setSource( QUrl::fromLocalFile("qml/Main.qml") );
    view.setResizeMode( QDeclarativeView::SizeViewToRootObject );
    QObject::connect(view.engine(), SIGNAL(quit()), qApp, SLOT(quit()));

    //view.setWindowFlags( flags );
    view.show();
    return app.exec();
}
