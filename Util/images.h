#ifndef IMAGES_H
#define IMAGES_H
#include <QQuickImageProvider>


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
