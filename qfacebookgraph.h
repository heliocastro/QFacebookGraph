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


#ifndef QFACEBOOKGRAPH_H
#define QFACEBOOKGRAPH_H

#include <QString>
#include <QVariant>
#include <QList>
#include <QPair>
#include <QUrl>
#include <QObject>
#include <QNetworkAccessManager>

#include "qfacebookgraph_global.h"

/**
* @brief Main class for Facebook API
*/
class QFACEBOOKGRAPHSHARED_EXPORT QFacebookGraph : public QObject {

    Q_OBJECT

    enum HttpVerb
    {
        GET,
        POST,
        DELETE
    };

public:
    QFacebookGraph(QObject *parent = 0);
    QFacebookGraph(const QString &apiKey, const QString &apiSecret);

    void Get(const QString &path);
    void Delete(const QString &path);
    void Post(const QString &path);
    QString accessToken() const;
    void setToken(const QString& token);
    QVariantMap result() const;
    void addArgument(const QString &key, const QString &value);
    virtual void requestDone(bool res = false);

private:
    void Call(const QUrl &url, HttpVerb httpVerb);
    QUrl baseUrl(const QString &path = QString::null);

private slots:
    void httpFinished();
    void httpReadyRead();

signals:
    void modelPopulated();

protected:
    QString m_accessToken;
    QByteArray m_httpResult;
    QNetworkAccessManager m_qnam;
    QNetworkReply *m_reply;
    bool m_httpRequestSucessfull;
    QVariantMap m_mapResult;
    QUrl m_url;
    QList<QPair<QString,QString> > m_args;
};

#endif // QFACEBOOKGRAPH_H
