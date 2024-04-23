#include "sportwin.h"
#include "ui_sportwin.h"

Sport::Sport(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sport)
{
    ui->setupUi(this);
    sp_prod = new Sportprod(this);
    sp_test = new SportTest(this);

    this->setWindowTitle("Sport");
    QPalette palette;
    QColor customColor(240, 255, 240);
    palette.setBrush(QPalette::Window, customColor);
    setPalette(palette);

    QHBoxLayout* layout = new QHBoxLayout(this);
    QWidget* widget1 = new QWidget;
    QWidget* widget2 = new QWidget;

    QVBoxLayout* layout1 = new QVBoxLayout;
    QVBoxLayout* layout2 = new QVBoxLayout;

    QPushButton* button1 = new QPushButton;
    button1->setText("Non-recommended products");
    QPushButton* button2 = new QPushButton;
    button2->setText("Test");

    QLabel* label1_im = new QLabel;
    QLabel* label2_im = new QLabel;

    QImage image1(":/img/img/S.jpg");
    QImage image2(":/img/img/T1.png");

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

    connect(button, &QPushButton::clicked, this, &Sport::goBack);

    connect(button1, &QPushButton::clicked, this, &Sport::openSportPrWin);
    connect(button2, &QPushButton::clicked, this, &Sport::openSportTWin);

    /*QImage image(":/img/img/S.jpg");
    ui->prodLabel->setPixmap(QPixmap::fromImage(image.scaled(250,150)));
    ui->widget->setFixedSize(300, 250);

    QImage image1(":/img/img/T.jpg");
    ui->testLabel->setPixmap(QPixmap::fromImage(image1.scaled(250,150)));
    ui->widget1->setFixedSize(300, 250);*/
}

Sport::~Sport()
{
    delete ui;
    delete sp_prod;
    delete sp_test;
}

void Sport::goBack()
{
    this->close();
    parentWidget()->show();
}

void Sport::openSportPrWin()
{
    this->hide();
    sp_prod->show();
}

void Sport::openSportTWin()
{
    this->hide();
    sp_test->show();
}
