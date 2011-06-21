#include "calculadora.h"

Calculadora::Calculadora(QObject *parent) :
    QObject(parent)
{
    this->infijoPila.clear();
    this->evaluarPila.clear();
    this->variables.clear();
    this->algebraicas.clear();
}

QString Calculadora::realizarOperaciones(QString ecuacion)
{
    QString ecuacionPostfijo;
    QString resultado;

    if(this->validate(ecuacion))
    {
       ecuacionPostfijo = this->toPostFijo(ecuacion,false);
        resultado.setNum(this->evaluar(ecuacionPostfijo,false));
    }
    else{

      resultado.clear();
      return resultado;
    }

    return resultado;
}

QString Calculadora::toPostFijo(QString ecua,bool sta)
{
    QString postFijo;

    this->infijoPila.push("(");
    ecua.append(')');

    while(!this->infijoPila.isEmpty()) //Mientras la pila no este vacia
    {
        for(int i = 0; i<ecua.length(); i++) //leer la ecuacion de izquierda a derecha
        {
            QString opeAc = this->tokens(ecua,i,sta); //devuelve el siguiente token

                qDebug()<<"Token Infijo->PostFijo: "<<opeAc;

            if(!this->isOperator(opeAc)&&opeAc!="("&&opeAc!=")"){ //si no es operador osea numero o varible
                    bool ok;
                    opeAc.toDouble(&ok);//si lo convirtio entonces es un numero

                    if(!ok)//si no lo convirtio es una variable
                        if(this->variables.contains(opeAc)){//si existe la variable
                        opeAc.setNum(this->variables.value(opeAc));//se le setea el valor de la variable a la expresion postFija XD
                        }
                    opeAc.prepend(",");
                    opeAc.append(",");
                    postFijo.append(opeAc);
                    continue;
            }

            if(opeAc=="(") //si es un parentencis para abrir
            {
                this->infijoPila.push(opeAc);
                continue;
            }

            if(isOperator(opeAc)) // si es operador
            {
                   while(priority(opeAc)<=priority(infijoPila.top())
                       && isOperator(infijoPila.top()))
                   {
                        postFijo+=this->infijoPila.pop();
                   }

                this->infijoPila.push(opeAc);
                continue;
            }

            if(opeAc==")") //si es cierre de parentesis
            {
             while(this->infijoPila.top()!="(")
             {
                postFijo+=this->infijoPila.pop();
             }
                infijoPila.pop();
             continue;
            }

        }
     }
      qDebug()<<"Convertido: Infijo->PostFijo: "<<postFijo;

    return postFijo;
}

QMap<int,double> Calculadora::obtenerTabla()
{
    return this->tablitaValores;
}

double Calculadora::getValorVariable(QString va)
{
    return this->variables.value(va);
}

QStringList Calculadora::getVariables()
{
    QList<QString> list = this->variables.keys();
    qDebug()<<"Numero variables: "<<list.length();
    QStringList l(list);
    qDebug()<<"Numero variables en QListString:"<<l.length();
    return l;

}


double Calculadora::evaluarFuncionEn(int valorX,QString funcion)
{
    if(this->validate(funcion))
    {
        QString temp = funcion.replace('X',QString().setNum(valorX));
        return this->evaluar(this->toPostFijo(temp,true),true);
    }

    return -1;
}

QVector<QPointF> Calculadora::evaluarEcuacion(QString ecua,int comienzo,int final)
{
    this->tablitaValores.clear();

    QVector<QPointF> puntos;

    if(this->validate(ecua))
    {
        for(int j = comienzo; j<=final;j++)
        {
           QString temp = ecua;

           temp.replace('X',QString().setNum(j));
           this->tablitaValores[j] = this->evaluar(toPostFijo(temp,true),true);
           puntos.push_back(QPointF(j,-this->evaluar(toPostFijo(temp,true),true)));
        }
    }

    return puntos;
}

int Calculadora::priority(QString ch)
{
    if(ch=="+"||ch=="-")
        return 1;
    if(ch=="/"||ch=="*")
        return 2;
    if(ch=="^"||ch=="SIN"||ch=="COS")
        return 3;
    return -1;
}

#define PI 3.14159265

double Calculadora::calcularUnarios(double n, QString oper)
{

    double resultado = 0;

    if(oper == "SIN")
       resultado = sin(n);
    if(oper == "COS")
       resultado = cos(n);

    return resultado;
}

double Calculadora::calcular(double n1, double n2, QChar oper)
{
    double resultado = 0;

    if(oper=='+')
        resultado = n1 + n2;
    if(oper=='-')
        resultado = n1 - n2;
    if(oper=='/')
        resultado = n1 / n2;
    if(oper=='*')
        resultado = n1 * n2;
    if(oper=='^'){
        resultado=n2;
        for(int i = 1;i<n1; i++) //elevando a n1 potencia
           resultado*=n2;
    }

    return resultado;
}


double Calculadora::evaluar(QString postFijo,bool sta)
{
    double x,y;

    postFijo.append('x');
    int i =0;

    while(postFijo.at(i)!= 'x')
    {

        QString act = this->tokens(postFijo,i,sta);

        if(!isOperator(act) && act!=","){
            qDebug()<<"Numero que se metio a la pila"<<act.toDouble();
            evaluarPila.push(act.toDouble());
        }
        else{

            if(act == "SIN" || act == "COS")
            {
                x = evaluarPila.pop();
                this->evaluarPila.push(calcularUnarios(x,act));
            }

            if(act!="," && act!="SIN" && act!="COS"){
            x = evaluarPila.pop();
            y = evaluarPila.pop();

            if(postFijo.at(i)=='/'||postFijo.at(i)=='-')
                this->evaluarPila.push(calcular(y,x,postFijo.at(i)));
            else
                this->evaluarPila.push(calcular(x,y,postFijo.at(i)));
            }
        }
        i++;
    }


    return evaluarPila.pop();
}


