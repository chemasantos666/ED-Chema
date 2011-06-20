#include "renderarea.h"

RenderArea::RenderArea(QWidget *parent) :
    QWidget(parent)
{

}

void RenderArea::dibujarNodo(Nodo n,QPainter &P)
{
    QColor color(Qt::blue);


    QFontMetrics m(QFont("prueba",11,2,true));

    int x = m.boundingRect(n.etiqueta).width();
    int y = m.boundingRect(n.etiqueta).height();

    P.setPen(Qt::black);

    if(n.pintado)
     P.setBrush(color);
    else
     P.setBrush(Qt::white);


    P.drawRoundRect(n.x,n.y,x,y);
    P.drawText(n.x+15,n.y+15,n.etiqueta);
}

void RenderArea::dibujarArista(Nodo n1,Nodo n2, float peso, QPainter &P)
{
    QFontMetrics m(QFont("prueba",11,2,true));

    int x1 = m.boundingRect(n1.etiqueta).width()/2;
    int y1 = m.boundingRect(n1.etiqueta).height()/2;

    int x2 = m.boundingRect(n2.etiqueta).width()/2;
    int y2 = m.boundingRect(n2.etiqueta).height()/2;

    P.setPen(Qt::black);
    P.drawLine(n1.x+x1,n1.y+y1,n2.x+x2,n2.y+y2);

    int midX, midY;
    midX = (n1.x+n2.x)/2;
    midY =  (n1.y+n2.y) / 2;
    QString temp;
    temp.setNum(peso,'f',1);
    P.drawText(midX,midY,temp);
}

void RenderArea::paintEvent(QPaintEvent *event)
{
    QPainter painter( this ); // Inicializar el Painter
    painter.setPen( Qt::black ); // La pluma en como vamos a dibujar es negra
    painter.setBrush(Qt::white);
    painter.drawRect(0,0,this->width()-1,this->height()-1);






    if(!this->dia.isEmpty() && !this->hora.isEmpty()){
    //TODO : Logica para pintar el grafo
   for (int i=0;i<MG->getSize();i++)  
    {

       Nodo n = MG->getNodo(i);
       //Primero dibujar todas las aristas que salen de el
       //

       if (!MG->esDirigido())
       {
           for (int j=i+1;j<MG->getSize();j++)
            {
               if (MG->getPesoArista(i,j,dia,hora)!=Multigrafo::INFINITO){
                   this->dibujarArista(n,MG->getNodo(j),
                                       MG->getPesoArista(i,j,dia,hora),
                                       painter);
               }
            }
            this->dibujarNodo(n,painter);
       }
    }
 }
}

void RenderArea::setDiaHora(QString dia, QString hora)
{
  this->dia = dia;
  this->hora = hora;
  this->update();
}
