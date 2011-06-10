#ifndef DICCIONARY_H
#define DICCIONARY_H

#include <QObject>
#include <QStringList>
#include <QFile>
#include <QIODevice>
#include <QTextStream>
#include <QDebug>
#include <QTime>
#include <QHash>


class Diccionary : public QObject
{
    Q_OBJECT

public:
    explicit Diccionary(QObject *parent = 0);
    ~Diccionary();

private:
    QList<QString> *hashTable;
    QStringList palabras;
    int sizeTable;
    int hashFuntion(QString);
    void insertWord(QString);
    QTime time;

signals:


public slots:
    QStringList getDiccionario();
            bool contains(QString);
      void loadDicctionary(QString);

};

#endif // DICCIONARY_H
