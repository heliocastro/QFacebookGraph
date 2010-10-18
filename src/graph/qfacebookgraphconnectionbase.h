/*
 * Copyright 2010 Helio Chissini de Castro <helio@collabora.co.uk>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0

 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
*/

#ifndef QFACEBOOKGRAPHCONNECTIONBASE_H
#define QFACEBOOKGRAPHCONNECTIONBASE_H

#include <QObject>
#include <QList>

#include <qfacebookgraph.h>

class QFacebookGraphCommonFeedModel;

class QFacebookGraphConnectionBase : public QFacebookGraph
{
    Q_OBJECT
public:
    explicit QFacebookGraphConnectionBase(QString fbid = QString::null, QObject *parent = 0);

public:
    QList<QObject*> getModel();
    virtual void populateModel();
    virtual void updatePrevious(int howMany = 25 );
    virtual void updateNext(int howMany = 25);
    virtual void update(int howMany = 25);

    void setFbid(const QString &fbid);
    QString fbid() const;

    void setPrevious(const QString &previous);
    QString previous() const;

    void setNext(const QString &next);
    QString next() const;

    void append( QFacebookGraphCommonFeedModel* obj );

private:
    void requestDone(bool ok = false);

private:
    QList<QObject*> m_model;
    QString m_previous;
    QString m_next;
    QString m_fbid;
};

#endif // QFACEBOOKGRAPHCONNECTIONBASE_H
