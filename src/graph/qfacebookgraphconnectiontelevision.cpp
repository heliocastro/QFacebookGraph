#include <QDebug>
#include <graph/qfacebookgraphconnectiontelevision.h>
#include <graph/qfacebookgraphcommonmediamodel.h>

QFacebookGraphConnectionTelevision::QFacebookGraphConnectionTelevision(QString fbid, QObject *parent) :
    QFacebookGraphConnectionMediaBase( fbid, parent )
{
    setFbid(fbid);
}


void QFacebookGraphConnectionTelevision::update(int howMany) {
    addArgument("limit", QString::number(howMany));
    if (fbid().isNull())
        Get( "/me/television" );
    else
        Get(fbid() + "/television");
}
