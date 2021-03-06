#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include "imagesmodel.h"

ImageUploadModel::ImageUploadModel()
{
    connect(&mHttpDownLoad, SIGNAL(DownLoadComplete(const QString&)),this,SLOT(SLTDownloadComplete(const QString&)));

    StandartModel::Parse(LoadFile("d:/2.json"));
}
void      ImageUploadModel::Parse(const QJsonObject& json)
{
    if (json.contains("images"))
    {
        QJsonArray array = json["images"].toArray();
        foreach (const QJsonValue& value, array) {
            ImageData data;
            QJsonObject object = value.toObject();
            if (object.contains("PathImage"))
            {
                data.sPathImage.append(object["PathImage"].toString().toUtf8());
            }
            if (object.contains("UrlImage"))
            {
                data.sUrlImage.append(object["UrlImage"].toString().toUtf8());
            }
            m_vListImageCache.append(data);
        }
    }
}

ImageData ImageUploadModel::getData(const QString& sUrl)
{
    foreach (ImageData data, m_vListImageCache)
    {
       if (data.sUrlImage == sUrl)
           return data;
    }
    UploadImage(QUrl(""));
    return ImageData();
}

ImageData ImageUploadModel::getData(const QUrl& sUrl)
{
    return getData(sUrl.toString());
}
void ImageUploadModel::SaveModel()
{
    QJsonArray images;
    QJsonObject object;
    foreach (const ImageData& item, m_vListImageCache) {
        QJsonObject obj;
        obj["PathImage"] = item.sPathImage + "m";
        obj["UrlImage"] = item.sUrlImage + "m";
        images.append(obj);
    }
    object["images"] = images;
    QJsonDocument doc(object);
    QByteArray bytes = doc.toJson();
    SaveFile(bytes);
}

bool ImageUploadModel::operator == (const ImageData& _data)
{
    foreach (ImageData data, m_vListImageCache)
    {
       if (data == _data)
           return true;
    }
    return false;
}
void ImageUploadModel::SLTDownloadComplete(const QString& _filename)
{
    mActualImageData.sPathImage = _filename;
    qWarning() << _filename;
}

void ImageUploadModel::UploadImage(const QUrl& /*_url*/)
{
    mActualImageData.sUrlImage = QUrl("http://api.odezhda-master.ru/images/catalog_3/52258b6d68bfd.jpg").toString();
    mHttpDownLoad.DownloadFile(QUrl("http://api.odezhda-master.ru/images/catalog_3/52258b6d68bfd.jpg"));

}
