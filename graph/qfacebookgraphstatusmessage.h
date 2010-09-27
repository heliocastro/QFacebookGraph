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

#ifndef QFACEBOOKGRAPHSTATUSMESSAGE_H
#define QFACEBOOKGRAPHSTATUSMESSAGE_H

#include <QObject>
#include <QDateTime>
#include <QString>
#include <QStringList>

class QFacebookGraphStatusMessage : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QStringList from READ from WRITE setFrom NOTIFY fromChanged)
    Q_PROPERTY(QString message READ message WRITE setMessage NOTIFY messageChanged)
    Q_PROPERTY(QDateTime updatedMessage READ updatedMessage WRITE setUpdatedmessage NOTIFY updatedMessageChanged)
    
public:
    explicit QFacebookGraphStatusMessage(QObject *parent = 0);
	
    QString id() const;
    void setId(const QString &id);

    QStringList from() const;
    void setFrom(const QStringList &from);

    QString message() const;
    void setMessage(const QString &message);

    QDateTime updatedMessage() const;
    void setUpdatedmessage(const QDateTime &updatedMessage);

signals:
    void idChanged();
    void fromChanged();
    void messageChanged();
    void updatedMessageChanged();

private:
    QString m_id;
    QStringList m_from;
    QString m_message;
    QDateTime m_updatedMessage;

};

#endif //QFACEBOOKGRAPHSTATUSMESSAGE_H

