#ifndef DIABETEPROD_H
#define DIABETEPROD_H

#include <QDialog>
#include <QPushButton>
#include "product.h"

namespace Ui {
class DiabeteProd;
}

class DiabeteProd : public QDialog
{
    Q_OBJECT

public:
    explicit DiabeteProd(QWidget *parent = nullptr);
    ~DiabeteProd();

private slots:
    void goBack();

private:
    Ui::DiabeteProd *ui;
};

#endif // DIABETEPROD_H
