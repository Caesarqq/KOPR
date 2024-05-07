// logindialog.cpp
#include "logindialog.h"
#include "registerdialog.h"  // Убедитесь, что подключили header файла вашего RegisterDialog
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QGraphicsDropShadowEffect>
#include <QMessageBox>
#include <QSettings>
#include <QCryptographicHash>

LoginDialog::LoginDialog(QWidget *parent) : QDialog(parent) {
    setFixedSize(610, 265); // Фиксированный размер окна
    setStyleSheet("QDialog { background-color: #37474F; }" // Фон основного окна
                  "QLabel { color: black; font-size: 18px; }"
                  "QLineEdit { border: 1px solid #a9a9a9; padding: 5px; margin-bottom: 5px; font-size: 18px; padding-left: 10px; }"
                  "#whitePanel { background-color: white; border-radius: 10px; }");

    auto *shadowEffect = new QGraphicsDropShadowEffect(this);
    shadowEffect->setBlurRadius(15);
    shadowEffect->setXOffset(0);
    shadowEffect->setYOffset(8);
    shadowEffect->setColor(QColor(0, 0, 0, 150));

    auto *whitePanel = new QWidget(this);
    whitePanel->setGraphicsEffect(shadowEffect);
    whitePanel->setStyleSheet("background-color: white; border-radius: 10px;");
    whitePanel->setFixedSize(560, 225);
    whitePanel->move(25, 20);

    auto *titleLabel = new QLabel(tr("Авторизация"), whitePanel);
    titleLabel->setStyleSheet("color: black; font-size: 24px; font-weight: bold;");
    titleLabel->setAlignment(Qt::AlignCenter);

    auto *formLayout = new QFormLayout();
    formLayout->setContentsMargins(30, 20, 30, 20); // Увеличиваем отступы для центрирования
    formLayout->setVerticalSpacing(15);

    auto *loginLabel = new QLabel(tr("Логин:"), whitePanel);
    loginEdit = new QLineEdit(whitePanel);
    loginEdit->setPlaceholderText(tr("Введите логин"));
    loginEdit->setFixedSize(400, 40);

    auto *passwordLabel = new QLabel(tr("Пароль:"), whitePanel);
    passwordEdit = new QLineEdit(whitePanel);
    passwordEdit->setEchoMode(QLineEdit::Password);
    passwordEdit->setPlaceholderText("••••••••");
    passwordEdit->setFixedSize(400, 40);

    formLayout->addRow(loginLabel, loginEdit);
    formLayout->addRow(passwordLabel, passwordEdit);

    auto *buttonLayout = new QHBoxLayout(); // Создаем горизонтальный лэйаут для кнопок
    auto *loginButton = new QPushButton(tr("Войти"), whitePanel);
    loginButton->setFixedSize(165, 45);
    loginButton->setStyleSheet("QPushButton { border: 2px solid #37474F; border-radius: 22px; background-color: #37474F; color: white; font-size: 18px; padding: 5px; }"
                               "QPushButton:hover { background-color: #455A64; }");

    auto *registerButton = new QPushButton(tr("Регистрация"), whitePanel);
    registerButton->setFixedSize(165, 45);
    registerButton->setStyleSheet("QPushButton { border: 2px solid #37474F; border-radius: 22px; background-color: #37474F; color: white; font-size: 18px; padding: 5px; }"
                                  "QPushButton:hover { background-color: #455A64; }");

    buttonLayout->addWidget(loginButton);
    buttonLayout->addWidget(registerButton);

    QVBoxLayout *mainLayout = new QVBoxLayout(whitePanel);
    mainLayout->addWidget(titleLabel);
    mainLayout->addLayout(formLayout);
    mainLayout->addLayout(buttonLayout, 0); // Добавляем кнопки в общий вертикальный лэйаут

    connect(loginButton, &QPushButton::clicked, this, &LoginDialog::handleLogin);
    connect(registerButton, &QPushButton::clicked, this, &LoginDialog::on_registerButton_clicked);

    setModal(true);
}

void LoginDialog::handleLogin() {
    QString username = loginEdit->text();
    QString password = passwordEdit->text();
    if (authenticate(username, password)) {
        QMessageBox infoBox;
        infoBox.setWindowTitle("Login Successful");
        infoBox.setText("Login successful!");
        infoBox.setIcon(QMessageBox::Information);
        infoBox.setStyleSheet("QMessageBox { background-color: white; }");  // Применяем тот же стиль, что и для регистрации
        infoBox.exec();
        accept();
    } else {
        QMessageBox warningBox;
        warningBox.setWindowTitle("Login");
        warningBox.setText("Invalid username or password!");
        warningBox.setIcon(QMessageBox::Warning);
        warningBox.setStyleSheet("QMessageBox { background-color: white; }");  // Стиль как у регистрации
        warningBox.exec();
    }
}

bool LoginDialog::authenticate(const QString &username, const QString &password) {
    QString storedHash = retrievePasswordHash(username);
    return storedHash == hashPassword(password);
}

QString LoginDialog::hashPassword(const QString &password) {
    QByteArray hash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    return QString::fromUtf8(hash.toHex());
}

QString LoginDialog::retrievePasswordHash(const QString& username) {
    QSettings settings("YourOrg", "YourApp");
    return settings.value(username).toString();
}

void LoginDialog::on_registerButton_clicked() {
    // Закрываем текущий диалог и открываем диалог регистрации
    close();
    RegisterDialog regDialog(this->parentWidget());
    regDialog.exec();
}
