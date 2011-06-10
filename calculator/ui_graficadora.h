/********************************************************************************
** Form generated from reading UI file 'graficadora.ui'
**
** Created: Wed 8. Jun 16:25:36 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAFICADORA_H
#define UI_GRAFICADORA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Graficadora
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *le_ecuacion;
    QPushButton *btn_graficar;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridTablita;
    QGroupBox *groupBox;
    QLineEdit *le_De;
    QLineEdit *le_A;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_8;
    QMenuBar *menubar;

    void setupUi(QMainWindow *Graficadora)
    {
        if (Graficadora->objectName().isEmpty())
            Graficadora->setObjectName(QString::fromUtf8("Graficadora"));
        Graficadora->resize(890, 570);
        centralwidget = new QWidget(Graficadora);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 651, 521));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        le_ecuacion = new QLineEdit(centralwidget);
        le_ecuacion->setObjectName(QString::fromUtf8("le_ecuacion"));
        le_ecuacion->setGeometry(QRect(720, 360, 160, 20));
        btn_graficar = new QPushButton(centralwidget);
        btn_graficar->setObjectName(QString::fromUtf8("btn_graficar"));
        btn_graficar->setGeometry(QRect(670, 390, 75, 23));
        gridLayoutWidget_2 = new QWidget(centralwidget);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(693, 30, 120, 231));
        gridTablita = new QGridLayout(gridLayoutWidget_2);
        gridTablita->setObjectName(QString::fromUtf8("gridTablita"));
        gridTablita->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(714, 262, 121, 80));
        le_De = new QLineEdit(groupBox);
        le_De->setObjectName(QString::fromUtf8("le_De"));
        le_De->setGeometry(QRect(34, 20, 71, 20));
        le_A = new QLineEdit(groupBox);
        le_A->setObjectName(QString::fromUtf8("le_A"));
        le_A->setGeometry(QRect(34, 50, 71, 20));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 22, 46, 20));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(16, 51, 50, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(670, 340, 46, 13));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(674, 360, 51, 20));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label_4->setFont(font);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(719, 10, 21, 21));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        label_5->setFont(font1);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(766, 10, 21, 21));
        label_8->setFont(font1);
        Graficadora->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Graficadora);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 890, 21));
        Graficadora->setMenuBar(menubar);

        retranslateUi(Graficadora);

        QMetaObject::connectSlotsByName(Graficadora);
    } // setupUi

    void retranslateUi(QMainWindow *Graficadora)
    {
        Graficadora->setWindowTitle(QApplication::translate("Graficadora", "MainWindow", 0, QApplication::UnicodeUTF8));
        btn_graficar->setText(QApplication::translate("Graficadora", "Graficar", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Graficadora", "Intervalos", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Graficadora", "DE:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Graficadora", "A:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Graficadora", "Funcion", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Graficadora", "F(X)=", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Graficadora", "X", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Graficadora", "Y", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Graficadora: public Ui_Graficadora {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAFICADORA_H
