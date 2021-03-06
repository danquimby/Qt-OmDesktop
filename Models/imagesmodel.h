#ifndef IMAGESMODEL_H
#define IMAGESMODEL_H

#include <QObject>
#include <QUrl>
#include <QFile>
#include <QImage>
#include <QNetworkAccessManager>
#include "Network/httprequest.h"

#include "standartmodel.h"

struct ImageData
{
    QString sPathImage;
    QString sUrlImage;

    bool Empty() const
    {
        return sPathImage.isEmpty() && sUrlImage.isEmpty();
    }
    bool operator == (const ImageData& data)
    {
        return sPathImage == data.sPathImage && sUrlImage == data.sUrlImage;
    }
};

class ImageUploadModel : public StandartModel
{
    QList<ImageData>    m_vListImageCache;
public:
    ImageUploadModel();
    void Parse(const QJsonObject& ) override;
    ImageData getData(const QString& /*sUrl*/);
    ImageData getData(const QUrl& /*sUrl*/);
    bool operator == (const ImageData& );
    void SaveModel() override;

    HttpDownload mHttpDownLoad;
public slots:
    void SLTDownloadComplete(const QString& ) override;
private:
    void UploadImage(const QUrl& );

    ImageData    mActualImageData;

    QNetworkAccessManager m_NetworkAccessManager;
    QNetworkReply *reply;
    QFile *file;

};

#endif // IMAGES_H
