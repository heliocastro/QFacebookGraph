/*
 * Copyright 2010 Helio Chissini de Castro <helio@collabora.co.uk>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0

 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
*/

#include <QDebug>
#include <QUrl>
#include <QDateTime>
#include <QSettings>

#include <qfacebookgraph.h>
#include <graph/qfacebookgraphconnectionhome.h>
#include <graph/qfacebookgraphconnectioninterests.h>
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
    ctxt->setContextProperty( "homeModel", QVariant::fromValue(home->model()));
    ctxt->setContextProperty( "userObject", user);
    ctxt->setContextProperty( "userEducationModel", QVariant::fromValue( user->educationModel()) );
    ctxt->setContextProperty( "userWorkModel", QVariant::fromValue( user->workModel()) );

    // Implement the oauth URL access just for demo
    QUrl loginUrlAccess( "https://graph.facebook.com/oauth/authorize" );
    loginUrlAccess.addQueryItem("client_id", CLIENT_ID);
    loginUrlAccess.addQueryItem("redirect_uri", "http://www.facebook.com/connect/login_success.html");
    loginUrlAccess.addQueryItem("type","user_agent" );
    loginUrlAccess.addQueryItem("display","touch");
    loginUrlAccess.addQueryItem("scope","read_stream,user_birthday,publish_stream");

    ctxt->setContextProperty( "loginUrlAccess", loginUrlAccess);

}

bool QtGraphTest::hasValidToken() {
    if( !settings->contains("token/expire") ||
            QDateTime::currentDateTime() > settings->value("token/expire").toDateTime() )
        return false;
    return true;
}


void QtGraphTest::updateHomeView() {
    homeList = home->model();
    ctxt->setContextProperty( "homeModel", QVariant::fromValue(homeList) );
}

void QtGraphTest::updateUserView()
{
    ctxt->setContextProperty( "userObject", user );
    ctxt->setContextProperty( "userEducationModel", QVariant::fromValue( user->educationModel()) );
    ctxt->setContextProperty( "userWorkModel", QVariant::fromValue( user->workModel()) );
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
    home->update();

    user->setToken( settings->value("token/token").toString() );
    connect(user, SIGNAL(modelPopulated()), this, SLOT(updateUserView()));
    user->update();

    //just for test
    QFacebookGraphConnectionInterests *pic = new QFacebookGraphConnectionInterests();
    pic->setToken( settings->value("token/token").toString() );
    pic->update();
}
