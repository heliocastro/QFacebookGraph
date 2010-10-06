#include <QDebug>

#include <qfacebookgraph.h>
#include <graph/qfacebookgraphconnectionhome.h>

QFacebookGraphConnectionHome::QFacebookGraphConnectionHome(QFacebookGraph *graph, QObject *parent) :
    QObject(parent)
{
    m_graph = graph;
    m_homeModel = QVariant();
    m_previous = QString::null;
    m_next = QString::null;
}

QVariant QFacebookGraphConnectionHome::getHomeModel()
{
    return m_homeModel;
}

void QFacebookGraphConnectionHome::update(int howMany)
{
    QUrl url = m_graph->baseUrl();
    url.setEncodedPath("/me/home");
    url.addQueryItem("limit", QString::number(howMany));
    m_graph->Get( url );
    connect( m_graph, SIGNAL(requestDone( bool )), this, SLOT( requestDone( bool ) ) );
}

void QFacebookGraphConnectionHome::next(int howMany)
{
    QUrl url = m_graph->baseUrl();
    url.setEncodedPath("/me/home");
    url.addQueryItem("limit", QString::number(howMany));
    url.addQueryItem("until", m_next);
    m_graph->Get( url );
    connect( m_graph, SIGNAL(requestDone( bool )), this, SLOT( requestDone( bool ) ) );
}

void QFacebookGraphConnectionHome::previous(int howMany)
{
    QUrl url = m_graph->baseUrl();
    url.setEncodedPath("/me/home");
    url.addQueryItem("limit", QString::number(howMany));
    url.addQueryItem("since", m_next);
    m_graph->Get( url );
    connect( m_graph, SIGNAL(requestDone( bool )), this, SLOT( requestDone( bool ) ) );
}

void QFacebookGraphConnectionHome::requestDone(bool ok)
{
    m_homeModel.clear();

    if (ok)
    {
        if(m_graph->result().contains("data"))
        {
            QVariantList list = m_graph->result().value("data").toList();
            QVariantList::const_iterator i;
            for (i = list.constBegin(); i != list.constEnd(); ++i)
            {
                qDebug() << *i << endl;
                qDebug() << "--------------------------";
            }

        }

        if(m_graph->result().contains("paging"))
        {
            QUrl url( m_graph->result().value("paging").toMap().value("next").toString() );
            m_next = url.queryItemValue("until");
            url = QUrl( m_graph->result().value("paging").toMap().value("previous").toString() );
            m_previous = url.queryItemValue("since");

            qDebug() << "NEXT: " << m_next << "   PREVIOUS: " << m_previous;
        }
    }
    else
        qDebug() << "Request failed";

    // We don't need the connection anymore
    disconnect(this,SLOT( requestDone( bool )));
}

