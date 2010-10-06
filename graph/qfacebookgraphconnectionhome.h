#ifndef QFACEBOOKGRAPHCONNECTIONHOME_H
#define QFACEBOOKGRAPHCONNECTIONHOME_H

#include <QObject>
#include <QVariant>

#include "qfacebookgraphconnectionhomemodel.h"

class QFacebookGraph;

class QFacebookGraphConnectionHome : public QObject
{
    Q_OBJECT
public:
    explicit QFacebookGraphConnectionHome(QFacebookGraph *graph, QObject *parent = 0);

signals:

public slots:

private slots:
    void requestDone(bool ok = false);

public:
    QVariant getHomeModel();
    void previous(int howMany = 25 );
    void next(int howMany = 25);
    void update(int howMany = 25);

private:
    QVariant m_homeModel;
    QFacebookGraph *m_graph;
    QString m_previous;
    QString m_next;
};

#endif // QFACEBOOKGRAPHCONNECTIONHOME_H
