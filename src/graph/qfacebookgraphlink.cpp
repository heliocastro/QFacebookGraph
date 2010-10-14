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

#include "qfacebookgraphlink.h"

QFacebookGraphLink::QFacebookGraphLink(QObject *parent) :
    QObject(parent)
{
    m_id = QString::null;
    m_from = QStringList();
    m_link = QUrl();
    m_name = QString::null;
    m_caption = QString::null;
    m_description = QString::null;
    m_icon = QUrl();
    m_picture = 0;
    m_message = QString::null;
    m_createdTime = QDateTime();
}

QString QFacebookGraphLink::id() const {
     return m_id;
}
void QFacebookGraphLink::setId(const QString &id) {
    if( m_id != id )
	    m_id = id;
}

QStringList QFacebookGraphLink::from() const {
     return m_from;
}
void QFacebookGraphLink::setFrom(const QStringList &from) {
    if( m_from != from )
	    m_from = from;
}

QUrl QFacebookGraphLink::link() const {
     return m_link;
}
void QFacebookGraphLink::setLink(const QUrl &link) {
    if( m_link != link )
	    m_link = link;
}

QString QFacebookGraphLink::name() const {
     return m_name;
}
void QFacebookGraphLink::setName(const QString &name) {
    if( m_name != name )
	    m_name = name;
}

QString QFacebookGraphLink::caption() const {
     return m_caption;
}
void QFacebookGraphLink::setCaption(const QString &caption) {
    if( m_caption != caption )
	    m_caption = caption;
}

QString QFacebookGraphLink::description() const {
     return m_description;
}
void QFacebookGraphLink::setDescription(const QString &description) {
    if( m_description != description )
	    m_description = description;
}

QUrl QFacebookGraphLink::icon() const {
     return m_icon;
}
void QFacebookGraphLink::setIcon(const QUrl &icon) {
    if( m_icon != icon )
	    m_icon = icon;
}

QUrl QFacebookGraphLink::picture() const {
     return m_picture;
}
void QFacebookGraphLink::setPicture(const QUrl &picture) {
    if( m_picture != picture )
	    m_picture = picture;
}

QString QFacebookGraphLink::message() const {
     return m_message;
}
void QFacebookGraphLink::setMessage(const QString &message) {
    if( m_message != message )
	    m_message = message;
}

QDateTime QFacebookGraphLink::createdTime() const {
     return m_createdTime;
}
void QFacebookGraphLink::setCreatedtime(const QDateTime &createdTime) {
    if( m_createdTime != createdTime )
	    m_createdTime = createdTime;
}

