#include <QDebug>
#include <QUrl>
#include <QDateTime>
#include <QSettings>

#include <qfacebookgraph.h>
#include <graph/qfacebookgraphconnectionhome.h>
#include<graph/qfacebookgraphuser.h>

#include "qtgraphtest.h"

// Use your own client id
#ifndef CLIENT_ID
#define CLIENT_ID "113759468684478"
#endif

QtGraphTest::QtGraphTest(QDeclarativeView *view, QObject *parent) :
    QObject(parent)
{
    settings = new QSettings("Collabora", "QtGraphTest");

    home = new QFacebookGraphConnectionHome();
    user = new QFacebookGraphUser();

    ctxt = view->rootContext();
    ctxt->setContextProperty( "test", this );
    ctxt->setContextProperty( "homeModel", QVariant::fromValue(home->getHomeModel()));
    ctxt->setContextProperty( "userObject", user);

    // Implement the oauth URL access just for demo
    QUrl loginUrlAccess( "https://graph.facebook.com/oauth/authorize" );
    loginUrlAccess.addQueryItem("client_id", CLIENT_ID);
    loginUrlAccess.addQueryItem("redirect_uri", "http://www.facebook.com/connect/login_success.html");
    loginUrlAccess.addQueryItem("type","type=user_agent&display=touch");

    ctxt->setContextProperty( "loginUrlAccess", loginUrlAccess);

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
    if( !hasValidToken() )
    {
        QString l( value );
        QUrl data( l );

        if( data.hasFragment() )
        {
            data = QUrl( l.replace("#", "?"));
            if( data.hasQueryItem("access_token") )
            {
                settings->setValue("token/expire",
                                   QDateTime::currentDateTime().addSecs(
                                       data.queryItemValue("expires_in").toInt() ) );
                settings->setValue("token/token", data.queryItemValue("access_token"));
            }
        }
        else
            return;
    }

    home->setToken( settings->value("token/token").toString() );
    connect(home, SIGNAL(modelPopulated()), this, SLOT(updateHomeView()));
    home->init();

    user->setToken( settings->value("token/token").toString() );
    //connect(user, SIGNAL(modelPopulated()), this, SLOT(updateUserView()));
    user->init();
}
