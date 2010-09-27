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

#ifndef QFACEBOOKGRAPHUSER_H
#define QFACEBOOKGRAPHUSER_H

#include <QObject>
#include <QDateTime>
#include <QString>
#include <QStringList>
#include <QUrl>

class QFacebookGraphUser : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString firstName READ firstName WRITE setFirstname NOTIFY firstNameChanged)
    Q_PROPERTY(QString lastName READ lastName WRITE setLastname NOTIFY lastNameChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QUrl link READ link WRITE setLink NOTIFY linkChanged)
    Q_PROPERTY(QString about READ about WRITE setAbout NOTIFY aboutChanged)
    Q_PROPERTY(QString birthday READ birthday WRITE setBirthday NOTIFY birthdayChanged)
    Q_PROPERTY(QStringList work READ work WRITE setWork NOTIFY workChanged)
    Q_PROPERTY(QStringList education READ education WRITE setEducation NOTIFY educationChanged)
    Q_PROPERTY(QString email READ email WRITE setEmail NOTIFY emailChanged)
    Q_PROPERTY(QUrl website READ website WRITE setWebsite NOTIFY websiteChanged)
    Q_PROPERTY(QUrl hometown READ hometown WRITE setHometown NOTIFY hometownChanged)
    Q_PROPERTY(QString location READ location WRITE setLocation NOTIFY locationChanged)
    Q_PROPERTY(QString bio READ bio WRITE setBio NOTIFY bioChanged)
    Q_PROPERTY(QString quotes READ quotes WRITE setQuotes NOTIFY quotesChanged)
    Q_PROPERTY(QString gender READ gender WRITE setGender NOTIFY genderChanged)
    Q_PROPERTY(QString interestedIn READ interestedIn WRITE setInterestedin NOTIFY interestedInChanged)
    Q_PROPERTY(QStringList meetingFor READ meetingFor WRITE setMeetingfor NOTIFY meetingForChanged)
    Q_PROPERTY(QString relationshipStatus READ relationshipStatus WRITE setRelationshipstatus NOTIFY relationshipStatusChanged)
    Q_PROPERTY(QString religion READ religion WRITE setReligion NOTIFY religionChanged)
    Q_PROPERTY(QString political READ political WRITE setPolitical NOTIFY politicalChanged)
    Q_PROPERTY(bool verified READ verified WRITE setVerified NOTIFY verifiedChanged)
    Q_PROPERTY(QString significantOther READ significantOther WRITE setSignificantother NOTIFY significantOtherChanged)
    Q_PROPERTY(QString timezone READ timezone WRITE setTimezone NOTIFY timezoneChanged)
    Q_PROPERTY(QDateTime updatedTime READ updatedTime WRITE setUpdatedtime NOTIFY updatedTimeChanged)
    
public:
    explicit QFacebookGraphUser(QObject *parent = 0);
	
    QString id() const;
    void setId(const QString &id);

    QString firstName() const;
    void setFirstname(const QString &firstName);

    QString lastName() const;
    void setLastname(const QString &lastName);

    QString name() const;
    void setName(const QString &name);

    QUrl link() const;
    void setLink(const QUrl &link);

    QString about() const;
    void setAbout(const QString &about);

    QString birthday() const;
    void setBirthday(const QString &birthday);

    QStringList work() const;
    void setWork(const QStringList &work);

    QStringList education() const;
    void setEducation(const QStringList &education);

    QString email() const;
    void setEmail(const QString &email);

    QUrl website() const;
    void setWebsite(const QUrl &website);

    QUrl hometown() const;
    void setHometown(const QUrl &hometown);

    QString location() const;
    void setLocation(const QString &location);

    QString bio() const;
    void setBio(const QString &bio);

    QString quotes() const;
    void setQuotes(const QString &quotes);

    QString gender() const;
    void setGender(const QString &gender);

    QString interestedIn() const;
    void setInterestedin(const QString &interestedIn);

    QStringList meetingFor() const;
    void setMeetingfor(const QStringList &meetingFor);

    QString relationshipStatus() const;
    void setRelationshipstatus(const QString &relationshipStatus);

    QString religion() const;
    void setReligion(const QString &religion);

    QString political() const;
    void setPolitical(const QString &political);

    bool verified() const;
    void setVerified(const bool &verified);

    QString significantOther() const;
    void setSignificantother(const QString &significantOther);

    QString timezone() const;
    void setTimezone(const QString &timezone);

    QDateTime updatedTime() const;
    void setUpdatedtime(const QDateTime &updatedTime);

signals:
    void idChanged();
    void firstNameChanged();
    void lastNameChanged();
    void nameChanged();
    void linkChanged();
    void aboutChanged();
    void birthdayChanged();
    void workChanged();
    void educationChanged();
    void emailChanged();
    void websiteChanged();
    void hometownChanged();
    void locationChanged();
    void bioChanged();
    void quotesChanged();
    void genderChanged();
    void interestedInChanged();
    void meetingForChanged();
    void relationshipStatusChanged();
    void religionChanged();
    void politicalChanged();
    void verifiedChanged();
    void significantOtherChanged();
    void timezoneChanged();
    void updatedTimeChanged();

private:
    QString m_id;
    QString m_firstName;
    QString m_lastName;
    QString m_name;
    QUrl m_link;
    QString m_about;
    QString m_birthday;
    QStringList m_work;
    QStringList m_education;
    QString m_email;
    QUrl m_website;
    QUrl m_hometown;
    QString m_location;
    QString m_bio;
    QString m_quotes;
    QString m_gender;
    QString m_interestedIn;
    QStringList m_meetingFor;
    QString m_relationshipStatus;
    QString m_religion;
    QString m_political;
    bool m_verified;
    QString m_significantOther;
    QString m_timezone;
    QDateTime m_updatedTime;

};

#endif //QFACEBOOKGRAPHUSER_H

