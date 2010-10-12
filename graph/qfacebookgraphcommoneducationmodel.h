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

#ifndef QFACEBOOKGRAPHCOMMONEDUCATIONMODEL_H
#define QFACEBOOKGRAPHCOMMONEDUCATIONMODEL_H

#include <QObject>
#include <QVariantMap>

class QFacebookGraphCommonEducationModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QVariantMap school READ school WRITE setSchool NOTIFY schoolChanged)
    Q_PROPERTY(QVariantMap year READ year WRITE setYear NOTIFY yearChanged)
    Q_PROPERTY(QString type READ type WRITE setType NOTIFY typeChanged)
    Q_PROPERTY(QVariantList concentration READ concentration WRITE setConcentration NOTIFY concentrationChanged())

public:
    explicit QFacebookGraphCommonEducationModel(QObject *parent = 0);

    QVariantMap school() const;
    void setSchool(const QVariantMap school);

    QVariantMap year() const;
    void setYear(const QVariantMap year);

    QString type() const;
    void setType(const QString &type);

    QVariantList concentration() const;
    void setConcentration(const QVariantList concentration);

    void populate(const QVariantMap map);

signals:
    void schoolChanged();
    void typeChanged();
    void yearChanged();
    void concentrationChanged();

private:
    QVariantMap m_school;
    QVariantMap m_year;
    QVariantList m_concentration;
    QString m_type;

};

#endif // QFACEBOOKGRAPHCOMMONEDUCATIONMODEL_H
