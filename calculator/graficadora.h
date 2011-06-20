#ifndef GRAFICADORA_H
#define GRAFICADORA_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTableWidget>
#include "calculadora.h"
#include "renderarea.h"

namespace Ui {
    class Graficadora;
}

class Graficadora : public QMainWindow
{
    Q_OBJECT

public:
    explicit Graficadora(QWidget *parent = 0);
    ~Graficadora();

private:
    QTableWidget *table;
    RenderArea *render;
   Calculadora calc;
   // QGraphicsScene scene;
   // QGraphicsView *view;
    QString funcion;
    double siguientePunto(int);
    void graficar(QMap<int,double>);
    void llenarTabla(QMap<int,double>);

    //QList<QPoint> generarPuntos(QString);
    Ui::Graficadora *ui;

private slots:
    void on_btn_salir_clicked();
    void on_btn_graficar_clicked();

};

#endif // GRAFICADORA_H
