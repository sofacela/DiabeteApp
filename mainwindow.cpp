
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include <QMessageBox>
#include <QVBoxLayout>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    kat = new Kategwin(this);

    this->setWindowTitle("Start");

    int w = this->width();
    int h = this->height();
    QPixmap backgroundImage(":/img/img/bcground.png");
    QPalette palette;
    palette.setBrush(ui->centralwidget->backgroundRole(), QBrush(backgroundImage.scaled(w,h)));
    ui->centralwidget->setPalette(palette);
    ui->centralwidget->setAutoFillBackground(true);

    this->setStyleSheet("QWidget { font-family: 'Lato'; font-size: 11pt; }");
    ui->label_2->setStyleSheet("color: #008000; font-size: 17pt;");

    this->layout()->addWidget(ui->pushButton1);//this ->setCentralWidget(imageLabel);


    /*ui->pushButton1->setStyleSheet("QPushButton{"
                                   "background-color: #4CAF50;"
                                   "color: white;"
                                   "border-radius: 15px;"
                                   "padding: 10px;"
                                   "}"
                                   "QPushButton:hover {"
                                   "    opacity: 0.5;"
                                   "}"
                                   "QPushButton:pressed {"
                                   "    background-color: #3e8e41;"
                                   "}");
    QPixmap pix(":/img/img/6.htm");
    int w1 = ui->label->width();
    int h1 = ui->label->height();
    ui->label->setPixmap(pix.scaled(w1, h1, Qt::KeepAspectRatio));*/
}

MainWindow::~MainWindow()
{
    delete ui;
    delete kat;
}

void MainWindow::keyPressEvent(QKeyEvent* event){
    if (event->key() == Qt::Key_Escape){
        QMessageBox::StandardButton buttons = QMessageBox::question(this, "Exit", "Do you want to exit?", QMessageBox::Yes| QMessageBox::No | QMessageBox::Cancel);
        if (buttons == QMessageBox::Yes) close();
    }
}

void MainWindow::on_pushButton1_clicked()
{
    kat->show();
    this->hide();
}

