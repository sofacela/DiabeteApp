#ifndef SPORTTEST_H
#define SPORTTEST_H

#include <QDialog>
#include "calculatecal.h"

namespace Ui {
class SportTest;
}

class SportTest : public QDialog
{
    Q_OBJECT

public:
    explicit SportTest(QWidget *parent = nullptr);
    ~SportTest();

private slots:
    void on_calculateButton_clicked();

    void goBack();

private:
    Ui::SportTest *ui;

    int age;
    QString gender;
    float weight;
    float height;
    float activityIn;

    float calories;
};

#endif // SPORTTEST_H
