#include "diabetewin.h"
#include "ui_diabetewin.h"

Diabete::Diabete(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Diabete)
{
    ui->setupUi(this);

    this->setWindowTitle("Diabetes");
    QPalette palette;
    QColor customColor(240, 255, 240);
    palette.setBrush(QPalette::Window, customColor);
    setPalette(palette);

    di_prod = new DiabeteProd(this);
    di_test = new DiabeteTest(this);

    QHBoxLayout* layout = new QHBoxLayout(this);
    QWidget* widget1 = new QWidget;
    QWidget* widget2 = new QWidget;

    QVBoxLayout* layout1 = new QVBoxLayout;
    QVBoxLayout* layout2 = new QVBoxLayout;

    QPushButton* button1 = new QPushButton;
    button1->setText("Prohibited products");
    QPushButton* button2 = new QPushButton;
    button2->setText("Test");

    QLabel* label1_im = new QLabel;
    QLabel* label2_im = new QLabel;

    QImage image1(":/img/img/D.jpg");
    QImage image2(":/img/img/T.jpg");

    label1_im->setPixmap(QPixmap::fromImage(image1.scaled(345,230)));
    label2_im->setPixmap(QPixmap::fromImage(image2.scaled(345,230)));

    layout1->addWidget(label1_im);
    layout1->addWidget(button1);

    layout2->addWidget(label2_im);
    layout2->addWidget(button2);

    widget1->setLayout(layout1);
    widget2->setLayout(layout2);

    widget1->setFixedSize(345,240);
    widget2->setFixedSize(345,240);

    layout->addWidget(widget1);
    layout->addWidget(widget2);

    QPushButton* button = new QPushButton("Back", this);
    button->move(40, 550);
    button->setFixedSize(80,24);

    connect(button, &QPushButton::clicked, this, &Diabete::goBack);

    connect(button1, &QPushButton::clicked, this, &Diabete::openDiabetePrWin);
    connect(button2, &QPushButton::clicked, this, &Diabete::openDiabeteTWin);

    /*QImage image(":/img/img/S.jpg");
    ui->prodLabel->setPixmap(QPixmap::fromImage(image.scaled(250,150)));
    ui->widget->setFixedSize(300, 250);

    QImage image1(":/img/img/T.jpg");
    ui->testLabel->setPixmap(QPixmap::fromImage(image1.scaled(250,150)));
    ui->widget1->setFixedSize(300, 250);*/

}

void Diabete::goBack()
{
    this->close();
    parentWidget()->show();
}

void Diabete::openDiabetePrWin()
{
    this->hide();
    di_prod->show();
}

void Diabete::openDiabeteTWin()
{
    this->hide();
    di_test->show();
}

Diabete::~Diabete()
{
    delete ui;
}
