#include <QDebug>
#include <graph/qfacebookgraphconnectionfriends.h>

QFacebookGraphConnectionFriends::QFacebookGraphConnectionFriends(QString fbid, QObject *parent) :
    QFacebookGraph( parent )
{
    m_fbid = fbid;
    m_friends = QVariantList();
}

void QFacebookGraphConnectionFriends::update() {
    if (fbid().isNull())
        Get( "/me/friends" );
    else
        Get(fbid() + "/friends");
}

void QFacebookGraphConnectionFriends::requestDone(bool ok) {
    if (ok) {
        m_friends = result().value("data").toList();
        emit modelPopulated();
    }
    else
        qDebug() << "Request failed";
}

QString QFacebookGraphConnectionFriends::fbid() const {
    return m_fbid;
}
void QFacebookGraphConnectionFriends::setFbid(const QString &fbid) {
    if(m_fbid != fbid) {
        m_fbid = fbid;
        emit fbidChanged();
    }
}

QVariantList QFacebookGraphConnectionFriends::friends() const {
    return m_friends;
}
void QFacebookGraphConnectionFriends::setFriends(const QVariantList &friends) {
    if(m_friends != friends) {
        m_friends = friends;
        emit friendsChanged();
    }
}
