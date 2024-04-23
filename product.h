
#ifndef PRODUCT_H
#define PRODUCT_H
#include <QString>
#include <QPixmap>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>



class Product
{
public:
    Product(const QString& name, const QImage& image):name(name), image(image){};
    QString getName();
    QImage getImage();
    void setImageSize(const QSize& size);
    QWidget* createwidget();
private:
    QString name;
    QImage image;
    QSize size;
};

#endif // PRODUCT_H
