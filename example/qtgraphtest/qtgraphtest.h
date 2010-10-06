#ifndef QTGRAPHTEST_H
#define QTGRAPHTEST_H

#include <QObject>

class QFacebookGraph;

class QtGraphTest : public QObject
{
    Q_OBJECT
public:
    explicit QtGraphTest(QObject *parent = 0);

signals:

public slots:
    void testUrl( const QString value );
    void requestDone( bool ok=false );

protected:
    QFacebookGraph *graph;

};

#endif // QTGRAPHTEST_H
