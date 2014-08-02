#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include "adm_window.h"
#include "director_window.h"
#include "data_base.h"
#include "dbf.h"
using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_pushButton_login_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
