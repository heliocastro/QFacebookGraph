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

#ifndef QFACEBOOKGRAPHEVENT_H
#define QFACEBOOKGRAPHEVENT_H

#include <QObject>
#include <QDateTime>
#include <QString>
#include <QStringList>

class QFacebookGraphEvent : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QStringList owner READ owner WRITE setOwner NOTIFY ownerChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged)
    Q_PROPERTY(QDateTime startTime READ startTime WRITE setStarttime NOTIFY startTimeChanged)
    Q_PROPERTY(QDateTime endTime READ endTime WRITE setEndtime NOTIFY endTimeChanged)
    Q_PROPERTY(QString location READ location WRITE setLocation NOTIFY locationChanged)
    Q_PROPERTY(QStringList venue READ venue WRITE setVenue NOTIFY venueChanged)
    Q_PROPERTY(QString privacy READ privacy WRITE setPrivacy NOTIFY privacyChanged)
    Q_PROPERTY(QDateTime updatedTime READ updatedTime WRITE setUpdatedtime NOTIFY updatedTimeChanged)
    
public:
    explicit QFacebookGraphEvent(QObject *parent = 0);
	
    QString id() const;
    void setId(const QString &id);

    QStringList owner() const;
    void setOwner(const QStringList &owner);

    QString name() const;
    void setName(const QString &name);

    QString description() const;
    void setDescription(const QString &description);

    QDateTime startTime() const;
    void setStarttime(const QDateTime &startTime);

    QDateTime endTime() const;
    void setEndtime(const QDateTime &endTime);

    QString location() const;
    void setLocation(const QString &location);

    QStringList venue() const;
    void setVenue(const QStringList &venue);

    QString privacy() const;
    void setPrivacy(const QString &privacy);

    QDateTime updatedTime() const;
    void setUpdatedtime(const QDateTime &updatedTime);

signals:
    void idChanged();
    void ownerChanged();
    void nameChanged();
    void descriptionChanged();
    void startTimeChanged();
    void endTimeChanged();
    void locationChanged();
    void venueChanged();
    void privacyChanged();
    void updatedTimeChanged();

private:
    QString m_id;
    QStringList m_owner;
    QString m_name;
    QString m_description;
    QDateTime m_startTime;
    QDateTime m_endTime;
    QString m_location;
    QStringList m_venue;
    QString m_privacy;
    QDateTime m_updatedTime;

};

#endif //QFACEBOOKGRAPHEVENT_H

