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

#include "qfacebookgraphsubscription.h"

QFacebookGraphSubscription::QFacebookGraphSubscription(QObject *parent) :
    QObject(parent)
{
    m_object = QString::null;
    m_fields = 0;
    m_callback_url = 0;
    m_active = 0;
}

QString QFacebookGraphSubscription::object() const {
     return m_object;
}
void QFacebookGraphSubscription::setObject(const QString &object) {
    if( m_object != object )
	    m_object != object;
}

QStringList QFacebookGraphSubscription::fields() const {
     return m_fields;
}
void QFacebookGraphSubscription::setFields(const QStringList &fields) {
    if( m_fields != fields )
	    m_fields != fields;
}

QUrl QFacebookGraphSubscription::callback_url() const {
     return m_callback_url;
}
void QFacebookGraphSubscription::setCallback_url(const QUrl &callback_url) {
    if( m_callback_url != callback_url )
	    m_callback_url != callback_url;
}

bool QFacebookGraphSubscription::active() const {
     return m_active;
}
void QFacebookGraphSubscription::setActive(const bool &active) {
    if( m_active != active )
	    m_active != active;
}

