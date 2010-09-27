/*
 * Copyright 2010 Helio Chissini de Castro
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


#ifndef QFACEBOOKGRAPH_H
#define QFACEBOOKGRAPH_H

#include <QString>
#include <QVariant>
#include <QMap>
#include <QUrl>

#include "qfacebook_global.h"

/**
* @brief Main class for Facebook API
*/
class QFACEBOOKGRAPHSHARED_EXPORT QFacebookGraph {
    enum HttpVerb
    {
        GET,
        POST,
        DELETE
    };

public:
    QFacebookGraph();
    QFacebookGraph(const QString &accessToken);
    QFacebookGraph(const QString &apiKey, const QString &apiSecret);

    QVariantMap Get(const QString &relativePath, QMap<QString,QString> args) const;
    QVariantMap Delete(const QString &relativePath) const;
    QVariantMap Post(const QString &relativePath, QMap<QString, QString> args) const;

private:
    QVariantMap Call(const QString &relativePath, HttpVerb httpVerb, QMap<QString,QString> args) const;
    QString MakeRequest(const QUrl &url, HttpVerb httpVerb, QMap<QString,QString> args ) const;
    QString EncodeMap(QMap<QString,QString> dict, bool questionMark) const;
	QString getAccessToken() const;

private:
    QString m_accessToken;
};

#endif // QFACEBOOKGRAPH_H
