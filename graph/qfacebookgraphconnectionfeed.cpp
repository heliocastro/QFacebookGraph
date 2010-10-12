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

QFacebookGraphConnectionFeed::QFacebookGraphConnectionFeed(QObject *parent) :
    QFacebookGraph(parent)
{
    m_previous = QString::null;
    m_next = QString::null;
    m_feedModel = FeedModelList();
}

FeedModelList QFacebookGraphConnectionFeed::getFeedModel() {
    return m_feedModel;
}

void QFacebookGraphConnectionFeed::update(int howMany) {
    addArgument("limit", QString::number(howMany));
    Get( "/me/feed" );
}

void QFacebookGraphConnectionFeed::next(int howMany) {
    addArgument("limit", QString::number(howMany));
    addArgument("until", m_next);
    Get( "/me/feed" );
}

void QFacebookGraphConnectionFeed::previous(int howMany) {
    addArgument("limit", QString::number(howMany));
    addArgument("since", m_next);
    Get( "/me/feed" );
}

void QFacebookGraphConnectionFeed::requestDone(bool ok) {
    m_feedModel.clear();

    if (ok)
    {
        if(result().contains("data"))
        {
            populateModel();
        }

        if(result().contains("paging"))
        {
            QUrl url(result().value("paging").toMap().value("next").toString());
            m_next = url.queryItemValue("until");
            url = QUrl(result().value("paging").toMap().value("previous").toString());
            m_previous = url.queryItemValue("since");
        }
        emit modelPopulated();
    }
    else
        qDebug() << "Request failed";
}

void QFacebookGraphConnectionFeed::populateModel() {
    QFacebookGraphConnectionFeedModel *feedObj = new QFacebookGraphConnectionFeedModel();

    QVariantList list = result().value("data").toList();
    QVariantList::const_iterator i;
    for (i = list.constBegin(); i != list.constEnd(); ++i)
    {
        QVariantMap::const_iterator j;
        for(j = (*i).toMap().constBegin(); j != (*i).toMap().constEnd(); ++j)
        {
            if(j.key() == "attribution")
                feedObj->setAttribution(j.value().toString());
            if(j.key() == "created_time")
                feedObj->setCreatedtime(j.value().toString());
            if(j.key() == "id")
                feedObj->setFbid(j.value().toString());
            if(j.key() == "from") {
                feedObj->setFromFbid(j.value().toMap().value("id").toString());
                feedObj->setFromName(j.value().toMap().value("name").toString());
            }
            if(j.key() == "type")
                feedObj->setType(j.value().toString());
            if(j.key() == "message")
                feedObj->setMessage(j.value().toString());
            if(j.key() == "caption")
                feedObj->setCaption(j.value().toString());
            if(j.key() == "description")
                feedObj->setDescription(j.value().toString());
            if(j.key() == "likes")
                feedObj->setLikes(j.value().toULongLong());
            if(j.key() == "updated_time")
                feedObj->setUpdatedtime(j.value().toString());
            if(j.key() == "icon")
                feedObj->setIcon(j.value().toUrl());
            if(j.key() == "picture")
                feedObj->setPicture(j.value().toUrl());
            if(j.key() == "link")
                feedObj->setLink(j.value().toUrl());
        }

        m_feedModel.append(feedObj);
        feedObj = new QFacebookGraphConnectionFeedModel();
    }
}
