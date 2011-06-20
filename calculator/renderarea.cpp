#include "renderarea.h"

RenderArea::RenderArea(QWidget *parent) :
    QWidget(parent)
{
    this->scalex = 0;
    this->scaley = 0;
}

void RenderArea::setScale(int x, int y)
{
    this->scalex = x;
    this->scaley = y;
}

void RenderArea::graficarEasy(QVector<QPointF> puntos)
{
   this->puntos =puntos;
}

void RenderArea::paintEvent(QPaintEvent *p)
{
    QPainter paint(this);

    paint.setBrush(Qt::darkGray);
    paint.setPen(Qt::black);

    paint.drawRect(0,0,this->width()-1,this->height()-1);
    paint.setPen(Qt::red);

    QPointF origin(this->width()/2,this->height()/2);

    paint.translate(origin);

    this->crearEjes(paint);

    if(this->puntos.size()!=0){
      paint.scale(this->width()/(this->puntos.size()),this->height()/(scaley));
      this->graficar(this->puntos,paint);
     }
}

void RenderArea::crearEjes(QPainter & P)
{
    P.drawLine(0,0,-this->width()/2,0);
    P.drawLine(0,0,this->width()/2,0);
    P.drawLine(0,0,0,-this->height()/2);
    P.drawLine(0,0,0,this->height()/2);
    P.drawText(4,-this->height()/2+10,"Y");
    P.drawText((this->width()/2)-10,-4,"X");
}

void RenderArea::graficar(QVector<QPointF> puntos, QPainter & P)
{
    qDebug()<<"Graficando";

    for(int i = 0; i<puntos.size(); i++)
    {
        P.drawPoint(puntos.at(i));


        qDebug()<<puntos.at(i);
    }

    for(int i = 0; i<puntos.size()-1; i++)
        P.drawLine(puntos.at(i),puntos.at(i+1));
}
