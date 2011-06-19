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
    QList<int> getCaminosUsados();

private:
    QList<int> caminos;
    int getNNodos(QString);
    void leerLinea(QString,int&);
    QVector<QVector<float> > p;

signals:

public slots:

    void getCaminos(int,int);
    QVector<QVector<float> > Floy(QVector<QVector<float> >);
    void cargarGrafo(QString);

};

#endif // CONSULTA_H
