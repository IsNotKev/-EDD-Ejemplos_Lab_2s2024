#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_sumar_clicked()
{
    int n1, n2, res;

    QString entrada1 = ui->num1->text();
    QString entrada2 = ui->num2->text();

    n1 = entrada1.toInt();
    n2 = entrada2.toInt();

    res = n1 + n2;

    ui->resultado->setText(QString::number(res));
}


void Widget::on_resta_clicked()
{
    int n1, n2, res;

    QString entrada1 = ui->num1->text();
    QString entrada2 = ui->num2->text();

    n1 = entrada1.toInt();
    n2 = entrada2.toInt();

    res = n1 - n2;

    ui->resultado->setText(QString::number(res));
}


void Widget::on_mul_clicked()
{
    int n1, n2, res;

    QString entrada1 = ui->num1->text();
    QString entrada2 = ui->num2->text();

    n1 = entrada1.toInt();
    n2 = entrada2.toInt();

    res = n1 * n2;

    ui->resultado->setText(QString::number(res));
}


void Widget::on_div_clicked()
{
    int n1, n2, res;

    QString entrada1 = ui->num1->text();
    QString entrada2 = ui->num2->text();

    n1 = entrada1.toInt();
    n2 = entrada2.toInt();

    res = n1 / n2;

    ui->resultado->setText(QString::number(res));
}

