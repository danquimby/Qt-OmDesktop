#ifndef ITEMS
#define ITEMS
#include <QObject>
#include <QDebug>
#include <QObject>
#include <QList>

enum TypeRequset{
    TypeRequsetSEND,
    TypeRequsetGET,
    TypeRequsetPOST,
    TypeRequsetDELETE,
    TypeRequsetPUT
};

struct RequstDataItem
{
    QString         m_sUrl;
    TypeRequset     m_eTypeRequest;
    QJsonObject*    m_JsonObject;
    RequstDataItem()
    {
    }

    RequstDataItem(QString Url, TypeRequset _TypeRequset, QJsonObject* _JsonObject)
        : m_sUrl(Url),
          m_eTypeRequest(_TypeRequset),
          m_JsonObject(_JsonObject)
    {
    }
    bool    Empty() const
    {
        return m_sUrl.count() == 0;
    }
};
typedef QList<RequstDataItem>   RequstDataItems;

#endif // ITEMS

