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

#include "qfacebookgraphvideo.h"

QFacebookGraphVideo::QFacebookGraphVideo(QObject *parent) :
    QObject(parent)
{
    m_id = QString::null;
    m_from = QStringList();
    m_message = QString::null;
    m_description = QString::null;
    m_lenght = QString::null;
    m_createdTime = QDateTime();
    m_updatedTime = QDateTime();
}

QString QFacebookGraphVideo::id() const {
     return m_id;
}
void QFacebookGraphVideo::setId(const QString &id) {
    if( m_id != id )
	    m_id = id;
}

QStringList QFacebookGraphVideo::from() const {
     return m_from;
}
void QFacebookGraphVideo::setFrom(const QStringList &from) {
    if( m_from != from )
	    m_from = from;
}

QString QFacebookGraphVideo::message() const {
     return m_message;
}
void QFacebookGraphVideo::setMessage(const QString &message) {
    if( m_message != message )
	    m_message = message;
}

QString QFacebookGraphVideo::description() const {
     return m_description;
}
void QFacebookGraphVideo::setDescription(const QString &description) {
    if( m_description != description )
	    m_description = description;
}

QString QFacebookGraphVideo::lenght() const {
     return m_lenght;
}
void QFacebookGraphVideo::setLenght(const QString &lenght) {
    if( m_lenght != lenght )
	    m_lenght = lenght;
}

QDateTime QFacebookGraphVideo::createdTime() const {
     return m_createdTime;
}
void QFacebookGraphVideo::setCreatedtime(const QDateTime &createdTime) {
    if( m_createdTime != createdTime )
	    m_createdTime = createdTime;
}

QDateTime QFacebookGraphVideo::updatedTime() const {
     return m_updatedTime;
}
void QFacebookGraphVideo::setUpdatedtime(const QDateTime &updatedTime) {
    if( m_updatedTime != updatedTime )
	    m_updatedTime = updatedTime;
}

