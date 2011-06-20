#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->consul = new Consulta();
    this->render = new RenderArea(this);
    QStringList l;


    l<<"Lunes"<<"Martes"<<"Miercoles"<<"Jueves"<<"Viernes"<<"Sabado"<<"Domingo";
    this->ui->cb_Dias->addItems(l);
    l.clear();
    l<<"0-1"<<"1-2"<<"2-3"<<"3-4"<<"4-5"<<"5-6"<<"6-7"<<"7-8"<<"8-9"<<"9-10"<<"10-11"<<"11-12"<<"12-13"<<"13-14"<<"14-15"<<"15-16"
            <<"16-17"<<"17-18"<<"18-19"<<"20-21"<<"21-22"<<"22-23"<<"23-0";

    this->ui->cb_Hora->addItems(l);




    connect(this->ui->cb_Dias,SIGNAL(currentIndexChanged(QString)),this,SLOT(on_cb_Dias_textChanged(QString)));
    connect(this->ui->cb_Dias,SIGNAL(currentIndexChanged(int)),this->ui->gridLayoutWidget,SLOT(update()));
    connect(this->ui->cb_Hora,SIGNAL(currentIndexChanged(QString)),this,SLOT(on_cb_Hora_textChanged(QString)));
    connect(this->ui->cb_Hora,SIGNAL(currentIndexChanged(int)),this->ui->gridLayoutWidget,SLOT(update()));



    this->ui->layoutGrafo->addWidget(render);
    this->inhabilitar();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::habilitar()
{
    this->ui->actionAgregar_Arista->setEnabled(true);
    this->ui->actionRemover_Arista->setEnabled(true);
    this->ui->btn_Consultar->setEnabled(true);
    this->ui->cb_Dias->setEnabled(true);
    this->ui->cb_Hora->setEnabled(true);

}

void MainWindow::inhabilitar()
{
    this->ui->actionAgregar_Arista->setDisabled(true);
    this->ui->actionRemover_Arista->setDisabled(true);
    this->ui->btn_Consultar->setDisabled(true);
    this->ui->cb_Dias->setDisabled(true);
    this->ui->cb_Hora->setDisabled(true);
}

void MainWindow::on_actionCargar_Grafo_triggered()
{

    QString path = QFileDialog::getOpenFileName(this,"Cargar Grafo","","*.txt");
    if(!path.isEmpty())
    {
        this->consul->cargarGrafo(path);


    this->render->setMultiGrafo(consul->mg);

    this->render->setDiaHora(this->ui->cb_Dias->currentText().toUpper()
                             ,this->ui->cb_Hora->currentText().toUpper());

    QTableWidget *ta = new QTableWidget(this->consul->mg->getSize(),1);

    for (int i = 0; i<this->consul->mg->getSize(); i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem(this->consul->mg->getNombreNodo(i));

        qDebug()<<item->text();

        ta->setItem(i,0,item);
    }

     this->ui->idem->addWidget(ta);
     table = new QTableWidget(this->consul->mg->getSize(),this->consul->mg->getSize(),this);
     this->ui->gridLayout_floy->addWidget(table);
     this->habilitar();
     this->mostrarFloy();
     this->setDiaHora();
 }


}

void MainWindow::mostrarFloy()
{

   QVector<QVector<float> > floyseado =  this->consul->Floy(this->consul->mg->getMatriz(this->ui->cb_Dias->currentText().toUpper()
                                                                                        ,this->ui->cb_Hora->currentText().toUpper()));

   QTableWidgetItem *item;



   for (int i = 0; i<floyseado.size(); i++)
   {
       for(int j = 0; j<floyseado.size(); j++)
       {
           qDebug()<<"FLOY MATRIZ:"<<QString().setNum(floyseado[i][j]);

           item = new QTableWidgetItem(QString::number(floyseado[i][j]));
         this->table->setItem(i,j,item);
       }
   }

}

