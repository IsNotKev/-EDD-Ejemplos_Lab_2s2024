/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QLineEdit *num1;
    QLineEdit *num2;
    QPushButton *sumar;
    QLabel *label_2;
    QLabel *resultado;
    QPushButton *resta;
    QPushButton *mul;
    QPushButton *div;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(769, 511);
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(260, 20, 261, 61));
        QFont font;
        font.setPointSize(22);
        font.setBold(true);
        label->setFont(font);
        num1 = new QLineEdit(Widget);
        num1->setObjectName("num1");
        num1->setGeometry(QRect(270, 130, 221, 31));
        num2 = new QLineEdit(Widget);
        num2->setObjectName("num2");
        num2->setGeometry(QRect(270, 180, 221, 31));
        sumar = new QPushButton(Widget);
        sumar->setObjectName("sumar");
        sumar->setGeometry(QRect(210, 240, 161, 41));
        label_2 = new QLabel(Widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(180, 360, 161, 61));
        QFont font1;
        font1.setPointSize(20);
        label_2->setFont(font1);
        resultado = new QLabel(Widget);
        resultado->setObjectName("resultado");
        resultado->setGeometry(QRect(360, 360, 161, 61));
        resultado->setFont(font1);
        resta = new QPushButton(Widget);
        resta->setObjectName("resta");
        resta->setGeometry(QRect(390, 240, 161, 41));
        mul = new QPushButton(Widget);
        mul->setObjectName("mul");
        mul->setGeometry(QRect(210, 290, 161, 41));
        div = new QPushButton(Widget);
        div->setObjectName("div");
        div->setGeometry(QRect(390, 290, 161, 41));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Pantalla1", nullptr));
        label->setText(QCoreApplication::translate("Widget", "BIENVENIDOS", nullptr));
        sumar->setText(QCoreApplication::translate("Widget", "Suma +", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "Resultado:", nullptr));
        resultado->setText(QString());
        resta->setText(QCoreApplication::translate("Widget", "Resta -", nullptr));
        mul->setText(QCoreApplication::translate("Widget", "Multiplicaci\303\263n *", nullptr));
        div->setText(QCoreApplication::translate("Widget", "Divisi\303\263n /", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
