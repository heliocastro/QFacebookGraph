#ifndef QFACEBOOKGRAPHCONNECTIONHOME_H
#define QFACEBOOKGRAPHCONNECTIONHOME_H

#include <QObject>
#include <QList>

#include <qfacebookgraph.h>
#include <graph/qfacebookgraphconnectionhomemodel.h>

typedef QList<QObject*> HomeModelList;

class QFacebookGraphConnectionHome : public QFacebookGraph
{
    Q_OBJECT
public:
    explicit QFacebookGraphConnectionHome(QObject *parent = 0);

public:
    HomeModelList getHomeModel();
    void previous(int howMany = 25 );
    void next(int howMany = 25);
    void init(int howMany = 25);

private:
    void populateModel();
    void requestDone(bool ok = false);

private:
    HomeModelList m_homeModel;
    QString m_previous;
    QString m_next;
};

#endif // QFACEBOOKGRAPHCONNECTIONHOME_H
