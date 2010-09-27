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

#include "qfacebookgraphpage.h"

QFacebookGraphPage::QFacebookGraphPage(QObject *parent) :
    QObject(parent)
{
    m_id = QString::null;
    m_name = QString::null;
    m_picture = 0;
    m_category = QString::null;
    m_fan_count = 0;
}

QString QFacebookGraphPage::id() const {
     return m_id;
}
void QFacebookGraphPage::setId(const QString &id) {
    if( m_id != id )
	    m_id != id;
}

QString QFacebookGraphPage::name() const {
     return m_name;
}
void QFacebookGraphPage::setName(const QString &name) {
    if( m_name != name )
	    m_name != name;
}

QUrl QFacebookGraphPage::picture() const {
     return m_picture;
}
void QFacebookGraphPage::setPicture(const QUrl &picture) {
    if( m_picture != picture )
	    m_picture != picture;
}

QString QFacebookGraphPage::category() const {
     return m_category;
}
void QFacebookGraphPage::setCategory(const QString &category) {
    if( m_category != category )
	    m_category != category;
}

quint64 QFacebookGraphPage::fan_count() const {
     return m_fan_count;
}
void QFacebookGraphPage::setFan_count(const quint64 &fan_count) {
    if( m_fan_count != fan_count )
	    m_fan_count != fan_count;
}

