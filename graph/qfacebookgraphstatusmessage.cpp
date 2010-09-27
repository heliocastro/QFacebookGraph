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

#include "qfacebookgraphstatusmessage.h"

QFacebookGraphStatusMessage::QFacebookGraphStatusMessage(QObject *parent) :
    QObject(parent)
{
    m_id = QString::null;
    m_from = 0;
    m_message = QString::null;
    m_updated_message = 0;
}

QString QFacebookGraphStatusMessage::id() const {
     return m_id;
}
void QFacebookGraphStatusMessage::setId(const QString &id) {
    if( m_id != id )
	    m_id != id;
}

QStringList QFacebookGraphStatusMessage::from() const {
     return m_from;
}
void QFacebookGraphStatusMessage::setFrom(const QStringList &from) {
    if( m_from != from )
	    m_from != from;
}

QString QFacebookGraphStatusMessage::message() const {
     return m_message;
}
void QFacebookGraphStatusMessage::setMessage(const QString &message) {
    if( m_message != message )
	    m_message != message;
}

QDateTime QFacebookGraphStatusMessage::updated_message() const {
     return m_updated_message;
}
void QFacebookGraphStatusMessage::setUpdated_message(const QDateTime &updated_message) {
    if( m_updated_message != updated_message )
	    m_updated_message != updated_message;
}

