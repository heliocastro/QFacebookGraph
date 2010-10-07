#ifndef QFACEBOOKGRAPHCONNECTIONFEED_H
#define QFACEBOOKGRAPHCONNECTIONFEED_H

#include <QObject>
#include <QList>

#include "qfacebookgraphconnectionfeedmodel.h"

class QFacebookGraph;

typedef QList<QObject*> FeedModelList;

class QFacebookGraphConnectionFeed : public QObject
{
    Q_OBJECT
public:
    explicit QFacebookGraphConnectionFeed(QString token = QString::null, QObject *parent = 0);

signals:

public slots:

private slots:
    void requestDone(bool ok = false);

public:
    FeedModelList getFeedModel();
    void previous(int howMany = 25 );
    void next(int howMany = 25);
    void update(int howMany = 25);

signals:
    void modelPopulated();

private:
    void populateModel();

private:
    FeedModelList m_feedModel;
    QFacebookGraph *m_graph;
    QString m_previous;
    QString m_next;
};

#endif // QFACEBOOKGRAPHCONNECTIONFEED_H
