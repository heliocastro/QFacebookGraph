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

#include "qfacebookgraphconnectionfeedmodel.h"

QFacebookGraphConnectionFeedModel::QFacebookGraphConnectionFeedModel(QObject *parent) :
    QObject(parent)
{
    m_id = QString::null;
    m_from = 0;
    m_to = 0;
    m_picture = 0;
    m_link = 0;
    m_icon = 0;
    m_name = QString::null;
    m_caption = QString::null;
    m_actions = 0;
    m_type = QString::null;
    m_created_time = 0;
    m_updated_time = 0;
    m_attribution = QString::null;
}

QString QFacebookGraphConnectionFeedModel::id() const {
     return m_id;
}
void QFacebookGraphConnectionFeedModel::setId(const QString &id) {
    if( m_id != id )
	    m_id != id;
}

QStringList QFacebookGraphConnectionFeedModel::from() const {
     return m_from;
}
void QFacebookGraphConnectionFeedModel::setFrom(const QStringList &from) {
    if( m_from != from )
	    m_from != from;
}

QHash QFacebookGraphConnectionFeedModel::to() const {
     return m_to;
}
void QFacebookGraphConnectionFeedModel::setTo(const QHash &to) {
    if( m_to != to )
	    m_to != to;
}

QUrl QFacebookGraphConnectionFeedModel::picture() const {
     return m_picture;
}
void QFacebookGraphConnectionFeedModel::setPicture(const QUrl &picture) {
    if( m_picture != picture )
	    m_picture != picture;
}

QUrl QFacebookGraphConnectionFeedModel::link() const {
     return m_link;
}
void QFacebookGraphConnectionFeedModel::setLink(const QUrl &link) {
    if( m_link != link )
	    m_link != link;
}

QUrl QFacebookGraphConnectionFeedModel::icon() const {
     return m_icon;
}
void QFacebookGraphConnectionFeedModel::setIcon(const QUrl &icon) {
    if( m_icon != icon )
	    m_icon != icon;
}

QString QFacebookGraphConnectionFeedModel::name() const {
     return m_name;
}
void QFacebookGraphConnectionFeedModel::setName(const QString &name) {
    if( m_name != name )
	    m_name != name;
}

QString QFacebookGraphConnectionFeedModel::caption() const {
     return m_caption;
}
void QFacebookGraphConnectionFeedModel::setCaption(const QString &caption) {
    if( m_caption != caption )
	    m_caption != caption;
}

QHash+QString,QUrl- QFacebookGraphConnectionFeedModel::actions() const {
     return m_actions;
}
void QFacebookGraphConnectionFeedModel::setActions(const QHash+QString,QUrl- &actions) {
    if( m_actions != actions )
	    m_actions != actions;
}

QString QFacebookGraphConnectionFeedModel::type() const {
     return m_type;
}
void QFacebookGraphConnectionFeedModel::setType(const QString &type) {
    if( m_type != type )
	    m_type != type;
}

QDateTime QFacebookGraphConnectionFeedModel::created_time() const {
     return m_created_time;
}
void QFacebookGraphConnectionFeedModel::setCreated_time(const QDateTime &created_time) {
    if( m_created_time != created_time )
	    m_created_time != created_time;
}

QDateTime QFacebookGraphConnectionFeedModel::updated_time() const {
     return m_updated_time;
}
void QFacebookGraphConnectionFeedModel::setUpdated_time(const QDateTime &updated_time) {
    if( m_updated_time != updated_time )
	    m_updated_time != updated_time;
}

QString QFacebookGraphConnectionFeedModel::attribution() const {
     return m_attribution;
}
void QFacebookGraphConnectionFeedModel::setAttribution(const QString &attribution) {
    if( m_attribution != attribution )
	    m_attribution != attribution;
}

