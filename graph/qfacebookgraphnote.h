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

#ifndef QFACEBOOKGRAPHNOTE_H
#define QFACEBOOKGRAPHNOTE_H

#include <QObject>
#include <QDateTime>
#include <QString>
#include <QStringList>
#include <QUrl>

class QFacebookGraphNote : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QStringList from READ from WRITE setFrom NOTIFY fromChanged)
    Q_PROPERTY(QStringList subject READ subject WRITE setSubject NOTIFY subjectChanged)
    Q_PROPERTY(QStringList message READ message WRITE setMessage NOTIFY messageChanged)
    Q_PROPERTY(QDateTime createdTime READ createdTime WRITE setCreatedtime NOTIFY createdTimeChanged)
    Q_PROPERTY(QDateTime updatedTime READ updatedTime WRITE setUpdatedtime NOTIFY updatedTimeChanged)
    Q_PROPERTY(QUrl icon READ icon WRITE setIcon NOTIFY iconChanged)
    
public:
    explicit QFacebookGraphNote(QObject *parent = 0);
	
    QString id() const;
    void setId(const QString &id);

    QStringList from() const;
    void setFrom(const QStringList &from);

    QStringList subject() const;
    void setSubject(const QStringList &subject);

    QStringList message() const;
    void setMessage(const QStringList &message);

    QDateTime createdTime() const;
    void setCreatedtime(const QDateTime &createdTime);

    QDateTime updatedTime() const;
    void setUpdatedtime(const QDateTime &updatedTime);

    QUrl icon() const;
    void setIcon(const QUrl &icon);

signals:
    void idChanged();
    void fromChanged();
    void subjectChanged();
    void messageChanged();
    void createdTimeChanged();
    void updatedTimeChanged();
    void iconChanged();

private:
    QString m_id;
    QStringList m_from;
    QStringList m_subject;
    QStringList m_message;
    QDateTime m_createdTime;
    QDateTime m_updatedTime;
    QUrl m_icon;

};

#endif //QFACEBOOKGRAPHNOTE_H

