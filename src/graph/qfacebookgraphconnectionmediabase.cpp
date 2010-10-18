#include <QDebug>
#include <graph/qfacebookgraphconnectionmediabase.h>
#include <graph/qfacebookgraphcommonmediamodel.h>

QFacebookGraphConnectionMediaBase::QFacebookGraphConnectionMediaBase(QString fbid, QObject *parent) :
    QFacebookGraph( parent )
{
    m_fbid = fbid;
    m_model = QList<QObject*>();
}

QList<QObject*> QFacebookGraphConnectionMediaBase::model() {
    return m_model;
}

void QFacebookGraphConnectionMediaBase::update(int howMany) {
    Q_UNUSED(howMany)
}

void QFacebookGraphConnectionMediaBase::requestDone(bool ok) {
    m_model.clear();

    if (ok)
    {
        if(result().contains("data"))
            populateModel();
        emit modelPopulated();
    }
    else
        qDebug() << "Request failed";
}

void QFacebookGraphConnectionMediaBase::populateModel() {
    QFacebookGraphCommonMediaModel *obj = new QFacebookGraphCommonMediaModel();

    QVariantList list = result().value("data").toList();
    QVariantList::const_iterator i;
    for (i = list.constBegin(); i != list.constEnd(); ++i)
    {
        QVariantMap::const_iterator j;
        for(j = (*i).toMap().constBegin(); j != (*i).toMap().constEnd(); ++j)
        {
            if(j.key() == "name")
                obj->setName(j.value().toString());
            if(j.key() == "created_time")
                obj->setCreatedTime( QDateTime::fromString( j.value().toString(),
                                                           "yyyy-MM-dd'T'hh:mm:ss+0000") );
            if(j.key() == "id")
                obj->setFbid(j.value().toString());
            if(j.key() == "category")
                obj->setCategory(j.value().toString());
        }
        append(obj);
        obj = new QFacebookGraphCommonMediaModel();
    }
}


void QFacebookGraphConnectionMediaBase::setFbid(const QString &fbid) {
    if(m_fbid != fbid)
        m_fbid = fbid;
}
QString QFacebookGraphConnectionMediaBase::fbid() const {
    return m_fbid;
}


void QFacebookGraphConnectionMediaBase::append(QFacebookGraphCommonMediaModel *obj) {
    m_model.append(obj);
}
