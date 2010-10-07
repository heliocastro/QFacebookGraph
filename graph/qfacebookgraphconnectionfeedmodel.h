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

#ifndef QFACEBOOKGRAPHCONNECTIONFEEDMODEL_H
#define QFACEBOOKGRAPHCONNECTIONFEEDMODEL_H

#include <QObject>
#include <QDateTime>
#include <QHash>
#include <QString>
#include <QStringList>
#include <QUrl>

typedef QHash<QString,QUrl> QHashActions;

class QFacebookGraphConnectionFeedModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString fbid READ fbid WRITE setFbid NOTIFY fbidChanged)
    Q_PROPERTY(QString fromName READ fromName WRITE setFromName NOTIFY fromNameChanged)
    Q_PROPERTY(QString fromFbid READ fromFbid WRITE setFromFbid NOTIFY fromFbidChanged)
    Q_PROPERTY(QString message READ message WRITE setMessage NOTIFY messageChanged)
    Q_PROPERTY(QUrl link READ link WRITE setLink NOTIFY linkChanged)
    Q_PROPERTY(QUrl icon READ icon WRITE setIcon NOTIFY iconChanged)
    Q_PROPERTY(QUrl picture READ picture WRITE setPicture NOTIFY pictureChanged)
    Q_PROPERTY(QHashActions actions READ actions WRITE setActions NOTIFY actionsChanged)
    Q_PROPERTY(QString type READ type WRITE setType NOTIFY typeChanged)
    Q_PROPERTY(QString createdTime READ createdTime WRITE setCreatedtime NOTIFY createdTimeChanged)
    Q_PROPERTY(QString updatedTime READ updatedTime WRITE setUpdatedtime NOTIFY updatedTimeChanged)
    Q_PROPERTY(QString attribution READ attribution WRITE setAttribution NOTIFY attributionChanged)
    Q_PROPERTY(qulonglong likes READ likes WRITE setLikes NOTIFY likesChanged)
    Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged)
    Q_PROPERTY(QString caption READ caption WRITE setCaption NOTIFY captionChanged)
    
public:
    explicit QFacebookGraphConnectionFeedModel(QObject *parent = 0);
	
    QString fbid() const;
    void setFbid(const QString &fbid);

    QString fromName() const;
    void setFromName(const QString &fromName);

    QString fromFbid() const;
    void setFromFbid(const QString &fromFbid);

    QString message() const;
    void setMessage(const QString &message);

    QUrl link() const;
    void setLink(const QUrl &link);

    QUrl icon() const;
    void setIcon(const QUrl &icon);

    QUrl picture() const;
    void setPicture(const QUrl &icon);

    QHashActions actions() const;
    void setActions(const QHashActions &actions);

    QString type() const;
    void setType(const QString &type);

    QString createdTime() const;
    void setCreatedtime(const QString &createdTime);

    QString updatedTime() const;
    void setUpdatedtime(const QString &updatedTime);

    QString attribution() const;
    void setAttribution(const QString &attribution);

    qulonglong likes() const;
    void setLikes(qulonglong likes);

    QString description() const;
    void setDescription(const QString &description);

    QString caption() const;
    void setCaption(const QString &caption);

signals:
    void fbidChanged();
    void fromNameChanged();
    void fromFbidChanged();
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

private:
    QString m_fbid;
    QString m_fromFbid;
    QString m_fromName;
    QString m_message;
    QUrl m_link;
    QUrl m_icon;
    QUrl m_picture;
    QHashActions m_actions;
    QString m_type;
    QString m_createdTime;
    QString m_updatedTime;
    QString m_attribution;
    qulonglong m_likes;
    QString m_caption;
    QString m_description;
};

#endif //QFACEBOOKGRAPHCONNECTIONFEEDMODEL_H

