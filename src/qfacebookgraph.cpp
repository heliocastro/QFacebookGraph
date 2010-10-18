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
#include <QNetworkProxy>
#include <QObject>

#include <qjson/parser.h>

#include "qfacebookgraph.h"

#ifndef GRAPH_URL_HOST
#define GRAPH_URL_HOST "https://graph.facebook.com"
#endif

QFacebookGraph::QFacebookGraph( QObject *parent) :
    QObject(parent)
{
    init();
}

QFacebookGraph::QFacebookGraph( const QString &apiKey, const QString &apiSecret ) {
    init();
    Q_UNUSED(apiKey);
    Q_UNUSED(apiSecret);
}

void QFacebookGraph::init() {
    m_accessToken = QString::null;
    m_httpResult = QByteArray();
    m_mapResult = QVariantMap();
    m_url = QUrl(GRAPH_URL_HOST);

#if defined(Q_WS_WIN) || defined(Q_WS_MAC)
    QNetworkProxyFactory::setUseSystemConfiguration(true);
#else
    QByteArray env = qgetenv("http_proxy");
    if( !env.isNull() ) {
        QUrl proxyurl( env );
        QNetworkProxy proxy;
        proxy.setType(QNetworkProxy::HttpProxy);
        proxy.setHostName(proxyurl.host());
        proxy.setPort(proxyurl.port());
        proxy.setUser(proxyurl.userName());
        proxy.setPassword(proxyurl.password());
        QNetworkProxy::setApplicationProxy(proxy);
    }
#endif
}

void QFacebookGraph::Get(const QString &path) {
    Call( baseUrl(path), GET);
}

void QFacebookGraph::Delete(const QString &path) {
    Call(baseUrl(path), DELETE);
}

void QFacebookGraph::Post(const QString &path) {
    Call(baseUrl(path), POST);
}

void QFacebookGraph::Call(const QUrl &url, HttpVerb httpVerb) {
    qDebug() << "Call URL: " << url << endl;

    Q_UNUSED(httpVerb);

    m_reply = m_qnam.get(QNetworkRequest(url));
    connect(m_reply, SIGNAL(finished()), this, SLOT(httpFinished()));
    connect(m_reply, SIGNAL(readyRead()), this, SLOT(httpReadyRead()));
}


void QFacebookGraph::setToken(const QString &token) {
    if(m_accessToken != token)
        m_accessToken = token;
}

QString QFacebookGraph::accessToken() const {
    return m_accessToken;
}

void QFacebookGraph::addArgument(const QString &key, const QString &value)
{
    m_args.append(QPair<QString,QString>(key, value));
}

QUrl QFacebookGraph::baseUrl(const QString &path) {
    QUrl url( m_url );

    // Set Path
    if(!path.isNull())
        url.setPath(path);

    // Set access token if exists
    if( !m_accessToken.isNull() || !m_accessToken.isEmpty()) {
        addArgument( "access_token", m_accessToken );
    }

    // Set arguments if exists and clean
    if(!m_args.empty()) {
        url.setQueryItems( m_args );
        m_args.clear();
    }

    return url;
}

void QFacebookGraph::httpReadyRead() {
    m_httpResult.append(m_reply->readAll());
}

void QFacebookGraph::httpFinished() {
    bool res = false;
    int replyCode =  m_reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();

    if( m_reply->error() )
    {
        qDebug() << "HTTP connection failed.";
        requestDone( res );
        return;
    }

    if(replyCode == 302) {
        res = true;
        m_mapResult["url_redirect"] = m_reply->attribute(QNetworkRequest::RedirectionTargetAttribute).toUrl();
    }
    else {
        QJson::Parser parser;
        m_mapResult = parser.parse(m_httpResult, &res).toMap();
    }

    m_reply->deleteLater();
    m_reply = 0;

    requestDone( res );
}

void QFacebookGraph::requestDone(bool res)
{
    // Virtual
    Q_UNUSED(res);
    qDebug() << "Base QFacebookGraph requestDone()" ;
}

QVariantMap QFacebookGraph::result() const {
    return m_mapResult;
}
