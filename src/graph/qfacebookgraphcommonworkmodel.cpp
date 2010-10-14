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

#include "qfacebookgraphcommonworkmodel.h"

QFacebookGraphCommonWorkModel::QFacebookGraphCommonWorkModel(QObject *parent) :
    QObject(parent)
{
    m_description = QString::null;
    m_startDate = QString::null;
    m_endDate = QString::null;
    m_location = QVariantMap();
    m_employer = QVariantMap();
    m_position = QVariantMap();
}

QVariantMap QFacebookGraphCommonWorkModel::employer() const {
    return m_employer;
}
void QFacebookGraphCommonWorkModel::setEmployer(const QVariantMap &employer) {
    if(m_employer != employer) {
        m_employer = employer;
        emit employerChanged();
    }
}

QVariantMap QFacebookGraphCommonWorkModel::position() const {
    return m_position;
}
void QFacebookGraphCommonWorkModel::setPosition(const QVariantMap &position) {
    if(m_position != position) {
        m_position = position;
        emit positionChanged();
    }
}

QVariantMap QFacebookGraphCommonWorkModel::location() const {
    return m_location;
}
void QFacebookGraphCommonWorkModel::setLocation(const QVariantMap &location) {
    if(m_location != location) {
        m_location = location;
        emit locationChanged();
    }
}

QString QFacebookGraphCommonWorkModel::description() const {
    return m_description;
}
void QFacebookGraphCommonWorkModel::setDescription(const QString &description) {
    if(m_description != description) {
        m_description = description;
        emit descriptionChanged();
    }
}

QString QFacebookGraphCommonWorkModel::startDate() const {
    return m_startDate;
}
void QFacebookGraphCommonWorkModel::setStartDate(const QString &startDate) {
    if(m_startDate != startDate) {
        m_startDate = startDate;
        emit startDateChanged();
    }
}

QString QFacebookGraphCommonWorkModel::endDate() const {
    return m_endDate;
}
void QFacebookGraphCommonWorkModel::setEndDate(const QString &endDate) {
    if(m_endDate != endDate) {
        m_endDate = endDate;
        emit endDateChanged();
    }
}

void QFacebookGraphCommonWorkModel::populate(const QVariantMap &map) {
    setLocation(map["location"].toMap());
    setPosition(map["position"].toMap());
    setEmployer(map["employer"].toMap());
    setStartDate(map["start_date"].toString());
    setEndDate(map["end_date"].toString());
    setDescription(map["description"].toString());
}
