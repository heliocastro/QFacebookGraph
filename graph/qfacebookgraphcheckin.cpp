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

#include "qfacebookgraphcheckin.h"

QFacebookGraphCheckin::QFacebookGraphCheckin(QObject *parent) :
    QObject(parent)
{
    m_id = QString::null;
    m_from = QStringList();
    m_tags = QStringList();
    m_place = QStringList();
    m_message = QString::null;
    m_coordinates = QString::null;
    m_application = QStringList();
    m_createdTime = QDateTime();
}

QString QFacebookGraphCheckin::id() const {
     return m_id;
}
void QFacebookGraphCheckin::setId(const QString &id) {
    if( m_id != id )
	    m_id = id;
}

QStringList QFacebookGraphCheckin::from() const {
     return m_from;
}
void QFacebookGraphCheckin::setFrom(const QStringList &from) {
    if( m_from != from )
	    m_from = from;
}

QStringList QFacebookGraphCheckin::tags() const {
     return m_tags;
}
void QFacebookGraphCheckin::setTags(const QStringList &tags) {
    if( m_tags != tags )
	    m_tags = tags;
}

QStringList QFacebookGraphCheckin::place() const {
     return m_place;
}
void QFacebookGraphCheckin::setPlace(const QStringList &place) {
    if( m_place != place )
	    m_place = place;
}

QString QFacebookGraphCheckin::message() const {
     return m_message;
}
void QFacebookGraphCheckin::setMessage(const QString &message) {
    if( m_message != message )
	    m_message = message;
}

QString QFacebookGraphCheckin::coordinates() const {
     return m_coordinates;
}
void QFacebookGraphCheckin::setCoordinates(const QString &coordinates) {
    if( m_coordinates != coordinates )
	    m_coordinates = coordinates;
}

QStringList QFacebookGraphCheckin::application() const {
     return m_application;
}
void QFacebookGraphCheckin::setApplication(const QStringList &application) {
    if( m_application != application )
	    m_application = application;
}

QDateTime QFacebookGraphCheckin::createdTime() const {
     return m_createdTime;
}
void QFacebookGraphCheckin::setCreatedtime(const QDateTime &createdTime) {
    if( m_createdTime != createdTime )
	    m_createdTime = createdTime;
}

