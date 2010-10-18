#include <QDebug>
#include <graph/qfacebookgraphconnectionbooks.h>
#include <graph/qfacebookgraphcommonmediamodel.h>

QFacebookGraphConnectionBooks::QFacebookGraphConnectionBooks(QString fbid, QObject *parent) :
    QFacebookGraphConnectionMediaBase( fbid, parent )
{
    setFbid(fbid);
}


void QFacebookGraphConnectionBooks::update(int howMany) {
    addArgument("limit", QString::number(howMany));
    if (fbid().isNull())
        Get( "/me/books" );
    else
        Get(fbid() + "/books");
}
