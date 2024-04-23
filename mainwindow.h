
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "kategwin.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow;}
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton1_clicked();

private:
    void keyPressEvent(QKeyEvent* event);
    Ui::MainWindow *ui;
    Kategwin *kat;
};

#endif // MAINWINDOW_H
