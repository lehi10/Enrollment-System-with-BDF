#ifndef DIRECTOR_WINDOW_H
#define DIRECTOR_WINDOW_H

#include <QMainWindow>
#include"data_base.h"

namespace Ui {
class director_window;
}

class director_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit director_window(QWidget *parent = 0);
    ~director_window();

private slots:

    void on_cargar_informacion_alumnos_clicked();

    void on_cargar_informacion_profesores_clicked();

    void on_cargar_informacion_administrativos_clicked();

    void on_agregar_adm_clicked();

    void on_agregar_profesor_clicked();

    void on_boton_agregar_alumno_clicked();

private:
    Ui::director_window *ui;
    data_base *DB_DIR;
};

#endif // DIRECTOR_WINDOW_H
