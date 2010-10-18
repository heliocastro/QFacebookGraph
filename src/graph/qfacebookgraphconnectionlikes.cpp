#include <QDebug>
#include <graph/qfacebookgraphconnectionlikes.h>
#include <graph/qfacebookgraphcommonmediamodel.h>

QFacebookGraphConnectionLikes::QFacebookGraphConnectionLikes(QString fbid, QObject *parent) :
    QFacebookGraphConnectionMediaBase( fbid, parent )
{
    setFbid(fbid);
}


void QFacebookGraphConnectionLikes::update(int howMany) {
    addArgument("limit", QString::number(howMany));
    if (fbid().isNull())
        Get( "/me/likes" );
    else
        Get(fbid() + "/likes");
}
