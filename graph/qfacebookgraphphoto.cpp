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

#include "qfacebookgraphphoto.h"

QFacebookGraphPhoto::QFacebookGraphPhoto(QObject *parent) :
    QObject(parent)
{
    m_id = QString::null;
    m_from = 0;
    m_tags = 0;
    m_name = QString::null;
    m_picture = 0;
    m_icon = 0;
    m_source = 0;
    m_height = 0;
    m_width = 0;
    m_link = 0;
    m_created_time = 0;
    m_updated_time = 0;
}

QString QFacebookGraphPhoto::id() const {
     return m_id;
}
void QFacebookGraphPhoto::setId(const QString &id) {
    if( m_id != id )
	    m_id != id;
}

QStringList QFacebookGraphPhoto::from() const {
     return m_from;
}
void QFacebookGraphPhoto::setFrom(const QStringList &from) {
    if( m_from != from )
	    m_from != from;
}

QStringList QFacebookGraphPhoto::tags() const {
     return m_tags;
}
void QFacebookGraphPhoto::setTags(const QStringList &tags) {
    if( m_tags != tags )
	    m_tags != tags;
}

QString QFacebookGraphPhoto::name() const {
     return m_name;
}
void QFacebookGraphPhoto::setName(const QString &name) {
    if( m_name != name )
	    m_name != name;
}

QUrl QFacebookGraphPhoto::picture() const {
     return m_picture;
}
void QFacebookGraphPhoto::setPicture(const QUrl &picture) {
    if( m_picture != picture )
	    m_picture != picture;
}

QUrl QFacebookGraphPhoto::icon() const {
     return m_icon;
}
void QFacebookGraphPhoto::setIcon(const QUrl &icon) {
    if( m_icon != icon )
	    m_icon != icon;
}

QUrl QFacebookGraphPhoto::source() const {
     return m_source;
}
void QFacebookGraphPhoto::setSource(const QUrl &source) {
    if( m_source != source )
	    m_source != source;
}

quint32 QFacebookGraphPhoto::height() const {
     return m_height;
}
void QFacebookGraphPhoto::setHeight(const quint32 &height) {
    if( m_height != height )
	    m_height != height;
}

quint32 QFacebookGraphPhoto::width() const {
     return m_width;
}
void QFacebookGraphPhoto::setWidth(const quint32 &width) {
    if( m_width != width )
	    m_width != width;
}

QUrl QFacebookGraphPhoto::link() const {
     return m_link;
}
void QFacebookGraphPhoto::setLink(const QUrl &link) {
    if( m_link != link )
	    m_link != link;
}

QDateTime QFacebookGraphPhoto::created_time() const {
     return m_created_time;
}
void QFacebookGraphPhoto::setCreated_time(const QDateTime &created_time) {
    if( m_created_time != created_time )
	    m_created_time != created_time;
}

QDateTime QFacebookGraphPhoto::updated_time() const {
     return m_updated_time;
}
void QFacebookGraphPhoto::setUpdated_time(const QDateTime &updated_time) {
    if( m_updated_time != updated_time )
	    m_updated_time != updated_time;
}

