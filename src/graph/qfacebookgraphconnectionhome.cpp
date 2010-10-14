#include <QDebug>
#include <graph/qfacebookgraphconnectionhome.h>

QFacebookGraphConnectionHome::QFacebookGraphConnectionHome(QString fbid, QObject *parent) :
    QFacebookGraph( parent )
{
    m_fbid = fbid;
    m_previous = QString::null;
    m_next = QString::null;
    m_homeModel = HomeModelList();
}

HomeModelList QFacebookGraphConnectionHome::getHomeModel() {
    return m_homeModel;
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
            if(j.key() == "from")
                homeObj->setFrom(j.value().toMap());
            if(j.key() == "actions" )
            {
                homeObj->setActions(j.value().toList());
                qDebug()  << j.value().toList() << endl << endl;
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
