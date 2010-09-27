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

#include "qfacebookgraphnote.h"

QFacebookGraphNote::QFacebookGraphNote(QObject *parent) :
    QObject(parent)
{
    m_id = QString::null;
    m_from = 0;
    m_subject = 0;
    m_message = 0;
    m_created_time = 0;
    m_updated_time = 0;
    m_icon = 0;
}

QString QFacebookGraphNote::id() const {
     return m_id;
}
void QFacebookGraphNote::setId(const QString &id) {
    if( m_id != id )
	    m_id != id;
}

QStringList QFacebookGraphNote::from() const {
     return m_from;
}
void QFacebookGraphNote::setFrom(const QStringList &from) {
    if( m_from != from )
	    m_from != from;
}

QStringList QFacebookGraphNote::subject() const {
     return m_subject;
}
void QFacebookGraphNote::setSubject(const QStringList &subject) {
    if( m_subject != subject )
	    m_subject != subject;
}

QStringList QFacebookGraphNote::message() const {
     return m_message;
}
void QFacebookGraphNote::setMessage(const QStringList &message) {
    if( m_message != message )
	    m_message != message;
}

QDateTime QFacebookGraphNote::created_time() const {
     return m_created_time;
}
void QFacebookGraphNote::setCreated_time(const QDateTime &created_time) {
    if( m_created_time != created_time )
	    m_created_time != created_time;
}

QDateTime QFacebookGraphNote::updated_time() const {
     return m_updated_time;
}
void QFacebookGraphNote::setUpdated_time(const QDateTime &updated_time) {
    if( m_updated_time != updated_time )
	    m_updated_time != updated_time;
}

QUrl QFacebookGraphNote::icon() const {
     return m_icon;
}
void QFacebookGraphNote::setIcon(const QUrl &icon) {
    if( m_icon != icon )
	    m_icon != icon;
}

