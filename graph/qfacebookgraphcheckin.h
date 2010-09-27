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

#ifndef QFACEBOOKGRAPHCHECKIN_H
#define QFACEBOOKGRAPHCHECKIN_H

#include <QObject>
#include <QDateTime>
#include <QString>
#include <QStringList>

class QFacebookGraphCheckin : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QStringList from READ from WRITE setFrom NOTIFY fromChanged)
    Q_PROPERTY(QStringList tags READ tags WRITE setTags NOTIFY tagsChanged)
    Q_PROPERTY(QStringList place READ place WRITE setPlace NOTIFY placeChanged)
    Q_PROPERTY(QString message READ message WRITE setMessage NOTIFY messageChanged)
    Q_PROPERTY(QString coordinates READ coordinates WRITE setCoordinates NOTIFY coordinatesChanged)
    Q_PROPERTY(QStringList application READ application WRITE setApplication NOTIFY applicationChanged)
    Q_PROPERTY(QDateTime createdTime READ createdTime WRITE setCreatedtime NOTIFY createdTimeChanged)
    
public:
    explicit QFacebookGraphCheckin(QObject *parent = 0);
	
    QString id() const;
    void setId(const QString &id);

    QStringList from() const;
    void setFrom(const QStringList &from);

    QStringList tags() const;
    void setTags(const QStringList &tags);

    QStringList place() const;
    void setPlace(const QStringList &place);

    QString message() const;
    void setMessage(const QString &message);

    QString coordinates() const;
    void setCoordinates(const QString &coordinates);

    QStringList application() const;
    void setApplication(const QStringList &application);

    QDateTime createdTime() const;
    void setCreatedtime(const QDateTime &createdTime);

signals:
    void idChanged();
    void fromChanged();
    void tagsChanged();
    void placeChanged();
    void messageChanged();
    void coordinatesChanged();
    void applicationChanged();
    void createdTimeChanged();

private:
    QString m_id;
    QStringList m_from;
    QStringList m_tags;
    QStringList m_place;
    QString m_message;
    QString m_coordinates;
    QStringList m_application;
    QDateTime m_createdTime;

};

#endif //QFACEBOOKGRAPHCHECKIN_H

