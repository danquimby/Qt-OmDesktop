#ifndef NETWORKRESPONCEITEM_H
#define NETWORKRESPONCEITEM_H
#include <QJsonObject>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

class INetworkResponceItem
{
public:
    virtual bool Containce() = 0;
    virtual void Parse(const QJsonObject& )=0;
    virtual bool Empty() = 0;
};
class IHttpNetwork
{
public:
    virtual void GetHttp(const QJsonArray& );
    virtual void PostHttp(const QJsonArray& );

};

class NetworkModel : public INetworkResponceItem, public IHttpNetwork
{
public:
    virtual bool Containce()
    {
        return false;
    }

    virtual void Parse(const QJsonObject& /*object*/)
    {
    }

    virtual bool Empty()
    {
        return true;
    }
    virtual void GetHttp(const QJsonArray& )
    {
    }

    virtual void PostHttp(const QJsonArray& )
    {
    }
};

struct RoleItem
{
    int     m_nRoleId;
    QString m_sRoleName;
    QString m_sRoleDescription;
};

class LoginModel : public QObject, public NetworkModel
{
    Q_OBJECT
    Q_PROPERTY(int GroupId READ GroupId)
    Q_PROPERTY(int LoginId READ LoginId)
    Q_PROPERTY(QString HashKey READ HashKey)
    Q_PROPERTY(QString RoleDescription READ RoleDescription)
    Q_PROPERTY(int RoleId READ RoleId)
    Q_PROPERTY(QString RoleName READ RoleName)
public:

    LoginModel(QObject* = 0);
    virtual void Parse(const QJsonObject& object)
    {
        //qWarning() << object;
        if (object.contains("id"))
            m_nLoginId = object["id"].toInt();
        if (object.contains("key"))
            m_sHashKey = object["key"].toString();
        if (object.contains("groupID"))
            m_nGroupId = object["groupID"].toInt();
        if (object.contains("roles"))
        {
            QJsonArray array = object["roles"].toArray();
            QJsonObject obj = array[0].toObject();
            if (obj.contains("role_id"))
                m_Role.m_nRoleId = obj["role_id"].toInt();
            if (obj.contains("role_name"))
                m_Role.m_sRoleName = obj["role_name"].toString();
            if (obj.contains("role_description"))
                m_Role.m_sRoleDescription = obj["role_description"].toString();

        }
    }

    int GroupId() const
    {
        return 0;
    }
    int LoginId() const
    {
        return 0;
    }
    QString HashKey() const
    {
        return "";
    }
    QString RoleDescription() const
    {
        return "";
    }
    int RoleId() const
    {
        return 0;
    }
    QString RoleName() const
    {
        return "";
    }
private:
    int     m_nGroupId;
    int     m_nLoginId;
    QString m_sHashKey;

    RoleItem m_Role;
};

#endif // NETWORKRESPONCEITEM_H
