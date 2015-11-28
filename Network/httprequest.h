#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H
#include <QObject>

class HttpRequest : public QObject
{
public:
    HttpRequest(QObject * = 0);

signals:
    void    onResponce(QString& );
};

#endif // HTTPREQUEST_H
