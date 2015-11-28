#include "mainwindow.h"
#include <QApplication>

#include <QJsonValue>
#include <QFile>
#include <QJsonDocument>
#include <QDebug>
#include <QJsonObject>
#include <QJsonArray>

#include "Network/networkresponceitem.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString val;
    QFile file;
    file.setFileName("d:/2.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    file.close();
    qWarning() << val;
    QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());

    INetworkResponceItem *model = new LoginModel();
    model->Parse(d.object());

    MainWindow w;
    w.show();

    return a.exec();
}
