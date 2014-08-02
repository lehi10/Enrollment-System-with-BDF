#include "director_window.h"
#include "ui_director_window.h"

director_window::director_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::director_window)
{
    ui->setupUi(this);
}

director_window::~director_window()
{
    delete ui;
}
