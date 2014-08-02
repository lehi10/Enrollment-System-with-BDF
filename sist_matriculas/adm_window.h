#ifndef ADM_WINDOW_H
#define ADM_WINDOW_H

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

private:
    Ui::adm_window *ui;
};

#endif // ADM_WINDOW_H
