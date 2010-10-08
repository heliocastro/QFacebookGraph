#ifndef QFACEBOOKGRAPHCONNECTIONFEED_H
#define QFACEBOOKGRAPHCONNECTIONFEED_H

#include <QObject>
#include <QList>

#include <qfacebookgraph.h>
#include <graph/qfacebookgraphconnectionfeedmodel.h>

typedef QList<QObject*> FeedModelList;

class QFacebookGraphConnectionFeed : public QFacebookGraph
{
    Q_OBJECT
public:
    explicit QFacebookGraphConnectionFeed(QObject *parent = 0);

public:
    FeedModelList getFeedModel();
    void init(int howMany = 25);
    void previous(int howMany = 25 );
    void next(int howMany = 25);


private:
    void populateModel();
    void requestDone(bool ok = false);

private:
    FeedModelList m_feedModel;
    QFacebookGraph *m_graph;
    QString m_previous;
    QString m_next;
};

#endif // QFACEBOOKGRAPHCONNECTIONFEED_H
