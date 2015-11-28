#include "httprequest.h"

HttpRequest::HttpRequest(QObject *object) : QObject(object)
{

}
/*
#include <QObject>
#include <QNetworkAccessManager>
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QThread>
#include <QDebug>

class HttpRequest : public QObject
{
    Q_OBJECT
public:
    explicit HttpRequest(QObject *parent = 0);
    void processRequest(QString URLaddress);
signals:

public slots:
    void finishedSlot(QNetworkReply* reply);
private:
    QNetworkAccessManager* nam;

};

#include "httprequest.h"


HttpRequest::HttpRequest(QObject *parent) :
    QObject(parent)
{
    // 1. Создаем QNetworkAccessManager и ожидаем от него сигнала finished
    nam = new QNetworkAccessManager(this);
    QObject::connect(nam, SIGNAL(finished(QNetworkReply*)),
             this, SLOT(finishedSlot(QNetworkReply*)));
}

void HttpRequest::processRequest(QString URLaddress)
{
    // 2. осуществляем вызов нужного УРЛа
    QUrl url(URLaddress);
    QNetworkReply* reply = nam->get(QNetworkRequest(url));
}

// 3. Принимаем и обрабатываем ответ сервера
void HttpRequest::finishedSlot(QNetworkReply* reply)
{
    // Не произошло-ли ошибки?
    if (reply->error() == QNetworkReply::NoError)
    {
        // Читаем ответ от сервера
        QByteArray bytes = reply->readAll();
        QString string(bytes);

        // Выводим ответ на экран
        qDebug() << string;
    }
    // Произошла какая-то ошибка
    else
    {
        // обрабатываем ошибку
        qDebug() << reply->errorString();
    }
    delete reply;
}

*/
