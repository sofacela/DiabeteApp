#ifndef DIABETETEST_H
#define DIABETETEST_H

#include <QDialog>
#include "diabetesrisktest.h"

namespace Ui {
class DiabeteTest;
}

class DiabeteTest : public QDialog
{
    Q_OBJECT

public:
    explicit DiabeteTest(QWidget *parent = nullptr);
    ~DiabeteTest();
private slots:
    void goBack();
    void on_calcButton_clicked();

private:
    Ui::DiabeteTest *ui;

    DiabetesRiskTest* test;
    QString gender;
    bool isOftenVegFr;
    bool isOftenEx;
    bool takeBlPrMed;
    bool wasHighBlGluc;
    int hasRelatDiab;
};

#endif // DIABETETEST_H
