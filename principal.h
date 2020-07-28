#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();
    void agregarTareas(QString,QString,QString,QString);
    void guarda();


private slots:
    void on_actionAgregar_triggered();

    void on_actionFinalizar_tarea_triggered();

    void on_actionSalir_triggered();

private:
    Ui::Principal *ui;
    void inicializarTareas();




};
#endif // PRINCIPAL_H
