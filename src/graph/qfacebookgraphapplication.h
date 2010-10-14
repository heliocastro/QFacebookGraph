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

#ifndef QFACEBOOKGRAPHAPPLICATION_H
#define QFACEBOOKGRAPHAPPLICATION_H

#include <QObject>
#include <QString>
#include <QUrl>

class QFacebookGraphApplication : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged)
    Q_PROPERTY(QString category READ category WRITE setCategory NOTIFY categoryChanged)
    Q_PROPERTY(QUrl link READ link WRITE setLink NOTIFY linkChanged)
    
public:
    explicit QFacebookGraphApplication(QObject *parent = 0);
	
    QString id() const;
    void setId(const QString &id);

    QString name() const;
    void setName(const QString &name);

    QString description() const;
    void setDescription(const QString &description);

    QString category() const;
    void setCategory(const QString &category);

    QUrl link() const;
    void setLink(const QUrl &link);

signals:
    void idChanged();
    void nameChanged();
    void descriptionChanged();
    void categoryChanged();
    void linkChanged();

private:
    QString m_id;
    QString m_name;
    QString m_description;
    QString m_category;
    QUrl m_link;

};

#endif //QFACEBOOKGRAPHAPPLICATION_H

