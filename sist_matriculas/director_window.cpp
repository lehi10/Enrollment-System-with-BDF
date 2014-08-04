#include "director_window.h"
#include "ui_director_window.h"
#include "libraries.h"
#include <QMessageBox>
#include <QTableWidgetItem>

director_window::director_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::director_window)
{
    ui->setupUi(this);
    DB_DIR=new data_base();
    ui->tabla_administrativos->setColumnWidth(0,30);
    ui->tabla_administrativos->setColumnWidth(3,70);
    ui->tabla_administrativos->setColumnWidth(2,150);
    ui->tabla_administrativos->setColumnWidth(4,50);

    ui->tabla_profesores->setColumnWidth(0,45);
    ui->tabla_profesores->setColumnWidth(3,70);
    ui->tabla_profesores->setColumnWidth(2,150);

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

void director_window::on_agregar_adm_clicked()
{
    string id=ui->input_adm_id->text().toStdString(),
           nombre=ui->input_nombre_adm->text().toStdString(),
           apellidos=ui->input_adm_apellidos->text().toStdString(),
           cargo=ui->input_adm_cargo->text().toStdString(),
           dni=ui->input_adm_dni->text().toStdString(),
           fecha_nac=ui->input_adm_fecha_nac->text().toStdString(),
           direccion=ui->input_adm_direccion->text().toStdString(),
           telf=ui->input_adm_telf->text().toStdString(),
           email=ui->input_adm_email->text().toStdString();
     string s1[9]= {id ,nombre,apellidos,cargo,dni,fecha_nac,direccion,telf,email};
     for(int i=0;i<9;i++)
     {
         if(s1[i]=="")
         {
             QMessageBox *msgBox=new QMessageBox(this);
             msgBox->setIcon(QMessageBox::Warning);
             msgBox->setText("Complete el formulario");
             msgBox->setWindowTitle("Confirmar");
             msgBox->setStandardButtons(QMessageBox::Ok);
             if(msgBox->exec() == QMessageBox::Ok)
             {
                 return;
             }
         }
     }


    QMessageBox *msgBox=new QMessageBox(this);
    msgBox->setText("¿ Esta seguro de agregar un nuevo Administrativo ?");
    msgBox->setWindowTitle("Confirmar");
    msgBox->setStandardButtons(QMessageBox::Yes|QMessageBox::No);
    if(msgBox->exec() == QMessageBox::Yes)
    {



        DB_DIR->administrativos.appendRecord(&s1[0],9);
    }
    on_cargar_informacion_administrativos_clicked();

}

void director_window::on_agregar_profesor_clicked()
{
    string id=ui->input_prof_id->text().toStdString(),
            nombre=ui->input_prof_nombre->text().toStdString(),
            apellidos=ui->input_prof_apellidos->text().toStdString(),
            escuela=ui->input_prof_escuela->text().toStdString(),
            profesion=ui->input_prof_profes->text().toStdString(),
            grado_prof=ui->input_prof_grado_p->text().toStdString(),
            dni=ui->input_prof_dni->text().toStdString(),
            fecha_nac=ui->input_prof_fecha->text().toStdString(),
            direccion=ui->input_prof_direccion->text().toStdString(),
            telf=ui->input_prof_telf->text().toStdString(),
            email=ui->input_prof_email->text().toStdString();
     string s1[11]= {id ,nombre,apellidos,escuela,profesion,grado_prof,dni,fecha_nac,direccion,telf,email};
     for(int i=0;i<11;i++)
     {
         if(s1[i]=="")
         {
             QMessageBox *msgBox=new QMessageBox(this);
             msgBox->setIcon(QMessageBox::Warning);
             msgBox->setText("Complete el formulario");
             msgBox->setWindowTitle("Confirmar");
             msgBox->setStandardButtons(QMessageBox::Ok);
             if(msgBox->exec() == QMessageBox::Ok)
             {
                 return;
             }
         }
     }


    QMessageBox *msgBox=new QMessageBox(this);
    msgBox->setText("¿ Esta seguro de agregar un nuevo Profesor ?");
    msgBox->setWindowTitle("Confirmar");
    msgBox->setStandardButtons(QMessageBox::Yes|QMessageBox::No);
    if(msgBox->exec() == QMessageBox::Yes)
    {
        DB_DIR->profesores.appendRecord(&s1[0],11);
        ui->input_prof_id->setText("");
        ui->input_prof_nombre->setText("");
        ui->input_prof_apellidos->setText("");
        ui->input_prof_escuela->setText("");
        ui->input_prof_profes->setText("");
        ui->input_prof_grado_p->setText("");
        ui->input_prof_dni->setText("");
        ui->input_prof_email->setText("");
        ui->input_prof_direccion->setText("");
        ui->input_prof_telf->setText("");
    }
    on_cargar_informacion_profesores_clicked();

}

void director_window::on_boton_agregar_alumno_clicked()
{
    string id=ui->input_alumno_id->text().toStdString(),
            nombre=ui->input_alumno_nombre->text().toStdString(),
            apellidos=ui->input_alumno_apellidos->text().toStdString(),
            escuela=ui->input_alumno_escuela->text().toStdString(),
            dni=ui->input_alumno_dni->text().toStdString(),
            fecha_nac=ui->input_alumno_fecha_nac->text().toStdString(),
            direccion=ui->input_alumno_direccion->text().toStdString(),
            telf=ui->input_alumno_telf->text().toStdString(),
            email=ui->input_alumno_email->text().toStdString();
     string s1[9]= {id ,nombre,apellidos,escuela,dni,fecha_nac,direccion,telf,email};
     for(int i=0;i<9;i++)
     {
         if(s1[i]=="")
         {
             QMessageBox *msgBox=new QMessageBox(this);
             msgBox->setIcon(QMessageBox::Warning);
             msgBox->setText("Complete el formulario");
             msgBox->setWindowTitle("Confirmar");
             msgBox->setStandardButtons(QMessageBox::Ok);
             if(msgBox->exec() == QMessageBox::Ok)
             {
                 return;
             }
         }
     }


    QMessageBox *msgBox=new QMessageBox(this);
    msgBox->setText("¿ Esta seguro de agregar un nuevo Alumno ?");
    msgBox->setWindowTitle("Confirmar");
    msgBox->setStandardButtons(QMessageBox::Yes|QMessageBox::No);
    if(msgBox->exec() == QMessageBox::Yes)
    {
        DB_DIR->alumnos.appendRecord(&s1[0],9);
        ui->input_alumno_id->setText("");
        ui->input_alumno_nombre->setText("");
        ui->input_alumno_apellidos->setText("");
        ui->input_alumno_escuela->setText("");
        ui->input_alumno_dni->setText("");
        ui->input_alumno_email->setText("");
        ui->input_alumno_direccion->setText("");
        ui->input_alumno_telf->setText("");
    }

    on_cargar_informacion_alumnos_clicked();
}
