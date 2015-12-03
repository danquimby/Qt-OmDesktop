#ifndef NETWORKRESPONCEITEM_H
#define NETWORKRESPONCEITEM_H
#include <QJsonObject>
#include <QJsonArray>
#include <QObject>
#include <QDebug>
#include <QList>
#include <QRunnable>
#include <QNetworkAccessManager>
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QEventLoop>
#include <QPointer>
#include "items.h"

class IHttpNetwork;
class IDataModel
{
public:
    virtual void Parse(QJsonObject* ) = 0;
};

class QueueRequest : public QObject
{
    Q_OBJECT

    static const int   MAX_QUEUE = 20;
    int         m_nCountQueue;
    QList<IHttpNetwork*>    m_vWaitList;
public:
    QueueRequest(QObject* = nullptr);
    void    AddRequset(IHttpNetwork* );
    int     CountQueue() const;
public slots:
    void    FinishedRequst();

};

//class INetworkResponceItem
//{
//public:
//    virtual bool Containce() = 0;
//    virtual void Parse(const QJsonObject& )=0;
//    virtual bool Empty() = 0;
//};

class IHttpNetwork
{
public:
    virtual void Get(const QJsonArray& ) =0;
    virtual void Post(const QJsonArray& ) =0;
    virtual void Delete(const QJsonArray& ) =0;
    virtual void Put(const QJsonArray& ) =0;
    virtual void Execute() =0;
};

class HttpNetwork : public QObject, public IHttpNetwork
{
    Q_OBJECT
public:
    explicit HttpNetwork(QObject* = nullptr);
    void Get(const QJsonArray& )    override;
    void Post(const QJsonArray& )   override;
    void Delete(const QJsonArray& ) override;
    void Put(const QJsonArray& )    override;
    void Execute() override;

public slots:
    virtual void CompleteRequest(QNetworkReply* reply);
signals:
    // emiting When the answer came.
    void    FinishRequest();
private:
    QNetworkAccessManager* m_NetworkAccessManager;

};

struct RoleItem
{
    int     m_nRoleId;
    QString m_sRoleName;
    QString m_sRoleDescription;
};

//class LoginModel : public QObject, public HttpNetwork
//{
//    Q_OBJECT
//    Q_PROPERTY(int GroupId READ GroupId)
//    Q_PROPERTY(int LoginId READ LoginId)
//    Q_PROPERTY(QString HashKey READ HashKey)
//    Q_PROPERTY(QString RoleDescription READ RoleDescription)
//    Q_PROPERTY(int RoleId READ RoleId)
//    Q_PROPERTY(QString RoleName READ RoleName)
//public:

//    LoginModel(QObject* = 0);
//    virtual void Parse(const QJsonObject& object)
//    {
//        //qWarning() << object;
//        if (object.contains("id"))
//            m_nLoginId = object["id"].toInt();
//        if (object.contains("key"))
//            m_sHashKey = object["key"].toString();
//        if (object.contains("groupID"))
//            m_nGroupId = object["groupID"].toInt();
//        if (object.contains("roles"))
//        {
//            QJsonArray array = object["roles"].toArray();
//            QJsonObject obj = array[0].toObject();
//            if (obj.contains("role_id"))
//                m_Role.m_nRoleId = obj["role_id"].toInt();
//            if (obj.contains("role_name"))
//                m_Role.m_sRoleName = obj["role_name"].toString();
//            if (obj.contains("role_description"))
//                m_Role.m_sRoleDescription = obj["role_description"].toString();

//        }
//    }

//    int GroupId() const
//    {
//        return 0;
//    }
//    int LoginId() const
//    {
//        return 0;
//    }
//    QString HashKey() const
//    {
//        return "";
//    }
//    QString RoleDescription() const
//    {
//        return "";
//    }
//    int RoleId() const
//    {
//        return 0;
//    }
//    QString RoleName() const
//    {
//        return "";
//    }
//private:
//    int     m_nGroupId;
//    int     m_nLoginId;
//    QString m_sHashKey;

//    RoleItem m_Role;
//};

#endif // NETWORKRESPONCEITEM_H
