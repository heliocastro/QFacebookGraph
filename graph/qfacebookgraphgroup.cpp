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

#include "qfacebookgraphgroup.h"

QFacebookGraphGroup::QFacebookGraphGroup(QObject *parent) :
    QObject(parent)
{
    m_id = QString::null;
    m_owner = 0;
    m_name = QString::null;
    m_description = QString::null;
    m_link = 0;
    m_venue = 0;
    m_privacy = QString::null;
    m_updated_time = 0;
}

QString QFacebookGraphGroup::id() const {
     return m_id;
}
void QFacebookGraphGroup::setId(const QString &id) {
    if( m_id != id )
	    m_id != id;
}

QStringList QFacebookGraphGroup::owner() const {
     return m_owner;
}
void QFacebookGraphGroup::setOwner(const QStringList &owner) {
    if( m_owner != owner )
	    m_owner != owner;
}

QString QFacebookGraphGroup::name() const {
     return m_name;
}
void QFacebookGraphGroup::setName(const QString &name) {
    if( m_name != name )
	    m_name != name;
}

QString QFacebookGraphGroup::description() const {
     return m_description;
}
void QFacebookGraphGroup::setDescription(const QString &description) {
    if( m_description != description )
	    m_description != description;
}

QUrl QFacebookGraphGroup::link() const {
     return m_link;
}
void QFacebookGraphGroup::setLink(const QUrl &link) {
    if( m_link != link )
	    m_link != link;
}

QStringList QFacebookGraphGroup::venue() const {
     return m_venue;
}
void QFacebookGraphGroup::setVenue(const QStringList &venue) {
    if( m_venue != venue )
	    m_venue != venue;
}

QString QFacebookGraphGroup::privacy() const {
     return m_privacy;
}
void QFacebookGraphGroup::setPrivacy(const QString &privacy) {
    if( m_privacy != privacy )
	    m_privacy != privacy;
}

QDateTime QFacebookGraphGroup::updated_time() const {
     return m_updated_time;
}
void QFacebookGraphGroup::setUpdated_time(const QDateTime &updated_time) {
    if( m_updated_time != updated_time )
	    m_updated_time != updated_time;
}

