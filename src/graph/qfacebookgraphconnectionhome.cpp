#include <QDebug>
#include <graph/qfacebookgraphconnectionhome.h>
#include <graph/qfacebookgraphcommonfeedmodel.h>

QFacebookGraphConnectionHome::QFacebookGraphConnectionHome(QString fbid, QObject *parent) :
    QFacebookGraphConnectionBase( fbid, parent )
{
    setFbid(fbid);
}


void QFacebookGraphConnectionHome::update(int howMany) {
    addArgument("limit", QString::number(howMany));
    if (fbid().isNull())
        Get( "/me/home" );
    else
        Get(fbid() + "/home");
}

void QFacebookGraphConnectionHome::updateNext(int howMany) {
    addArgument("limit", QString::number(howMany));
    addArgument("until", next());
    if (fbid().isNull())
        Get( "/me/home" );
    else
        Get(fbid() + "/home");
}

void QFacebookGraphConnectionHome::updatePrevious(int howMany) {
    addArgument("limit", QString::number(howMany));
    addArgument("since", previous());
    if (fbid().isNull())
        Get( "/me/home" );
    else
        Get(fbid() + "/home");
}
