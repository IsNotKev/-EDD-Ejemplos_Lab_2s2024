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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLineEdit *entrada;
    QPushButton *insertar;
    QLabel *salida;
    QPushButton *graficar;
    QComboBox *comboBox;
    QLabel *salidaOrden;
    QLineEdit *inputEliminar;
    QPushButton *eliminar;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(927, 505);
        entrada = new QLineEdit(Widget);
        entrada->setObjectName("entrada");
        entrada->setGeometry(QRect(120, 80, 141, 31));
        insertar = new QPushButton(Widget);
        insertar->setObjectName("insertar");
        insertar->setGeometry(QRect(280, 80, 111, 31));
        salida = new QLabel(Widget);
        salida->setObjectName("salida");
        salida->setGeometry(QRect(460, 60, 371, 281));
        salida->setScaledContents(false);
        graficar = new QPushButton(Widget);
        graficar->setObjectName("graficar");
        graficar->setGeometry(QRect(200, 130, 111, 31));
        comboBox = new QComboBox(Widget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(150, 270, 161, 31));
        salidaOrden = new QLabel(Widget);
        salidaOrden->setObjectName("salidaOrden");
        salidaOrden->setGeometry(QRect(80, 340, 311, 31));
        QFont font;
        font.setPointSize(14);
        salidaOrden->setFont(font);
        inputEliminar = new QLineEdit(Widget);
        inputEliminar->setObjectName("inputEliminar");
        inputEliminar->setGeometry(QRect(310, 430, 171, 31));
        eliminar = new QPushButton(Widget);
        eliminar->setObjectName("eliminar");
        eliminar->setGeometry(QRect(500, 430, 121, 41));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        insertar->setText(QCoreApplication::translate("Widget", "Insertar", nullptr));
        salida->setText(QString());
        graficar->setText(QCoreApplication::translate("Widget", "Graficar", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Widget", "PreOrder", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Widget", "PostOrder", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("Widget", "InOrder", nullptr));

        salidaOrden->setText(QString());
        eliminar->setText(QCoreApplication::translate("Widget", "Elimiinar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
