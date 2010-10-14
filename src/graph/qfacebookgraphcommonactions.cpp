#include "qfacebookgraphcommonactions.h"

QFacebookGraphCommonActions::QFacebookGraphCommonActions(QObject *parent) :
    QObject(parent)
{
    m_action = QVariantMap();
    qRegisterMetaType<ActionModelList>("ActionModelList");
}

QVariantMap QFacebookGraphCommonActions::action() const {
    return m_action;
}
void QFacebookGraphCommonActions::setAction(const QVariantMap &action) {
    if(m_action != action) {
        m_action = action;
        emit actionChanged();
    }
}
