#include <QDebug>
#include <graph/qfacebookgraphconnectioninterests.h>
#include <graph/qfacebookgraphcommonmediamodel.h>

QFacebookGraphConnectionInterests::QFacebookGraphConnectionInterests(QString fbid, QObject *parent) :
    QFacebookGraphConnectionMediaBase( fbid, parent )
{
    setFbid(fbid);
}


void QFacebookGraphConnectionInterests::update(int howMany) {
    addArgument("limit", QString::number(howMany));
    if (fbid().isNull())
        Get( "/me/interests" );
    else
        Get(fbid() + "/interests");
}
