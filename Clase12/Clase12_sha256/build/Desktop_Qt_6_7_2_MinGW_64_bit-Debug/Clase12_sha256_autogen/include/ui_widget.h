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
    QLineEdit *entrada;
    QPushButton *convertir;
    QLabel *salida;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(690, 320);
        entrada = new QLineEdit(Widget);
        entrada->setObjectName("entrada");
        entrada->setGeometry(QRect(250, 50, 113, 24));
        convertir = new QPushButton(Widget);
        convertir->setObjectName("convertir");
        convertir->setGeometry(QRect(270, 100, 80, 24));
        salida = new QLabel(Widget);
        salida->setObjectName("salida");
        salida->setGeometry(QRect(40, 200, 621, 31));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        convertir->setText(QCoreApplication::translate("Widget", "Convertir", nullptr));
        salida->setText(QCoreApplication::translate("Widget", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
