/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon 20. Jun 12:06:05 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCargar_Grafo;
    QAction *actionAgregar_Arista;
    QAction *actionRemover_Arista;
    QWidget *centralWidget;
    QTabWidget *tw_Contenedor;
    QWidget *Multigrafo;
    QWidget *gridLayoutWidget_2;
    QGridLayout *layoutGrafo;
    QGroupBox *groupBox;
    QComboBox *cb_Dias;
    QComboBox *cb_Hora;
    QLabel *label;
    QLabel *label_2;
    QGroupBox *groupBox_2;
    QLineEdit *le_Origen;
    QLineEdit *le_Destino;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *btn_Consultar;
    QTextEdit *te_RutaOptima;
    QLabel *label_5;
    QLabel *lbDia;
    QLabel *lbHora;
    QWidget *Floyd;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_floy;
    QWidget *gridLayoutWidget_3;
    QGridLayout *idem;
    QMenuBar *menuBar;
    QMenu *menu_Archivo;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(944, 615);
        MainWindow->setMinimumSize(QSize(944, 615));
        MainWindow->setMaximumSize(QSize(944, 615));
        actionCargar_Grafo = new QAction(MainWindow);
        actionCargar_Grafo->setObjectName(QString::fromUtf8("actionCargar_Grafo"));
        actionAgregar_Arista = new QAction(MainWindow);
        actionAgregar_Arista->setObjectName(QString::fromUtf8("actionAgregar_Arista"));
        actionRemover_Arista = new QAction(MainWindow);
        actionRemover_Arista->setObjectName(QString::fromUtf8("actionRemover_Arista"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tw_Contenedor = new QTabWidget(centralWidget);
        tw_Contenedor->setObjectName(QString::fromUtf8("tw_Contenedor"));
        tw_Contenedor->setGeometry(QRect(5, 4, 931, 571));
        Multigrafo = new QWidget();
        Multigrafo->setObjectName(QString::fromUtf8("Multigrafo"));
        gridLayoutWidget_2 = new QWidget(Multigrafo);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 10, 621, 531));
        layoutGrafo = new QGridLayout(gridLayoutWidget_2);
        layoutGrafo->setSpacing(6);
        layoutGrafo->setContentsMargins(11, 11, 11, 11);
        layoutGrafo->setObjectName(QString::fromUtf8("layoutGrafo"));
        layoutGrafo->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(Multigrafo);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(654, 6, 120, 151));
        groupBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        cb_Dias = new QComboBox(groupBox);
        cb_Dias->setObjectName(QString::fromUtf8("cb_Dias"));
        cb_Dias->setGeometry(QRect(10, 40, 101, 22));
        cb_Hora = new QComboBox(groupBox);
        cb_Hora->setObjectName(QString::fromUtf8("cb_Hora"));
        cb_Hora->setGeometry(QRect(50, 74, 61, 22));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 46, 16));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 79, 46, 13));
        label_2->setFont(font);
        groupBox_2 = new QGroupBox(Multigrafo);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(650, 166, 160, 141));
        le_Origen = new QLineEdit(groupBox_2);
        le_Origen->setObjectName(QString::fromUtf8("le_Origen"));
        le_Origen->setGeometry(QRect(70, 21, 81, 20));
        le_Destino = new QLineEdit(groupBox_2);
        le_Destino->setObjectName(QString::fromUtf8("le_Destino"));
        le_Destino->setGeometry(QRect(70, 71, 81, 20));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 71, 61, 21));
        label_3->setFont(font);
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 21, 61, 31));
        label_4->setFont(font);
        btn_Consultar = new QPushButton(groupBox_2);
        btn_Consultar->setObjectName(QString::fromUtf8("btn_Consultar"));
        btn_Consultar->setGeometry(QRect(10, 110, 140, 23));
        te_RutaOptima = new QTextEdit(Multigrafo);
        te_RutaOptima->setObjectName(QString::fromUtf8("te_RutaOptima"));
        te_RutaOptima->setGeometry(QRect(648, 318, 271, 221));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        te_RutaOptima->setFont(font1);
        label_5 = new QLabel(Multigrafo);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(820, 10, 61, 16));
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setUnderline(true);
        font2.setWeight(75);
        label_5->setFont(font2);
        lbDia = new QLabel(Multigrafo);
        lbDia->setObjectName(QString::fromUtf8("lbDia"));
        lbDia->setGeometry(QRect(800, 40, 121, 41));
        lbDia->setFont(font);
        lbHora = new QLabel(Multigrafo);
        lbHora->setObjectName(QString::fromUtf8("lbHora"));
        lbHora->setGeometry(QRect(800, 100, 101, 16));
        lbHora->setFont(font);
        tw_Contenedor->addTab(Multigrafo, QString());
        Floyd = new QWidget();
        Floyd->setObjectName(QString::fromUtf8("Floyd"));
        gridLayoutWidget = new QWidget(Floyd);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 541, 451));
        gridLayout_floy = new QGridLayout(gridLayoutWidget);
        gridLayout_floy->setSpacing(6);
        gridLayout_floy->setContentsMargins(11, 11, 11, 11);
        gridLayout_floy->setObjectName(QString::fromUtf8("gridLayout_floy"));
        gridLayout_floy->setContentsMargins(0, 0, 0, 0);
        gridLayoutWidget_3 = new QWidget(Floyd);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(580, 10, 160, 451));
        idem = new QGridLayout(gridLayoutWidget_3);
        idem->setSpacing(6);
        idem->setContentsMargins(11, 11, 11, 11);
        idem->setObjectName(QString::fromUtf8("idem"));
        idem->setContentsMargins(0, 0, 0, 0);
        tw_Contenedor->addTab(Floyd, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 944, 21));
        menu_Archivo = new QMenu(menuBar);
        menu_Archivo->setObjectName(QString::fromUtf8("menu_Archivo"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menu_Archivo->menuAction());
        menu_Archivo->addAction(actionCargar_Grafo);
        menu_Archivo->addAction(actionAgregar_Arista);
        menu_Archivo->addAction(actionRemover_Arista);

        retranslateUi(MainWindow);

        tw_Contenedor->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Ruta Corta", 0, QApplication::UnicodeUTF8));
        actionCargar_Grafo->setText(QApplication::translate("MainWindow", "Cargar Grafo", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionCargar_Grafo->setToolTip(QApplication::translate("MainWindow", "Carge un grafo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionCargar_Grafo->setShortcut(QApplication::translate("MainWindow", "Ctrl+G", 0, QApplication::UnicodeUTF8));
        actionAgregar_Arista->setText(QApplication::translate("MainWindow", "Agregar o Modificar Arista", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionAgregar_Arista->setToolTip(QApplication::translate("MainWindow", "Agregar Arista", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionAgregar_Arista->setShortcut(QApplication::translate("MainWindow", "Ctrl+A", 0, QApplication::UnicodeUTF8));
        actionRemover_Arista->setText(QApplication::translate("MainWindow", "Remover Arista", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionRemover_Arista->setToolTip(QApplication::translate("MainWindow", "Borra Arista Entre 2 Nodos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionRemover_Arista->setShortcut(QApplication::translate("MainWindow", "Ctrl+D", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Filtro", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Dia", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Hora", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Calcular Ruta", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Destino", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Origen", 0, QApplication::UnicodeUTF8));
        btn_Consultar->setText(QApplication::translate("MainWindow", "Consultar", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Aristas", 0, QApplication::UnicodeUTF8));
        lbDia->setText(QApplication::translate("MainWindow", "Grafo para dia:", 0, QApplication::UnicodeUTF8));
        lbHora->setText(QApplication::translate("MainWindow", "Hora:", 0, QApplication::UnicodeUTF8));
        tw_Contenedor->setTabText(tw_Contenedor->indexOf(Multigrafo), QApplication::translate("MainWindow", "Multigrafo", 0, QApplication::UnicodeUTF8));
        tw_Contenedor->setTabText(tw_Contenedor->indexOf(Floyd), QApplication::translate("MainWindow", "Floyd", 0, QApplication::UnicodeUTF8));
        menu_Archivo->setTitle(QApplication::translate("MainWindow", "&Archivo", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
