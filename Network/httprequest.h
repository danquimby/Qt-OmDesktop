#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H
#include <QObject>
#include <QNetworkAccessManager>
#include <QFile>
#include <QDir>
#include <QNetworkReply>

class HttpRequest : public QObject
{
    Q_OBJECT

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
    explicit    HttpDownload(QObject* = nullptr);
    void        DownloadFile(const QUrl& , const QString& = QString());
signals:
    void        DownLoadComplete(const QString& );
private slots:
    void        httpReadyRead();
    void        httpDownloadFinished();
private:
    void        StartDownload(const QUrl& );
    QNetworkAccessManager* m_pNetworkAccessManager;
    QNetworkReply *m_pNetworkReply;
    QFile *m_pFile;

};

#endif // HTTPREQUEST_H
