#include "diabeteprod.h"
#include "ui_diabeteprod.h"

DiabeteProd::DiabeteProd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DiabeteProd)
{
    ui->setupUi(this);

    this->setWindowTitle("Foods to Avoid");
    QPalette palette;
    QColor customColor(240, 255, 240);
    palette.setBrush(QPalette::Window, customColor);
    setPalette(palette);

    QLabel *label = new QLabel("Foods to Avoid in Type 2 Diabetes", this);
    label->move(320, 40);
    label->setFixedSize(300, 100);

    QHBoxLayout* layout = new QHBoxLayout();

    Product* sweets = new Product("Sweets", QImage(":/img/img/s1.jpg"));
    //sweets->setImageSize(QSize(20,20));
    QWidget* sweetsWidget = sweets->createwidget();

    Product* bakery = new Product("Flour and confectionery", QImage(":/img/img/d1.jpg"));
    QWidget* bakeryWidget = bakery->createwidget();

    Product* whitePr = new Product("Made from white flour", QImage(":/img/img/d7.jpg"));
    QWidget* whitePrWidget = whitePr->createwidget();

    Product* sweetFr = new Product("Sweet fruits", QImage(":/img/img/d66.jpg"));
    QWidget* sweetFrWidget = sweetFr->createwidget();

    Product* sweetDairy = new Product("Sweet dairy products", QImage(":/img/img/s6.jpg"));
    QWidget* sweetDairyWidget = sweetDairy->createwidget();

    Product* alcohol = new Product("Alcohol", QImage(":/img/img/s2.jpg"));
    QWidget* alcoholWidget = alcohol->createwidget();

    Product* fatPr = new Product("Fat containing foods", QImage(":/img/img/d3.png"));
    QWidget* fatPrWidget = fatPr->createwidget();

    Product* semiPr = new Product("Semi-finished products", QImage(":/img/img/d4.jpg"));
    QWidget* semiPrWidget = semiPr->createwidget();

    Product* transF = new Product("Trans fats", QImage(":/img/img/d5.jpg"));
    QWidget* transFWidget = transF->createwidget();

    layout->addWidget(sweetsWidget);
    layout->addWidget(bakeryWidget);
    layout->addWidget(whitePrWidget);
    layout->addWidget(sweetFrWidget);
    layout->addWidget(sweetDairyWidget);
    layout->addWidget(alcoholWidget);
    layout->addWidget(fatPrWidget);
    layout->addWidget(semiPrWidget);
    layout->addWidget(transFWidget);

    QWidget* contentWidget = new QWidget();
    contentWidget->setLayout(layout);

    ui->scrollArea->setWidgetResizable(true);
    ui->scrollArea->setWidget(contentWidget);

    QPushButton* button = new QPushButton("Back", this);
    button->move(40, 550);
    button->setFixedSize(80,24);

    connect(button, &QPushButton::clicked, this, &DiabeteProd::goBack);

}

void DiabeteProd::goBack(){
    this->close();
    parentWidget()->show();
}

DiabeteProd::~DiabeteProd()
{
    delete ui;
}
