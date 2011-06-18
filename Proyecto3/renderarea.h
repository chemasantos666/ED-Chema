#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include "multigrafo.h"
#include <QPainter>
#include <QFontMetrics>

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = 0);
     void setMultiGrafo(Multigrafo *G ) { this->MG = G; }
     void setDiaHora(QString,QString);
signals:

public slots:

private:

    Multigrafo *MG;
    QString dia,hora;
    void dibujarNodo(Nodo n,QPainter &P);
    void dibujarArista(Nodo n1,Nodo n2, float peso, QPainter &P);
protected:
   void paintEvent(QPaintEvent *event);
};

#endif // RENDERAREA_H
