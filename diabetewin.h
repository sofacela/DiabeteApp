#ifndef DIABETEWIN_H
#define DIABETEWIN_H

#include <QDialog>
#include "diabeteprod.h"
#include "diabetetest.h"
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>

namespace Ui {
class Diabete;
}

class Diabete : public QDialog
{
    Q_OBJECT

public:
    explicit Diabete(QWidget *parent = nullptr);
    ~Diabete();

private slots:
    void openDiabetePrWin();

    void openDiabeteTWin();

    void goBack();
private:
    Ui::Diabete *ui;
    DiabeteProd *di_prod;
    DiabeteTest *di_test;
};

#endif // DIABETEWIN_H
