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

#include <qjson/parser.h>

#include "qfacebookgraph.h"


QFacebookGraph::QFacebookGraph()
{
    m_accessToken = QString::null;
}

QFacebookGraph::QFacebookGraph( const QString &accessToken )
{
    m_accessToken = accessToken;
}

QFacebookGraph::QFacebookGraph( const QString &apiKey, const QString &apiSecret )
{
    Q_UNUSED( apiKey )
    Q_UNUSED( apiSecret )
    m_accessToken = QString::null;
}

QVariantMap QFacebookGraph::Get(const QString &relativePath, QMap<QString,QString> args) const
{
    return Call(relativePath, GET, args);
}

QVariantMap QFacebookGraph::Delete(const QString &relativePath) const
{
    QMap<QString,QString> empty = QMap<QString,QString>();
    return Call(relativePath, DELETE, empty);
}

QVariantMap QFacebookGraph::Post(const QString &relativePath, QMap<QString,QString> args) const
{
    return Call(relativePath, POST, args);
}

QVariantMap QFacebookGraph::Call(const QString &relativePath, HttpVerb httpVerb, QMap<QString,QString> args) const
{
    QUrl url("https://graph.facebook.com" + relativePath);

    if( accessToken().isNull() || accessToken().isEmpty())
    {
        args["access_token"] = accessToken();
    }

    QJson::Parser parser;
    bool ok;

    const QByteArray data = MakeRequest(url, httpVerb, args).toAscii();
    QVariantMap result = parser.parse(data, &ok).toMap();

    return result;
}

QString QFacebookGraph::MakeRequest(const QUrl &url, HttpVerb httpVerb, QMap<QString,QString> args) const
{
    Q_UNUSED( url )
    Q_UNUSED( httpVerb )
    Q_UNUSED( args )
    return QString::null;
}

QString QFacebookGraph::EncodeMap(QMap<QString,QString> dict, bool questionMark) const
{
    QString result;

    if(questionMark)
        result.append("?");

    QMapIterator<QString,QString> i(dict);
    while (i.hasNext())
    {
        i.next();
        result.append(i.key());
        result.append('=');
        result.append(i.value());
        result.append('&');
    }
    result.remove(result.length() -1, 1);
    return result;
}

QString QFacebookGraph::accessToken() const
{
    return m_accessToken;
}

