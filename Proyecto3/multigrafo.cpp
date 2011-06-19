#include "multigrafo.h"

Multigrafo::Multigrafo(int size, bool dirigido, QObject *parent):
    QObject(parent)
{
    this->size = size;
    this->dirigido = dirigido;

    this->nodos = new Nodo[size];


    this->inicializarMatrices();
    this->resetNodos();

    srand(time(0));
}

Multigrafo::~Multigrafo()
{
    //falta implementar

}

void Multigrafo::resetNodos()
{
    for(int i = 0; i<size; i++)
        this->nodos[i].pintado=false;

}

float Multigrafo::getPesoArista(int n1, int n2, QString dia, QString hora)
{
    return this->multiple[dia][hora][n1][n2];
}

void Multigrafo::setNombreNodo(QString nombre, int nodo)
{
    this->nodos[nodo].etiqueta = nombre;
    qDebug()<<"Pos nodo: "<<nodo<<" Nombre: "<<this->nodos[nodo].etiqueta;
}

void Multigrafo::setPos(int nodo,int x, int y)
{
    this->nodos[nodo].x = x;
    this->nodos[nodo].y = y;
}

void Multigrafo::generarPosicionesRandom(int ancho, int alto)
{
    for (int i=0;i<this->size;i++)
    {
      bool Dcolision=true;
      int cont=0;
      int candidato_x, candidato_y;

      while(Dcolision&&cont<=Multigrafo::INTENTOS_COLISION) // intentos
      {
          candidato_x = rand() % ancho;
          candidato_y = rand() % alto;
          // Este metodo chequea contra el resto sino colisiona
          // Hasta el nodo i
          if (!this->colision(i,candidato_x,candidato_y))
               Dcolision=false;
          else
              cont++;
      }

      this->nodos[i].x = candidato_x  ;
      this->nodos[i].y = candidato_y;

    }
}

bool Multigrafo::colision(int limite, int candidato_x, int candidato_y)
{
    float dist;
    for(int i=0; i<limite; i++)
    {
        dist = Multigrafo::distancia(nodos[i].x,nodos[i].y,
                                candidato_x,candidato_y);

        qDebug() << "nodo:" << i <<"<->" << limite << "candidatos:" << candidato_x << ":"
                 << candidato_y << " Distancia:" << dist ;

        if(dist<=Multigrafo::DELTACOLISION)
        {   qDebug() << "Colision Detected: " << dist;
            return true;
        }
    }
    return false;
}

QVector<QVector<float> > Multigrafo::getMatriz(QString dia, QString hora)
{
    return this->multiple[dia][hora];
}

int Multigrafo::indexOff(QString nom)
{
    qDebug()<<nom;


    for(int i = 0; i<this->size; i++)
    {
        if(this->nodos[i].etiqueta == nom){
         qDebug()<<"Nombre en el arreglo de nodos: "<<this->nodos[i].etiqueta;
         return i;
        }
    }
    return -1;
}

void Multigrafo::calcularDistancias()
{

    /*
    for (int i = 0 ; i< this->size; i++)
    {
        for (int j=0; j< this->size; j++ )
        {
          if (i!=j) // Si no es el mismo
             this->addArista(i,j,
                                    Multigrafo::distancia( this->getNodo(i),
                                                      this->getNodo(j)
                                                     )
                                 );

        }
    }*/

}

void Multigrafo::setPesoArista(int n1, int n2, QString dia, QString hora, float peso)
{


    if(n1!=n2 && multiple[dia][hora][n1][n2]!=this->INFINITO)
    {
        multiple[dia][hora][n1][n2] = peso;
        if(!this->dirigido)
            multiple[dia][hora][n2][n1] = peso;
    }
    qDebug()<<"Prueba para ver si esta trabajando: "<<" Peso: "<<multiple[dia][hora][n1][n2]<<"Nodo1: "<<this->getNodo(n1).etiqueta
            <<" Nodo2:"<<this->getNodo(n2).etiqueta;
}

