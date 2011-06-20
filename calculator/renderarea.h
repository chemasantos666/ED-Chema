#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QPainter>
#include <QVector>
#include <QPoint>
#include <QDebug>

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = 0);
    QVector <QPointF> puntos;
    double scalex;
    double scaley;

signals:

public slots:
    void graficarEasy(QVector<QPointF>);
    void graficar(QVector<QPointF>,QPainter &);
    void crearEjes(QPainter &);
    void setScale(int,int);


protected:
    void paintEvent(QPaintEvent *);


};

#endif // RENDERAREA_H
