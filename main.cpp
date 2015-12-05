#include "mainwindow.h"
#include <QApplication>

#include <QJsonValue>
#include <QFile>
#include <QJsonDocument>
#include <QDebug>
#include <QJsonObject>
#include <QJsonArray>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>

#include "Network/networkresponceitem.h"
#include "Network/qeuerequests.h"

int main(int argc, char *argv[])
{
/*
    QApplication a(argc, argv);
    QString val;
    QFile file;
    file.setFileName("d:/2.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    file.close();
    //qWarning() << val;
    QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());

    HttpNetwork* work = new HttpNetwork();
    QueueRequest *req = new QueueRequest;
    QObject::connect(work, SIGNAL(FinishRequest()),req,SLOT(FinishedRequst()));

    for(int i = 0;i < 200;i++)
    {
        req->AddRequset(work);
    }

    MainWindow w;
    w.show();
*/
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    engine.load(QUrl("qrc:/Qml/main.qml"));
    QObject *topLevel = engine.rootObjects().value(0);
    QQuickWindow *window = qobject_cast<QQuickWindow *>(topLevel);
    window->show();


    return app.exec();
}
