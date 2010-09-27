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

#ifndef QFACEBOOKGRAPHPOST_H
#define QFACEBOOKGRAPHPOST_H

#include <QObject>
#include <QDateTime>
#include <QHash+QString,QUrl->
#include <QList+QStringList->
#include <QString>
#include <QStringList>
#include <quint64>
#include <QUrl>

class QFacebookGraphPost : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QStringList from READ from WRITE setFrom NOTIFY fromChanged)
    Q_PROPERTY(QList+QStringList- to READ to WRITE setTo NOTIFY toChanged)
    Q_PROPERTY(QString message READ message WRITE setMessage NOTIFY messageChanged)
    Q_PROPERTY(QUrl picture READ picture WRITE setPicture NOTIFY pictureChanged)
    Q_PROPERTY(QUrl link READ link WRITE setLink NOTIFY linkChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString caption READ caption WRITE setCaption NOTIFY captionChanged)
    Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged)
    Q_PROPERTY(QUrl source READ source WRITE setSource NOTIFY sourceChanged)
    Q_PROPERTY(QUrl icon READ icon WRITE setIcon NOTIFY iconChanged)
    Q_PROPERTY(QString attribution READ attribution WRITE setAttribution NOTIFY attributionChanged)
    Q_PROPERTY(QHash+QString,QUrl- actions READ actions WRITE setActions NOTIFY actionsChanged)
    Q_PROPERTY(quint64 likes READ likes WRITE setLikes NOTIFY likesChanged)
    Q_PROPERTY(QDateTime created_time READ created_time WRITE setCreated_time NOTIFY created_timeChanged)
    Q_PROPERTY(QDateTime updated_time READ updated_time WRITE setUpdated_time NOTIFY updated_timeChanged)
    
public:
    explicit QFacebookGraphPost(QObject *parent = 0);
	
    QString id() const;
    void setId(const QString &id);

    QStringList from() const;
    void setFrom(const QStringList &from);

    QList+QStringList- to() const;
    void setTo(const QList+QStringList- &to);

    QString message() const;
    void setMessage(const QString &message);

    QUrl picture() const;
    void setPicture(const QUrl &picture);

    QUrl link() const;
    void setLink(const QUrl &link);

    QString name() const;
    void setName(const QString &name);

    QString caption() const;
    void setCaption(const QString &caption);

    QString description() const;
    void setDescription(const QString &description);

    QUrl source() const;
    void setSource(const QUrl &source);

    QUrl icon() const;
    void setIcon(const QUrl &icon);

    QString attribution() const;
    void setAttribution(const QString &attribution);

    QHash+QString,QUrl- actions() const;
    void setActions(const QHash+QString,QUrl- &actions);

    quint64 likes() const;
    void setLikes(const quint64 &likes);

    QDateTime created_time() const;
    void setCreated_time(const QDateTime &created_time);

    QDateTime updated_time() const;
    void setUpdated_time(const QDateTime &updated_time);

signals:
    void idChanged();
    void fromChanged();
    void toChanged();
    void messageChanged();
    void pictureChanged();
    void linkChanged();
    void nameChanged();
    void captionChanged();
    void descriptionChanged();
    void sourceChanged();
    void iconChanged();
    void attributionChanged();
    void actionsChanged();
    void likesChanged();
    void created_timeChanged();
    void updated_timeChanged();

private:
    QString m_id;
    QStringList m_from;
    QList+QStringList- m_to;
    QString m_message;
    QUrl m_picture;
    QUrl m_link;
    QString m_name;
    QString m_caption;
    QString m_description;
    QUrl m_source;
    QUrl m_icon;
    QString m_attribution;
    QHash+QString,QUrl- m_actions;
    quint64 m_likes;
    QDateTime m_created_time;
    QDateTime m_updated_time;

};

#endif //QFACEBOOKGRAPHPOST_H

