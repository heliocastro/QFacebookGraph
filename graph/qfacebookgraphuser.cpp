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

#include "qfacebookgraphuser.h"

QFacebookGraphUser::QFacebookGraphUser(QString token, const QString &user, QObject *parent) :
    QObject(parent)
{
    m_graph = new QFacebookGraph( token );
    m_userModel = QVariant();
    m_user = user;

    update();
}

QVariant QFacebookGraphUser::getUserModel() const {
    return m_userModel;
}

void QFacebookGraphUser::update() {
    QUrl url = m_graph->baseUrl();
    if(m_user.isNull())
        url.setEncodedPath("/me");
    else
    {
        QString path("/" + m_user);
        url.setEncodedPath(path.toAscii());
    }
    m_graph->Get( url );
    connect( m_graph, SIGNAL(requestDone( bool )), this, SLOT( requestDone( bool ) ) );
}

void QFacebookGraphUser::requestDone(bool ok) {
    if(ok)
    {
        m_userModel = m_graph->result();
        qDebug() << m_userModel;
    }
}
