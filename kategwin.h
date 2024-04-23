#ifndef KATEGWIN_H
#define KATEGWIN_H

#include <QDialog>
#include <QPalette>
#include "diabetewin.h"
#include "sportwin.h"

namespace Ui {
class ategwin;
}

class Kategwin : public QDialog
{
    Q_OBJECT

public:
    explicit Kategwin(QWidget *parent = nullptr);
    ~Kategwin();

private slots:

    void openSportWin();

    void openDiabeteWin();

    void on_pushButton_clicked();

private:
    Ui::ategwin *ui;
    Sport *sportwin;
    Diabete *diabetewin;
};

#endif // KATEGWIN_H
