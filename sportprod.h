#ifndef SPORTPROD_H
#define SPORTPROD_H

#include <QDialog>
#include "product.h"
#include <QPushButton>

namespace Ui {
class Sportprod;
}

class Sportprod : public QDialog
{
    Q_OBJECT

public:
    explicit Sportprod(QWidget *parent = nullptr);
    ~Sportprod();

private slots:
    void goBack();

private:
    Ui::Sportprod *ui;
};

#endif // SPORTPROD_H