void MainWindow::on_actionAgregar_Arista_triggered()
{
   QInputDialog insert;
   QString nodo1;
   QString nodo2;
   double peso;

   nodo1 = insert.getText(this,"Insertar Arista","Ingrese el Nombre del Primer Nodo.").toUpper().trimmed();

   if(!nodo1.isEmpty()){
     nodo2 = insert.getText(this,"Agregar Arista","Ingrese el Nombre del Segundo Nodo.").toUpper().trimmed();

        if(!nodo2.isEmpty())
             peso = insert.getDouble(this,"Agregar Arista","Ingrese el Peso de La Arista",0.1,1);
        else
            return;
    }else
        return;


   QString dia = this->ui->cb_Dias->currentText().toUpper();
   QString hora = this->ui->cb_Hora->currentText().toUpper();

   int n1,n2;

   n1 = this->consul->mg->getIndexNodo(nodo1);
   n2 = this->consul->mg->getIndexNodo(nodo2);

   qDebug()<<"nodo1: "<<n1<<" nodo2:"<<n2;

   if(n1==-1 || n2==-1){
       if(n1==-1)
           QMessageBox::critical(this,"Error","El nombre "+nodo1+" no existe!!");
       if(n2==-1)
           QMessageBox::critical(this,"Error","El nombre "+nodo2+" no existe!!");
      return;
  }

   this->consul->mg->addArista(n1,n2,dia,hora,(float)peso);
   this->mostrarFloy();
   this->ui->gridLayoutWidget->update();
}

void MainWindow::on_cb_Dias_textChanged(QString dia )
{
   this->render->setDiaHora(dia.toUpper(),this->ui->cb_Hora->currentText().toUpper());
   this->consul->mg->resetNodos();
   this->mostrarFloy();
   this->ui->te_RutaOptima->clear();
   this->setDiaHora();
}

void MainWindow::on_cb_Hora_textChanged(QString hora )
{

    this->render->setDiaHora(this->ui->cb_Dias->currentText().toUpper(),hora.toUpper());
    this->consul->mg->resetNodos();
    this->mostrarFloy();
    this->ui->te_RutaOptima->clear();
    this->setDiaHora();
}

void MainWindow::on_btn_Consultar_clicked()
{
    this->consul->mg->resetNodos();
    this->ui->te_RutaOptima->clear();

    QString origin = this->ui->le_Origen->text().toUpper().trimmed();
    QString dest = this->ui->le_Destino->text().toUpper().trimmed();
    int n1 = this->consul->mg->getIndexNodo(origin);
    int n2 = this->consul->mg->getIndexNodo(dest);

    if(n1 !=-1 && n2 != -1)
    {
     this->consul->mg->setNodoPintado(n1,true);
     this->consul->mg->setNodoPintado(n2,true);


     if(this->table->item(n1,n2)->text().toInt()!=99999)
     {
         this->consul->getCaminos(n1,n2);

         QList<int> caminos = this->consul->getCaminosUsados();

         this->ui->te_RutaOptima->append("La Mejor Ruta Para Llegar a "+dest+" desde "+origin+" en el dia "+this->ui->cb_Dias->currentText()+" en la hora "+
                                    this->ui->cb_Hora->currentText()+" es:");
         this->ui->te_RutaOptima->append(QString("1-")+origin);

         int i;

         for (i = 0; i<caminos.length(); i++)
             this->ui->te_RutaOptima->append(QString::number(i+2)+"-"+this->consul->mg->getNombreNodo(caminos.at(i)));

           this->ui->te_RutaOptima->append(QString::number(i+2)+"-"+dest);


           this->ui->te_RutaOptima->append("Con un costo en minutos de: "+this->table->item(n1,n2)->text());
    }else{
        this->ui->te_RutaOptima->append("Es imposible llegar!!!");
    }

     this->render->update();
 }else{
     QMessageBox::critical(this,"Error","Origen o Destino no Existentes!!!");
 }

}

void MainWindow::setDiaHora()
{
    this->ui->lbDia->setText("Grafo para dia:\n"+this->ui->cb_Dias->currentText());
    this->ui->lbHora->setText("Hora: "+this->ui->cb_Hora->currentText());
}

void MainWindow::on_actionRemover_Arista_triggered()
{
    QString ndo2;

    QString ndo1 = QInputDialog::getText(this,"Borra Arista","Ingrese Nombre de Nodo").toUpper().trimmed();

    if(!ndo1.isEmpty())
     ndo2 = QInputDialog::getText(this,"Borra Arista","Ingrese Nombre de Nodo").toUpper().trimmed();



    if(!ndo1.isEmpty() && !ndo2.isEmpty())
    {
        int n1,n2;
        n1 = this->consul->mg->getIndexNodo(ndo1);
        n2 = this->consul->mg->getIndexNodo(ndo2);

        this->consul->mg->removerArista(n1,n2,this->ui->cb_Dias->currentText().toUpper()
                                        ,this->ui->cb_Hora->currentText().toUpper());

        this->mostrarFloy();
        this->ui->gridLayoutWidget->update();
    }
}
