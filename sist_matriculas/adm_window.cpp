#include "adm_window.h"
#include "ui_adm_window.h"

adm_window::adm_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::adm_window)
{
    ui->setupUi(this);
}

adm_window::~adm_window()
{
    delete ui;
}
