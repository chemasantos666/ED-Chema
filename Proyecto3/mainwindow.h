#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "consulta.h"
#include "renderarea.h"
#include <QFileDialog>
#include <QTableWidget>
#include <QInputDialog>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QDebug>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Consulta *consul;
    RenderArea *render;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:

    QTableWidget *table;
    Ui::MainWindow *ui;

private slots:
    void on_btn_Consultar_clicked();
    void on_cb_Hora_textChanged(QString );
    void on_cb_Dias_textChanged(QString );
    void on_actionAgregar_Arista_triggered();
    void mostrarFloy();
    void on_btn_MostrarGrafo_clicked();
    void on_actionCargar_Grafo_triggered();
};

#endif // MAINWINDOW_H
