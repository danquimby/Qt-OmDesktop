#include <QNetworkReply>
#include <QByteArray>
#include <QDebug>
#include "networkresponceitem.h"

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
        qWarning() << "FinishedRequst " << m_vWaitList.count();
        m_nCountQueue++;
        m_vWaitList[m_vWaitList.count() - 1]->Execute();
        m_vWaitList.removeLast();
    } else
    {
        if (m_nCountQueue > 0)
            m_nCountQueue--;
    }
}

///////////////////////////////////
HttpNetwork::HttpNetwork(QObject* object)
    : QObject(object)
{
    m_NetworkAccessManager = new QNetworkAccessManager(this);
    QObject::connect(m_NetworkAccessManager, SIGNAL(finished(QNetworkReply*)),
             this, SLOT(CompleteRequest(QNetworkReply*)));
}
/*
void HttpRequest::processRequest(QString URLaddress)
{
    // 2. осуществляем вызов нужного УРЛа
    QUrl url(URLaddress);
    QNetworkReply* reply = nam->get(QNetworkRequest(url));
}
*/
// 3. Принимаем и обрабатываем ответ сервера
void HttpNetwork::CompleteRequest(QNetworkReply* reply)
{
    // Не произошло-ли ошибки?
    if (reply->error() == QNetworkReply::NoError)
    {
        // Читаем ответ от сервера
        QByteArray bytes = reply->readAll();
        QString string(bytes);

        // Выводим ответ на экран
        qDebug() << string;
        emit FinishRequest();
    }
    // Произошла какая-то ошибка
    else
    {
        // обрабатываем ошибку
        qDebug() << reply->errorString();
    }
    delete reply;
}

void HttpNetwork::Get(const QJsonArray& )
{
    QUrl url("http://api.odezhda-master.ru/api/system/version");
    m_NetworkAccessManager->get(QNetworkRequest(url));
}
void HttpNetwork::Post(const QJsonArray& )
{
}
void HttpNetwork::Delete(const QJsonArray& )
{
}
void HttpNetwork::Put(const QJsonArray& )
{
}
void HttpNetwork::Execute()
{

    QUrl url("http://api.odezhda-master.ru/api/ordersstatus/status?_fakeUser=[1]");
    QNetworkRequest request(url);
    request.setRawHeader("Authorization", "Basic YWthZG9tQGdtYWlsLmNvbTpZVGcxWmpBMU1tUTFNelZoTW1JeFpESTVabUZqTmpZNVpUazBPVFUyTWprNk1tUT0=");

    m_NetworkAccessManager->get(request);
}

