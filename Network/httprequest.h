#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H
#include <QObject>
#include <QNetworkAccessManager>
#include <QFile>
#include <QDir>
#include <QNetworkReply>

class HttpRequest : public QObject
{
public:
    HttpRequest(QObject * = 0);

signals:
    void    onResponce(QString& );
private:
    QNetworkAccessManager qnam;
    QNetworkReply *reply;
    QFile *file;
};

class HttpDownload : public QObject
{
    Q_OBJECT
public:
    explicit    HttpDownload(QObject* );
    void        DownloadFile(const QString& , const QString& = QString());
signals:
    void        DownLoadComplete(const QString& );

private:
    QNetworkAccessManager m_NetworkAccessManager;
    QNetworkReply *m_pNetworkReply;
    QFile *m_pFile;

};

#endif // HTTPREQUEST_H
