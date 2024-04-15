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

    void on_action_2_triggered();

    void on_action_3_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
