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
    m_fbid = QString::null;
    m_fromName = QString::null;
    m_fromFbid = QString::null;
    m_message = QString::null;
    m_link = QUrl();
    m_icon = QUrl();
    m_picture = QUrl();
    m_actions = QHashActions();
    m_type = QString::null;
    m_createdTime = QString::null;
    m_updatedTime = QString::null;
    m_attribution = QString::null;
    m_caption = QString::null;
    m_description = QString::null;
}

QString QFacebookGraphConnectionFeedModel::fbid() const {
    return m_fbid;
}
void QFacebookGraphConnectionFeedModel::setFbid(const QString &fbid) {
    if( m_fbid != fbid )
    {
        m_fbid = fbid;
        emit fbidChanged();
    }
}

QString QFacebookGraphConnectionFeedModel::fromName() const {
    return m_fromName;
}

void QFacebookGraphConnectionFeedModel::setFromName(const QString &fromName) {
    if( m_fromName != fromName ) {
        m_fromName = fromName;
        emit fromNameChanged();
    }
}

QString QFacebookGraphConnectionFeedModel::fromFbid() const {
    return m_fromFbid;
}

void QFacebookGraphConnectionFeedModel::setFromFbid(const QString &fromFbid) {
    if( m_fromFbid != fromFbid ) {
        m_fromFbid = fromFbid;
        emit fromFbidChanged();
    }
}

QString QFacebookGraphConnectionFeedModel::message() const {
    return m_message;
}
void QFacebookGraphConnectionFeedModel::setMessage(const QString &message) {
    if( m_message != message ) {
        m_message = message;
        emit messageChanged();
    }
}

QUrl QFacebookGraphConnectionFeedModel::link() const {
    return m_link;
}
void QFacebookGraphConnectionFeedModel::setLink(const QUrl &link) {
    if( m_link != link ) {
        m_link = link;
        emit linkChanged();
    }
}

QUrl QFacebookGraphConnectionFeedModel::icon() const {
    return m_icon;
}
void QFacebookGraphConnectionFeedModel::setIcon(const QUrl &icon) {
    if( m_icon != icon ) {
        m_icon = icon;
        emit iconChanged();
    }
}

QUrl QFacebookGraphConnectionFeedModel::picture() const {
    return m_picture;
}
void QFacebookGraphConnectionFeedModel::setPicture(const QUrl &picture) {
    if( m_picture != picture ) {
        m_picture = picture;
        emit pictureChanged();
    }
}

QHashActions QFacebookGraphConnectionFeedModel::actions() const {
    return m_actions;
}
void QFacebookGraphConnectionFeedModel::setActions(const QHashActions &actions) {
    if( m_actions != actions ) {
        m_actions = actions;
        emit actionsChanged();
    }
}

QString QFacebookGraphConnectionFeedModel::type() const {
    return m_type;
}
void QFacebookGraphConnectionFeedModel::setType(const QString &type) {
    if( m_type != type ) {
        m_type = type;
        emit typeChanged();
    }
}

QString QFacebookGraphConnectionFeedModel::createdTime() const {
    return m_createdTime;
}
void QFacebookGraphConnectionFeedModel::setCreatedtime(const QString &createdTime) {
    if( m_createdTime != createdTime ) {
        m_createdTime = createdTime;
        emit createdTimeChanged();
    }
}

QString QFacebookGraphConnectionFeedModel::updatedTime() const {
    return m_updatedTime;
}
void QFacebookGraphConnectionFeedModel::setUpdatedtime(const QString &updatedTime) {
    if( m_updatedTime != updatedTime ) {
        m_updatedTime = updatedTime;
        emit updatedTimeChanged();
    }
}

QString QFacebookGraphConnectionFeedModel::attribution() const {
    return m_attribution;
}
void QFacebookGraphConnectionFeedModel::setAttribution(const QString &attribution) {
    if( m_attribution != attribution ) {
        m_attribution = attribution;
        emit attributionChanged();
    }
}

qulonglong QFacebookGraphConnectionFeedModel::likes() const {
    return m_likes;
}
void QFacebookGraphConnectionFeedModel::setLikes(qulonglong likes) {
    if( m_likes != likes ) {
        m_likes = likes;
        emit likesChanged();
    }
}

QString QFacebookGraphConnectionFeedModel::description() const {
    return m_description;
}
void QFacebookGraphConnectionFeedModel::setDescription(const QString &description) {
    if( m_description != description )
    {
        m_description = description;
        emit descriptionChanged();
    }
}

QString QFacebookGraphConnectionFeedModel::caption() const {
    return m_caption;
}
void QFacebookGraphConnectionFeedModel::setCaption(const QString &caption) {
    if( m_caption != caption )
    {
        m_caption = caption;
        emit captionChanged();
    }
}
