#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QInputDialog>
#include <QLineEdit>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_login_clicked()
{
    DBF readTest;
    readTest.open("../DB/usuarios.dbf",true);

    string id=ui->input_id->text().toStdString();
    string pass=ui->input_pass->text().toStdString();

    vector<string>* row=readTest.select_all_of(0,id);
    readTest.close();
    for_each(row->begin(),row->end(),[](string dato)
    {
       cout<<dato<<endl;
    });
    if((*row)[0]!= "")
    {
        if(pass==(*row)[1])
        {
            cout<<"succes"<<endl;
            if((*row)[2]=="adm")
            {
                adm_window *adm=new adm_window(this);

                adm->showMaximized();
                this->hide();
            }
            if((*row)[2]=="director")
            {
                director_window *direc=new director_window(this);
                direc->showMaximized();
                this->hide();
                return;
            }
        }
        else
        {
            QMessageBox messageBox;
            messageBox.warning(0,"Error","Contraseña Incorrecta !");
            messageBox.setFixedSize(500,200);
            return;

        }

    }
    else
    {
        QMessageBox messageBox;
        messageBox.warning(0,"Error","No existe el ID !");
        messageBox.setFixedSize(500,200);

    }




}


//MOSTRAR TODO EL CONTENIDO DE UNA TABLA
/*
vector<vector<string>*>* matriz=readTest.get_matriz();
for_each(matriz->begin(),matriz->end(),[](vector<string>* fila)
{
    for_each(fila->begin(),fila->end(),[](string dato)
    {
        cout<<dato<<" ";
    });
    cout<<endl;
});
*/

/*
    QString text = QInputDialog::getText(this, tr("Enter the username"),
    tr("User name:"), QLineEdit::Normal);
    cout<<text.toStdString()<<endl;
*/

/*
    QErrorMessage errorMessage;
    errorMessage.showMessage("Testing Error message");
    errorMessage.exec();
*/
