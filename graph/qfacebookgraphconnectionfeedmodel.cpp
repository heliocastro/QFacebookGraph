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
    m_from = QStringList();
    m_to = QHashTo();
    m_picture = QUrl();
    m_link = QUrl();
    m_icon = QUrl();
    m_name = QString::null;
    m_caption = QString::null;
    m_actions = QHashActions();
    m_type = QString::null;
    m_createdTime = QDateTime();
    m_updatedTime = QDateTime();
    m_attribution = QString::null;
}

QString QFacebookGraphConnectionFeedModel::id() const {
    return m_id;
}
void QFacebookGraphConnectionFeedModel::setId(const QString &id) {
    if( m_id != id )
        m_id = id;
}

QStringList QFacebookGraphConnectionFeedModel::from() const {
    return m_from;
}
void QFacebookGraphConnectionFeedModel::setFrom(const QStringList &from) {
    if( m_from != from )
        m_from = from;
}

QHashTo QFacebookGraphConnectionFeedModel::to() const {
    return m_to;
}
void QFacebookGraphConnectionFeedModel::setTo(const QHashTo &to) {
    if( m_to != to )
        m_to = to;
}

QUrl QFacebookGraphConnectionFeedModel::picture() const {
    return m_picture;
}
void QFacebookGraphConnectionFeedModel::setPicture(const QUrl &picture) {
    if( m_picture != picture )
        m_picture = picture;
}

QUrl QFacebookGraphConnectionFeedModel::link() const {
    return m_link;
}
void QFacebookGraphConnectionFeedModel::setLink(const QUrl &link) {
    if( m_link != link )
        m_link = link;
}

QUrl QFacebookGraphConnectionFeedModel::icon() const {
    return m_icon;
}
void QFacebookGraphConnectionFeedModel::setIcon(const QUrl &icon) {
    if( m_icon != icon )
        m_icon = icon;
}

QString QFacebookGraphConnectionFeedModel::name() const {
    return m_name;
}
void QFacebookGraphConnectionFeedModel::setName(const QString &name) {
    if( m_name != name )
        m_name = name;
}

QString QFacebookGraphConnectionFeedModel::caption() const {
    return m_caption;
}
void QFacebookGraphConnectionFeedModel::setCaption(const QString &caption) {
    if( m_caption != caption )
        m_caption = caption;
}

QHashActions QFacebookGraphConnectionFeedModel::actions() const {
    return m_actions;
}
void QFacebookGraphConnectionFeedModel::setActions(const QHashActions &actions) {
    if( m_actions != actions )
        m_actions = actions;
}

QString QFacebookGraphConnectionFeedModel::type() const {
    return m_type;
}
void QFacebookGraphConnectionFeedModel::setType(const QString &type) {
    if( m_type != type )
        m_type = type;
}

QDateTime QFacebookGraphConnectionFeedModel::createdTime() const {
    return m_createdTime;
}
void QFacebookGraphConnectionFeedModel::setCreatedtime(const QDateTime &createdTime) {
    if( m_createdTime != createdTime )
        m_createdTime = createdTime;
}

QDateTime QFacebookGraphConnectionFeedModel::updatedTime() const {
    return m_updatedTime;
}
void QFacebookGraphConnectionFeedModel::setUpdatedtime(const QDateTime &updatedTime) {
    if( m_updatedTime != updatedTime )
        m_updatedTime = updatedTime;
}

QString QFacebookGraphConnectionFeedModel::attribution() const {
    return m_attribution;
}
void QFacebookGraphConnectionFeedModel::setAttribution(const QString &attribution) {
    if( m_attribution != attribution )
        m_attribution = attribution;
}

