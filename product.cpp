
#include "product.h"


QString Product::getName(){
    return this->name;
}

QImage Product::getImage(){
    return this->image;
}

void Product::setImageSize(const QSize& size){
    this->size = size;
}

QWidget* Product::createwidget(){
    QWidget* widget = new QWidget;
    QVBoxLayout* layout = new QVBoxLayout(widget);

    QLabel* imageLabel = new QLabel();
    QLabel* nameLabel = new QLabel(name);
    nameLabel->setAlignment(Qt::AlignCenter);

    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, QColor(255, 165, 0));//Qt::magenta);
    widget -> setAutoFillBackground(true);
    widget -> setPalette(pal);

    imageLabel->setPixmap(QPixmap::fromImage(image.scaled(200,150)));
    widget -> setFixedSize(210, 200);

    layout->addWidget(imageLabel);
    layout->addWidget(nameLabel);

    return widget;
}
