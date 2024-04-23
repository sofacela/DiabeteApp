#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    if (ui->comboBox->currentIndex() == 0){

    } else if (ui->comboBox->currentIndex() == 1){

    }
}

Dialog::~Dialog()
{
    delete ui;
}
