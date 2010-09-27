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
    Q_PROPERTY(QDateTime created_time READ created_time WRITE setCreated_time NOTIFY created_timeChanged)
    Q_PROPERTY(QDateTime updated_time READ updated_time WRITE setUpdated_time NOTIFY updated_timeChanged)
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

    QDateTime created_time() const;
    void setCreated_time(const QDateTime &created_time);

    QDateTime updated_time() const;
    void setUpdated_time(const QDateTime &updated_time);

    QUrl icon() const;
    void setIcon(const QUrl &icon);

signals:
    void idChanged();
    void fromChanged();
    void subjectChanged();
    void messageChanged();
    void created_timeChanged();
    void updated_timeChanged();
    void iconChanged();

private:
    QString m_id;
    QStringList m_from;
    QStringList m_subject;
    QStringList m_message;
    QDateTime m_created_time;
    QDateTime m_updated_time;
    QUrl m_icon;

};

#endif //QFACEBOOKGRAPHNOTE_H

