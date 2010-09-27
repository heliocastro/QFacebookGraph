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

#ifndef QFACEBOOKGRAPHPHOTO_H
#define QFACEBOOKGRAPHPHOTO_H

#include <QObject>
#include <QDateTime>
#include <QString>
#include <QStringList>
#include <QUrl>

class QFacebookGraphPhoto : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QStringList from READ from WRITE setFrom NOTIFY fromChanged)
    Q_PROPERTY(QStringList tags READ tags WRITE setTags NOTIFY tagsChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QUrl picture READ picture WRITE setPicture NOTIFY pictureChanged)
    Q_PROPERTY(QUrl icon READ icon WRITE setIcon NOTIFY iconChanged)
    Q_PROPERTY(QUrl source READ source WRITE setSource NOTIFY sourceChanged)
    Q_PROPERTY(quint32 height READ height WRITE setHeight NOTIFY heightChanged)
    Q_PROPERTY(quint32 width READ width WRITE setWidth NOTIFY widthChanged)
    Q_PROPERTY(QUrl link READ link WRITE setLink NOTIFY linkChanged)
    Q_PROPERTY(QDateTime createdTime READ createdTime WRITE setCreatedtime NOTIFY createdTimeChanged)
    Q_PROPERTY(QDateTime updatedTime READ updatedTime WRITE setUpdatedtime NOTIFY updatedTimeChanged)
    
public:
    explicit QFacebookGraphPhoto(QObject *parent = 0);
	
    QString id() const;
    void setId(const QString &id);

    QStringList from() const;
    void setFrom(const QStringList &from);

    QStringList tags() const;
    void setTags(const QStringList &tags);

    QString name() const;
    void setName(const QString &name);

    QUrl picture() const;
    void setPicture(const QUrl &picture);

    QUrl icon() const;
    void setIcon(const QUrl &icon);

    QUrl source() const;
    void setSource(const QUrl &source);

    quint32 height() const;
    void setHeight(const quint32 &height);

    quint32 width() const;
    void setWidth(const quint32 &width);

    QUrl link() const;
    void setLink(const QUrl &link);

    QDateTime createdTime() const;
    void setCreatedtime(const QDateTime &createdTime);

    QDateTime updatedTime() const;
    void setUpdatedtime(const QDateTime &updatedTime);

signals:
    void idChanged();
    void fromChanged();
    void tagsChanged();
    void nameChanged();
    void pictureChanged();
    void iconChanged();
    void sourceChanged();
    void heightChanged();
    void widthChanged();
    void linkChanged();
    void createdTimeChanged();
    void updatedTimeChanged();

private:
    QString m_id;
    QStringList m_from;
    QStringList m_tags;
    QString m_name;
    QUrl m_picture;
    QUrl m_icon;
    QUrl m_source;
    quint32 m_height;
    quint32 m_width;
    QUrl m_link;
    QDateTime m_createdTime;
    QDateTime m_updatedTime;

};

#endif //QFACEBOOKGRAPHPHOTO_H

