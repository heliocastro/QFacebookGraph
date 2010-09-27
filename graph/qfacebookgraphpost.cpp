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

#include "qfacebookgraphpost.h"

QFacebookGraphPost::QFacebookGraphPost(QObject *parent) :
    QObject(parent)
{
    m_id = QString::null;
    m_from = 0;
    m_to = 0;
    m_message = QString::null;
    m_picture = 0;
    m_link = 0;
    m_name = QString::null;
    m_caption = QString::null;
    m_description = QString::null;
    m_source = 0;
    m_icon = 0;
    m_attribution = QString::null;
    m_actions = 0;
    m_likes = 0;
    m_created_time = 0;
    m_updated_time = 0;
}

QString QFacebookGraphPost::id() const {
     return m_id;
}
void QFacebookGraphPost::setId(const QString &id) {
    if( m_id != id )
	    m_id != id;
}

QStringList QFacebookGraphPost::from() const {
     return m_from;
}
void QFacebookGraphPost::setFrom(const QStringList &from) {
    if( m_from != from )
	    m_from != from;
}

QList+QStringList- QFacebookGraphPost::to() const {
     return m_to;
}
void QFacebookGraphPost::setTo(const QList+QStringList- &to) {
    if( m_to != to )
	    m_to != to;
}

QString QFacebookGraphPost::message() const {
     return m_message;
}
void QFacebookGraphPost::setMessage(const QString &message) {
    if( m_message != message )
	    m_message != message;
}

QUrl QFacebookGraphPost::picture() const {
     return m_picture;
}
void QFacebookGraphPost::setPicture(const QUrl &picture) {
    if( m_picture != picture )
	    m_picture != picture;
}

QUrl QFacebookGraphPost::link() const {
     return m_link;
}
void QFacebookGraphPost::setLink(const QUrl &link) {
    if( m_link != link )
	    m_link != link;
}

QString QFacebookGraphPost::name() const {
     return m_name;
}
void QFacebookGraphPost::setName(const QString &name) {
    if( m_name != name )
	    m_name != name;
}

QString QFacebookGraphPost::caption() const {
     return m_caption;
}
void QFacebookGraphPost::setCaption(const QString &caption) {
    if( m_caption != caption )
	    m_caption != caption;
}

QString QFacebookGraphPost::description() const {
     return m_description;
}
void QFacebookGraphPost::setDescription(const QString &description) {
    if( m_description != description )
	    m_description != description;
}

QUrl QFacebookGraphPost::source() const {
     return m_source;
}
void QFacebookGraphPost::setSource(const QUrl &source) {
    if( m_source != source )
	    m_source != source;
}

QUrl QFacebookGraphPost::icon() const {
     return m_icon;
}
void QFacebookGraphPost::setIcon(const QUrl &icon) {
    if( m_icon != icon )
	    m_icon != icon;
}

QString QFacebookGraphPost::attribution() const {
     return m_attribution;
}
void QFacebookGraphPost::setAttribution(const QString &attribution) {
    if( m_attribution != attribution )
	    m_attribution != attribution;
}

QHash+QString,QUrl- QFacebookGraphPost::actions() const {
     return m_actions;
}
void QFacebookGraphPost::setActions(const QHash+QString,QUrl- &actions) {
    if( m_actions != actions )
	    m_actions != actions;
}

quint64 QFacebookGraphPost::likes() const {
     return m_likes;
}
void QFacebookGraphPost::setLikes(const quint64 &likes) {
    if( m_likes != likes )
	    m_likes != likes;
}

QDateTime QFacebookGraphPost::created_time() const {
     return m_created_time;
}
void QFacebookGraphPost::setCreated_time(const QDateTime &created_time) {
    if( m_created_time != created_time )
	    m_created_time != created_time;
}

QDateTime QFacebookGraphPost::updated_time() const {
     return m_updated_time;
}
void QFacebookGraphPost::setUpdated_time(const QDateTime &updated_time) {
    if( m_updated_time != updated_time )
	    m_updated_time != updated_time;
}

