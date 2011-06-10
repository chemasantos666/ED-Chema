#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ui->te_Show->setAlignment(Qt::AlignRight);
   // g.show();
 //   connect(&this->calcu,SIGNAL(sintaxError(bool)),this,SLOT(presentarError(bool)));

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_btn_Evaluate_clicked()
{
    QString ecuation = this->ui->le_inEcuation->text().toUpper().trimmed();
    qDebug()<<ecuation;
    QString resultado = this->calcu.parseComand(ecuation);

    if(resultado.isEmpty())
        this->presentarError();
    else
       this->ui->te_Show->append(resultado);
}









void MainWindow::presentarError()
{
    this->ui->te_Show->append("ERROR:Sintaxis");
    this->ui->te_Show->setAlignment(Qt::AlignRight);
}

void MainWindow::on_actionGraficar_triggered()
{
    this->g.show();
}
