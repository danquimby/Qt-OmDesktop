#include <QException>
#include <QJsonDocument>
#include <QJsonObject>

#include "standartmodel.h"

StandartModel::StandartModel(QObject *parent) : QObject(parent)
{
}
void StandartModel::Parse(const QJsonObject& )
{
}

void StandartModel::Parse(const QString& value)
{
    m_sFilenameJson = "d://2.json";
    Parse(QJsonDocument::fromJson(value.toUtf8()).object());
}
void StandartModel::SaveModel()
{
    if (!m_sFilenameJson.isEmpty())
        SaveAsModel(m_sFilenameJson);
    else
        throw;
}
void StandartModel::SaveAsModel(const QString& /*_filename*/)
{
}
void StandartModel::SaveFile(const QByteArray& _bytes)
{
    QFile file;
    file.setFileName(_filename);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    if(!file.isOpen())
    {
        qDebug() << "- Error, unable to open" << "outputFilename" << "for output";
        throw;
    }
    QTextStream outStream(&file);
    outStream << _bytes;
    file.close();
}
