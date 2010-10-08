#include <QDebug>
#include <QUrl>
#include <QDateTime>
#include <QSettings>

#include <qfacebookgraph.h>
#include <graph/qfacebookgraphconnectionhome.h>
#include<graph/qfacebookgraphuser.h>

#include "qtgraphtest.h"

QtGraphTest::QtGraphTest(QDeclarativeView *view, QObject *parent) :
    QObject(parent)
{
    settings = new QSettings("Collabora", "QtGraphTest");
    ctxt = view->rootContext();
    ctxt->setContextProperty( "test", this );
    ctxt->setContextProperty( "homeModel", QVariant::fromValue(HomeModelList()));
    ctxt->setContextProperty( "userObject", user);
}

bool QtGraphTest::hasValidToken() {
    if( !settings->contains("token/expire") ||
            QDateTime::currentDateTime() > settings->value("token/expire").toDateTime() )
        return false;
    return true;
}


void QtGraphTest::updateHomeView() {
    homeList = home->getHomeModel();
    ctxt->setContextProperty( "homeModel", QVariant::fromValue(homeList) );
}

void QtGraphTest::updateUserView()
{
    ctxt->setContextProperty( "userObject", user );
}

void QtGraphTest::testUrl( const QString value ) {
    QString token;

    if( !hasValidToken() )
    {
        QString l( value );
        QUrl data( l );

        if( data.hasFragment() )
        {
            data = QUrl( l.replace("#", "?"));
            if( data.hasQueryItem("access_token") )
            {
                token = data.queryItemValue("access_token");
                settings->setValue("token/expire",
                                   QDateTime::currentDateTime().addSecs(
                                       data.queryItemValue("expires_in").toInt() ) );
                settings->setValue("token/token", token);
            }
        }
        else
            return;
    }

    token = settings->value("token/token").toString();

    home = new QFacebookGraphConnectionHome(token);
    connect(home, SIGNAL(modelPopulated()), this, SLOT(updateHomeView()));

    user = new QFacebookGraphUser(token);
    connect(user, SIGNAL(modelPopulated()), this, SLOT(updateUserView()));
}
