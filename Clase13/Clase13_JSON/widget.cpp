#include "widget.h"
#include "./ui_widget.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <QTextStream>
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

void Widget::on_pushButton_clicked()
{
    QString name = ui->name->text();
    QString age = ui->age->text();
    QString city = ui->city->text();

    QJsonObject jsonObj;
    jsonObj["name"] = name;
    jsonObj["age"] = age.toInt();
    jsonObj["city"] = city;

    QJsonDocument jsonDoc(jsonObj);

    QString jsonString = jsonDoc.toJson(QJsonDocument::Indented);

    QFile file("output.json");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream out(&file);
        out << jsonString;
        file. close();

        QMessageBox::information(this, "JSON Guardado", "El archivo JSON ha sido guardado exitosamente.");
    }else {
        QMessageBox::warning(this, "Error", "No se puedo abrir el archivo.");
    }
}

