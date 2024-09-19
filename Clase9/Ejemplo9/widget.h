#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "abb.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_insertar_clicked();

    void on_graficar_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_eliminar_clicked();

private:
    Ui::Widget *ui;
    ABB arbol;
};
#endif // WIDGET_H
