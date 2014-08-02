#include "director_window.h"
#include "ui_director_window.h"
#include "libraries.h"
#include <QTableWidgetItem>

director_window::director_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::director_window)
{
    ui->setupUi(this);
    DB_DIR=new data_base();

}

director_window::~director_window()
{
    delete ui;
}



void director_window::on_cargar_informacion_alumnos_clicked()
{
    cout<<"pass"<<endl;
    vector<vector<string>*> * matriz=DB_DIR->alumnos.get_matriz();
    cout<<"pass2"<<endl;
    ui->tabla_alumnos->setRowCount(DB_DIR->alumnos.GetNumRecords());
    cout<<"pass3"<<endl;
    int current_column=0;

    for_each(matriz->begin(),matriz->end(),[this,&current_column](vector<string>* fila)
    {
        int current_row=0;
        for_each(fila->begin(),fila->end(),[this,&current_row,&current_column](string dato)
        {
            ui->tabla_alumnos->setItem(current_row,current_column,new QTableWidgetItem(QString(dato.c_str())));
            current_row++;

        });
        cout<<endl;
        current_column++;
    });

}

void director_window::on_cargar_informacion_profesores_clicked()
{
    vector<vector<string>*> * matriz=DB_DIR->profesores.get_matriz();
    ui->tabla_profesores->setRowCount(DB_DIR->profesores.GetNumRecords());
    int current_column=0;

    for_each(matriz->begin(),matriz->end(),[this,&current_column](vector<string>* fila)
    {
        int current_row=0;
        for_each(fila->begin(),fila->end(),[this,&current_row,&current_column](string dato)
        {
            ui->tabla_profesores->setItem(current_row,current_column,new QTableWidgetItem(QString(dato.c_str())));
            current_row++;
        });
        current_column++;
    });
}

void director_window::on_cargar_informacion_administrativos_clicked()
{
    vector<vector<string>*> * matriz=DB_DIR->administrativos.get_matriz();
    ui->tabla_administrativos->setRowCount(DB_DIR->administrativos.GetNumRecords());
    int current_column=0;

    for_each(matriz->begin(),matriz->end(),[this,&current_column](vector<string>* fila)
    {
        int current_row=0;
        for_each(fila->begin(),fila->end(),[this,&current_row,&current_column](string dato)
        {
            ui->tabla_administrativos->setItem(current_row,current_column,new QTableWidgetItem(QString(dato.c_str())));
            current_row++;

        });
        cout<<endl;
        current_column++;
    });
}
