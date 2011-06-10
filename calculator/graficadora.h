#ifndef GRAFICADORA_H
#define GRAFICADORA_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTableWidget>
#include "calculadora.h"

namespace Ui {
    class Graficadora;
}

class Graficadora : public QMainWindow
{
    Q_OBJECT

public:
    explicit Graficadora(QWidget *parent = 0);
    ~Graficadora();
    const static int  ORIGEN_X = 300;
    const static int  ORIGEN_Y = 250;


private:

   Calculadora calc;
    QGraphicsScene scene;
    QGraphicsView *view;
    QString funcion;
    double siguientePunto(int);
    void graficar(QMap<int,double>);
    void llenarTabla(QMap<int,double>);
    void construirEjes(QGraphicsScene&);
    Ui::Graficadora *ui;

private slots:
    void on_btn_graficar_clicked();

};

#endif // GRAFICADORA_H
