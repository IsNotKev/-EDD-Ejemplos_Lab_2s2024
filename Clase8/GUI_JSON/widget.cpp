#include "widget.h"
#include "./ui_widget.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

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

void Widget::on_cargar_clicked()
{
    QString ruta = QFileDialog::getOpenFileName(
        this,
        "Open file",
        "/",
        "Text Files (*.json);;All Files (*,*)");

    QString final;

    if(!ruta.isEmpty()){
        QFile file(ruta);

        if(file.open(QFile::ReadOnly)){
            // Leer todo el contenido del archivo
            QByteArray jsonData = file.readAll();
            file.close();

            // Crear un documento JSON a partir de los datos
            QJsonDocument doc = QJsonDocument::fromJson(jsonData);

            // Comprobar si el documento es un array
            if (doc.isArray()) {
                QJsonArray root = doc.array();

                // Iterar a través del array
                foreach (const QJsonValue &v, root) {
                    QJsonObject obj = v.toObject();
                    QString nombre = obj.value("nombre").toString();
                    int años = obj.value("años").toInt();

                    // Concatenar los valores
                    final += nombre + ", " + QString::number(años) + "\n";
                }

                // Mostrar el resultado en el widget 'result'
                ui->texto->setText(final);

                // Mostrar un MessageBox indicando que se leyó correctamente
                QMessageBox::information(this, "Éxito", "El archivo JSON se leyó correctamente.");
            } else {
                // Mostrar un mensaje de error si no es un array
                QMessageBox::warning(this, "Error", "El archivo JSON no es un array.");
            }

        }else{
            // Mostrar un mensaje de error si no se pudo abrir el archivo
            QMessageBox::warning(this, "Error", "No se pudo abrir el archivo.");
        }
    }
}

