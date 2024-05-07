#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QSettings>
#include <QCryptographicHash>

class RegisterDialog : public QDialog {
    Q_OBJECT

public:
    explicit RegisterDialog(QWidget *parent = nullptr);

private slots:
    void on_registerButton_clicked();
    void on_loginButton_clicked();
private:
    QLineEdit *usernameLineEdit;
    QLineEdit *passwordLineEdit;
    QPushButton *registerButton;

    bool isUsernameExists(const QString &username);
    void saveCredentials(const QString &username, const QString &password);
    QString hashPassword(const QString &password);
};

#endif // REGISTERDIALOG_H
