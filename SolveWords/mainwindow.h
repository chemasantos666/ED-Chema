#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QTableWidget>
#include <QTableWidgetItem>
#include "soupresolver.h"
#include "diccionary.h"
#include <QChar>
#include <QMessageBox>
#include <QHeaderView>
#include <QInputDialog>

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
    void clean();
    Diccionary dictio;
    QTableWidget *soup;
    SoupResolver *logical;
    bool dictioLoaded;
    bool soupLoaded;
    Ui::MainWindow *ui;
    int contadorPintadas;

private slots:
    void on_actionLimite_triggered();
    void on_btn_reset_clicked();
    void mostrarDiccionario();
    void pintar(QList<QPoint>);
    void on_Resolver_clicked();
    void on_actionCargarSopa_triggered();
    void loadSoup();
    void on_actionCargarDiccionario_triggered();

};

#endif // MAINWINDOW_H
