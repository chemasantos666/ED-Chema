#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);




    this->dictioLoaded = false;
    this->soupLoaded = false;
    this->contadorPintadas = 0;

}

void MainWindow::clean()
{

    this->ui->lw_palabrasEncontradas->clear();
    this->ui->le_cantidadPalabras->clear();
    this->ui->le_tiempo->clear();

    this->soupLoaded = false;

    delete this->logical;
    delete this->soup;

}

MainWindow::~MainWindow()
{
    delete ui;
    qDebug()<<this->contadorPintadas;
}


void MainWindow::mostrarDiccionario()
{
    this->ui->lw_Diccinario->addItems(this->dictio.getDiccionario());
}

void MainWindow::on_actionCargarDiccionario_triggered()
{


    QString pathFile = QFileDialog::getOpenFileName(this,"Open a Text File","/","*.txt");
    if(!pathFile.isEmpty()){

        this->dictio.loadDicctionary(pathFile);
        this->mostrarDiccionario();
        this->dictioLoaded = true;
    }
}

void MainWindow::loadSoup()
{
    if(this->soupLoaded){
       delete this->soup;
     }

    this->soup = new QTableWidget(this->logical->size,this->logical->size,this);


   for(int i = 0; i<this->logical->size; i++)
    {
       for(int z = 0; z<this->logical->size; z++)
       {
           QTableWidgetItem *t = new QTableWidgetItem(this->logical->logicalSoup[i][z]);

           this->soup->setItem(i,z,t);
       }
   }
   QHeaderView *viewH;
   QHeaderView *viewV;

   viewH = new QHeaderView(Qt::Horizontal);
   viewV = new QHeaderView(Qt::Vertical);


   viewH->setDefaultSectionSize(15);
   viewV->setDefaultSectionSize(15);
   viewH->setVisible(false);
   viewV->setVisible(false);


   this->soup->setHorizontalHeader(viewH);
   this->soup->setVerticalHeader(viewV);

     this->ui->gridLayout->addWidget(this->soup);
     this->soupLoaded = true;
}

void MainWindow::on_actionCargarSopa_triggered()
{
    QString pathSopa = QFileDialog::getOpenFileName(this,"Open a Text File",":/","*.txt");

    this->logical = new SoupResolver(&this->dictio,this);

    connect(this->logical,SIGNAL(pintar(QList<QPoint>)),this,SLOT(pintar(QList<QPoint>)));

    if(!pathSopa.isEmpty() && this->logical!=0)
    {
        this->logical->loadSoup(pathSopa);
        this->loadSoup();
    }
}

void MainWindow::on_Resolver_clicked()
{
    if(this->dictioLoaded && this->soupLoaded){
        this->ui->lw_palabrasEncontradas->clear();
        this->ui->lw_palabrasEncontradas->addItems(this->logical->solveSoup());
        this->ui->le_cantidadPalabras->setText(QString().setNum(this->logical->cantidad));
        this->ui->le_tiempo->setText(QString().setNum(this->logical->time));
    }
    else{
        if(!soupLoaded)
            if(QMessageBox::critical(this,"Error","No se ha cargado ninguna sopa de letras aun!!\nPresione Ok para cargar una.",QMessageBox::Accepted,QMessageBox::Cancel)
                ==QMessageBox::Accepted)
                    this->on_actionCargarSopa_triggered();
        if(!dictioLoaded)
        if(QMessageBox::critical(this,"Error","No se ha cargado ningun diccionario aun!!\nPresione Ok para cargar un diccionario.",QMessageBox::Accepted,QMessageBox::Cancel)
            ==QMessageBox::Accepted)
            this->on_actionCargarDiccionario_triggered();
    }
}

void MainWindow::pintar(QList<QPoint> puntos)
{
    this->soup->reset();
    this->contadorPintadas++;

    for(int i = 0; i<puntos.length(); i++)
        this->soup->item(puntos.at(i).x(),puntos.at(i).y())->setBackgroundColor(QColor(Qt::red));

}

void MainWindow::on_btn_reset_clicked()
{
    this->clean();
}

void MainWindow::on_actionLimite_triggered()
{
    if(this->soupLoaded && this->dictioLoaded){
        int limite = QInputDialog::getInt(this,"Limite","Elija el Limite de caracteres que las palabras\ntendra!!!",2,2);
        this->logical->setLimite(limite);
    }else{
        QMessageBox::critical(this,"Error","No se a Cargado Nada!!!");
    }
}
