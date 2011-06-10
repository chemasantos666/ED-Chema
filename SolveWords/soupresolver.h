#ifndef SOUPRESOLVER_H
#define SOUPRESOLVER_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include "diccionary.h"
#include <QChar>
#include <QTime>
#include <QStringList>
#include <QTableWidgetItem>
#include <QList>


class SoupResolver : public QObject
{
    Q_OBJECT
public:
    explicit SoupResolver(Diccionary*,QObject *parent = 0);
    ~SoupResolver();
    int size;
    int time;
    int cantidad;
    QChar **logicalSoup;

private:
    int limite;
    Diccionary *dic;
    QStringList Encontradas;
    QList<QTableWidgetItem*> temp;
    QList<QPoint> diagonalesArr_abj_Dere;
    QList<QPoint> diagonalesAbj_Arr_Dere;
    QList<QPoint> diagonalesAbj_Arr_Izq;
    QList<QPoint> diagonalesArr_abj_Izq;
    QList<QPoint> verticalesArr_Abj;
    QList<QPoint> verticalesAbj_Arr;
    QList<QPoint> horizontalesIz_Der;
    QList<QPoint> horizontalesDer_Iz;



signals:
    void pintar(QList<QPoint>);

public slots:

    QStringList solveSoup();
    void loadSoup(QString);

};

#endif // SOUPRESOLVER_H
