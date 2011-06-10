/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu 9. Jun 22:52:42 2011
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
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCargarDiccionario;
    QAction *actionCargarSopa;
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QListWidget *lw_palabrasEncontradas;
    QLabel *label;
    QPushButton *Resolver;
    QLineEdit *le_tiempo;
    QLineEdit *le_cantidadPalabras;
    QLabel *label_2;
    QLabel *label_3;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QListWidget *lw_Diccinario;
    QLabel *label_4;
    QPushButton *btn_reset;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(980, 678);
        actionCargarDiccionario = new QAction(MainWindow);
        actionCargarDiccionario->setObjectName(QString::fromUtf8("actionCargarDiccionario"));
        actionCargarSopa = new QAction(MainWindow);
        actionCargarSopa->setObjectName(QString::fromUtf8("actionCargarSopa"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 771, 621));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayoutWidget_2 = new QWidget(centralWidget);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(806, 40, 160, 311));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        lw_palabrasEncontradas = new QListWidget(gridLayoutWidget_2);
        lw_palabrasEncontradas->setObjectName(QString::fromUtf8("lw_palabrasEncontradas"));

        gridLayout_2->addWidget(lw_palabrasEncontradas, 0, 0, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(807, 16, 141, 16));
        QFont font;
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        Resolver = new QPushButton(centralWidget);
        Resolver->setObjectName(QString::fromUtf8("Resolver"));
        Resolver->setGeometry(QRect(806, 370, 75, 23));
        le_tiempo = new QLineEdit(centralWidget);
        le_tiempo->setObjectName(QString::fromUtf8("le_tiempo"));
        le_tiempo->setGeometry(QRect(916, 420, 41, 20));
        le_cantidadPalabras = new QLineEdit(centralWidget);
        le_cantidadPalabras->setObjectName(QString::fromUtf8("le_cantidadPalabras"));
        le_cantidadPalabras->setGeometry(QRect(916, 450, 41, 20));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(860, 421, 51, 16));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(787, 450, 121, 21));
        label_3->setFont(font1);
        gridLayoutWidget_3 = new QWidget(centralWidget);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(787, 500, 159, 131));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        lw_Diccinario = new QListWidget(gridLayoutWidget_3);
        lw_Diccinario->setObjectName(QString::fromUtf8("lw_Diccinario"));

        gridLayout_3->addWidget(lw_Diccinario, 0, 0, 1, 1);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(787, 470, 71, 30));
        label_4->setFont(font1);
        btn_reset = new QPushButton(centralWidget);
        btn_reset->setObjectName(QString::fromUtf8("btn_reset"));
        btn_reset->setGeometry(QRect(888, 370, 75, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 980, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionCargarDiccionario);
        menuFile->addAction(actionCargarSopa);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Letter Soup Resolver", 0, QApplication::UnicodeUTF8));
        actionCargarDiccionario->setText(QApplication::translate("MainWindow", "cargarDiccionario", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionCargarDiccionario->setToolTip(QApplication::translate("MainWindow", "Cargar Palabras", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionCargarDiccionario->setShortcut(QApplication::translate("MainWindow", "Ctrl+D", 0, QApplication::UnicodeUTF8));
        actionCargarSopa->setText(QApplication::translate("MainWindow", "CargarSopa", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionCargarSopa->setToolTip(QApplication::translate("MainWindow", "Elija una Sopa", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionCargarSopa->setShortcut(QApplication::translate("MainWindow", "Ctrl+F", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Palabras Encontradas", 0, QApplication::UnicodeUTF8));
        Resolver->setText(QApplication::translate("MainWindow", "Resolver ", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Tiempo: ", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Cantidad Palabras:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Diccionario", 0, QApplication::UnicodeUTF8));
        btn_reset->setText(QApplication::translate("MainWindow", "Reset", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "&File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
