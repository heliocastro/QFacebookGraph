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

#include "qfacebookgraphalbum.h"

QFacebookGraphAlbum::QFacebookGraphAlbum(QObject *parent) :
    QObject(parent)
{
    m_id = QString::null;
    m_from = QHashFrom();
    m_description = QString::null;
    m_location = QString::null;
    m_link = QUrl();
    m_privacy = QString::null;
    m_count = 0;
    m_createdTime = QDateTime();
    m_updatedTime = QDateTime();
    m_comments = 0;
}

QString QFacebookGraphAlbum::id() const {
     return m_id;
}
void QFacebookGraphAlbum::setId(const QString &id) {
    if( m_id != id )
	    m_id = id;
}

QHashFrom QFacebookGraphAlbum::from() const {
     return m_from;
}
void QFacebookGraphAlbum::setFrom(const QHashFrom &from) {
    if( m_from != from )
	    m_from = from;
}

QString QFacebookGraphAlbum::description() const {
     return m_description;
}
void QFacebookGraphAlbum::setDescription(const QString &description) {
    if( m_description != description )
	    m_description = description;
}

QString QFacebookGraphAlbum::location() const {
     return m_location;
}
void QFacebookGraphAlbum::setLocation(const QString &location) {
    if( m_location != location )
	    m_location = location;
}

QUrl QFacebookGraphAlbum::link() const {
     return m_link;
}
void QFacebookGraphAlbum::setLink(const QUrl &link) {
    if( m_link != link )
	    m_link = link;
}

QString QFacebookGraphAlbum::privacy() const {
     return m_privacy;
}
void QFacebookGraphAlbum::setPrivacy(const QString &privacy) {
    if( m_privacy != privacy )
	    m_privacy = privacy;
}

quint32 QFacebookGraphAlbum::count() const {
     return m_count;
}
void QFacebookGraphAlbum::setCount(const quint32 &count) {
    if( m_count != count )
	    m_count = count;
}

QDateTime QFacebookGraphAlbum::createdTime() const {
     return m_createdTime;
}
void QFacebookGraphAlbum::setCreatedtime(const QDateTime &createdTime) {
    if( m_createdTime != createdTime )
	    m_createdTime = createdTime;
}

QDateTime QFacebookGraphAlbum::updatedTime() const {
     return m_updatedTime;
}
void QFacebookGraphAlbum::setUpdatedtime(const QDateTime &updatedTime) {
    if( m_updatedTime != updatedTime )
	    m_updatedTime = updatedTime;
}

quint32 QFacebookGraphAlbum::comments() const {
     return m_comments;
}
void QFacebookGraphAlbum::setComments(const quint32 &comments) {
    if( m_comments != comments )
	    m_comments = comments;
}

