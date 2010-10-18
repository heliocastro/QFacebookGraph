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

#ifndef QFACEBOOKGRAPHCONNECTIONPICTURE_H
#define QFACEBOOKGRAPHCONNECTIONPICTURE_H

#include <QObject>

#include <qfacebookgraph.h>

class QFacebookGraphConnectionPicture : public QFacebookGraph
{
    Q_OBJECT

    Q_PROPERTY(QString fbid READ fbid WRITE setFbid NOTIFY fbidChanged)
    Q_PROPERTY(QUrl picture READ picture WRITE setPicture NOTIFY pictureChanged)
public:
    explicit QFacebookGraphConnectionPicture(QString fbid = QString::null, QObject *parent = 0);

public:
    virtual void update();

    void setFbid(const QString &fbid);
    QString fbid() const;

    void setPicture(const QUrl &picture);
    QUrl picture() const;

signals:
    void fbidChanged();
    void pictureChanged();

private:
    void requestDone(bool ok = false);

private:
    QString m_fbid;
    QUrl m_picture;
};

#endif // QFACEBOOKGRAPHCONNECTIONBASE_H
