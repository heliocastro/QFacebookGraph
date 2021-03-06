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

#ifndef QFACEBOOKGRAPHSUBSCRIPTION_H
#define QFACEBOOKGRAPHSUBSCRIPTION_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <QUrl>

class QFacebookGraphSubscription : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString object READ object WRITE setObject NOTIFY objectChanged)
    Q_PROPERTY(QStringList fields READ fields WRITE setFields NOTIFY fieldsChanged)
    Q_PROPERTY(QUrl callbackUrl READ callbackUrl WRITE setCallbackurl NOTIFY callbackUrlChanged)
    Q_PROPERTY(bool active READ active WRITE setActive NOTIFY activeChanged)
    
public:
    explicit QFacebookGraphSubscription(QObject *parent = 0);
	
    QString object() const;
    void setObject(const QString &object);

    QStringList fields() const;
    void setFields(const QStringList &fields);

    QUrl callbackUrl() const;
    void setCallbackurl(const QUrl &callbackUrl);

    bool active() const;
    void setActive(const bool &active);

signals:
    void objectChanged();
    void fieldsChanged();
    void callbackUrlChanged();
    void activeChanged();

private:
    QString m_object;
    QStringList m_fields;
    QUrl m_callbackUrl;
    bool m_active;

};

#endif //QFACEBOOKGRAPHSUBSCRIPTION_H

