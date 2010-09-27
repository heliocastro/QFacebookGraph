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

#include "qfacebookgraphevent.h"

QFacebookGraphEvent::QFacebookGraphEvent(QObject *parent) :
    QObject(parent)
{
    m_id = QString::null;
    m_owner = QStringList();
    m_name = QString::null;
    m_description = QString::null;
    m_startTime = QDateTime();
    m_endTime = QDateTime();
    m_location = QString::null;
    m_venue = QStringList();
    m_privacy = QString::null;
    m_updatedTime = QDateTime();
}

QString QFacebookGraphEvent::id() const {
     return m_id;
}
void QFacebookGraphEvent::setId(const QString &id) {
    if( m_id != id )
	    m_id = id;
}

QStringList QFacebookGraphEvent::owner() const {
     return m_owner;
}
void QFacebookGraphEvent::setOwner(const QStringList &owner) {
    if( m_owner != owner )
	    m_owner = owner;
}

QString QFacebookGraphEvent::name() const {
     return m_name;
}
void QFacebookGraphEvent::setName(const QString &name) {
    if( m_name != name )
	    m_name = name;
}

QString QFacebookGraphEvent::description() const {
     return m_description;
}
void QFacebookGraphEvent::setDescription(const QString &description) {
    if( m_description != description )
	    m_description = description;
}

QDateTime QFacebookGraphEvent::startTime() const {
     return m_startTime;
}
void QFacebookGraphEvent::setStarttime(const QDateTime &startTime) {
    if( m_startTime != startTime )
	    m_startTime = startTime;
}

QDateTime QFacebookGraphEvent::endTime() const {
     return m_endTime;
}
void QFacebookGraphEvent::setEndtime(const QDateTime &endTime) {
    if( m_endTime != endTime )
	    m_endTime = endTime;
}

QString QFacebookGraphEvent::location() const {
     return m_location;
}
void QFacebookGraphEvent::setLocation(const QString &location) {
    if( m_location != location )
	    m_location = location;
}

QStringList QFacebookGraphEvent::venue() const {
     return m_venue;
}
void QFacebookGraphEvent::setVenue(const QStringList &venue) {
    if( m_venue != venue )
	    m_venue = venue;
}

QString QFacebookGraphEvent::privacy() const {
     return m_privacy;
}
void QFacebookGraphEvent::setPrivacy(const QString &privacy) {
    if( m_privacy != privacy )
	    m_privacy = privacy;
}

QDateTime QFacebookGraphEvent::updatedTime() const {
     return m_updatedTime;
}
void QFacebookGraphEvent::setUpdatedtime(const QDateTime &updatedTime) {
    if( m_updatedTime != updatedTime )
	    m_updatedTime = updatedTime;
}

