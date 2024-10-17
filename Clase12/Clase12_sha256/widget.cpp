#include "widget.h"
#include "./ui_widget.h"
#include <QCryptographicHash>
#include <QMessageBox>

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

void Widget::on_convertir_clicked()
{
    QString entrada = ui->entrada->text();

    if (entrada.isEmpty()){
        QMessageBox::warning(this,"Entrada Vacía", "Por favor, ingrese texto");
        return;
    }

    QCryptographicHash hash(QCryptographicHash::Sha256);
    hash.addData(entrada.toUtf8());
    QString salida = hash.result().toHex();

    ui->salida->setText(salida);
}

