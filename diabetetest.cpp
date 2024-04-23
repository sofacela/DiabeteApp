#include "diabetetest.h"
#include "ui_diabetetest.h"

DiabeteTest::DiabeteTest(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DiabeteTest)
{
    ui->setupUi(this);

    this->setWindowTitle("Risk test");
    QPalette palette;
    QColor customColor(240, 255, 240);
    palette.setBrush(QPalette::Window, customColor);
    setPalette(palette);

    QPushButton* button = new QPushButton("Back", this);
    button->move(40, 550);
    button->setFixedSize(80,24);

    connect(button, &QPushButton::clicked, this, &DiabeteTest::goBack);
}

void DiabeteTest::goBack(){
    this->close();
    parentWidget()->show();
}

DiabeteTest::~DiabeteTest()
{
    delete ui;
    delete test;
}

void DiabeteTest::on_calcButton_clicked()
{
    if (ui->manButton->isChecked()){
        this->gender = ui->manButton->text();
    } else if (ui->womanButton->isChecked()){
        this->gender = ui->womanButton->text();
    }
    if (ui->rtComboBox->currentIndex() == 0){
        this->isOftenVegFr = 1;
    } else if (ui->rtComboBox->currentIndex() == 0){
        this->isOftenVegFr = 0;
    }
    if (ui->exComboBox->currentIndex() == 0){
        this->isOftenEx = 1;
    } else if (ui->exComboBox->currentIndex() == 1){
        this->isOftenEx = 0;
    }
    if (ui->medComboBox->currentIndex() == 0){
        this->takeBlPrMed = 0;
    } else if (ui->medComboBox->currentIndex() == 1){
        this->takeBlPrMed = 1;
    }
    if (ui->glComboBox->currentIndex() == 0){
        this->wasHighBlGluc = 0;
    } else if (ui->glComboBox->currentIndex() == 1){
        this->wasHighBlGluc = 1;
    }
    if (ui->rtComboBox->currentIndex() == 0){
        this->hasRelatDiab = 0;
    } else if (ui->rtComboBox->currentIndex() == 1){
        this->hasRelatDiab = 1;
    } else if (ui->rtComboBox->currentIndex() == 2){
        this->hasRelatDiab = 2;
    }
    /*if (ui->waistCicumEdit->isModified() && !(ui->manButton->isChecked() || ui->womanButton->isChecked())) {
        QMessageBox::warning(this, "Error", "Please select a radio button (choose your gender).");
    } else {
    }*/
    test = new DiabetesRiskTest(gender, ui->ageEdit->text().toFloat(), ui->bodyMassIndexEdit->text().toFloat(), ui->waistCicumEdit->text().toFloat(), this->isOftenVegFr, this->isOftenEx, this->takeBlPrMed, this->wasHighBlGluc, this->hasRelatDiab);

    test->calculateScore();
    QString labelResult = test->isRiskMessage();
    QMessageBox::information(this, "Test Results", labelResult);
}

