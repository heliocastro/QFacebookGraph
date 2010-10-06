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

#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QObject>

#include <qjson/parser.h>


#include "qfacebookgraph.h"

QFacebookGraph::QFacebookGraph( const QString &accessToken ) {
    m_accessToken = accessToken;
    m_httpResult = QByteArray();
    m_mapResult = QVariantMap();

    m_url = QUrl("https://graph.facebook.com");
    if( !m_accessToken.isNull() || !m_accessToken.isEmpty())
        m_url.addQueryItem( "access_token", m_accessToken);

}

QFacebookGraph::QFacebookGraph( const QString &apiKey, const QString &apiSecret ) {
    m_accessToken = QString::null;
    m_httpResult = QByteArray();
    m_mapResult = QVariantMap();

    Q_UNUSED(apiKey);
    Q_UNUSED(apiSecret);
}

void QFacebookGraph::Get(const QUrl &url) {
    Call(url, GET);
}

void QFacebookGraph::Delete(const QUrl &url) {
    Call(url, DELETE);
}

void QFacebookGraph::Post(const QUrl &url) {
    Call(url, POST);
}

void QFacebookGraph::Call(const QUrl &url, HttpVerb httpVerb) {
    qDebug() << "Call URL: " << url;

    Q_UNUSED(httpVerb);

    m_reply = m_qnam.get( QNetworkRequest(url));
    connect(m_reply, SIGNAL(finished()), this, SLOT(httpFinished()));
    connect(m_reply, SIGNAL(readyRead()), this, SLOT(httpReadyRead()));
}


QString QFacebookGraph::accessToken() const {
    return m_accessToken;
}

QUrl QFacebookGraph::baseUrl() const {
    return m_url;
}

void QFacebookGraph::httpReadyRead() {
    m_httpResult.append(m_reply->readAll());
}

void QFacebookGraph::httpFinished() {
    if( m_reply->error() )
    {
        qDebug() << "HTTP connection failed.";
        emit requestDone(false);
    }

    QJson::Parser parser;
    bool ok;

    m_mapResult = parser.parse(m_httpResult, &ok).toMap();

    emit requestDone(true);

    m_reply->deleteLater();
    m_reply = 0;
}

QVariantMap QFacebookGraph::result() const {
    return m_mapResult;
}
