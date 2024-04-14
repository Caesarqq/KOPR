#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

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

    void on_action_about_triggered();
    void on_action_end_triggered();
<<<<<<< HEAD
    void on_action_2_triggered();
=======
    void on_action_3_triggered();
>>>>>>> ef06c7026cc3bf54404f648df4dcabdc578d8cb0
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
