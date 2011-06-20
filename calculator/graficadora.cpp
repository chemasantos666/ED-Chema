#include "graficadora.h"
#include "ui_graficadora.h"

Graficadora::Graficadora(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Graficadora)
{
    ui->setupUi(this);

    this->render = new RenderArea(this);

    this->table = new QTableWidget(this);
    this->ui->gridTablita->addWidget(this->table);

    this->ui->gridLayout->addWidget(this->render);
    this->ui->gridLayout->update();
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

    int cantidadPuntos = tablaDeValores.count();

    int xMin = this->ui->le_De->text().toInt();
    int xMax = this->ui->le_A->text().toInt();

}


void Graficadora::llenarTabla(QMap<int, double> tablita)
{
    this->table->clear();

    int De = this->ui->le_De->text().toInt();
    int A = this->ui->le_A->text().toInt();

    int fila = 0;
    int columna = 0;

    QHeaderView *view = new QHeaderView(Qt::Horizontal);

    this->table->setRowCount((A-De)+1);
    this->table->setColumnCount(2);
    view->setDefaultSectionSize(60);
    view->setVisible(false);


    this->table->setHorizontalHeader(view);

    QHeaderView *vview = new QHeaderView(Qt::Vertical);
           vview->setVisible(false);

           this->table->setVerticalHeader(vview);



    for(int i = De; i<=A; i++)
    {
       columna = 0;
      QTableWidgetItem * y = new QTableWidgetItem(QString().setNum(tablita.value(i)));

      QTableWidgetItem * x = new QTableWidgetItem(QString().setNum(i));

      this->table->setItem(fila,columna++,x);
      this->table->setItem(fila++,columna,y);



    }


}



void Graficadora::on_btn_graficar_clicked()
{
    qDebug()<<this->ui->le_ecuacion->text().toUpper();
    this->funcion = this->ui->le_ecuacion->text().trimmed().toUpper();
    int de = this->ui->le_De->text().toInt();
    int a = this->ui->le_A->text().toInt();

   QVector<QPointF> puntos =  this->calc.evaluarEcuacion(this->ui->le_ecuacion->text().trimmed().toUpper(),de,a);

   float scalex = abs(a)+abs(de);
   float scaley = puntos.at(puntos.size()-1).y() + puntos.at(0).y();
   this->render->setScale(scalex,scalex);


   this->render->graficarEasy(puntos);
   this->llenarTabla(this->calc.obtenerTabla());

    this->render->update();
}

void Graficadora::on_btn_salir_clicked()
{
    QVector<QPointF> f;
    this->render->graficarEasy(f);
    this->table->clear();
    this->ui->le_A->clear();
    this->ui->le_De->clear();
    this->ui->le_ecuacion->clear();
    this->close();
}
