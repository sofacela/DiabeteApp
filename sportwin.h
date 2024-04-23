#ifndef SPORTWIN_H
#define SPORTWIN_H

#include <QDialog>
#include "sportprod.h"
#include "sporttest.h"

namespace Ui {
class Sport;
}

class Sport : public QDialog
{
    Q_OBJECT

public:
    explicit Sport(QWidget *parent = nullptr);
    ~Sport();

private slots:
    void openSportPrWin();

    void openSportTWin();

    void goBack();

private:
    Ui::Sport *ui;
    Sportprod *sp_prod;
    SportTest *sp_test;
};

#endif // SPORTWIN_H
