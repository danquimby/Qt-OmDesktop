#include "images.h"

//QString dataPath = QStandardPaths::​writableLocation(QStandardPaths::AppDataLocation);

//CacheImage::CacheImage(QObject* o)
//    : QObject(o)
//{
//    connect(reply, SIGNAL(finished()),
//            this, SLOT(httpFinished()));
//    connect(reply, SIGNAL(readyRead()),
//            this, SLOT(httpReadyRead()));

//}

//QImage* CacheImage::GetImage(const QString& sUrl)
//{
//    foreach (ImageData data, m_listImages) {
//        if (data.sImageUrl == sUrl)
//        {
//            // found in json file
//            QImage* image = new QImage(data.sImageSource);
//            return image;
//        }
//    }
//    return new QImage;
//}
//QImage* CacheImage::GetImage(const QUrl& /*url*/)
//{

//    return new QImage;
//}
//QImage* CacheImage::GetAsyncImage(const QUrl& /*url*/)
//{
//return new QImage;
//}

//QImage* CacheImage::DownLoadImage(const QString& /*sUrl*/)
//{
//    return new QImage;
//}

QImage createSubImage(QImage* image, const QRect & rect)
{
    size_t offset = rect.x() * image->depth() / 8
                    + rect.y() * image->bytesPerLine();
    return QImage(image->bits() + offset, rect.width(), rect.height(),
                  image->bytesPerLine(), image->format());
}
