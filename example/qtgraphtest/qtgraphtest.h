#ifndef QTGRAPHTEST_H
#define QTGRAPHTEST_H

#include <QObject>
#include <QVariant>
#include <QDeclarativeView>
#include <QDeclarativeContext>

#include <graph/qfacebookgraphuser.h>
#include <graph/qfacebookgraphconnectionhome.h>

class QSettings;
class QFacebookGraph;

class QtGraphTest : public QObject
{
    Q_OBJECT
public:
    explicit QtGraphTest(QDeclarativeView *view, QObject *parent = 0);

signals:

public slots:
    void testUrl( const QString value );
    bool hasValidToken();
    void updateHomeView();
    void updateUserView();

private:
    QDeclarativeContext *ctxt;
    QFacebookGraphConnectionHome *home;
    QFacebookGraphUser *user;
    QSettings *settings;
    QList<QObject*> homeList;
};

#endif // QTGRAPHTEST_H
