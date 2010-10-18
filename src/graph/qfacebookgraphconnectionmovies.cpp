#include <QDebug>
#include <graph/qfacebookgraphconnectionmovies.h>
#include <graph/qfacebookgraphcommonmediamodel.h>

QFacebookGraphConnectionMovies::QFacebookGraphConnectionMovies(QString fbid, QObject *parent) :
    QFacebookGraphConnectionMediaBase( fbid, parent )
{
    setFbid(fbid);
}


void QFacebookGraphConnectionMovies::update(int howMany) {
    addArgument("limit", QString::number(howMany));
    if (fbid().isNull())
        Get( "/me/movies" );
    else
        Get(fbid() + "/movies");
}
