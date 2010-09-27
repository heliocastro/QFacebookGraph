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

#include "qfacebookgraphapplication.h"

QFacebookGraphApplication::QFacebookGraphApplication(QObject *parent) :
    QObject(parent)
{
    m_id = QString::null;
    m_name = QString::null;
    m_description = QString::null;
    m_category = QString::null;
    m_link = QUrl();
}

QString QFacebookGraphApplication::id() const {
     return m_id;
}
void QFacebookGraphApplication::setId(const QString &id) {
    if( m_id != id )
	    m_id = id;
}

QString QFacebookGraphApplication::name() const {
     return m_name;
}
void QFacebookGraphApplication::setName(const QString &name) {
    if( m_name != name )
	    m_name = name;
}

QString QFacebookGraphApplication::description() const {
     return m_description;
}
void QFacebookGraphApplication::setDescription(const QString &description) {
    if( m_description != description )
	    m_description = description;
}

QString QFacebookGraphApplication::category() const {
     return m_category;
}
void QFacebookGraphApplication::setCategory(const QString &category) {
    if( m_category != category )
	    m_category = category;
}

QUrl QFacebookGraphApplication::link() const {
     return m_link;
}
void QFacebookGraphApplication::setLink(const QUrl &link) {
    if( m_link != link )
	    m_link = link;
}

