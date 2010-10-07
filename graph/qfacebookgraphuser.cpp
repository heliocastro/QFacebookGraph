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

#include "qfacebookgraphuser.h"

QFacebookGraphUser::QFacebookGraphUser(QObject *parent) :
    QFacebookGraph(parent)
{
}

QFacebookGraphUser::QFacebookGraphUser(QString token, const QString &user, QObject *parent) :
    QFacebookGraph(token, parent)
{
    m_user = user;
    m_fbid = QString::null;
    m_firstName = QString::null;
    m_lastName = QString::null;
    m_name = QString::null;
    m_link = QUrl();
    m_about = QString::null;
    m_birthday = QString::null;
    m_work = QStringList();
    m_education = QStringList();
    m_email = QString::null;
    m_website = QUrl();
    m_hometown = QUrl();
    m_location = QString::null;
    m_bio = QString::null;
    m_quotes = QString::null;
    m_gender = QString::null;
    m_interestedIn = QString::null;
    m_meetingFor = QStringList();
    m_relationshipStatus = QString::null;
    m_religion = QString::null;
    m_political = QString::null;
    m_verified = 0;
    m_significantOther = QString::null;
    m_timezone = QString::null;
    m_updatedTime = QString::null;
    update();
}

void QFacebookGraphUser::update() {
    QUrl url = baseUrl();
    if(m_user.isNull())
        url.setEncodedPath("/me");
    else
    {
        QString path("/" + m_user);
        url.setEncodedPath(path.toAscii());
    }
    Get( url );
}

void QFacebookGraphUser::requestDone(bool ok) {
    if(ok)
    {
        emit modelPopulated();
    }
}

QString QFacebookGraphUser::fbid() const {
    return m_fbid;
}
void QFacebookGraphUser::setFbid(const QString &fbid) {
    if( m_fbid != fbid ) {
        m_fbid = fbid;
        emit fbidChanged();
    }
}

QString QFacebookGraphUser::firstName() const {
    return m_firstName;
}
void QFacebookGraphUser::setFirstname(const QString &firstName) {
    if( m_firstName != firstName ) {
        m_firstName = firstName;
        emit firstNameChanged();
    }
}

QString QFacebookGraphUser::lastName() const {
    return m_lastName;
}
void QFacebookGraphUser::setLastname(const QString &lastName) {
    if( m_lastName != lastName ) {
        m_lastName = lastName;
        emit lastNameChanged();
    }
}

QString QFacebookGraphUser::name() const {
    return m_name;
}
void QFacebookGraphUser::setName(const QString &name) {
    if( m_name != name ) {
        m_name = name;
        emit nameChanged();
    }
}

QUrl QFacebookGraphUser::link() const {
    return m_link;
}
void QFacebookGraphUser::setLink(const QUrl &link) {
    if( m_link != link ) {
        m_link = link;
        emit linkChanged();
    }
}

QString QFacebookGraphUser::about() const {
    return m_about;
}
void QFacebookGraphUser::setAbout(const QString &about) {
    if( m_about != about ) {
        m_about = about;
        emit aboutChanged();
    }
}

QString QFacebookGraphUser::birthday() const {
    return m_birthday;
}
void QFacebookGraphUser::setBirthday(const QString &birthday) {
    if( m_birthday != birthday ) {
        m_birthday = birthday;
        emit birthdayChanged();
    }
}

QStringList QFacebookGraphUser::work() const {
    return m_work;
}
void QFacebookGraphUser::setWork(const QStringList &work) {
    if( m_work != work ) {
        m_work = work;
        emit workChanged();
    }
}

QStringList QFacebookGraphUser::education() const {
    return m_education;
}
void QFacebookGraphUser::setEducation(const QStringList &education) {
    if( m_education != education ) {
        m_education = education;
        emit educationChanged();
    }
}

QString QFacebookGraphUser::email() const {
    return m_email;
}
void QFacebookGraphUser::setEmail(const QString &email) {
    if( m_email != email ) {
        m_email = email;
        emit emailChanged();
    }
}

