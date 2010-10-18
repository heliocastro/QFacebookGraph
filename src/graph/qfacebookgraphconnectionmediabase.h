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

#ifndef QFACEBOOKGRAPHCONNECTIONMEDIABASE_H
#define QFACEBOOKGRAPHCONNECTIONMEDIABASE_H

#include <QObject>
#include <QList>

#include <qfacebookgraph.h>

class QFacebookGraphCommonMediaModel;

class QFacebookGraphConnectionMediaBase : public QFacebookGraph
{
    Q_OBJECT
public:
    explicit QFacebookGraphConnectionMediaBase(QString fbid = QString::null, QObject *parent = 0);

public:
    QList<QObject*> model();
    virtual void populateModel();
    virtual void update(int howMany = 25);

    void setFbid(const QString &fbid);
    QString fbid() const;

    void append( QFacebookGraphCommonMediaModel* obj );

private:
    void requestDone(bool ok = false);

private:
    QList<QObject*> m_model;
    QString m_fbid;
};

#endif // QFacebookGraphConnectionMediaBase_H