Nodo Multigrafo::getNodo(int i)
{
  return this->nodos[i];
}

void Multigrafo::removerArista(int n1, int n2, QString dia, QString hora)
{

    if(n1!=n2)
    {
        this->multiple[dia][hora][n1][n2] = Multigrafo::INFINITO;
        if(!this->dirigido)
            this->multiple[dia][hora][n2][n1] = Multigrafo::INFINITO;
    }
}

void Multigrafo::addArista(int n1, int n2, QString dia, QString hora, float peso)
{
    qDebug()<<"Dia:"<<dia<<" Hora:"<<hora;
    qDebug()<<"n1:"<<this->nodos[n1].etiqueta<<" n2:"<<this->nodos[n2].etiqueta<<" Peso:";

    if(n1!=n2)
    {
        qDebug()<<"entra al if diferente";
        this->multiple[dia][hora][n1][n2] = peso;
        if(!this->dirigido)
            this->multiple[dia][hora][n2][n1] = peso;

    }
}



void Multigrafo::inicializarMatrices()
{
    for(int i = 0; i<7; i++)
    {
        QString dia;
        switch(i)
        {
        case 0:
            dia = "LUNES";
            break;
        case 1:
            dia = "MARTES";
            break;
        case 2:
            dia = "MIERCOLES";
            break;
        case 3:
            dia = "JUEVES";
            break;
        case 4:
            dia = "VIERNES";
            break;
        case 5:
            dia = "SABADO";
            break;
        case 6:
            dia = "DOMINGO";
            break;
        }
        for(int j = 0; j<23; j++)
        {
            QString intervalo;
            switch(j)
            {
            case 0:
                intervalo = "0-1";
                break;
            case 1:
                intervalo = "1-2";
                break;
            case 2:
                intervalo = "2-3";
                break;
            case 3:
                intervalo = "3-4";
                break;
            case 4:
                intervalo = "4-5";
                break;
            case 5:
                intervalo = "5-6";
                break;
            case 6:
                intervalo = "6-7";
                break;
            case 7:
                intervalo = "7-8";
                break;
            case 8:
                intervalo = "8-9";
                break;
            case 9:
                intervalo = "9-10";
                break;
            case 10:
                intervalo = "10-11";
                break;
            case 11:
                intervalo = "11-12";
                break;
            case 12:
                intervalo = "12-13";
                break;
            case 13:
                intervalo = "13-14";
                break;
            case 14:
                intervalo = "14-15";
                break;
            case 15:
                intervalo = "15-16";
                break;
            case 16:
                intervalo = "16-17";
                break;
            case 17:
                intervalo = "18-19";
                break;
            case 18:
                intervalo = "19-20";
                break;
            case 19:
                intervalo = "20-21";
                break;
            case 20:
                intervalo = "21-22";
                break;
            case 21:
                intervalo = "22-23";
                break;
            case 22:
                intervalo = "23-0";
                break;
            case 23:
                intervalo = "0-1";
                break;
           }
           this->multiple[dia][intervalo].resize(size);
           for(int c = 0; c<size; c++)
               this->multiple[dia][intervalo][c].resize(size);;

           for(int c = 0; c<size; c++)
           {
               for(int f = 0; f<size; f++){
                   if(c!=f)
                        this->multiple[dia][intervalo][c][f] = this->INFINITO;
                   else
                        this->multiple[dia][intervalo][c][f] = 0;
               }
           }
        }
    }
}

void Multigrafo::setNodoPintado(int n, bool sta)
{
    this->nodos[n].pintado = sta;
}

int Multigrafo::getIndexNodo(QString etiqueta)
{
    for (int i = 0; i<this->size; i++)
        if(nodos[i].etiqueta==etiqueta)
            return i;
    return -1;
}

QString Multigrafo::getNombreNodo(int i)
{
    if(i<=this->size)
    return this->nodos[i].etiqueta;
}
