#ifndef ADM_WINDOW_H
#define ADM_WINDOW_H
#include"data_base.h"
#include <QMainWindow>

namespace Ui {
class adm_window;
}

class adm_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit adm_window(QWidget *parent = 0);
    ~adm_window();

private slots:
    void on_tabWidget_tabBarClicked(int index);


    void on_cargar_alumnos_clicked();

private:
    Ui::adm_window *ui;
    data_base *DB;

};

#endif // ADM_WINDOW_H
