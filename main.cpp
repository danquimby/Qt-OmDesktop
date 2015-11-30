#include "mainwindow.h"
#include <QApplication>

#include <QJsonValue>
#include <QFile>
#include <QJsonDocument>
#include <QDebug>
#include <QJsonObject>
#include <QJsonArray>

#include "Network/networkresponceitem.h"
#include "Network/qeuerequests.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString val;
    QFile file;
    file.setFileName("d:/2.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    file.close();
    //qWarning() << val;
    QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());

    ActionReqest* req = new ActionReqest();
    req->SetRequest(RequstDataItem("http://stackoverflow.com/questions/15893040/how-to-create-read-write-json-files-in-qt5",TypeRequsetGET,0));
    for(int i = 0;i < 20;i++)
        Singleton::getInstance()->AddRequestTask(req);
//    INetworkResponceItem *model = new LoginModel();
//    model->Parse(d.object());

    MainWindow w;
    w.show();

    return a.exec();
}
