#include "principal.h"
#include "ui_principal.h"
#include<QFile>
#include<QDebug>
#include<QTableWidget>
#include"agregar.h"
#include<QMessageBox>

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    //Pongo las color a las cabeceras de la tabla
    ui->outDetalle->setStyleSheet("QHeaderView::section { color: red}");
    //Establesco las cabeceras de la tabla
    QStringList cabecera = {tr("Nombre"), tr("Tipo"), tr("Fecha"),tr("Prioridad")};
    ui->outDetalle->setColumnCount(4);
    ui->outDetalle->setHorizontalHeaderLabels(cabecera);
    inicializarTareas();

}

Principal::~Principal()
{
    delete ui;
}

void Principal::inicializarTareas()
{
    // abrir archivos
    QFile archivo("Tareas.txt");
    qDebug() << archivo.exists();
    // leer el archivo de productos
    if(archivo.open(QFile::ReadOnly)){
        QTextStream in(&archivo);
        while (!in.atEnd()){
            QString linea = in.readLine();
            //separar datos por ;
            QStringList datos = linea.split(';');
            //Separo por partes cada linea leida
            QString nombre = datos[0];
            QString tipo = datos[1];
            QString fecha = datos[2];
            QString prioridad=datos[3];
            int posicion=ui->outDetalle->rowCount();
            ui->outDetalle->insertRow(posicion);
            //Establesco en la tabla
            ui->outDetalle->setItem(posicion,0,new QTableWidgetItem(nombre));
            ui->outDetalle->setItem(posicion,1,new QTableWidgetItem(tipo));
            ui->outDetalle->setItem(posicion,2,new QTableWidgetItem(fecha));
            ui->outDetalle->setItem(posicion,3,new QTableWidgetItem(prioridad));


        }
    }else{
        qDebug()<<"No se encuentra el archivo Tareas.txt en la caperta de construccion";

    }
    archivo.close();
}

void Principal::agregarTareas(QString nombre,QString tipo,QString fecha,QString prioridad)
{
    //agrego mas tareas
    int pos=ui->outDetalle->rowCount();
    ui->outDetalle->insertRow(pos);
    ui->outDetalle->setItem(pos,0,new QTableWidgetItem(nombre));
    ui->outDetalle->setItem(pos,1,new QTableWidgetItem(tipo));
    ui->outDetalle->setItem(pos,2,new QTableWidgetItem(fecha));
    ui->outDetalle->setItem(pos,3,new QTableWidgetItem(prioridad));
   //LLamo al metodo guarda para guardar lo que se encuentra en la tabla
    guarda();

}

void Principal::guarda()
{

    QString fileName = "Tareas.txt";
    if (fileName.isEmpty()) {
        return;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly |   QFile::Text)) {
        ui->statusbar->showMessage(tr("No se puede abrir el archivo"));
        return;
    }

    QTextStream out(&file);
    int rowCount = ui->outDetalle->rowCount();
    int colCount = ui->outDetalle->columnCount();

    for (int i = 0; i < rowCount; i++) {

        for (int j = 0; j < colCount; j++) {
            if (j > 0) {
                out << ";";
            }
            QTableWidgetItem* item = ui->outDetalle->item(i,j);
            out << item->data(Qt::DisplayRole).toString();
        }
        out << "\n";
    }
    ui->statusbar->showMessage(tr("Guardado en el archivo: ") + fileName,5000);

}

void Principal::on_actionAgregar_triggered()
{
    //Implemento un objeto de clase Agregar
    Agregar *dlgAgregar=new Agregar;
    close();
    //Abro el dialog
    dlgAgregar->show();

}

void Principal::on_actionFinalizar_tarea_triggered()
{
    //Finalizo la tarea y elimina de la tabla
    int p = ui->outDetalle->currentRow();
    ui->outDetalle->removeRow(p);
}

void Principal::on_actionSalir_triggered()
{
    //Salgo del programa
    close();

}
