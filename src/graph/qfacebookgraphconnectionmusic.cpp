#include <QDebug>
#include <graph/qfacebookgraphconnectionmusic.h>
#include <graph/qfacebookgraphcommonmediamodel.h>

QFacebookGraphConnectionMusic::QFacebookGraphConnectionMusic(QString fbid, QObject *parent) :
    QFacebookGraphConnectionMediaBase( fbid, parent )
{
    setFbid(fbid);
}


void QFacebookGraphConnectionMusic::update(int howMany) {
    addArgument("limit", QString::number(howMany));
    if (fbid().isNull())
        Get( "/me/music" );
    else
        Get(fbid() + "/music");
}
