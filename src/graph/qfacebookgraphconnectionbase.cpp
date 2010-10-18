#include <QDebug>
#include <graph/qfacebookgraphconnectionbase.h>
#include <graph/qfacebookgraphcommonfeedmodel.h>

QFacebookGraphConnectionBase::QFacebookGraphConnectionBase(QString fbid, QObject *parent) :
    QFacebookGraph( parent )
{
    m_fbid = fbid;
    m_previous = QString::null;
    m_next = QString::null;
    m_model = QList<QObject*>();
}

QList<QObject*> QFacebookGraphConnectionBase::model() {
    return m_model;
}

void QFacebookGraphConnectionBase::update(int howMany) {
    Q_UNUSED(howMany)
}

void QFacebookGraphConnectionBase::updateNext(int howMany) {
    Q_UNUSED(howMany)
}

void QFacebookGraphConnectionBase::updatePrevious(int howMany) {
    Q_UNUSED(howMany)
}

void QFacebookGraphConnectionBase::requestDone(bool ok) {
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

void QFacebookGraphConnectionBase::populateModel() {
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
                obj->setCreatedTime( QDateTime::fromString( j.value().toString(),
                                                           "yyyy-MM-dd'T'hh:mm:ss+0000") );
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
                obj->setCreatedTime( QDateTime::fromString( j.value().toString(),
                                                           "yyyy-MM-dd'T'hh:mm:ss+0000") );
            if(j.key() == "icon")
                obj->setIcon(j.value().toUrl());
            if(j.key() == "picture")
                obj->setPicture(j.value().toUrl());
            if(j.key() == "privacy")
                obj->setPrivacy(j.value().toMap());
            if(j.key() == "link")
                obj->setLink(j.value().toUrl());
        }
        append(obj);
        obj = new QFacebookGraphCommonFeedModel();
    }
}


void QFacebookGraphConnectionBase::setFbid(const QString &fbid) {
    if(m_fbid != fbid)
        m_fbid = fbid;
}
QString QFacebookGraphConnectionBase::fbid() const {
    return m_fbid;
}


void QFacebookGraphConnectionBase::setPrevious(const QString &previous) {
    if(m_previous != previous)
        m_previous = previous;
}
QString QFacebookGraphConnectionBase::previous() const {
    return m_previous;
}

void QFacebookGraphConnectionBase::setNext(const QString &next) {
    if(m_next != next)
        m_next = next;
}
QString QFacebookGraphConnectionBase::next() const {
    return m_next;
}

void QFacebookGraphConnectionBase::append(QFacebookGraphCommonFeedModel *obj) {
    m_model.append(obj);
}
