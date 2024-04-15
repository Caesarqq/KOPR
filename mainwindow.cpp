#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aboutdialog.h"
#include "enddialog.h"
#include "connectionsettingsdialog.h"
#include "logindialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget->resizeColumnsToContents();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_about_triggered() {
    AboutDialog *dialog = new AboutDialog(this);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->exec();
}
void MainWindow::on_action_end_triggered() {
    EndDialog *dialog = new EndDialog(this);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->exec();
}
void MainWindow::on_action_2_triggered() {
    ConnectionSettingsDialog *dialog = new ConnectionSettingsDialog(this);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->exec();
}
void MainWindow::on_action_3_triggered() {
    LoginDialog *loginDialog = new LoginDialog(this);
    loginDialog->setAttribute(Qt::WA_DeleteOnClose);
    loginDialog->exec();
}
