#include <QDebug>
#include <graph/qfacebookgraphconnectionposts.h>

QFacebookGraphConnectionPosts::QFacebookGraphConnectionPosts(QString fbid, QObject *parent) :
    QFacebookGraphConnectionBase( fbid, parent )
{
    setFbid(fbid);
}


void QFacebookGraphConnectionPosts::update(int howMany) {
    addArgument("limit", QString::number(howMany));
    if (fbid().isNull())
        Get( "/me/posts" );
    else
        Get(fbid() + "/posts");
}

void QFacebookGraphConnectionPosts::updateNext(int howMany) {
    addArgument("limit", QString::number(howMany));
    addArgument("until", next());
    if (fbid().isNull())
        Get( "/me/posts" );
    else
        Get(fbid() + "/posts");
}

void QFacebookGraphConnectionPosts::updatePrevious(int howMany) {
    addArgument("limit", QString::number(howMany));
    addArgument("since", previous());
    if (fbid().isNull())
        Get( "/me/posts" );
    else
        Get(fbid() + "/posts");
}
