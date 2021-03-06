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

#ifndef QFACEBOOKGRAPHCOMMONFEEDMODEL_H
#define QFACEBOOKGRAPHCOMMONFEEDMODEL_H

#include <QObject>
#include <QDateTime>
#include <QString>
#include <QStringList>
#include <QUrl>
#include <QVariantMap>

class QFacebookGraphCommonFeedModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString fbid READ fbid WRITE setFbid NOTIFY fbidChanged)
    Q_PROPERTY(QVariantMap from READ from WRITE setFrom NOTIFY fromChanged)
    Q_PROPERTY(QVariantList to READ to WRITE setTo NOTIFY toChanged)
    Q_PROPERTY(QString message READ message WRITE setMessage NOTIFY messageChanged)
    Q_PROPERTY(QUrl link READ link WRITE setLink NOTIFY linkChanged)
    Q_PROPERTY(QUrl icon READ icon WRITE setIcon NOTIFY iconChanged)
    Q_PROPERTY(QUrl picture READ picture WRITE setPicture NOTIFY pictureChanged)
    Q_PROPERTY(QVariantList actions READ actions WRITE setActions NOTIFY actionsChanged)
    Q_PROPERTY(QString type READ type WRITE setType NOTIFY typeChanged)
    Q_PROPERTY(QDateTime createdTime READ createdTime WRITE setCreatedTime NOTIFY createdTimeChanged)
    Q_PROPERTY(QDateTime updatedTime READ updatedTime WRITE setUpdatedtime NOTIFY updatedTimeChanged)
    Q_PROPERTY(QString attribution READ attribution WRITE setAttribution NOTIFY attributionChanged)
    Q_PROPERTY(qulonglong likes READ likes WRITE setLikes NOTIFY likesChanged)
    Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged)
    Q_PROPERTY(QString caption READ caption WRITE setCaption NOTIFY captionChanged)
    Q_PROPERTY(QVariantList comments READ comments WRITE setComments NOTIFY commentsChanged)
    Q_PROPERTY(qulonglong count READ count WRITE setCount NOTIFY countChanged)
    Q_PROPERTY(QVariantMap privacy READ privacy WRITE setPrivacy NOTIFY privacyChanged)
    
public:
    explicit QFacebookGraphCommonFeedModel(QObject *parent = 0);
	
    QString fbid() const;
    void setFbid(const QString &fbid);

    QVariantMap from() const;
    void setFrom(const QVariantMap &from);

    QVariantList to() const;
    void setTo(const QVariantList &to);

    QString message() const;
    void setMessage(const QString &message);

    QUrl link() const;
    void setLink(const QUrl &link);

    QUrl icon() const;
    void setIcon(const QUrl &icon);

    QUrl picture() const;
    void setPicture(const QUrl &icon);

    QVariantList actions() const;
    void setActions(const QVariantList &actions);

    QVariantList comments() const;
    void setComments(const QVariantList &comments);

    QString type() const;
    void setType(const QString &type);

    QDateTime createdTime() const;
    void setCreatedTime(const QDateTime &createdTime);

    QDateTime updatedTime() const;
    void setUpdatedtime(const QDateTime &updatedTime);

    QString attribution() const;
    void setAttribution(const QString &attribution);

    qulonglong likes() const;
    void setLikes(qulonglong likes);

    qulonglong count() const;
    void setCount(qulonglong count);

    QString description() const;
    void setDescription(const QString &description);

    QString caption() const;
    void setCaption(const QString &caption);

    QVariantMap privacy() const;
    void setPrivacy(const QVariantMap &from);

signals:
    void fbidChanged();
    void fromChanged();
    void toChanged();
    void messageChanged();
    void linkChanged();
    void iconChanged();
    void pictureChanged();
    void actionsChanged();
    void typeChanged();
    void createdTimeChanged();
    void updatedTimeChanged();
    void attributionChanged();
    void likesChanged();
    void captionChanged();
    void descriptionChanged();
    void commentsChanged();
    void countChanged();
    void privacyChanged();

private:
    QString m_fbid;
    QVariantMap m_from;
    QVariantList m_to;
    QString m_message;
    QUrl m_link;
    QUrl m_icon;
    QUrl m_picture;
    QVariantList m_actions;
    QString m_type;
    QDateTime m_createdTime;
    QDateTime m_updatedTime;
    QString m_attribution;
    qulonglong m_likes;
    QString m_caption;
    QString m_description;
    QVariantList m_comments;
    qulonglong m_count;
    QVariantMap m_privacy;
};

#endif //QFACEBOOKGRAPHCOMMONFEEDMODEL_H

