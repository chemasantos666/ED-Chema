#include "consulta.h"

Consulta::Consulta(QObject *parent) :
    QObject(parent)
{

}

int Consulta::getNNodos(QString path)
{
    QFile fi (path);
    int cont = 0;

    if(fi.open(QIODevice::ReadOnly|QIODevice::Text)){
        QTextStream t(&fi);

        while(!t.atEnd())
        {
            QString linea = t.readLine();
            if(linea.at(0)=='-')
                cont++;
        }

    }else{
        qDebug()<<"Ocurrio un error en la contada de nodos";
    }

    return cont;
}

void Consulta::leerLinea(QString linea,int& i)
{
    QStringList nodo,arista;
    QString nombre,posX,posY;
    QString dia,hora,n1,n2,peso;

    if(linea.at(0)=='-')
    {
         nodo = linea.split(",");
         nombre = nodo.at(0);
         nombre = nombre.mid(nombre.indexOf("-")+1);
         posX = nodo.at(1);
         posY = nodo.at(2);

        this->mg->setNombreNodo(nombre,i);
        this->mg->setPos(i,posX.toInt(),posY.toInt());
        i++;
    }else if(linea.at(0)!='[' && linea.at(0)!='-'){
         arista = linea.split(",");
         dia = arista.at(0);
         hora = arista.at(1);
         n1 = arista.at(2);
         n2 = arista.at(3);
         peso = arista.at(4);

         int nod1 = this->mg->indexOff(n1);
         int nod2 = this->mg->indexOff(n2);

         this->mg->addArista(nod1,nod2,dia,hora,peso.toFloat());

    }
}

QVector<QVector<float> > Consulta::Floy(QVector<QVector<float> > A)
{
    p.resize(mg->getSize());
    for(int i = 0; i<this->mg->getSize(); i++)
        p[i].resize(this->mg->getSize());

    for(int i = 0; i<this->mg->getSize(); i++)
        for(int j = 0; j<this->mg->getSize(); j++)
            p[i][j] = -1;


    for (int k =0; k<this->mg->getSize();k++)
        for (int i =0; i<mg->getSize();i++)
            for (int j =0; j<mg->getSize();j++)
            {
               float peso = A[i][k] + A[k][j];
               if(peso < Multigrafo::INFINITO)
                   if (peso < A[i][j]){
                       A[i][j] = peso ;
                       p[i][j] = k;
                   }
             }

    return A;

}

void Consulta::getCaminos(int i, int j)
{


    int k;
    k = this->p[i][j];

    qDebug()<<"Lo saco y ya esta el camino en K:"<<k;

    if(k==-1)
     return;


    this->getCaminos(i,k);
    this->mg->setNodoPintado(k,true);
    this->caminos.push_back(k);
    this->getCaminos(k,j);

}

QList<int> Consulta::getCaminosUsados()
{
    QList<int> temp;
    temp = this->caminos;
    this->caminos.clear();
    return temp;
}

void Consulta::cargarGrafo(QString path)
{
    QFile f(path);
    int i = 0;

    this->mg = new Multigrafo(this->getNNodos(path),false);

    if(f.open(QIODevice::Text|QIODevice::ReadOnly))
    {
        QTextStream stream(&f);
        while(!stream.atEnd())
        {
            QString line = stream.readLine();
            this->leerLinea(line.toUpper(),i);

        }

    }else{
        qDebug()<<"Ocurrio un error abriendo el archivo";
    }
}
