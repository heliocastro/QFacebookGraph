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

#ifndef QFACEBOOKGRAPHUSER_H
#define QFACEBOOKGRAPHUSER_H

#include <QObject>
#include <QString>
#include <QVariant>

#include <qfacebookgraph.h>

class QFacebookGraphUser : public QObject
{
    Q_OBJECT
    
public:
    explicit QFacebookGraphUser(QString token = QString::null, const QString &user = QString::null, QObject *parent = 0);

public:
    QVariant getUserModel() const;
    void update();

private slots:
    void requestDone(bool ok = false);

protected:
    QFacebookGraph *m_graph;
    QVariant m_userModel;
    QString m_user;
};

#endif //QFACEBOOKGRAPHUSER_H

