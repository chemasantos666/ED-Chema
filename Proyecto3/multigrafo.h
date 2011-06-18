#ifndef MULTIGRAFO_H
#define MULTIGRAFO_H

#include <QObject>
#include <QDebug>
#include "stdio.h"
#include "cmath"
#include "time.h"
#include <QMap>
#include <QString>
#include <QVector>

class Nodo{
public:
    int x,y;
    QString etiqueta;
};

class Multigrafo : public QObject
{
    Q_OBJECT
public:
    explicit Multigrafo(int,bool,QObject *parent = 0);
    ~Multigrafo();
    QVector<QVector<float> > getMatriz(QString,QString);
    static const float INFINITO = 99999.00;
    static const float DELTACOLISION = 25.0;
    static const int INTENTOS_COLISION =2;

    static float distancia(Nodo A, Nodo B)
    {
      return (sqrt( (B.x-A.x)*(B.x-A.x) + (B.y-A.y)*(B.y-A.y) ));
    }

    static float distancia(int x1,int y1, int x2,int y2)
    {
      return (sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) ));
    }

signals:

public slots:
    void addArista(int, int, QString,QString,float);
    void removerArista(int,int,QString,QString);
    Nodo getNodo(int i);
    QString getNombreNodo(int);
    int getIndexNodo(QString);
    float getPesoArista(int,int,QString,QString);
    void setPesoArista(int,int,QString,QString,float peso);
    void setNombreNodo(QString nombre,int nodo);
    void generarPosicionesRandom(int ancho,int alto);
     int indexOff(QString);
    void setPos(int,int,int);
     void calcularDistancias() ;
     bool esDirigido() { return dirigido ;}
     int getSize() { return size; } // Regresa cuantos Nodos

private:
     bool colision(int,int,int);
    void inicializarMatrices();
    QMap<QString,QMap<QString,QVector<QVector<float> > > > multiple;
    Nodo *nodos;
    int size;
    bool dirigido;


};

#endif // MULTIGRAFO_H
