#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QSettings>
#include <QCryptographicHash>

class LoginDialog : public QDialog {
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);

private slots:
    void handleLogin(); // Слот для обработки входа, который вы уже используете
    void on_registerButton_clicked();

private:
    QLineEdit *loginEdit; // Поле для ввода логина
    QLineEdit *passwordEdit; // Поле для ввода пароля
    QPushButton *loginButton; // Кнопка для подтверждения входа

    // Методы для аутентификации
    bool authenticate(const QString &username, const QString &password); // Проверка учетных данных
    QString hashPassword(const QString &password); // Хэширование пароля
    void saveCredentials(const QString& username, const QString& password); // Сохранение учетных данных
    QString retrievePasswordHash(const QString& username); // Получение хэша пароля
};

#endif // LOGINDIALOG_H
