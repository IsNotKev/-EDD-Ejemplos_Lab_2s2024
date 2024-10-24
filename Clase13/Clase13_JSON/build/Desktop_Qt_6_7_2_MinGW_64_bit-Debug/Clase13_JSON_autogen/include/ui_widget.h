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
    QLineEdit *name;
    QLineEdit *city;
    QLineEdit *age;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(500, 332);
        name = new QLineEdit(Widget);
        name->setObjectName("name");
        name->setGeometry(QRect(220, 60, 113, 24));
        city = new QLineEdit(Widget);
        city->setObjectName("city");
        city->setGeometry(QRect(220, 90, 113, 24));
        age = new QLineEdit(Widget);
        age->setObjectName("age");
        age->setGeometry(QRect(220, 130, 113, 24));
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(110, 60, 61, 16));
        label_2 = new QLabel(Widget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(110, 90, 49, 16));
        label_3 = new QLabel(Widget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(120, 130, 49, 16));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(160, 200, 151, 51));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "Nombre", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "Ciudad", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "Edad", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "Escribir JSON", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
