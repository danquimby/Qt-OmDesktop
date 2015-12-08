#include "httprequest.h"

HttpRequest::HttpRequest(QObject *object)
    : QObject(object)
{

}

HttpDownload::HttpDownload(QObject* object)
    : QObject(object)
{

}

void HttpDownload::DownloadFile(const QString& _sUrl , const QString& _sFilename)
{
    if (_sFilename.isEmpty())
    {

    }
}

