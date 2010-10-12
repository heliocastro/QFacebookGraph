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

#ifndef QFACEBOOKGRAPHCOMMONWORKMODEL_H
#define QFACEBOOKGRAPHCOMMONWORKMODEL_H

#include <QObject>
#include <QVariantMap>
#include <QString>

class QFacebookGraphCommonWorkModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QVariantMap employer READ employer WRITE setEmployer NOTIFY employerChanged)
    Q_PROPERTY(QVariantMap position READ position WRITE setPosition NOTIFY positionChanged)
    Q_PROPERTY(QVariantMap location READ location WRITE setLocation NOTIFY locationChanged)
    Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged)
    Q_PROPERTY(QString startDate READ startDate WRITE setStartDate NOTIFY startDateChanged)
    Q_PROPERTY(QString endDate READ endDate WRITE setEndDate NOTIFY endDateChanged)

public:
    explicit QFacebookGraphCommonWorkModel(QObject *parent = 0);

    QVariantMap employer() const;
    void setEmployer(const QVariantMap &employer);

    QVariantMap position() const;
    void setPosition(const QVariantMap &position);

    QVariantMap location() const;
    void setLocation(const QVariantMap &location);

    QString description() const;
    void setDescription(const QString &description);

    QString startDate() const;
    void setStartDate(const QString &startDate);

    QString endDate() const;
    void setEndDate(const QString &endDate);

    void populate(const QVariantMap &map);

signals:
    void employerChanged();
    void positionChanged();
    void locationChanged();
    void descriptionChanged();
    void startDateChanged();
    void endDateChanged();

private:
    QVariantMap m_employer;
    QVariantMap m_position;
    QVariantMap m_location;
    QString m_description;
    QString m_startDate;
    QString m_endDate;
};

#endif // QFACEBOOKGRAPHCOMMONWORKMODEL_H
