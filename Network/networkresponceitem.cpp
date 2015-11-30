#include <QNetworkReply>
#include <QByteArray>
#include <QDebug>
#include "networkresponceitem.h"

//LoginModel::LoginModel(QObject* parent) : QObject(parent)
//{

//}

ActionReqest::ActionReqest(QObject* o)
    : QObject(o)
{
    nam = new QNetworkAccessManager(this);
//    QObject::connect(nam, SIGNAL(finished(QNetworkReply*)),
//             this, SLOT(finishedSlot(QNetworkReply*)));
}
void ActionReqest::SetRequest(const RequstDataItem& item)
{
    m_RequstItem = item;
}

void ActionReqest::finishedSlot(QNetworkReply* reply)
{
    // Не произошло-ли ошибки?
    if (reply->error() == QNetworkReply::NoError)
    {
        // Читаем ответ от сервера
        QByteArray bytes = reply->readAll();
        QString string(bytes);

        // Выводим ответ на экран
        qWarning() << string;
        //emit FinishedRequest();
    }
    // Произошла какая-то ошибка
    else
    {
        // обрабатываем ошибку
        qDebug() << reply->errorString();
    }
    delete reply;
}
