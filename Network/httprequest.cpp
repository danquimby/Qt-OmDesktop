#include <QStandardPaths>
#include "httprequest.h"

HttpRequest::HttpRequest(QObject *object)
    : QObject(object)
{
}

HttpDownload::HttpDownload(QObject* object)
    : QObject(object),
      m_pFile(nullptr)
{
    m_pNetworkAccessManager = new QNetworkAccessManager(this);
}

void HttpDownload::DownloadFile(const QUrl& _url , const QString& _sFilename)
{
    QString path = QStandardPaths::standardLocations(QStandardPaths::DownloadLocation).at(0) + "/upload/";

    if (!QDir().mkpath(path))
    {
        qDebug() << "dont create or open folder " << path;
        return;
    }
    QFileInfo fileInfo(_url.path());
    QString fileName = _url.fileName();

    if (fileName.isEmpty() && _sFilename.isEmpty())
    {
        qDebug() << "fileName is empty ";
        return;
    }

    if (QFile::exists(path + fileName)) {
        qWarning() << "exist next action remove " << fileName;
        QFile::remove(path + fileName);
    }

    if (m_pFile)
        delete m_pFile;
    m_pFile = new QFile(path + fileName);

    if (!m_pFile->open(QIODevice::WriteOnly))
    {
        qDebug() << "don't open file " << path + fileName;
        delete m_pFile;
        m_pFile = nullptr;
        return;
    }
    if (_sFilename.isEmpty())
    {

    }
    StartDownload(_url);
}
void HttpDownload::httpReadyRead()
{

    if (m_pFile)
        m_pFile->write(m_pNetworkReply->readAll());
}

void HttpDownload::httpDownloadFinished()
{
    m_pFile->flush();
    m_pFile->close();
    if (m_pNetworkReply->error()) {
        qDebug() << "error download " << m_pFile->fileName();
        m_pFile->remove();
    } else
    {
        qWarning() << "successful download" << m_pFile->fileName();
    }
    emit DownLoadComplete(m_pFile->fileName());
    m_pNetworkReply->deleteLater();
    m_pNetworkReply = nullptr;
    delete m_pFile;
    m_pFile = nullptr;
}

void HttpDownload::StartDownload(const QUrl & _url)
{
    QUrl requestUrl(_url);
    requestUrl.setQuery("_user_type_=0");
    //qWarning() << requestUrl;
    m_pNetworkReply = m_pNetworkAccessManager->get(QNetworkRequest(requestUrl));
    connect(m_pNetworkReply, SIGNAL(readyRead()),
            this, SLOT(httpReadyRead()));

    connect(m_pNetworkReply, SIGNAL(finished()),
            this, SLOT(httpDownloadFinished()));
}
