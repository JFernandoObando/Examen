#include "principal.h"
#include<QTranslator>
#include<QInputDialog>
#include <QApplication>
#include<QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator traduccion;
    //Solicitando al usuario que seleccione un idioma
    QStringList idiomas;
    idiomas<<"Ingles"<<"Italiano"<<"Español";
    QString idioma=QInputDialog::getItem(NULL,
                                         "Idioma",
                                         "Seleccione un idioma",
                                         idiomas);
    //Dependiendo del idioma seleccionado,carga el archivo de traduccion*/
   if(idioma=="Ingles"){
        traduccion.load(":/Examen_en.qm");

    }else if(idioma=="Italiano"){

    }
    //Si es diferente de español se instala la traduccion en
    //toda la aplicacion
    if(idioma!="Español"){
        a.installTranslator(&traduccion);
    }
    Principal w;
    w.show();
    return a.exec();
}
