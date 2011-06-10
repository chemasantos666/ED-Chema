#include "graficadora.h"
#include "ui_graficadora.h"

Graficadora::Graficadora(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Graficadora)
{
    ui->setupUi(this);



    this->scene.setSceneRect(0,0,600,500);
    this->scene.addRect(0,0,600,500);




    /*
    for (int i = 0; i<100; i++)
    {
        qDebug()<< 247-((i*i)/500);

        scene.addEllipse((i+Graficadora::ORIGEN_X),247-((i*i)/100),1,1,QPen(Qt::red));
        scene.addEllipse((Graficadora::ORIGEN_X-i),247-((i*i)/100),1,1,QPen(Qt::red));
    }
    */





    this->view = new QGraphicsView(&scene);
    this->construirEjes(this->scene);
    this->scene.setBackgroundBrush(QBrush(Qt::darkGray));


    this->ui->gridLayout->addWidget(this->view);

}

double Graficadora::siguientePunto(int x)
{
    return this->calc.evaluarFuncionEn(x,this->funcion);
}


Graficadora::~Graficadora()
{
    delete ui;
}

void Graficadora::graficar(QMap<int, double> tablaDeValores)
{

    int cantidadPuntos = tablaDeValores.count(); //cantidad de puntos a graficar

    int xMin = this->ui->le_De->text().toInt();
    int xMax = this->ui->le_A->text().toInt();

    int escalaX = ((this->scene.height()/xMax))/(xMax-xMin);

    qDebug()<<"Valor de la Escala: "<<escalaX;


    for(int i = xMin;i<=escalaX*this->ORIGEN_Y; i+escalaX)
    {

            this->scene.addEllipse(i+this->ORIGEN_X,this->ORIGEN_Y-(this->siguientePunto(i)/this->ORIGEN_Y),1,1,QPen(Qt::red));

            this->scene.addEllipse(this->ORIGEN_X-i,this->ORIGEN_Y-(this->siguientePunto(i)/this->ORIGEN_Y),1,1,QPen(Qt::red));
    }

    this->view->update();
}

void Graficadora::llenarTabla(QMap<int, double> tablita)
{

    int De = this->ui->le_De->text().toInt();
    int A = this->ui->le_A->text().toInt();

    int fila = 0;
    int columna = 0;
    qDebug()<<"Antes de crear el tempTable";
    QHeaderView *view = new QHeaderView(Qt::Horizontal);

    view->setDefaultSectionSize(60);
    view->setVisible(false);

    QTableWidget *tempTable = new QTableWidget((A-De)+1,2,this);

    tempTable->setHorizontalHeader(view);

    QHeaderView *vview = new QHeaderView(Qt::Vertical);
           vview->setVisible(false);

           tempTable->setVerticalHeader(vview);



    for(int i = De; i<=A; i++)
    {
       columna = 0;
      QTableWidgetItem * y = new QTableWidgetItem(QString().setNum(tablita.value(i)));
      qDebug()<<"Y="<<y->text();
      QTableWidgetItem * x = new QTableWidgetItem(QString().setNum(tablita.key(y->text().toDouble())));
      qDebug()<<"X="<<x->text();

      tempTable->setItem(fila,columna++,x);
      tempTable->setItem(fila++,columna,y);

      qDebug()<<"Agregando al TAble";

    }
    this->ui->gridTablita->addWidget(tempTable);

}

void Graficadora::construirEjes(QGraphicsScene & scene)
{
    scene.addLine(this->ORIGEN_X,0,this->ORIGEN_X,this->scene.height(),QPen(Qt::red));
    scene.addLine(0,this->ORIGEN_Y,this->scene.width(),this->ORIGEN_Y,QPen(Qt::red));
}



void Graficadora::on_btn_graficar_clicked()
{
    qDebug()<<this->ui->le_ecuacion->text().toUpper();
    this->funcion = this->ui->le_ecuacion->text().trimmed().toUpper();

    this->calc.evaluarEcuacion(this->ui->le_ecuacion->text().trimmed().toUpper(),this->ui->le_De->text().toInt()
                               ,this->ui->le_A->text().toInt());

   this->llenarTabla(this->calc.obtenerTabla());
    this->graficar(this->calc.obtenerTabla());
}
