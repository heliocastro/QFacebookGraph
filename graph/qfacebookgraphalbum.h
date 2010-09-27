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

#ifndef QFACEBOOKGRAPHALBUM_H
#define QFACEBOOKGRAPHALBUM_H

#include <QObject>
#include <QDateTime>
#include <QObject>
#include <QString>
#include <QHash>
#include <QUrl>

typedef QHash<QString,QString> QHashFrom;

class QFacebookGraphAlbum : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QHashFrom from READ from WRITE setFrom NOTIFY fromChanged)
    Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged)
    Q_PROPERTY(QString location READ location WRITE setLocation NOTIFY locationChanged)
    Q_PROPERTY(QUrl link READ link WRITE setLink NOTIFY linkChanged)
    Q_PROPERTY(QString privacy READ privacy WRITE setPrivacy NOTIFY privacyChanged)
    Q_PROPERTY(quint32 count READ count WRITE setCount NOTIFY countChanged)
    Q_PROPERTY(QDateTime createdTime READ createdTime WRITE setCreatedtime NOTIFY createdTimeChanged)
    Q_PROPERTY(QDateTime updatedTime READ updatedTime WRITE setUpdatedtime NOTIFY updatedTimeChanged)
    Q_PROPERTY(quint32 comments READ comments WRITE setComments NOTIFY commentsChanged)
    
public:
    explicit QFacebookGraphAlbum(QObject *parent = 0);
	
    QString id() const;
    void setId(const QString &id);

    QHashFrom from() const;
    void setFrom(const QHashFrom &from);

    QString description() const;
    void setDescription(const QString &description);

    QString location() const;
    void setLocation(const QString &location);

    QUrl link() const;
    void setLink(const QUrl &link);

    QString privacy() const;
    void setPrivacy(const QString &privacy);

    quint32 count() const;
    void setCount(const quint32 &count);

    QDateTime createdTime() const;
    void setCreatedtime(const QDateTime &createdTime);

    QDateTime updatedTime() const;
    void setUpdatedtime(const QDateTime &updatedTime);

    quint32 comments() const;
    void setComments(const quint32 &comments);

signals:
    void idChanged();
    void fromChanged();
    void descriptionChanged();
    void locationChanged();
    void linkChanged();
    void privacyChanged();
    void countChanged();
    void createdTimeChanged();
    void updatedTimeChanged();
    void commentsChanged();

private:
    QString m_id;
    QHashFrom m_from;
    QString m_description;
    QString m_location;
    QUrl m_link;
    QString m_privacy;
    quint32 m_count;
    QDateTime m_createdTime;
    QDateTime m_updatedTime;
    quint32 m_comments;

};

#endif //QFACEBOOKGRAPHALBUM_H