QUrl QFacebookGraphUser::website() const {
    return m_website;
}
void QFacebookGraphUser::setWebsite(const QUrl &website) {
    if( m_website != website ) {
        m_website = website;
        emit websiteChanged();
    }
}

QUrl QFacebookGraphUser::hometown() const {
    return m_hometown;
}
void QFacebookGraphUser::setHometown(const QUrl &hometown) {
    if( m_hometown != hometown ) {
        m_hometown = hometown;
        emit hometownChanged();
    }
}

QString QFacebookGraphUser::location() const {
    return m_location;
}
void QFacebookGraphUser::setLocation(const QString &location) {
    if( m_location != location ) {
        m_location = location;
        emit locationChanged();
    }
}

QString QFacebookGraphUser::bio() const {
    return m_bio;
}
void QFacebookGraphUser::setBio(const QString &bio) {
    if( m_bio != bio ) {
        m_bio = bio;
        emit bioChanged();
    }
}

QString QFacebookGraphUser::quotes() const {
    return m_quotes;
}
void QFacebookGraphUser::setQuotes(const QString &quotes) {
    if( m_quotes != quotes ) {
        m_quotes = quotes;
        emit quotesChanged();
    }
}

QString QFacebookGraphUser::gender() const {
    return m_gender;
}
void QFacebookGraphUser::setGender(const QString &gender) {
    if( m_gender != gender ) {
        m_gender = gender;
        emit genderChanged();
    }
}

QString QFacebookGraphUser::interestedIn() const {
    return m_interestedIn;
}
void QFacebookGraphUser::setInterestedin(const QString &interestedIn) {
    if( m_interestedIn != interestedIn ) {
        m_interestedIn = interestedIn;
        emit interestedInChanged();
    }
}

QStringList QFacebookGraphUser::meetingFor() const {
    return m_meetingFor;
}
void QFacebookGraphUser::setMeetingfor(const QStringList &meetingFor) {
    if( m_meetingFor != meetingFor ) {
        m_meetingFor = meetingFor;
        emit meetingForChanged();
    }
}

QString QFacebookGraphUser::relationshipStatus() const {
    return m_relationshipStatus;
}
void QFacebookGraphUser::setRelationshipstatus(const QString &relationshipStatus) {
    if( m_relationshipStatus != relationshipStatus ) {
        m_relationshipStatus = relationshipStatus;
        emit relationshipStatusChanged();
    }
}
QString QFacebookGraphUser::religion() const {
    return m_religion;
}
void QFacebookGraphUser::setReligion(const QString &religion) {
    if( m_religion != religion ) {
        m_religion = religion;
        emit religionChanged();
    }
}

QString QFacebookGraphUser::political() const {
    return m_political;
}
void QFacebookGraphUser::setPolitical(const QString &political) {
    if( m_political != political ) {
        m_political = political;
        emit politicalChanged();
    }
}

bool QFacebookGraphUser::verified() const {
    return m_verified;
}
void QFacebookGraphUser::setVerified(const bool &verified) {
    if( m_verified != verified ) {
        m_verified = verified;
        emit verifiedChanged();
    }
}

QString QFacebookGraphUser::significantOther() const {
    return m_significantOther;
}
void QFacebookGraphUser::setSignificantother(const QString &significantOther) {
    if( m_significantOther != significantOther ) {
        m_significantOther = significantOther;
        emit significantOtherChanged();
    }
}

QString QFacebookGraphUser::timezone() const {
    return m_timezone;
}
void QFacebookGraphUser::setTimezone(const QString &timezone) {
    if( m_timezone != timezone ) {
        m_timezone = timezone;
        emit timezoneChanged();
    }
}

QString QFacebookGraphUser::updatedTime() const {
    return m_updatedTime;
}
void QFacebookGraphUser::setUpdatedtime(const QString &updatedTime) {
    if( m_updatedTime != updatedTime ) {
        m_updatedTime = updatedTime;
        updatedTimeChanged();
    }
}
