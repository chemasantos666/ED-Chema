/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat 18. Jun 15:46:35 2011
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
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCargar_Grafo;
    QAction *actionAgregar_Arista;
    QWidget *centralWidget;
    QTabWidget *tw_Contenedor;
    QWidget *Multigrafo;
    QWidget *gridLayoutWidget_2;
    QGridLayout *layoutGrafo;
    QGroupBox *groupBox;
    QComboBox *cb_Dias;
    QComboBox *cb_Hora;
    QPushButton *btn_MostrarGrafo;
    QLabel *label;
    QLabel *label_2;
    QGroupBox *groupBox_2;
    QLineEdit *le_Origen;
    QLineEdit *le_Destino;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *btn_Consultar;
    QGroupBox *groupBox_3;
    QLineEdit *le_OrigenM;
    QLineEdit *le_DestinoM;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *btn_Modificar;
    QLabel *label_7;
    QLineEdit *le_Tiempo;
    QWidget *Floy;
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
        MainWindow->resize(867, 615);
        actionCargar_Grafo = new QAction(MainWindow);
        actionCargar_Grafo->setObjectName(QString::fromUtf8("actionCargar_Grafo"));
        actionAgregar_Arista = new QAction(MainWindow);
        actionAgregar_Arista->setObjectName(QString::fromUtf8("actionAgregar_Arista"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tw_Contenedor = new QTabWidget(centralWidget);
        tw_Contenedor->setObjectName(QString::fromUtf8("tw_Contenedor"));
        tw_Contenedor->setGeometry(QRect(5, 4, 851, 571));
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
        btn_MostrarGrafo = new QPushButton(groupBox);
        btn_MostrarGrafo->setObjectName(QString::fromUtf8("btn_MostrarGrafo"));
        btn_MostrarGrafo->setGeometry(QRect(11, 115, 75, 23));
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
        groupBox_3 = new QGroupBox(Multigrafo);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(650, 319, 181, 191));
        le_OrigenM = new QLineEdit(groupBox_3);
        le_OrigenM->setObjectName(QString::fromUtf8("le_OrigenM"));
        le_OrigenM->setGeometry(QRect(82, 21, 81, 20));
        le_DestinoM = new QLineEdit(groupBox_3);
        le_DestinoM->setObjectName(QString::fromUtf8("le_DestinoM"));
        le_DestinoM->setGeometry(QRect(81, 66, 81, 20));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(9, 66, 61, 21));
        label_5->setFont(font);
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 21, 61, 31));
        label_6->setFont(font);
        btn_Modificar = new QPushButton(groupBox_3);
        btn_Modificar->setObjectName(QString::fromUtf8("btn_Modificar"));
        btn_Modificar->setGeometry(QRect(10, 155, 140, 23));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(8, 98, 131, 21));
        label_7->setFont(font);
        le_Tiempo = new QLineEdit(groupBox_3);
        le_Tiempo->setObjectName(QString::fromUtf8("le_Tiempo"));
        le_Tiempo->setGeometry(QRect(84, 124, 70, 20));
        tw_Contenedor->addTab(Multigrafo, QString());
        Floy = new QWidget();
        Floy->setObjectName(QString::fromUtf8("Floy"));
        gridLayoutWidget = new QWidget(Floy);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 541, 451));
        gridLayout_floy = new QGridLayout(gridLayoutWidget);
        gridLayout_floy->setSpacing(6);
        gridLayout_floy->setContentsMargins(11, 11, 11, 11);
        gridLayout_floy->setObjectName(QString::fromUtf8("gridLayout_floy"));
        gridLayout_floy->setContentsMargins(0, 0, 0, 0);
        gridLayoutWidget_3 = new QWidget(Floy);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(580, 10, 160, 451));
        idem = new QGridLayout(gridLayoutWidget_3);
        idem->setSpacing(6);
        idem->setContentsMargins(11, 11, 11, 11);
        idem->setObjectName(QString::fromUtf8("idem"));
        idem->setContentsMargins(0, 0, 0, 0);
        tw_Contenedor->addTab(Floy, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 867, 21));
        menu_Archivo = new QMenu(menuBar);
        menu_Archivo->setObjectName(QString::fromUtf8("menu_Archivo"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menu_Archivo->menuAction());
        menu_Archivo->addAction(actionCargar_Grafo);
        menu_Archivo->addAction(actionAgregar_Arista);

        retranslateUi(MainWindow);

        tw_Contenedor->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionCargar_Grafo->setText(QApplication::translate("MainWindow", "Cargar Grafo", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionCargar_Grafo->setToolTip(QApplication::translate("MainWindow", "Carge un grafo", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionCargar_Grafo->setShortcut(QApplication::translate("MainWindow", "Ctrl+G", 0, QApplication::UnicodeUTF8));
        actionAgregar_Arista->setText(QApplication::translate("MainWindow", "Agregar Arista", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionAgregar_Arista->setToolTip(QApplication::translate("MainWindow", "Agregar Arista", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionAgregar_Arista->setShortcut(QApplication::translate("MainWindow", "Ctrl+A", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Filtro", 0, QApplication::UnicodeUTF8));
        btn_MostrarGrafo->setText(QApplication::translate("MainWindow", "Mostrar", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Dia", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Hora", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Calcular Ruta", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Destino", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Origen", 0, QApplication::UnicodeUTF8));
        btn_Consultar->setText(QApplication::translate("MainWindow", "Consultar", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Modificacion", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Destino", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Origen", 0, QApplication::UnicodeUTF8));
        btn_Modificar->setText(QApplication::translate("MainWindow", "Modificar", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Tiempo Minutos", 0, QApplication::UnicodeUTF8));
        tw_Contenedor->setTabText(tw_Contenedor->indexOf(Multigrafo), QApplication::translate("MainWindow", "Multigrafo", 0, QApplication::UnicodeUTF8));
        tw_Contenedor->setTabText(tw_Contenedor->indexOf(Floy), QApplication::translate("MainWindow", "Floy", 0, QApplication::UnicodeUTF8));
        menu_Archivo->setTitle(QApplication::translate("MainWindow", "&Archivo", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
