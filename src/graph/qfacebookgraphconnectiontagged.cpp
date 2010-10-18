#include <QDebug>
#include <graph/qfacebookgraphconnectiontagged.h>
#include <graph/qfacebookgraphcommonfeedmodel.h>

QFacebookGraphConnectionTagged::QFacebookGraphConnectionTagged(QString fbid, QObject *parent) :
    QFacebookGraphConnectionBase(fbid,parent)
{
    setFbid(fbid);
}

void QFacebookGraphConnectionTagged::update(int howMany) {
    addArgument("limit", QString::number(howMany));
    if (fbid().isNull())
        Get( "/me/tagged" );
    else
        Get(fbid() + "/tagged");
}

void QFacebookGraphConnectionTagged::updateNext(int howMany) {
    addArgument("limit", QString::number(howMany));
    addArgument("until", next());
    if (fbid().isNull())
        Get( "/me/tagged" );
    else
        Get(fbid() + "/tagged");
}

void QFacebookGraphConnectionTagged::updatePrevious(int howMany) {
    addArgument("limit", QString::number(howMany));
    addArgument("since", previous());
    if (fbid().isNull())
        Get( "/me/tagged" );
    else
        Get(fbid() + "/tagged");
}
