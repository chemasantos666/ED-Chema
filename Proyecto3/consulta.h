#ifndef CONSULTA_H
#define CONSULTA_H

#include <QObject>
#include "multigrafo.h"
#include <QFile>
#include <QTextStream>
#include <QStringList>

class Consulta : public QObject
{
    Q_OBJECT
public:
    explicit Consulta(QObject *parent = 0);
    Multigrafo *mg;


private:
     QVector<QVector<float> > p;
    int getNNodos(QString);
    void leerLinea(QString,int&);


signals:

public slots:
    void imprimirCaminos(int,int);
    QVector<QVector<float> > Floy(QVector<QVector<float> >);
    void cargarGrafo(QString);

};

#endif // CONSULTA_H
