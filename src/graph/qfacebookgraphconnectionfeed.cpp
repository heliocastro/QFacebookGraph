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

#include <graph/qfacebookgraphconnectionfeed.h>
#include <graph/qfacebookgraphcommonfeedmodel.h>

QFacebookGraphConnectionFeed::QFacebookGraphConnectionFeed(QString fbid, QObject *parent) :
    QFacebookGraphConnectionBase(fbid, parent)
{
    setFbid(fbid);
}

void QFacebookGraphConnectionFeed::update(int howMany) {
    addArgument("limit", QString::number(howMany));
    if (fbid().isNull())
        Get( "/me/feed" );
    else
        Get(fbid() + "/feed");
}

void QFacebookGraphConnectionFeed::updateNext(int howMany) {
    addArgument("limit", QString::number(howMany));
    addArgument("until", next());
    if (fbid().isNull())
        Get( "/me/feed" );
    else
        Get(fbid() + "/feed");
}

void QFacebookGraphConnectionFeed::updatePrevious(int howMany) {
    addArgument("limit", QString::number(howMany));
    addArgument("since", previous());
    if (fbid().isNull())
        Get( "/me/feed" );
    else
        Get(fbid() + "/feed");
}
