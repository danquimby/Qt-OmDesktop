#ifndef QEUEREQUESTS_H
#define QEUEREQUESTS_H

#include <QThreadPool>
#include <QDebug>

#include "networkresponceitem.h"

//class QeueRequests : public QObject
//{
//    Q_OBJECT
//public:
//    explicit QeueRequests(QObject *parent = 0);
//    void     AddRequestTask(ActionReqest* );
//private:
//    QThreadPool *pool;
//};

//class Singleton
//{
//  private:
//    static QeueRequests * p_instance;
//    // Конструкторы и оператор присваивания недоступны клиентам
//    Singleton() {}
//    Singleton( const QeueRequests& );
//    Singleton& operator=( QeueRequests& );
//  public:
//    static QeueRequests * getInstance() {
//        if(!p_instance)
//            p_instance = new QeueRequests();
//        return p_instance;
//    }
//};

#endif // QEUEREQUESTS_H
