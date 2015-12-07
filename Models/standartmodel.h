#ifndef STANDARTMODEL_H
#define STANDARTMODEL_H

#include <QObject>

class IModel
{
    virtual void Parse(const QJsonObject& ) =0;
    virtual void Parse(const QString& ) =0;
    virtual void SaveModel() =0;
};


class StandartModel : public QObject, public IModel
{
    Q_OBJECT
public:
    explicit StandartModel(QObject *parent = 0);
    void Parse(const QJsonObject& ) override;
    void Parse(const QString& ) override;
    void SaveModel() override;

protected:
    QString LoadFile(const QString& );
    void SaveFile(const QByteArray& );

    QString m_sFilenameJson;

};

#endif // STANDARTMODEL_H
