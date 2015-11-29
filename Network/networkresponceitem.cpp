#include "networkresponceitem.h"

LoginModel::LoginModel(QObject* parent) : QObject(parent)
{

}

QueueRequest::QueueRequest(QObject* object)
    : QObject(object) ,
      m_nCountQueue(0)
{

}

void QueueRequest::AddRequset(INetworkResponceItem* )
{

}

int QueueRequest::CountQueue() const
{
    return m_nCountQueue;
}

void QueueRequest::FinishedRequst()
{
    m_nCountQueue = m_nCountQueue == 0 ? 0 : --m_nCountQueue;
}


