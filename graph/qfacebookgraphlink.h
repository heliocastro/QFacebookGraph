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

#ifndef QFACEBOOKGRAPHLINK_H
#define QFACEBOOKGRAPHLINK_H

#include <QObject>
#include <QDateTime>
#include <QString>
#include <QStringList>
#include <Qurl>
#include <QUrl>

class QFacebookGraphLink : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QStringList from READ from WRITE setFrom NOTIFY fromChanged)
    Q_PROPERTY(QUrl link READ link WRITE setLink NOTIFY linkChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString caption READ caption WRITE setCaption NOTIFY captionChanged)
    Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged)
    Q_PROPERTY(QUrl icon READ icon WRITE setIcon NOTIFY iconChanged)
    Q_PROPERTY(Qurl picture READ picture WRITE setPicture NOTIFY pictureChanged)
    Q_PROPERTY(QString message READ message WRITE setMessage NOTIFY messageChanged)
    Q_PROPERTY(QDateTime created_time READ created_time WRITE setCreated_time NOTIFY created_timeChanged)
    
public:
    explicit QFacebookGraphLink(QObject *parent = 0);
	
    QString id() const;
    void setId(const QString &id);

    QStringList from() const;
    void setFrom(const QStringList &from);

    QUrl link() const;
    void setLink(const QUrl &link);

    QString name() const;
    void setName(const QString &name);

    QString caption() const;
    void setCaption(const QString &caption);

    QString description() const;
    void setDescription(const QString &description);

    QUrl icon() const;
    void setIcon(const QUrl &icon);

    Qurl picture() const;
    void setPicture(const Qurl &picture);

    QString message() const;
    void setMessage(const QString &message);

    QDateTime created_time() const;
    void setCreated_time(const QDateTime &created_time);

signals:
    void idChanged();
    void fromChanged();
    void linkChanged();
    void nameChanged();
    void captionChanged();
    void descriptionChanged();
    void iconChanged();
    void pictureChanged();
    void messageChanged();
    void created_timeChanged();

private:
    QString m_id;
    QStringList m_from;
    QUrl m_link;
    QString m_name;
    QString m_caption;
    QString m_description;
    QUrl m_icon;
    Qurl m_picture;
    QString m_message;
    QDateTime m_created_time;

};

#endif //QFACEBOOKGRAPHLINK_H

