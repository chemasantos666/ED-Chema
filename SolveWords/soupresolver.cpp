#include "soupresolver.h"

SoupResolver::SoupResolver(Diccionary * dic, QObject *parent) :
    QObject(parent)
{
    this->dic = dic;
    this->limite = 3;
}

SoupResolver::~SoupResolver()
{
    delete []this->logicalSoup;

}

void SoupResolver::loadSoup(QString path)
{
    QFile file(path);

    if(file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QTextStream stream(&file);

        QString bac;
        stream>>bac;

        bac = bac.trimmed();

        this->size = bac.length();

        this->logicalSoup = new QChar*[size];

        for(int i = 0; i<size; i++)
            this->logicalSoup[i] = new QChar[size];


        stream.seek(0);

        for(int i = 0; i<size; i++)
        {
            QString line;
            stream>>line;

            line = line.trimmed();

            for(int f = 0; f<line.length(); f++)
            {
              this->logicalSoup[i][f] = line[f];
              //qDebug()<<"("<<i<<","<<f<<"-"<<line[f]<<")";
            }
        }

    }else{
     qDebug()<<"Ocurrio un Error";
    }
}

QStringList SoupResolver::solveSoup()
{
    QString wordToFindHN; // Horizontal Normal
    QString wordToFindHI; // Horizontal Inverso
    QString wordToFindVA; // Vertical Para Abajo
    QString wordToFindVAA; // Vertical Para Arriba;
    QString wordToFindDiagADe; //Diagonal Abajo derecha;
    QString wordToFindDiagARDe; //Diagonal Arriba Izquierda->derecha;
    QString wordToFindDiagAbIz; //Diagonal Abajo Derecha->Izquierda;
    QString wordToFindDiagArIz; //Diagonal Arriba Derecha->Izquierda;

    QList<QPoint> verticalesArr_AbjTemp;
    QList<QPoint> horizontalesIz_DerTemp;
    QList<QPoint> diagonalesArr_abj_DereTemp;
    QList<QPoint> diagonalesAbj_Arr_DereTemp;
    QList<QPoint> horizontalesDer_IzTemp;
    QList<QPoint> verticalesAbj_ArrTemp;
    QList<QPoint> diagonalesAbj_Arr_IzqTemp;
    QList<QPoint> diagonalesArr_abj_IzqTemp;


    int diagFil = 0;
    int diagCol = 0;
    int diagFilIn = 0;
    int diagFilNega = 0;
    int diagFilPos = 0;

    this->Encontradas.clear();

    QTime time;
    time.start();

    for(int i = 0; i<this->size; i++)
    {

        for(int f = 0; f<this->size; f++)
        {

            diagCol = f;
            diagFil = i;
            diagFilIn = i;

            wordToFindHN.clear();
            wordToFindVA.clear();
            wordToFindDiagADe.clear();
            wordToFindDiagARDe.clear();


             horizontalesIz_DerTemp.clear();
             verticalesArr_AbjTemp.clear();
             diagonalesAbj_Arr_DereTemp.clear();
             diagonalesArr_abj_DereTemp.clear();

            for(int w = f; w<this->size; w++)
            {
                wordToFindHN += this->logicalSoup[i][w];
                wordToFindVA += this->logicalSoup[w][i];

                horizontalesIz_DerTemp.push_back(QPoint(i,w));
                verticalesArr_AbjTemp.push_back(QPoint(w,i));

                    if(diagFilIn>=0){
                        wordToFindDiagARDe += this->logicalSoup[diagFilIn--][w];
                      diagonalesAbj_Arr_DereTemp.push_back(QPoint(diagFilIn+1,w));
                    }

                    if((diagCol < this->size && diagFil < this->size)){
                        wordToFindDiagADe += this->logicalSoup[diagFil++][diagCol++];
                      diagonalesArr_abj_DereTemp.push_back(QPoint(diagFil-1,diagCol-1));
                    }
                    //rango de 4 a 15 caractares
                //
                //if((wordToFindHN.length()>=3 && wordToFindHN.length()<=15)
                  //  && (wordToFindVA.length()>=3 && wordToFindVA.length()<=15)){

                    if(wordToFindHN.length()>=this->limite)
                    if(this->dic->contains(wordToFindHN.toUpper())){
                        //qDebug()<<"Palabra encontrada Izquierda-Derecha(H):"<<wordToFindHN;
                        this->Encontradas.push_back(wordToFindHN);
                        wordToFindHN.clear();
                       this->horizontalesIz_Der.append(horizontalesIz_DerTemp);


                    }
                    if(wordToFindVA.length()>=this->limite)
                    if(this->dic->contains(wordToFindVA.toUpper())){
                       //qDebug()<<"Palabra encontrada arriba-abajo(V):"<<wordToFindVA;
                       this->Encontradas.push_back(wordToFindVA);
                       wordToFindVA.clear();
                       this->verticalesArr_Abj.append(verticalesArr_AbjTemp);
                   }

                //}

                //if((wordToFindDiagADe.length()>=3 && wordToFindDiagADe.length()<=15)
                //&& (wordToFindDiagARDe.length()>=3 && wordToFindDiagARDe.length()<=15))
                //{

                    if(wordToFindDiagADe.length()>=this->limite)
                    if(this->dic->contains(wordToFindDiagADe.toUpper())){
                       //qDebug()<<"Palabra encontrada izquierda-derecha(D,Abajo):"<<wordToFindDiagADe;
                       this->Encontradas.push_back(wordToFindDiagADe);
                       wordToFindDiagADe.clear();
                       this->diagonalesArr_abj_Dere.append(diagonalesArr_abj_DereTemp);
                   }

                    if(wordToFindDiagARDe.length()>=this->limite)
                    if(this->dic->contains(wordToFindDiagARDe.toUpper())){ 
                       //qDebug()<<"Palabra encontrada Izquierda-derecha(D,Arriba):"<<wordToFindDiagARDe;
                       this->Encontradas.push_back(wordToFindDiagARDe);
                       wordToFindDiagARDe.clear();
                       this->diagonalesAbj_Arr_Dere.append(diagonalesAbj_Arr_DereTemp);
                   }
                //}

            }


            if(f!=0)
            {
                diagFilNega = i;
                diagFilPos = i;

                wordToFindHI.clear();
                wordToFindVAA.clear();
                wordToFindDiagAbIz.clear();
                wordToFindDiagArIz.clear();
                horizontalesDer_IzTemp.clear();
                verticalesAbj_ArrTemp.clear();
                diagonalesAbj_Arr_IzqTemp.clear();
                diagonalesArr_abj_IzqTemp.clear();

                for(int l = f; l>=0; l--)
                {
                    wordToFindHI += this->logicalSoup[i][l];
                    wordToFindVAA += this->logicalSoup[l][i];

                horizontalesDer_IzTemp.push_back(QPoint(i,l));
                   verticalesAbj_ArrTemp.push_back(QPoint(l,i));

                    if(diagFilNega>=0){
                        wordToFindDiagAbIz += this->logicalSoup[diagFilNega--][l];
                       diagonalesArr_abj_IzqTemp.push_back(QPoint(diagFilNega+1,l));
                    }
                    if(diagFilPos<this->size){
                        wordToFindDiagArIz += this->logicalSoup[diagFilPos++][l];
                       diagonalesAbj_Arr_IzqTemp.push_back(QPoint(diagFilPos-1,l));
                    }

                        //rango de 4 a 15 caracteres maximo
                  //  if((wordToFindHI.length()>=3 && wordToFindHI.length()<=15)
                    //   &&(wordToFindVAA.length()>=3 && wordToFindVAA.length()<=15))
                      //  {

                        if(wordToFindHI.length()>=this->limite)
                        if(this->dic->contains(wordToFindHI.toUpper())){
                                //qDebug()<<"Palabra Encontrada Derecha-Izquierda(H):"<<wordToFindHI;
                                this->Encontradas.push_back(wordToFindHI);
                                wordToFindHI.clear();
                                this->horizontalesDer_Iz.append(horizontalesDer_IzTemp);
                            }

                        if(wordToFindVAA.length()>=this->limite)
                        if(this->dic->contains(wordToFindVAA.toUpper())){
                                //qDebug()<<"Palabra Encontrada Abajo-Arriba(V):"<<wordToFindVAA;
                                this->Encontradas.push_back(wordToFindVAA);
                                wordToFindVAA.clear();
                                this->verticalesAbj_Arr.append(verticalesAbj_ArrTemp);;
                            }
                        //}

                       //if((wordToFindDiagAbIz.length()>=3 && wordToFindDiagAbIz.length()<=15)
                       //&&(wordToFindDiagArIz.length()>=3 && wordToFindDiagArIz.length()<=15 ))
                         //  {
                        if(wordToFindDiagAbIz.length()>=this->limite)
                        if(this->dic->contains(wordToFindDiagAbIz.toUpper())){
                                //qDebug()<<"Palabra Encontrada Diagonal Invertida(Derecha->Izquierda):"<<wordToFindDiagAbIz;
                                this->Encontradas.push_back(wordToFindDiagAbIz);
                                 wordToFindDiagAbIz.clear();
                                this->diagonalesArr_abj_Izq.append(diagonalesArr_abj_IzqTemp);
                            }

                        if(wordToFindDiagArIz.length()>=this->limite)
                        if(this->dic->contains(wordToFindDiagArIz.toUpper())){
                               //qDebug()<<"Palabra Encontrada Diagonal Invertida(Derecha->IzquierdaA):"<<wordToFindDiagArIz;

                               this->Encontradas.push_back(wordToFindDiagArIz);
                                wordToFindDiagArIz.clear();
                               this->diagonalesAbj_Arr_Izq.append(diagonalesAbj_Arr_IzqTemp);;
                           }
                       //}
                }
            }
        }
    }
    this->time = time.elapsed();
    this->cantidad = this->Encontradas.length();
    qDebug()<<"Tiempo que tardo:"<<time.elapsed();


    emit this->pintar(this->diagonalesAbj_Arr_Dere);
    emit this->pintar(this->diagonalesAbj_Arr_Izq);
    emit this->pintar(this->diagonalesArr_abj_Dere);
    emit this->pintar(this->diagonalesArr_abj_Izq);
    emit this->pintar(this->horizontalesDer_Iz);
    emit this->pintar(this->horizontalesIz_Der);
    emit this->pintar(this->verticalesAbj_Arr);
    emit this->pintar(this->verticalesArr_Abj);

    this->diagonalesAbj_Arr_Dere.clear();this->horizontalesDer_Iz.clear();
    this->diagonalesAbj_Arr_Izq.clear();this->horizontalesIz_Der.clear();
    this->diagonalesArr_abj_Dere.clear();this->verticalesAbj_Arr.clear();
    this->diagonalesArr_abj_Izq.clear();this->verticalesArr_Abj.clear();

    qDebug()<<"Numero de Pabras encontradas"<<Encontradas.length();

    return this->Encontradas;
}