QString Calculadora::tokens(QString infijo, int &i,bool sta)
{
    QString token;

    if(sta){

        while((infijo.at(i)=='-'||infijo.at(i).isNumber()||infijo.at(i)=='.'||infijo.at(i)=='S'||infijo.at(i)=='I'||infijo.at(i)=='N'||infijo.at(i)=='O'||infijo.at(i)=='C')
             && (infijo.at(i+1)=='C'||infijo.at(i+1)=='O'||infijo.at(i+1)=='S'||infijo.at(i+1)=='I'||infijo.at(i+1)=='N'||infijo.at(i+1)=='.' || infijo.at(i+1).isNumber())
             && i<infijo.length()-1)
        {
            token.push_back(infijo.at(i));
            i++;
        }

        token.push_back(infijo.at(i));
        qDebug()<<"Tokenizando"<<token;
        qDebug()<<"valor de i:"<<i;

  }else{
      while((infijo.at(i).isNumber()||infijo.at(i)=='.'||infijo.at(i)=='S'||infijo.at(i)=='I'||infijo.at(i)=='N'||infijo.at(i)=='O'||infijo.at(i)=='C')
           && (infijo.at(i+1)=='C'||infijo.at(i+1)=='O'||infijo.at(i+1)=='S'||infijo.at(i+1)=='I'||infijo.at(i+1)=='N'||infijo.at(i+1)=='.' || infijo.at(i+1).isNumber())
           && i<infijo.length()-1)
      {
          token.push_back(infijo.at(i));
          i++;
      }

      token.push_back(infijo.at(i));
      qDebug()<<"Tokenizando"<<token;
      qDebug()<<"valor de i:"<<i;

  }

   return token;
}

bool Calculadora::validate(QString ecua)
{
    int pair = 0;

    for(int i = 0; i<ecua.length(); i++)
    {
        if(ecua.at(i)=='(')
            pair++;
        if(ecua.at(i)==')')
            pair--;
    }

    for(int i = 0; i<ecua.length()-1; i++)
    {

       if((ecua.at(i)=='-'||ecua.at(i)=='+'||ecua.at(i)=='/'||ecua.at(i)=='*'||ecua.at(i)=='^')&&
          (ecua.at(i+1)=='-'||ecua.at(i+1)=='+'||ecua.at(i+1)=='/'||ecua.at(i+1)=='*'||ecua.at(i+1)=='^'))
           return false;

       if((ecua.at(i)=='-'||ecua.at(i)=='+'||ecua.at(i)=='/'||ecua.at(i)=='*'||ecua.at(i)=='.') &&(ecua.at(i+1)==')'))
           return false;

       if((ecua.at(i)=='(')&&(ecua.at(i+1)=='-'||ecua.at(i+1)=='+'||ecua.at(i+1)=='/'||ecua.at(i+1)=='*'))
           return false;

       if(ecua.at(i)=='(' && ecua.at(i+1)==')')
           return false;

       if(ecua.at(i)=='.' && ecua.at(i+1)=='.')
           return false;

    }

    QString test;

    for(int i = 0; i<ecua.length(); i++)
    {
        test+=ecua.at(i);
        if(test.length()>=3)
        {
            for(int j = 0; j<test.length()-1;j++)
            {
                if(test.at(j)=='C' && test.at(j+1) == 'C')
                    return false;

                if(test.at(j)=='O' && test.at(j+1) == 'O')
                    return false;

                if(test.at(j)=='S' && test.at(j+1) == 'S')
                    return false;

                if(test.at(j)=='I' && test.at(j+1) == 'I')
                    return false;
                if(test.at(j)=='N' && test.at(j+1) == 'N')
                    return false;
            }
        }
        continue;
    }

    if(ecua.at(0)=='+'||ecua.at(0)=='/'||ecua.at(0)=='*'||ecua.at(0)=='-'||ecua.at(0)=='^')
        return false;

    if(ecua.at(ecua.length()-1)=='+'||ecua.at(ecua.length()-1)=='/'||ecua.at(ecua.length()-1)=='*'
       ||ecua.at(ecua.length()-1)=='-'||ecua.at(ecua.length()-1)=='^'||ecua.at(ecua.length()-1)=='.')      
        return false;

    if(pair!=0)
        return false;

    return true;
}

bool Calculadora::isOperator(QString c)
{
    if(c == "+"||c == "-"||c == "/"||c == "*"||c == "^"||c=="SIN"||c=="COS")
        return true;
    return false;
}

QString Calculadora::parseComand(QString comand)
{
  QString comando = comand.mid(0,3);

     if(comando == "DEF")
         return this->meterVariable(comand);

   return this->realizarOperaciones(comand);
}

QString Calculadora::meterVariable(QString comando)
{
    QString variable = comando.at(comando.indexOf(":")+1);
    QString Operacion = comando.mid(comando.indexOf("=")+1);


    if(variable=="X")
        return QString("Variable X es Reservada");

    qDebug()<<variable<<"="<<Operacion;


    if(this->validate(Operacion))
    {
        if(!this->variables.contains(variable))
        {
            this->variables[variable] = this->evaluar(this->toPostFijo(Operacion,false),false);
            qDebug()<<"Valor de:"<<variable<<this->variables.value(variable);
            return QString("Variable Def.");
        }
        else
           return QString("Variable Existente");
    }
    else
        return QString("Error:Sintaxis");



}
