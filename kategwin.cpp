#include "kategwin.h"
#include "ui_kategwin.h"

Kategwin::Kategwin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ategwin)
{
    ui->setupUi(this);
    sportwin = new Sport(this);
    diabetewin = new Diabete(this);

    this->setWindowTitle("Categories");

    QPalette palette;
    QColor customColor(240, 255, 240);
    palette.setBrush(QPalette::Window, customColor);
    setPalette(palette);

    QHBoxLayout* layout = new QHBoxLayout(this);
    QWidget* widget1 = new QWidget;
    QWidget* widget2 = new QWidget;
    QWidget* widget3 = new QWidget;

    QVBoxLayout* layout1 = new QVBoxLayout;
    QVBoxLayout* layout2 = new QVBoxLayout;
    QVBoxLayout* layout3 = new QVBoxLayout;

    QLabel* label1 = new QLabel("Sport");
    label1->setAlignment(Qt::AlignHCenter);
    QLabel* label2 = new QLabel("Diabetes");
    label2->setAlignment(Qt::AlignHCenter);
    QLabel* label3 = new QLabel("Сardiovascular diseases");
    label3->setAlignment(Qt::AlignHCenter);

    QPushButton* button1 = new QPushButton;
    button1->setText("More");
    QPushButton* button2 = new QPushButton;
    button2->setText("More");
    QPushButton* button3 = new QPushButton;
    button3->setText("More");

    QLabel* label1_im = new QLabel;
    QLabel* label2_im = new QLabel;
    QLabel* label3_im = new QLabel;

    QImage image1(":/img/img/K1.jpg");
    QImage image2(":/img/img/K2.jpg");
    QImage image3(":/img/img/T1.png");

    label1_im->setPixmap(QPixmap::fromImage(image1.scaled(280,190)));
    label2_im->setPixmap(QPixmap::fromImage(image2.scaled(280,190)));
    label3_im->setPixmap(QPixmap::fromImage(image3.scaled(280,190)));

    layout1->addWidget(label1_im);
    layout1->addWidget(label1);
    layout1->addWidget(button1);

    layout2->addWidget(label2_im);
    layout2->addWidget(label2);
    layout2->addWidget(button2);

    layout3->addWidget(label3_im);
    layout3->addWidget(label3);
    layout3->addWidget(button3);

    widget1->setLayout(layout1);
    widget2->setLayout(layout2);
    widget3->setLayout(layout3);

    widget1->setFixedSize(300,240);
    widget2->setFixedSize(300,240);
    widget3->setFixedSize(300,240);

    layout->addWidget(widget1);
    layout->addWidget(widget2);
    //layout->addWidget(widget3);
    //layout->addWidget(ui->pushButton);
    //ui->pushButton->move(20, 550);

    connect(button1, &QPushButton::clicked, this, &Kategwin::openSportWin);
    connect(button2, &QPushButton::clicked, this, &Kategwin::openDiabeteWin);
    //connect(button3, &QPushButton::clicked, this, &Kategwin::openHeartWin);
}

Kategwin::~Kategwin()
{
    delete ui;
    delete sportwin;
    delete diabetewin;
}

void Kategwin::openSportWin(){
    this->hide();
    sportwin->show();
}
void Kategwin::on_pushButton_clicked()
{
    parentWidget()->show();
    this->hide();
}

void Kategwin::openDiabeteWin()
{
    diabetewin->show();
    this->hide();
}

/*
void Kategwin::on_pushButton_2_clicked()
{
    this->hide();
    sportwin->show();
}*/

