#include "sporttest.h"
#include "ui_sporttest.h"

SportTest::SportTest(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SportTest)
{
    ui->setupUi(this);
    QPushButton* button = new QPushButton("Back", this);
    button->move(40, 550);
    button->setFixedSize(80,24);

    connect(button, &QPushButton::clicked, this, &SportTest::goBack);

    this->setWindowTitle("Calorie calculator");
    QPalette palette;
    QColor customColor(240, 255, 240);
    palette.setBrush(QPalette::Window, customColor);
    setPalette(palette);
}

SportTest::~SportTest()
{
    delete ui;
}

void SportTest::on_calculateButton_clicked()
{
    if (ui->radioMale->isChecked()){
        gender = ui->radioMale->text();
    } else if (ui->radioFemale->isChecked()){
        gender = ui->radioFemale->text();
    }

    if (ui->activity->currentIndex() == 0){
        activityIn = 1.2;
    } else if (ui->activity->currentIndex() == 1){
        activityIn = 1.375;
    } else if (ui->activity->currentIndex() == 2){
        activityIn = 1.55;
    } else if (ui->activity->currentIndex() == 3){
        activityIn = 1.7;
    } else{
        activityIn = 1.9;
    }

    age = ui->ageEdit->text().toInt();
    weight = ui->weightEdit->text().toFloat();
    height = ui->heightEdit->text().toFloat();
    CalculateCal* calculate_cal = new CalculateCal(age, gender, weight, height, activityIn);
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QLabel* result = new QLabel(this);
    if (ui->radioMifflin->isChecked()){
        if (ui->radioKcal->isChecked()){
            calories = calculate_cal->getCaloriesMifflin();
        } else if (ui->radioKilojoules->isChecked()){
            calories = calculate_cal->convertTokJ(calculate_cal->getCaloriesMifflin());
        }
    } else if (ui->radioHarris->isChecked()){
        if (ui->radioKcal->isChecked()){
            calories = calculate_cal->getCaloriesHarris();
        } else if (ui->radioKilojoules->isChecked()){
            calories = calculate_cal->convertTokJ(calculate_cal->getCaloriesHarris());
        }
    }
    result->setText("Daily caloire intake: " + QString::number(calories));
    //mainLayout->addWidget(result);
    //result->move(500, 250);
    QHBoxLayout *resultLayout = new QHBoxLayout();
    resultLayout->addStretch();// Добавление растяжки для выравнивания посередине
    result->move(0, 50);
    resultLayout->addWidget(result);

    mainLayout->addLayout(resultLayout);

    setLayout(mainLayout);
    //result->show();
    //delete result;
    ui->calculateButton->hide();
    delete calculate_cal;/*
    delete mainLayout;
    delete resultLayout;
    delete result;*/

}

void SportTest::goBack(){
    this->close();
    parentWidget()->show();
}

