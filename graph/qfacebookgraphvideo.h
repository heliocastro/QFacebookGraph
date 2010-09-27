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

#ifndef QFACEBOOKGRAPHVIDEO_H
#define QFACEBOOKGRAPHVIDEO_H

#include <QObject>
#include <QDateTime>
#include <QString>
#include <QStringList>

class QFacebookGraphVideo : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QStringList from READ from WRITE setFrom NOTIFY fromChanged)
    Q_PROPERTY(QString message READ message WRITE setMessage NOTIFY messageChanged)
    Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged)
    Q_PROPERTY(QString lenght READ lenght WRITE setLenght NOTIFY lenghtChanged)
    Q_PROPERTY(QDateTime createdTime READ createdTime WRITE setCreatedtime NOTIFY createdTimeChanged)
    Q_PROPERTY(QDateTime updatedTime READ updatedTime WRITE setUpdatedtime NOTIFY updatedTimeChanged)
    
public:
    explicit QFacebookGraphVideo(QObject *parent = 0);
	
    QString id() const;
    void setId(const QString &id);

    QStringList from() const;
    void setFrom(const QStringList &from);

    QString message() const;
    void setMessage(const QString &message);

    QString description() const;
    void setDescription(const QString &description);

    QString lenght() const;
    void setLenght(const QString &lenght);

    QDateTime createdTime() const;
    void setCreatedtime(const QDateTime &createdTime);

    QDateTime updatedTime() const;
    void setUpdatedtime(const QDateTime &updatedTime);

signals:
    void idChanged();
    void fromChanged();
    void messageChanged();
    void descriptionChanged();
    void lenghtChanged();
    void createdTimeChanged();
    void updatedTimeChanged();

private:
    QString m_id;
    QStringList m_from;
    QString m_message;
    QString m_description;
    QString m_lenght;
    QDateTime m_createdTime;
    QDateTime m_updatedTime;

};

#endif //QFACEBOOKGRAPHVIDEO_H

