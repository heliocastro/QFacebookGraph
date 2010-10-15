#include <QDebug>
#include <graph/qfacebookgraphconnectionhome.h>
#include <graph/qfacebookgraphcommonfeedmodel.h>

QFacebookGraphConnectionHome::QFacebookGraphConnectionHome(QString fbid, QObject *parent) :
    QFacebookGraph( parent )
{
    m_fbid = fbid;
    m_previous = QString::null;
    m_next = QString::null;
    m_model = QList<QObject*>();
}

QList<QObject*> QFacebookGraphConnectionHome::getModel() {
    return m_model;
}

void QFacebookGraphConnectionHome::update(int howMany) {
    addArgument("limit", QString::number(howMany));
    if (m_fbid.isNull())
        Get( "/me/home" );
    else
        Get(m_fbid + "/home");
}

void QFacebookGraphConnectionHome::next(int howMany) {
    addArgument("limit", QString::number(howMany));
    addArgument("until", m_next);
    if (m_fbid.isNull())
        Get( "/me/home" );
    else
        Get(m_fbid + "/home");
}

void QFacebookGraphConnectionHome::previous(int howMany) {
    addArgument("limit", QString::number(howMany));
    addArgument("since", m_next);
    if (m_fbid.isNull())
        Get( "/me/home" );
    else
        Get(m_fbid + "/home");
}

void QFacebookGraphConnectionHome::requestDone(bool ok) {
    m_model.clear();

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
    QFacebookGraphCommonFeedModel *obj = new QFacebookGraphCommonFeedModel();

    QVariantList list = result().value("data").toList();
    QVariantList::const_iterator i;
    for (i = list.constBegin(); i != list.constEnd(); ++i)
    {
        QVariantMap::const_iterator j;
        for(j = (*i).toMap().constBegin(); j != (*i).toMap().constEnd(); ++j)
        {
            if(j.key() == "attribution")
                obj->setAttribution(j.value().toString());
            if(j.key() == "created_time")
                obj->setCreatedtime(j.value().toString());
            if(j.key() == "id")
                obj->setFbid(j.value().toString());
            if(j.key() == "from")
                obj->setFrom(j.value().toMap());
            if(j.key() == "actions")
                obj->setActions(j.value().toList());
            if(j.key() == "comments")
                obj->setComments(j.value().toMap()["data"].toList());
            if(j.key() == "type")
                obj->setType(j.value().toString());
            if(j.key() == "message")
                obj->setMessage(j.value().toString());
            if(j.key() == "caption")
                obj->setCaption(j.value().toString());
            if(j.key() == "description")
                obj->setDescription(j.value().toString());
            if(j.key() == "likes")
                obj->setLikes(j.value().toULongLong());
            if(j.key() == "updated_time")
                obj->setUpdatedtime(j.value().toString());
            if(j.key() == "icon")
                obj->setIcon(j.value().toUrl());
            if(j.key() == "picture")
                obj->setPicture(j.value().toUrl());
            if(j.key() == "link")
                obj->setLink(j.value().toUrl());
        }
        m_model.append(obj);
        obj = new QFacebookGraphCommonFeedModel();
    }
}
