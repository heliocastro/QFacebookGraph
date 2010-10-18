#include <QDebug>
#include <graph/qfacebookgraphconnectionpicture.h>

QFacebookGraphConnectionPicture::QFacebookGraphConnectionPicture(QString fbid, QObject *parent) :
    QFacebookGraph( parent )
{
    m_fbid = fbid;
    m_picture = QUrl();
}

void QFacebookGraphConnectionPicture::update() {
    if (fbid().isNull())
        Get( "/me/picture" );
    else
        Get(fbid() + "/picture");
}

void QFacebookGraphConnectionPicture::requestDone(bool ok) {
    if (ok) {
        m_picture = result().value("url_redirect").toUrl();
        emit modelPopulated();
    }
    else
        qDebug() << "Request failed";
}

QString QFacebookGraphConnectionPicture::fbid() const {
    return m_fbid;
}
void QFacebookGraphConnectionPicture::setFbid(const QString &fbid) {
    if(m_fbid != fbid) {
        m_fbid = fbid;
        emit fbidChanged();
    }
}

QUrl QFacebookGraphConnectionPicture::picture() const {
    return m_picture;
}
void QFacebookGraphConnectionPicture::setPicture(const QUrl &picture) {
    if(m_picture != picture) {
        m_picture = picture;
        emit pictureChanged();
    }
}
