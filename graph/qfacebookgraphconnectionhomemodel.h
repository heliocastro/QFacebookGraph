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

#ifndef QFACEBOOKGRAPHCONNECTIONHOMEMODEL_H
#define QFACEBOOKGRAPHCONNECTIONHOMEMODEL_H

#include <QObject>
#include <QDateTime>
#include <QHash>
#include <QString>
#include <QStringList>
#include <QUrl>

typedef QHash<QString,QUrl> QHashActions;

class QFacebookGraphConnectionHomeModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QStringList from READ from WRITE setFrom NOTIFY fromChanged)
    Q_PROPERTY(QString message READ message WRITE setMessage NOTIFY messageChanged)
    Q_PROPERTY(QUrl link READ link WRITE setLink NOTIFY linkChanged)
    Q_PROPERTY(QUrl icon READ icon WRITE setIcon NOTIFY iconChanged)
    Q_PROPERTY(QHashActions actions READ actions WRITE setActions NOTIFY actionsChanged)
    Q_PROPERTY(QString type READ type WRITE setType NOTIFY typeChanged)
    Q_PROPERTY(QDateTime createdTime READ createdTime WRITE setCreatedtime NOTIFY createdTimeChanged)
    Q_PROPERTY(QDateTime updatedTime READ updatedTime WRITE setUpdatedtime NOTIFY updatedTimeChanged)
    Q_PROPERTY(QString attribution READ attribution WRITE setAttribution NOTIFY attributionChanged)
    
public:
    explicit QFacebookGraphConnectionHomeModel(QObject *parent = 0);
	
    QString id() const;
    void setId(const QString &id);

    QStringList from() const;
    void setFrom(const QStringList &from);

    QString message() const;
    void setMessage(const QString &message);

    QUrl link() const;
    void setLink(const QUrl &link);

    QUrl icon() const;
    void setIcon(const QUrl &icon);

    QHashActions actions() const;
    void setActions(const QHashActions &actions);

    QString type() const;
    void setType(const QString &type);

    QDateTime createdTime() const;
    void setCreatedtime(const QDateTime &createdTime);

    QDateTime updatedTime() const;
    void setUpdatedtime(const QDateTime &updatedTime);

    QString attribution() const;
    void setAttribution(const QString &attribution);

signals:
    void idChanged();
    void fromChanged();
    void messageChanged();
    void linkChanged();
    void iconChanged();
    void actionsChanged();
    void typeChanged();
    void createdTimeChanged();
    void updatedTimeChanged();
    void attributionChanged();

private:
    QString m_id;
    QStringList m_from;
    QString m_message;
    QUrl m_link;
    QUrl m_icon;
    QHashActions m_actions;
    QString m_type;
    QDateTime m_createdTime;
    QDateTime m_updatedTime;
    QString m_attribution;
};

#endif //QFACEBOOKGRAPHCONNECTIONHOMEMODEL_H

