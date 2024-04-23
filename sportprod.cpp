#include "sportprod.h"
#include "ui_sportprod.h"

Sportprod::Sportprod(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sportprod)
{
    ui->setupUi(this);

    this->setWindowTitle("Non-recommended products");
    QPalette palette;
    QColor customColor(240, 255, 240);
    palette.setBrush(QPalette::Window, customColor);
    setPalette(palette);

    QLabel *label = new QLabel("Non-recommended products", this);
    label->move(320, 40);
    label->setFixedSize(300, 100);

    QHBoxLayout* layout = new QHBoxLayout();

    Product* sweets = new Product("Sweets", QImage(":/img/img/s1.jpg"));
    QWidget* sweetsWidget = sweets->createwidget();

    Product* alcohol = new Product("Alcohol", QImage(":/img/img/s2.jpg"));
    QWidget* alcoholWidget = alcohol->createwidget();

    Product* smockedPr = new Product("Smoked food", QImage(":/img/img/s3.jpg"));
    QWidget* smockedPrWidget = smockedPr->createwidget();

    Product* cannedF = new Product("Canned food", QImage(":/img/img/s4.jpg"));
    QWidget* cannedFWidget = cannedF->createwidget();

    Product* fastF = new Product("Fast food", QImage(":/img/img/s5.jpg"));
    QWidget* fastFWidget = fastF->createwidget();

    Product* sweetDairy = new Product("Sweet dairy products", QImage(":/img/img/s6.jpg"));
    QWidget* sweetDairyWidget = sweetDairy->createwidget();


    layout->addWidget(sweetsWidget);
    layout->addWidget(alcoholWidget);
    layout->addWidget(smockedPrWidget);
    layout->addWidget(cannedFWidget);
    layout->addWidget(fastFWidget);
    layout->addWidget(sweetDairyWidget);

    QWidget* contentWidget = new QWidget();
    contentWidget->setLayout(layout);

    ui->scrollArea->setWidgetResizable(true);
    ui->scrollArea->setWidget(contentWidget);

    QPushButton* button = new QPushButton("Back", this);
    button->move(40, 550);
    button->setFixedSize(80,24);

    connect(button, &QPushButton::clicked, this, &Sportprod::goBack);

}

void Sportprod::goBack(){
    this->close();
    parentWidget()->show();
}

Sportprod::~Sportprod()
{
    delete ui;
}
