#ifndef IMAGES_H
#define IMAGES_H
#include <QQuickImageProvider>
#include <QNetworkReply>
#include <QFile>


struct ImageData
{
    QString sImageSource;
    QString sImageUrl;
};

class CacheImage : public QObject
{
public:
    CacheImage(QObject* = nullptr);

    QImage* GetImage(const QString& sUrl);
    QImage* GetImage(const QUrl& url);
public slots:
    QImage* GetAsyncImage(const QUrl& url);
signals:
    QImage* finishedDownLoad();
private:
    QImage* DownLoadImage(const QString& sUrl);

    QNetworkAccessManager m_NetworkAccessManager;
    QNetworkReply *reply;
    QFile *file;
    QList<ImageData>    m_listImages;
};

class ImageProvider : public QQuickImageProvider
{
public:
    ImageProvider()
        : QQuickImageProvider(QQuickImageProvider::Pixmap)
    {
    }

    QPixmap requestPixmap(const QString & /*id*/, QSize * /*size*/, const QSize & /*requestedSize*/)
    {
//        int width = 100;
//        int height = 50;

        QPixmap pixmap("D:\\Projects\\C++\\Qt\\Qt-OmDesktop\\data\\disk.png");
//        if (size)
//            *size = QSize(width, height);
//        QPixmap pixmap(requestedSize.width() > 0 ? requestedSize.width() : width,
//                       requestedSize.height() > 0 ? requestedSize.height() : height);
//        pixmap.fill(QColor(id).rgba());

        return pixmap;
    }
};

extern QImage createSubImage(QImage* image, const QRect & rect);

#endif // IMAGES_H
