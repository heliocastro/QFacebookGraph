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

#include "qfacebookgraphuser.h"

QFacebookGraphUser::QFacebookGraphUser(QObject *parent) :
    QObject(parent)
{
    m_id = QString::null;
    m_first_name = QString::null;
    m_last_name = QString::null;
    m_name = QString::null;
    m_link = 0;
    m_about = QString::null;
    m_birthday = QString::null;
    m_work = 0;
    m_education = 0;
    m_email = QString::null;
    m_website = 0;
    m_hometown = 0;
    m_location = QString::null;
    m_bio = QString::null;
    m_quotes = QString::null;
    m_gender = QString::null;
    m_interested_in = QString::null;
    m_meeting_for = 0;
    m_relationship_status = QString::null;
    m_religion = QString::null;
    m_political = QString::null;
    m_verified = 0;
    m_significant_other = QString::null;
    m_timezone = QString::null;
    m_updated_time = 0;
}

QString QFacebookGraphUser::id() const {
     return m_id;
}
void QFacebookGraphUser::setId(const QString &id) {
    if( m_id != id )
	    m_id != id;
}

QString QFacebookGraphUser::first_name() const {
     return m_first_name;
}
void QFacebookGraphUser::setFirst_name(const QString &first_name) {
    if( m_first_name != first_name )
	    m_first_name != first_name;
}

QString QFacebookGraphUser::last_name() const {
     return m_last_name;
}
void QFacebookGraphUser::setLast_name(const QString &last_name) {
    if( m_last_name != last_name )
	    m_last_name != last_name;
}

QString QFacebookGraphUser::name() const {
     return m_name;
}
void QFacebookGraphUser::setName(const QString &name) {
    if( m_name != name )
	    m_name != name;
}

QUrl QFacebookGraphUser::link() const {
     return m_link;
}
void QFacebookGraphUser::setLink(const QUrl &link) {
    if( m_link != link )
	    m_link != link;
}

QString QFacebookGraphUser::about() const {
     return m_about;
}
void QFacebookGraphUser::setAbout(const QString &about) {
    if( m_about != about )
	    m_about != about;
}

QString QFacebookGraphUser::birthday() const {
     return m_birthday;
}
void QFacebookGraphUser::setBirthday(const QString &birthday) {
    if( m_birthday != birthday )
	    m_birthday != birthday;
}

QStringList QFacebookGraphUser::work() const {
     return m_work;
}
void QFacebookGraphUser::setWork(const QStringList &work) {
    if( m_work != work )
	    m_work != work;
}

QStringList QFacebookGraphUser::education() const {
     return m_education;
}
void QFacebookGraphUser::setEducation(const QStringList &education) {
    if( m_education != education )
	    m_education != education;
}

QString QFacebookGraphUser::email() const {
     return m_email;
}
void QFacebookGraphUser::setEmail(const QString &email) {
    if( m_email != email )
	    m_email != email;
}

QUrl QFacebookGraphUser::website() const {
     return m_website;
}
void QFacebookGraphUser::setWebsite(const QUrl &website) {
    if( m_website != website )
	    m_website != website;
}

QUrl QFacebookGraphUser::hometown() const {
     return m_hometown;
}
void QFacebookGraphUser::setHometown(const QUrl &hometown) {
    if( m_hometown != hometown )
	    m_hometown != hometown;
}

QString QFacebookGraphUser::location() const {
     return m_location;
}
void QFacebookGraphUser::setLocation(const QString &location) {
    if( m_location != location )
	    m_location != location;
}

QString QFacebookGraphUser::bio() const {
     return m_bio;
}
void QFacebookGraphUser::setBio(const QString &bio) {
    if( m_bio != bio )
	    m_bio != bio;
}

QString QFacebookGraphUser::quotes() const {
     return m_quotes;
}
void QFacebookGraphUser::setQuotes(const QString &quotes) {
    if( m_quotes != quotes )
	    m_quotes != quotes;
}

QString QFacebookGraphUser::gender() const {
     return m_gender;
}
void QFacebookGraphUser::setGender(const QString &gender) {
    if( m_gender != gender )
	    m_gender != gender;
}

QString QFacebookGraphUser::interested_in() const {
     return m_interested_in;
}
void QFacebookGraphUser::setInterested_in(const QString &interested_in) {
    if( m_interested_in != interested_in )
	    m_interested_in != interested_in;
}

QStringList QFacebookGraphUser::meeting_for() const {
     return m_meeting_for;
}
void QFacebookGraphUser::setMeeting_for(const QStringList &meeting_for) {
    if( m_meeting_for != meeting_for )
	    m_meeting_for != meeting_for;
}

QString QFacebookGraphUser::relationship_status() const {
     return m_relationship_status;
}
void QFacebookGraphUser::setRelationship_status(const QString &relationship_status) {
    if( m_relationship_status != relationship_status )
	    m_relationship_status != relationship_status;
}

QString QFacebookGraphUser::religion() const {
     return m_religion;
}
void QFacebookGraphUser::setReligion(const QString &religion) {
    if( m_religion != religion )
	    m_religion != religion;
}

QString QFacebookGraphUser::political() const {
     return m_political;
}
void QFacebookGraphUser::setPolitical(const QString &political) {
    if( m_political != political )
	    m_political != political;
}

bool QFacebookGraphUser::verified() const {
     return m_verified;
}
void QFacebookGraphUser::setVerified(const bool &verified) {
    if( m_verified != verified )
	    m_verified != verified;
}

QString QFacebookGraphUser::significant_other() const {
     return m_significant_other;
}
void QFacebookGraphUser::setSignificant_other(const QString &significant_other) {
    if( m_significant_other != significant_other )
	    m_significant_other != significant_other;
}

QString QFacebookGraphUser::timezone() const {
     return m_timezone;
}
void QFacebookGraphUser::setTimezone(const QString &timezone) {
    if( m_timezone != timezone )
	    m_timezone != timezone;
}

QDateTime QFacebookGraphUser::updated_time() const {
     return m_updated_time;
}
void QFacebookGraphUser::setUpdated_time(const QDateTime &updated_time) {
    if( m_updated_time != updated_time )
	    m_updated_time != updated_time;
}

