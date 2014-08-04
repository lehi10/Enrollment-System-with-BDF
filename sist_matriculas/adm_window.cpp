#include "adm_window.h"
#include "ui_adm_window.h"
#include "libraries.h"
#include <QTableWidgetItem>
#include <QMessageBox>

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
    cout<<"pass"<<endl;
    vector<vector<string>*> * matriz=DB->alumnos.get_matriz();
    cout<<"pass2"<<endl;
    ui->tabla_alumnos->setRowCount(DB->alumnos.GetNumRecords());
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


void adm_window::on_boton_agregar_alumno_clicked()
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
        DB->alumnos.appendRecord(&s1[0],9);
        ui->input_alumno_id->setText("");
        ui->input_alumno_nombre->setText("");
        ui->input_alumno_apellidos->setText("");
        ui->input_alumno_escuela->setText("");
        ui->input_alumno_dni->setText("");
        ui->input_alumno_email->setText("");
        ui->input_alumno_direccion->setText("");
        ui->input_alumno_telf->setText("");
    }
    on_cargar_alumnos_clicked();
}


void adm_window::on_boton_buscar_calificaciones_alumno_clicked()
{
    string id_alumno=ui->input_id_alumno_notas->text().toStdString();
    vector<vector<string>* >* matriz_notas=DB->notas.matriz_select_all_of(0,id_alumno);
    if(matriz_notas->size()<1)
    {
        return;
    }
    ui->tabla_notas_alumno->setRowCount( matriz_notas->size());
    int aprovados=0;
    int desaprovados=0;
    int cursos=0;
    int promedio=0;

    for(int i=0;i<matriz_notas->size();i++)
    {
        for(int j=2;j<7;j++)
        {
            string dato=(*((*matriz_notas)[i]))[j];
            ui->tabla_notas_alumno->setItem(i,j-2,new QTableWidgetItem(QString(dato.c_str())));
            cout<<(*((*matriz_notas)[i]))[j]<<" ";
        }
        string nota_str=(*((*matriz_notas)[i]))[5];
        int nota=atoi(nota_str.c_str());
        if(nota>=11)
            aprovados++;
        if(nota<11)
            desaprovados++;
        cursos++;
        promedio=promedio+nota;
    }

    promedio=promedio/cursos;
    ui->line_nombre_alumno->setText(QString((*((*matriz_notas)[0]))[1].c_str()));
    ui->line_aprobado->setText(QString(to_string(aprovados).c_str()));
    ui->line_desaprobado->setText(QString(to_string(desaprovados).c_str()));
    ui->line_cant_cursos->setText(QString(to_string(cursos).c_str()));
    ui->line_promedio->setText(QString(to_string(promedio).c_str()));
}

void adm_window::on_boton_buscar_clicked()
{
        string id=ui->input_id_alumno_ing_notas->text().toStdString();
        try
        {
            vector<string>*row=DB->alumnos.select_all_of(0,id);
            string nombre_alumno=(*row)[1];
            nombre_alumno.append(" ").append((*row)[2]);
            ui->line_nombre_alumno_resultado->setText(QString(nombre_alumno.c_str()));
            ui->line_id_alumno_resultado->setText(QString(id.c_str()));
        }
        catch(string er)
        {

            QMessageBox *msgBox=new QMessageBox(this);
            msgBox->setIcon(QMessageBox::Warning);
            msgBox->setText(QString(er.c_str()));
            msgBox->setWindowTitle("Confirmar");
            msgBox->setStandardButtons(QMessageBox::Ok);
            if(msgBox->exec() == QMessageBox::Ok)
            {
                return;
            }
        }


}

void adm_window::on_boton_ingresar_nota_clicked()
{
    string  curso=ui->input_ing_notas_curso->text().toStdString(),
            nota1=ui->input_ing_notas_1nota->text().toStdString(),
            nota2=ui->input_ing_notas_2nota->text().toStdString(),
            nota3=ui->input_ing_notas_3nota->text().toStdString();

    int     promedio=(atoi(nota1.c_str())+atoi(nota2.c_str())+atoi(nota3.c_str()))/3;

    QString id_str=ui->line_id_alumno_resultado->text();
    QString nombre_alumno=ui->line_nombre_alumno_resultado->text();

    string s1[7]= {id_str.toStdString(),nombre_alumno.toStdString(),curso,nota1,nota2,nota3,to_string(promedio)};


     for(int i=0;i<7;i++)
     {
         cout<<s1[i]<< "/"<<endl;
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

    QString mensaje="¿ Esta seguro de registrar las notas ";
    mensaje.append(nombre_alumno).append(" ?");
    msgBox->setText(mensaje);
    msgBox->setWindowTitle("Confirmar");
    msgBox->setStandardButtons(QMessageBox::Yes|QMessageBox::No);
    if(msgBox->exec() == QMessageBox::Yes)
    {
        DB->notas.appendRecord(s1,7);
        ui->input_id_alumno_notas->setText("");
        ui->input_ing_notas_curso->setText("");
        ui->input_ing_notas_1nota->setText("");
        ui->input_ing_notas_2nota->setText("");
        ui->input_ing_notas_3nota->setText("");

        ui->line_nombre_alumno_estado->setText(nombre_alumno);
        ui->line_curso_estado->setText(QString(curso.c_str()));
        ui->line_promedio_estado->setText(QString(to_string(promedio).c_str()));
        if(promedio>=11)
        {
            ui->line_estado_curso_estado->setText("APROBADO");
        }
        else
        {
            ui->line_estado_curso_estado->setText("DESAPROBADO");
        }
    }

}
