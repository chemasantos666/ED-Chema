#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "calculadora.h"
#include "graficadora.h"


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Graficadora g;
    Calculadora calcu;
    Ui::MainWindow *ui;

private slots:

    void on_actionGraficar_triggered();
    void presentarError();
    void on_btn_Evaluate_clicked();

};

#endif // MAINWINDOW_H
