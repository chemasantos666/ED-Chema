    #ifndef CALCULADORA_H
#define CALCULADORA_H

#include <QObject>
#include <QStack>
#include <QMap>
#include <QDebug>
#include <cmath>
#include <QPoint>
#include <QStringList>
class Calculadora : public QObject
{
    Q_OBJECT
public:

    explicit Calculadora(QObject *parent = 0);
    QVector<QPointF> evaluarEcuacion(QString,int,int);
    QMap<int,double> obtenerTabla();

    double evaluarFuncionEn(int,QString);

private:

    QMap<int,double> tablitaValores;
    QStack <QString> infijoPila;
    QStack <double> evaluarPila;
    QMap <QString,double> variables;//variables con valores numericos definidos
    QMap <QChar,QString> algebraicas;//char variable QString expresion algebraica;
private slots:

    QString meterVariable(QString);
    QString tokens(QString,int&,bool);
    int priority(QString);
    bool validate(QString);
    double evaluar(QString,bool);
    long calcularUnarios(double,QString);
    double calcular(double,double,QChar);
    bool isOperator(QString);

    QString toPostFijo(QString,bool);
    QString realizarOperaciones(QString);

signals:


public slots:
   QString parseComand(QString);
   QStringList getVariables();
   double getValorVariable(QString);
};

#endif // CALCULADORA_H
