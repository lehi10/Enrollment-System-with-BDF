#ifndef DIRECTOR_WINDOW_H
#define DIRECTOR_WINDOW_H

#include <QMainWindow>

namespace Ui {
class director_window;
}

class director_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit director_window(QWidget *parent = 0);
    ~director_window();

private:
    Ui::director_window *ui;
};

#endif // DIRECTOR_WINDOW_H
