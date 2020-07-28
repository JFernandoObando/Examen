#ifndef AGREGAR_H
#define AGREGAR_H

#include <QDialog>

namespace Ui {
class Agregar;
}

class Agregar : public QDialog
{
    Q_OBJECT

public:
    explicit Agregar(QWidget *parent = nullptr);
    ~Agregar();
public slots:

    void on_pushButton_released();

    void on_cmdoK_released();

private:
    Ui::Agregar *ui;
};

#endif // AGREGAR_H
