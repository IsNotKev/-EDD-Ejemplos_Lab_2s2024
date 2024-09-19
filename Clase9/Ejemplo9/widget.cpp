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

void Widget::on_insertar_clicked()
{
    QString inputText = ui->entrada->text();

    bool ok;
    int value = inputText.toInt(&ok);

    if (ok){
        arbol.insert(value);
        ui->salida->setText("Valor insertado correctamente: " + inputText);
    }else{
        ui->salida->setText("Por favor ingrese un número válido");
    }

}


void Widget::on_graficar_clicked()
{
    arbol.graph("abb");

    QImage imagen = QImage("abb.png");
    QPixmap mapa = QPixmap::fromImage(imagen);

    ui->salida->setPixmap(mapa);
    ui->salida->setScaledContents(true);
}


void Widget::on_comboBox_currentIndexChanged(int index)
{
    QString resultado;

    switch (index) {
    case 0: //PreOrder
        resultado = QString::fromStdString(arbol.preorder());
        break;
    case 1: //PostOrder
        resultado = QString::fromStdString(arbol.posorder());
        break;
    case 2: //InOrder
        resultado = QString::fromStdString(arbol.inorder());
        break;
    default:
        resultado = "Seleccione un recorrido válido";
        break;
    }

    ui->salidaOrden->setText(resultado);
}


void Widget::on_eliminar_clicked()
{
    QString inputText = ui->inputEliminar->text();

    bool ok;
    int value = inputText.toInt(&ok);

    if (ok){
        arbol.del(value);
        ui->salida->setText("Valor eliminado correctamente: " + inputText);
    }else{
        ui->salida->setText("Por favor ingrese un número válido.");
    }
}

