#include "diccionary.h"

Diccionary::Diccionary(QObject *parent) :
    QObject(parent)
{
    this->sizeTable = 500;
    this->hashTable = new QList<QString>[this->sizeTable];

}

Diccionary::~Diccionary()
{
    delete [] this->hashTable;
}

int Diccionary::hashFuntion(QString word)
{
    int suma = 0;

    for(int i = 0; i<word.length(); i++)
        suma+=word[i].toAscii();

    return suma%this->sizeTable;
}

void Diccionary::insertWord(QString newWord)
{
    int pos = this->hashFuntion(newWord);

    if(!this->hashTable[pos].contains(newWord)){
        this->hashTable[pos].push_back(newWord);
        this->palabras.push_back(newWord);
    }

}

QStringList Diccionary::getDiccionario()
{
   return this->palabras;
}

void Diccionary::loadDicctionary(QString path)
{
    this->time.start();

    QFile textFile(path);


    if(textFile.open(QIODevice::Text|QIODevice::ReadOnly))
    {
        QTextStream f(&textFile);

        while(!f.atEnd())
        {
            QString word;
            f>>word;
            this->insertWord(word.toUpper());
        }
        textFile.close();

    }else{
        qDebug()<<"Ocurrio Un Error";
    }

    qDebug()<<time.elapsed();

}

bool Diccionary::contains(QString word)
{
    return this->hashTable[this->hashFuntion(word)].contains(word);
}
