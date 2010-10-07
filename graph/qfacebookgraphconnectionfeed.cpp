#include <QDebug>

#include <graph/qfacebookgraphconnectionfeed.h>

QFacebookGraphConnectionFeed::QFacebookGraphConnectionFeed(QString token, QObject *parent) :
    QFacebookGraph(token, parent)
{
    m_previous = QString::null;
    m_next = QString::null;
    m_feedModel = FeedModelList();

    // Inital connection
    update();
}

FeedModelList QFacebookGraphConnectionFeed::getFeedModel() {
    return m_feedModel;
}

void QFacebookGraphConnectionFeed::update(int howMany) {
    QUrl url = baseUrl();
    url.setEncodedPath("/me/feed");
    url.addQueryItem("limit", QString::number(howMany));
    Get( url );
}

void QFacebookGraphConnectionFeed::next(int howMany) {
    QUrl url = baseUrl();
    url.setEncodedPath("/me/feed");
    url.addQueryItem("limit", QString::number(howMany));
    url.addQueryItem("until", m_next);
    Get( url );
}

void QFacebookGraphConnectionFeed::previous(int howMany) {
    QUrl url = baseUrl();
    url.setEncodedPath("/me/feed");
    url.addQueryItem("limit", QString::number(howMany));
    url.addQueryItem("since", m_next);
    Get( url );
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
