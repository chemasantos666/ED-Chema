/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed 8. Jun 14:21:13 2011
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
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionGraficar;
    QWidget *centralWidget;
    QPushButton *btn_Evaluate;
    QLineEdit *le_inEcuation;
    QLabel *lb_expresion;
    QTextEdit *te_Show;
    QMenuBar *menuBar;
    QMenu *menuOptions;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(337, 262);
        actionGraficar = new QAction(MainWindow);
        actionGraficar->setObjectName(QString::fromUtf8("actionGraficar"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        btn_Evaluate = new QPushButton(centralWidget);
        btn_Evaluate->setObjectName(QString::fromUtf8("btn_Evaluate"));
        btn_Evaluate->setGeometry(QRect(250, 190, 75, 23));
        le_inEcuation = new QLineEdit(centralWidget);
        le_inEcuation->setObjectName(QString::fromUtf8("le_inEcuation"));
        le_inEcuation->setGeometry(QRect(20, 170, 301, 20));
        lb_expresion = new QLabel(centralWidget);
        lb_expresion->setObjectName(QString::fromUtf8("lb_expresion"));
        lb_expresion->setGeometry(QRect(20, 190, 61, 16));
        QFont font;
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        lb_expresion->setFont(font);
        te_Show = new QTextEdit(centralWidget);
        te_Show->setObjectName(QString::fromUtf8("te_Show"));
        te_Show->setGeometry(QRect(20, 20, 301, 141));
        te_Show->setFont(font);
        te_Show->setLayoutDirection(Qt::RightToLeft);
        te_Show->setTabChangesFocus(false);
        te_Show->setLineWrapMode(QTextEdit::WidgetWidth);
        te_Show->setReadOnly(true);
        te_Show->setAcceptRichText(false);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 337, 21));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QString::fromUtf8("menuOptions"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menuOptions->menuAction());
        menuOptions->addAction(actionGraficar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionGraficar->setText(QApplication::translate("MainWindow", "Graficar", 0, QApplication::UnicodeUTF8));
        btn_Evaluate->setText(QApplication::translate("MainWindow", "Evaluate", 0, QApplication::UnicodeUTF8));
        lb_expresion->setText(QApplication::translate("MainWindow", "Expresion", 0, QApplication::UnicodeUTF8));
        menuOptions->setTitle(QApplication::translate("MainWindow", "Opciones", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
