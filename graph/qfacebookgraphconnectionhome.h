#ifndef QFACEBOOKGRAPHCONNECTIONHOME_H
#define QFACEBOOKGRAPHCONNECTIONHOME_H

#include <QObject>
#include <QList>

#include "qfacebookgraphconnectionhomemodel.h"

class QFacebookGraph;

typedef QList<QObject*> HomeModelList;

class QFacebookGraphConnectionHome : public QObject
{
    Q_OBJECT
public:
    explicit QFacebookGraphConnectionHome(QString token = QString::null, QObject *parent = 0);

signals:

public slots:

private slots:
    void requestDone(bool ok = false);

public:
    HomeModelList getHomeModel();
    void previous(int howMany = 25 );
    void next(int howMany = 25);
    void update(int howMany = 25);

signals:
    void modelPopulated();

private:
    void populateModel();

private:
    HomeModelList m_homeModel;
    QFacebookGraph *m_graph;
    QString m_previous;
    QString m_next;
};

#endif // QFACEBOOKGRAPHCONNECTIONHOME_H
