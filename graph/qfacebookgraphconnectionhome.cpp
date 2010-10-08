#include <QDebug>
#include <graph/qfacebookgraphconnectionhome.h>

QFacebookGraphConnectionHome::QFacebookGraphConnectionHome(QString token, QObject *parent) :
    QFacebookGraph( token, parent )
{
    m_previous = QString::null;
    m_next = QString::null;
    m_homeModel = HomeModelList();

    // Inital connection
    update();
}

HomeModelList QFacebookGraphConnectionHome::getHomeModel() {
    return m_homeModel;
}

void QFacebookGraphConnectionHome::update(int howMany) {
    QUrl url = baseUrl("/me/home");
    url.addQueryItem("limit", QString::number(howMany));
    Get( url );
}

void QFacebookGraphConnectionHome::next(int howMany) {
    QUrl url = baseUrl("/me/home");
    url.addQueryItem("limit", QString::number(howMany));
    url.addQueryItem("until", m_next);
    Get( url );
}

void QFacebookGraphConnectionHome::previous(int howMany) {
    QUrl url = baseUrl("/me/home");
    url.addQueryItem("limit", QString::number(howMany));
    url.addQueryItem("since", m_next);
    Get( url );
}

void QFacebookGraphConnectionHome::requestDone(bool ok) {
    m_homeModel.clear();

    if (ok)
    {
        if(result().contains("data"))
            populateModel();

        if(result().contains("paging"))
        {
            QUrl url( result().value("paging").toMap().value("next").toString() );
            m_next = url.queryItemValue("until");
            url = QUrl( result().value("paging").toMap().value("previous").toString() );
            m_previous = url.queryItemValue("since");
        }
        emit modelPopulated();
    }
    else
        qDebug() << "Request failed";
}

void QFacebookGraphConnectionHome::populateModel() {
    QFacebookGraphConnectionHomeModel *homeObj = new QFacebookGraphConnectionHomeModel();

    QVariantList list = result().value("data").toList();
    QVariantList::const_iterator i;
    for (i = list.constBegin(); i != list.constEnd(); ++i)
    {
        QVariantMap::const_iterator j;
        for(j = (*i).toMap().constBegin(); j != (*i).toMap().constEnd(); ++j)
        {
            if(j.key() == "attribution")
                homeObj->setAttribution(j.value().toString());
            if(j.key() == "created_time")
                homeObj->setCreatedtime(j.value().toString());
            if(j.key() == "id")
                homeObj->setFbid(j.value().toString());
            if(j.key() == "from") {
                homeObj->setFromFbid(j.value().toMap().value("id").toString());
                homeObj->setFromName(j.value().toMap().value("name").toString());
            }
            if(j.key() == "type")
                homeObj->setType(j.value().toString());
            if(j.key() == "message")
                homeObj->setMessage(j.value().toString());
            if(j.key() == "caption")
                homeObj->setCaption(j.value().toString());
            if(j.key() == "description")
                homeObj->setDescription(j.value().toString());
            if(j.key() == "likes")
                homeObj->setLikes(j.value().toULongLong());
            if(j.key() == "updated_time")
                homeObj->setUpdatedtime(j.value().toString());
            if(j.key() == "icon")
                homeObj->setIcon(j.value().toUrl());
            if(j.key() == "picture")
                homeObj->setPicture(j.value().toUrl());
            if(j.key() == "link")
                homeObj->setLink(j.value().toUrl());
        }
        m_homeModel.append(homeObj);
        homeObj = new QFacebookGraphConnectionHomeModel();
    }
}
