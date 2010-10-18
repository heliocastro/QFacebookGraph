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

#ifndef QFACEBOOKGRAPHCOMMONMEDIAMODEL_H
#define QFACEBOOKGRAPHCOMMONMEDIAMODEL_H

#include <QObject>
#include <QDateTime>
#include <QString>

class QFacebookGraphCommonMediaModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString fbid READ fbid WRITE setFbid NOTIFY fbidChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString category READ category WRITE setCategory NOTIFY categoryChanged)
    Q_PROPERTY(QDateTime createdTime READ createdTime WRITE setCreatedTime NOTIFY createdTimeChanged)
    
public:
    explicit QFacebookGraphCommonMediaModel(QObject *parent = 0);
	
    QString fbid() const;
    void setFbid(const QString &fbid);

    QString name() const;
    void setName(const QString &name);

    QString category() const;
    void setCategory(const QString &category);

    QDateTime createdTime() const;
    void setCreatedTime(const QDateTime &createdTime);

signals:
    void fbidChanged();
    void nameChanged();
    void categoryChanged();
    void createdTimeChanged();

private:
    QString m_fbid;
    QString m_name;
    QString m_category;
    QDateTime m_createdTime;
};

#endif //QFACEBOOKGRAPHCOMMONMEDIAMODEL_H

