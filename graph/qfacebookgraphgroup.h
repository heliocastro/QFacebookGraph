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

#ifndef QFACEBOOKGRAPHGROUP_H
#define QFACEBOOKGRAPHGROUP_H

#include <QObject>
#include <QDateTime>
#include <QString>
#include <QStringList>
#include <QUrl>

class QFacebookGraphGroup : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QStringList owner READ owner WRITE setOwner NOTIFY ownerChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged)
    Q_PROPERTY(QUrl link READ link WRITE setLink NOTIFY linkChanged)
    Q_PROPERTY(QStringList venue READ venue WRITE setVenue NOTIFY venueChanged)
    Q_PROPERTY(QString privacy READ privacy WRITE setPrivacy NOTIFY privacyChanged)
    Q_PROPERTY(QDateTime updatedTime READ updatedTime WRITE setUpdatedtime NOTIFY updatedTimeChanged)
    
public:
    explicit QFacebookGraphGroup(QObject *parent = 0);
	
    QString id() const;
    void setId(const QString &id);

    QStringList owner() const;
    void setOwner(const QStringList &owner);

    QString name() const;
    void setName(const QString &name);

    QString description() const;
    void setDescription(const QString &description);

    QUrl link() const;
    void setLink(const QUrl &link);

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
    void linkChanged();
    void venueChanged();
    void privacyChanged();
    void updatedTimeChanged();

private:
    QString m_id;
    QStringList m_owner;
    QString m_name;
    QString m_description;
    QUrl m_link;
    QStringList m_venue;
    QString m_privacy;
    QDateTime m_updatedTime;

};

#endif //QFACEBOOKGRAPHGROUP_H

