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

#ifndef QFACEBOOKGRAPHPAGE_H
#define QFACEBOOKGRAPHPAGE_H

#include <QObject>
#include <QString>
#include <quint64>
#include <QUrl>

class QFacebookGraphPage : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QUrl picture READ picture WRITE setPicture NOTIFY pictureChanged)
    Q_PROPERTY(QString category READ category WRITE setCategory NOTIFY categoryChanged)
    Q_PROPERTY(quint64 fan_count READ fan_count WRITE setFan_count NOTIFY fan_countChanged)
    
public:
    explicit QFacebookGraphPage(QObject *parent = 0);
	
    QString id() const;
    void setId(const QString &id);

    QString name() const;
    void setName(const QString &name);

    QUrl picture() const;
    void setPicture(const QUrl &picture);

    QString category() const;
    void setCategory(const QString &category);

    quint64 fan_count() const;
    void setFan_count(const quint64 &fan_count);

signals:
    void idChanged();
    void nameChanged();
    void pictureChanged();
    void categoryChanged();
    void fan_countChanged();

private:
    QString m_id;
    QString m_name;
    QUrl m_picture;
    QString m_category;
    quint64 m_fan_count;

};

#endif //QFACEBOOKGRAPHPAGE_H

