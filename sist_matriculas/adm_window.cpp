#include "adm_window.h"
#include "ui_adm_window.h"
#include "libraries.h"
#include <QTableWidgetItem>

adm_window::adm_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::adm_window)
{
    ui->setupUi(this);
    DB=new data_base();

}

adm_window::~adm_window()
{
    delete ui;
}

void adm_window::on_tabWidget_tabBarClicked(int index)
{
    cout<<index<<endl;
}



void adm_window::on_cargar_alumnos_clicked()
{
    vector<vector<string>* > *matriz=DB->alumnos.get_matriz();
    ui->tabla_alumnos->setRowCount(DB->alumnos.GetNumRecords());

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
