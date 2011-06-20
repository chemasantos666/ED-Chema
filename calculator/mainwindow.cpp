#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ui->te_Show->setAlignment(Qt::AlignRight);
    connect(this->ui->cb_Variables,SIGNAL(currentIndexChanged(QString)),this,SLOT(on_cb_Variables_currentIndexChanged(QString)));

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

    this->ui->cb_Variables->clear();
    this->ui->cb_Variables->addItems(this->calcu.getVariables());
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

void MainWindow::on_le_inEcuation_returnPressed()
{
    if(!this->ui->le_inEcuation->text().isEmpty())
        this->on_btn_Evaluate_clicked();
}

void MainWindow::on_cb_Variables_currentIndexChanged(QString k )
{
    this->ui->le_valorVariable->setText(QString::number(this->calcu.getValorVariable(k)));
}
