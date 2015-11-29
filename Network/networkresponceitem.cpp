#include "networkresponceitem.h"

LoginModel::LoginModel(QObject* parent) : QObject(parent)
{

}

QueueRequest::QueueRequest(QObject* object)
    : QObject(object) ,
      m_nCountQueue(0)
{
    m_vWaitList = QList<IHttpNetwork*>();
}

void QueueRequest::AddRequset(IHttpNetwork* item)
{
    if (CountQueue() > MAX_QUEUE)
    {
        m_vWaitList.append(item);
    }
    else
    {
        m_nCountQueue++;
        item->Execute();
    }
}

int QueueRequest::CountQueue() const
{
    return m_nCountQueue;
}

void QueueRequest::FinishedRequst()
{
    if (m_vWaitList.count() > 0)
    {
        m_nCountQueue++;
        m_vWaitList[m_vWaitList.count()]->Execute();
        m_vWaitList.removeLast();
    } else
    {
        if (m_nCountQueue > 0)
            m_nCountQueue--;
    }
}


