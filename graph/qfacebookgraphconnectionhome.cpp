#include <QDebug>

#include <qfacebookgraph.h>
#include <graph/qfacebookgraphconnectionhome.h>
#include <graph/qfacebookgraphconnectionhomemodel.h>

QFacebookGraphConnectionHome::QFacebookGraphConnectionHome(QString token, QObject *parent) :
    QObject(parent)
{
    m_graph = new QFacebookGraph(token);
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
    QUrl url = m_graph->baseUrl();
    url.setEncodedPath("/me/home");
    url.addQueryItem("limit", QString::number(howMany));
    m_graph->Get( url );
    connect( m_graph, SIGNAL(requestDone( bool )), this, SLOT( requestDone( bool ) ) );
}

void QFacebookGraphConnectionHome::next(int howMany) {
    QUrl url = m_graph->baseUrl();
    url.setEncodedPath("/me/home");
    url.addQueryItem("limit", QString::number(howMany));
    url.addQueryItem("until", m_next);
    m_graph->Get( url );
    connect( m_graph, SIGNAL(requestDone( bool )), this, SLOT( requestDone( bool ) ) );
}

void QFacebookGraphConnectionHome::previous(int howMany) {
    QUrl url = m_graph->baseUrl();
    url.setEncodedPath("/me/home");
    url.addQueryItem("limit", QString::number(howMany));
    url.addQueryItem("since", m_next);
    m_graph->Get( url );
    connect( m_graph, SIGNAL(requestDone( bool )), this, SLOT( requestDone( bool ) ) );
}

void QFacebookGraphConnectionHome::requestDone(bool ok) {
    m_homeModel.clear();

    if (ok)
    {
        if(m_graph->result().contains("data"))
        {
            populateModel();
        }

        if(m_graph->result().contains("paging"))
        {
            QUrl url( m_graph->result().value("paging").toMap().value("next").toString() );
            m_next = url.queryItemValue("until");
            url = QUrl( m_graph->result().value("paging").toMap().value("previous").toString() );
            m_previous = url.queryItemValue("since");

            //qDebug() << "NEXT: " << m_next << "   PREVIOUS: " << m_previous;
        }
        emit modelPopulated();
    }
    else
        qDebug() << "Request failed";

    // We don't need the connection anymore
    disconnect(this,SLOT( requestDone( bool )));
}

void QFacebookGraphConnectionHome::populateModel() {
    QFacebookGraphConnectionHomeModel *homeObj = new QFacebookGraphConnectionHomeModel();

    QVariantList list = m_graph->result().value("data").toList();
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

        //qDebug() << "Id: " << homeObj->fbid();
        m_homeModel.append(homeObj);
        homeObj = new QFacebookGraphConnectionHomeModel();
    }
    qDebug() << endl;

}
