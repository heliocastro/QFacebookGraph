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
    m_id = QString::null;
    m_from = QStringList();
    m_message = QString::null;
    m_link = QUrl();
    m_icon = QUrl();
    m_actions = QHashActions();
    m_type = QString::null;
    m_createdTime = QDateTime();
    m_updatedTime = QDateTime();
    m_attribution = QString::null;
}

QString QFacebookGraphConnectionHomeModel::id() const {
     return m_id;
}
void QFacebookGraphConnectionHomeModel::setId(const QString &id) {
    if( m_id != id )
	    m_id = id;
}

QStringList QFacebookGraphConnectionHomeModel::from() const {
     return m_from;
}
void QFacebookGraphConnectionHomeModel::setFrom(const QStringList &from) {
    if( m_from != from )
	    m_from = from;
}

QString QFacebookGraphConnectionHomeModel::message() const {
     return m_message;
}
void QFacebookGraphConnectionHomeModel::setMessage(const QString &message) {
    if( m_message != message )
	    m_message = message;
}

QUrl QFacebookGraphConnectionHomeModel::link() const {
     return m_link;
}
void QFacebookGraphConnectionHomeModel::setLink(const QUrl &link) {
    if( m_link != link )
	    m_link = link;
}

QUrl QFacebookGraphConnectionHomeModel::icon() const {
     return m_icon;
}
void QFacebookGraphConnectionHomeModel::setIcon(const QUrl &icon) {
    if( m_icon != icon )
	    m_icon = icon;
}

QHashActions QFacebookGraphConnectionHomeModel::actions() const {
     return m_actions;
}
void QFacebookGraphConnectionHomeModel::setActions(const QHashActions &actions) {
    if( m_actions != actions )
	    m_actions = actions;
}

QString QFacebookGraphConnectionHomeModel::type() const {
     return m_type;
}
void QFacebookGraphConnectionHomeModel::setType(const QString &type) {
    if( m_type != type )
	    m_type = type;
}

QDateTime QFacebookGraphConnectionHomeModel::createdTime() const {
     return m_createdTime;
}
void QFacebookGraphConnectionHomeModel::setCreatedtime(const QDateTime &createdTime) {
    if( m_createdTime != createdTime )
	    m_createdTime = createdTime;
}

QDateTime QFacebookGraphConnectionHomeModel::updatedTime() const {
     return m_updatedTime;
}
void QFacebookGraphConnectionHomeModel::setUpdatedtime(const QDateTime &updatedTime) {
    if( m_updatedTime != updatedTime )
	    m_updatedTime = updatedTime;
}

QString QFacebookGraphConnectionHomeModel::attribution() const {
     return m_attribution;
}
void QFacebookGraphConnectionHomeModel::setAttribution(const QString &attribution) {
    if( m_attribution != attribution )
	    m_attribution = attribution;
}

