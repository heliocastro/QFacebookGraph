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

#include <graph/qfacebookgraphcommonmediamodel.h>

QFacebookGraphCommonMediaModel::QFacebookGraphCommonMediaModel(QObject *parent) :
    QObject(parent)
{
    m_fbid = QString::null;
    m_name = QString::null;
    m_category = QString();
    m_createdTime = QDateTime();
}

QString QFacebookGraphCommonMediaModel::fbid() const {
    return m_fbid;
}
void QFacebookGraphCommonMediaModel::setFbid(const QString &fbid) {
    if( m_fbid != fbid )
    {
        m_fbid = fbid;
        emit fbidChanged();
    }
}

QString QFacebookGraphCommonMediaModel::name() const {
    return m_name;
}
void QFacebookGraphCommonMediaModel::setName(const QString &name) {
    if( m_name != name ) {
        m_name = name;
        emit nameChanged();
    }
}


QString QFacebookGraphCommonMediaModel::category() const {
    return m_category;
}
void QFacebookGraphCommonMediaModel::setCategory(const QString &category) {
    if( m_category != category ) {
        m_category = category;
        emit categoryChanged();
    }
}

QDateTime QFacebookGraphCommonMediaModel::createdTime() const {
    return m_createdTime;
}
void QFacebookGraphCommonMediaModel::setCreatedTime(const QDateTime &createdTime) {
    if( m_createdTime != createdTime ) {
        m_createdTime = createdTime;
        emit createdTimeChanged();
    }
}
