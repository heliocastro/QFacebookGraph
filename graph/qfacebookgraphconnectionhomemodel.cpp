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

#include "qfacebookgraphconnectionhomemodel.h"

QFacebookGraphConnectionHomeModel::QFacebookGraphConnectionHomeModel(QObject *parent) :
    QObject(parent)
{
    m_fbid = QString::null;
    m_fromName = QString::null;
    m_fromFbid = QString::null;
    m_message = QString::null;
    m_link = QUrl();
    m_icon = QUrl();
    m_picture = QUrl();
    m_actionsComment = QUrl();
    m_actionsLike = QUrl();
    m_type = QString::null;
    m_createdTime = QString::null;
    m_updatedTime = QString::null;
    m_attribution = QString::null;
    m_caption = QString::null;
    m_description = QString::null;
}

QString QFacebookGraphConnectionHomeModel::fbid() const {
    return m_fbid;
}
void QFacebookGraphConnectionHomeModel::setFbid(const QString &fbid) {
    if( m_fbid != fbid )
    {
        m_fbid = fbid;
        emit fbidChanged();
    }
}

QString QFacebookGraphConnectionHomeModel::fromName() const {
    return m_fromName;
}

void QFacebookGraphConnectionHomeModel::setFromName(const QString &fromName) {
    if( m_fromName != fromName ) {
        m_fromName = fromName;
        emit fromNameChanged();
    }
}

QString QFacebookGraphConnectionHomeModel::fromFbid() const {
    return m_fromFbid;
}

void QFacebookGraphConnectionHomeModel::setFromFbid(const QString &fromFbid) {
    if( m_fromFbid != fromFbid ) {
        m_fromFbid = fromFbid;
        emit fromFbidChanged();
    }
}

QString QFacebookGraphConnectionHomeModel::message() const {
    return m_message;
}
void QFacebookGraphConnectionHomeModel::setMessage(const QString &message) {
    if( m_message != message ) {
        m_message = message;
        emit messageChanged();
    }
}

QUrl QFacebookGraphConnectionHomeModel::link() const {
    return m_link;
}
void QFacebookGraphConnectionHomeModel::setLink(const QUrl &link) {
    if( m_link != link ) {
        m_link = link;
        emit linkChanged();
    }
}

QUrl QFacebookGraphConnectionHomeModel::icon() const {
    return m_icon;
}
void QFacebookGraphConnectionHomeModel::setIcon(const QUrl &icon) {
    if( m_icon != icon ) {
        m_icon = icon;
        emit iconChanged();
    }
}

QUrl QFacebookGraphConnectionHomeModel::picture() const {
    return m_picture;
}
void QFacebookGraphConnectionHomeModel::setPicture(const QUrl &picture) {
    if( m_picture != picture ) {
        m_picture = picture;
        emit pictureChanged();
    }
}

QUrl QFacebookGraphConnectionHomeModel::actionsComment() const {
    return m_actionsComment;
}
void QFacebookGraphConnectionHomeModel::setActionsComment(const QUrl &actionsComment) {
    if( m_actionsComment != actionsComment ) {
        m_actionsComment = actionsComment;
        emit actionsCommentChanged();
    }
}

QUrl QFacebookGraphConnectionHomeModel::actionsLike() const {
    return m_actionsLike;
}
void QFacebookGraphConnectionHomeModel::setActionsLike(const QUrl &actionsLike) {
    if( m_actionsLike != actionsLike ) {
        m_actionsLike = actionsLike;
        emit actionsLikeChanged();
    }
}

QString QFacebookGraphConnectionHomeModel::type() const {
    return m_type;
}
void QFacebookGraphConnectionHomeModel::setType(const QString &type) {
    if( m_type != type ) {
        m_type = type;
        emit typeChanged();
    }
}

QString QFacebookGraphConnectionHomeModel::createdTime() const {
    return m_createdTime;
}
void QFacebookGraphConnectionHomeModel::setCreatedtime(const QString &createdTime) {
    if( m_createdTime != createdTime ) {
        m_createdTime = createdTime;
        emit createdTimeChanged();
    }
}

QString QFacebookGraphConnectionHomeModel::updatedTime() const {
    return m_updatedTime;
}
void QFacebookGraphConnectionHomeModel::setUpdatedtime(const QString &updatedTime) {
    if( m_updatedTime != updatedTime ) {
        m_updatedTime = updatedTime;
        emit updatedTimeChanged();
    }
}

QString QFacebookGraphConnectionHomeModel::attribution() const {
    return m_attribution;
}
void QFacebookGraphConnectionHomeModel::setAttribution(const QString &attribution) {
    if( m_attribution != attribution ) {
        m_attribution = attribution;
        emit attributionChanged();
    }
}

qulonglong QFacebookGraphConnectionHomeModel::likes() const {
    return m_likes;
}
void QFacebookGraphConnectionHomeModel::setLikes(qulonglong likes) {
    if( m_likes != likes ) {
        m_likes = likes;
        emit likesChanged();
    }
}

QString QFacebookGraphConnectionHomeModel::description() const {
    return m_description;
}
void QFacebookGraphConnectionHomeModel::setDescription(const QString &description) {
    if( m_description != description )
    {
        m_description = description;
        emit descriptionChanged();
    }
}

QString QFacebookGraphConnectionHomeModel::caption() const {
    return m_caption;
}
void QFacebookGraphConnectionHomeModel::setCaption(const QString &caption) {
    if( m_caption != caption )
    {
        m_caption = caption;
        emit captionChanged();
    }
}
