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

#include <QDebug>
#include "qfacebookgraphcommoneducationmodel.h"

QFacebookGraphCommonEducationModel::QFacebookGraphCommonEducationModel(QObject *parent) :
    QObject(parent)
{
    m_school = QVariantMap();
}


QVariantMap QFacebookGraphCommonEducationModel::school() const {
    return m_school;
}

void QFacebookGraphCommonEducationModel::setSchool(const QVariantMap school) {
    if(m_school != school) {
        m_school = school;
        emit schoolChanged();
    }
}

QVariantMap QFacebookGraphCommonEducationModel::year() const {
    return m_year;
}

void QFacebookGraphCommonEducationModel::setYear(const QVariantMap year) {
    if(m_year != year) {
        m_year = year;
        emit yearChanged();
    }
}

QVariantList QFacebookGraphCommonEducationModel::concentration() const {
    return m_concentration;
}

void QFacebookGraphCommonEducationModel::setConcentration(const QVariantList concentration) {
    if(m_concentration != concentration) {
        m_concentration = concentration;
        emit concentrationChanged();
    }
}

QString QFacebookGraphCommonEducationModel::type() const {
    return m_type;
}

void QFacebookGraphCommonEducationModel::setType(const QString &type) {
    if(m_type != type) {
        m_type = type;
        emit typeChanged();
    }
}


void QFacebookGraphCommonEducationModel::populate(const QVariantMap &map) {
    setSchool(map["school"].toMap());
    setYear(map["year"].toMap());
    setConcentration(map["concentration"].toList());
    setType(map["type"].toString());
}

