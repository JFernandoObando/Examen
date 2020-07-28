#include "agregar.h"
#include "ui_agregar.h"
#include"principal.h"
#include<QFile>
#include<QTextStream>
#include<QDebug>

Agregar::Agregar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Agregar)
{
    ui->setupUi(this);
}

Agregar::~Agregar()
{
    delete ui;
}


void Agregar::on_pushButton_released()
{
    //Agrego un objeto de la clase principal
    Principal *prin=new Principal;
    //Cierro la ventana del dialog
    close();
    //Abro la ventana principal
    prin->show();

}

void Agregar::on_cmdoK_released()
{
    //Agrego un objeto de la clase principal
    Principal *prin=new Principal;
    //Obtengo datos ingresados
      QString nombre=ui->inNombre->text();
      QString tipo=ui->inTipo->currentText();
      QString fecha=ui->inFecha->text();
      //Establesco prioridad
      QString prioridad;

        if(ui->inPrioridadAlta->isChecked()){
            prioridad=tr("Alta");
        }
        if(ui->inPrioridadM->isChecked()){
            prioridad=tr("Media");
        }
        if(ui->inPrioridadB->isChecked()){
            prioridad=tr("Baja");
        }
        //Agrego los datos ingresados en el metodo de la clase principal
      prin->agregarTareas(nombre,tipo,fecha,prioridad);
      //Abro ventana principal y cierro ventada de agregar
      //Para que carge las nuevas tareas
      prin->show();

}
