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

#include <graph/qfacebookgraphcommonfeedmodel.h>

QFacebookGraphCommonFeedModel::QFacebookGraphCommonFeedModel(QObject *parent) :
    QObject(parent)
{
    m_fbid = QString::null;
    m_from = QVariantMap();
    m_to = QVariantList();
    m_message = QString::null;
    m_link = QUrl();
    m_icon = QUrl();
    m_picture = QUrl();
    m_actions = QVariantList();
    m_comments = QVariantList();
    m_type = QString::null;
    m_createdTime = QString::null;
    m_updatedTime = QString::null;
    m_attribution = QString::null;
    m_caption = QString::null;
    m_description = QString::null;
    m_likes = 0;
    m_count = 0;
}

QString QFacebookGraphCommonFeedModel::fbid() const {
    return m_fbid;
}
void QFacebookGraphCommonFeedModel::setFbid(const QString &fbid) {
    if( m_fbid != fbid )
    {
        m_fbid = fbid;
        emit fbidChanged();
    }
}

QVariantMap QFacebookGraphCommonFeedModel::from() const {
    return m_from;
}
void QFacebookGraphCommonFeedModel::setFrom(const QVariantMap &from) {
    if( m_from != from ) {
        m_from = from;
        emit fromChanged();
    }
}

QVariantList QFacebookGraphCommonFeedModel::to() const {
    return m_to;
}
void QFacebookGraphCommonFeedModel::setTo(const QVariantList &to) {
    if( m_to != to ) {
        m_to = to;
        emit toChanged();
    }
}

QString QFacebookGraphCommonFeedModel::message() const {
    return m_message;
}
void QFacebookGraphCommonFeedModel::setMessage(const QString &message) {
    if( m_message != message ) {
        m_message = message;
        emit messageChanged();
    }
}

QUrl QFacebookGraphCommonFeedModel::link() const {
    return m_link;
}
void QFacebookGraphCommonFeedModel::setLink(const QUrl &link) {
    if( m_link != link ) {
        m_link = link;
        emit linkChanged();
    }
}

QUrl QFacebookGraphCommonFeedModel::icon() const {
    return m_icon;
}
void QFacebookGraphCommonFeedModel::setIcon(const QUrl &icon) {
    if( m_icon != icon ) {
        m_icon = icon;
        emit iconChanged();
    }
}

QUrl QFacebookGraphCommonFeedModel::picture() const {
    return m_picture;
}
void QFacebookGraphCommonFeedModel::setPicture(const QUrl &picture) {
    if( m_picture != picture ) {
        m_picture = picture;
        emit pictureChanged();
    }
}

QVariantList QFacebookGraphCommonFeedModel::actions() const {
    return m_actions;
}
void QFacebookGraphCommonFeedModel::setActions(const QVariantList &actions) {
    if(m_actions != actions)
    {
        m_actions = actions;
        emit actionsChanged();
    }
}

QVariantList QFacebookGraphCommonFeedModel::comments() const {
    return m_comments;
}
void QFacebookGraphCommonFeedModel::setComments(const QVariantList &comments) {
    if(m_comments != comments)
    {
        m_comments = comments;
        emit commentsChanged();
    }
}

QString QFacebookGraphCommonFeedModel::type() const {
    return m_type;
}
void QFacebookGraphCommonFeedModel::setType(const QString &type) {
    if( m_type != type ) {
        m_type = type;
        emit typeChanged();
    }
}

QString QFacebookGraphCommonFeedModel::createdTime() const {
    return m_createdTime;
}
void QFacebookGraphCommonFeedModel::setCreatedtime(const QString &createdTime) {
    if( m_createdTime != createdTime ) {
        m_createdTime = createdTime;
        emit createdTimeChanged();
    }
}

QString QFacebookGraphCommonFeedModel::updatedTime() const {
    return m_updatedTime;
}
void QFacebookGraphCommonFeedModel::setUpdatedtime(const QString &updatedTime) {
    if( m_updatedTime != updatedTime ) {
        m_updatedTime = updatedTime;
        emit updatedTimeChanged();
    }
}

QString QFacebookGraphCommonFeedModel::attribution() const {
    return m_attribution;
}
void QFacebookGraphCommonFeedModel::setAttribution(const QString &attribution) {
    if( m_attribution != attribution ) {
        m_attribution = attribution;
        emit attributionChanged();
    }
}

qulonglong QFacebookGraphCommonFeedModel::likes() const {
    return m_likes;
}
void QFacebookGraphCommonFeedModel::setLikes(qulonglong likes) {
    if( m_likes != likes ) {
        m_likes = likes;
        emit likesChanged();
    }
}

qulonglong QFacebookGraphCommonFeedModel::count() const {
    return m_count;
}
void QFacebookGraphCommonFeedModel::setCount(qulonglong count) {
    if( m_count != count ) {
        m_count = count;
        emit countChanged();
    }
}

QString QFacebookGraphCommonFeedModel::description() const {
    return m_description;
}
void QFacebookGraphCommonFeedModel::setDescription(const QString &description) {
    if( m_description != description )
    {
        m_description = description;
        emit descriptionChanged();
    }
}

QString QFacebookGraphCommonFeedModel::caption() const {
    return m_caption;
}
void QFacebookGraphCommonFeedModel::setCaption(const QString &caption) {
    if( m_caption != caption )
    {
        m_caption = caption;
        emit captionChanged();
    }
}
