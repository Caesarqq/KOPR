#include "RegisterDialog.h"
#include "logindialog.h"
#include <QGraphicsDropShadowEffect>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QMessageBox>
#include <QSettings>
#include <QCryptographicHash>

RegisterDialog::RegisterDialog(QWidget *parent) : QDialog(parent) {
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

    auto *titleLabel = new QLabel(tr("Регистрация"), whitePanel);
    titleLabel->setStyleSheet("color: black; font-size: 24px; font-weight: bold;");
    titleLabel->setAlignment(Qt::AlignCenter);

    auto *formLayout = new QFormLayout();
    formLayout->setContentsMargins(30, 20, 30, 20); // Увеличиваем отступы для центрирования
    formLayout->setAlignment(Qt::AlignCenter); // Центрируем все элементы формы

    auto *loginLabel = new QLabel(tr("Логин:"), whitePanel);
    usernameLineEdit = new QLineEdit(whitePanel);
    usernameLineEdit->setPlaceholderText(tr("Введите логин"));
    usernameLineEdit->setFixedSize(400, 40);

    auto *passwordLabel = new QLabel(tr("Пароль:"), whitePanel);
    passwordLineEdit = new QLineEdit(whitePanel);
    passwordLineEdit->setEchoMode(QLineEdit::Password);
    passwordLineEdit->setPlaceholderText("••••••••");
    passwordLineEdit->setFixedSize(400, 40);

    formLayout->addRow(loginLabel, usernameLineEdit);
    formLayout->addRow(passwordLabel, passwordLineEdit);

    QVBoxLayout *mainLayout = new QVBoxLayout(whitePanel);
    mainLayout->addWidget(titleLabel);
    mainLayout->addLayout(formLayout);

    // Горизонтальный лэйаут для кнопок
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    registerButton = new QPushButton(tr("Зарегистрироваться"), whitePanel);
    registerButton->setFixedSize(215, 45);
    registerButton->setStyleSheet("QPushButton { border: 2px solid #37474F; border-radius: 22px; background-color: #37474F; color: white; font-size: 18px; padding: 5px; }"
                                  "QPushButton:hover { background-color: #455A64; }");

    QPushButton *loginButton = new QPushButton(tr("Авторизация"), whitePanel);
    loginButton->setFixedSize(215, 45);
    loginButton->setStyleSheet("QPushButton { border: 2px solid #37474F; border-radius: 22px; background-color: #37474F; color: white; font-size: 18px; padding: 5px; }"
                               "QPushButton:hover { background-color: #455A64; }");

    buttonLayout->addWidget(registerButton);
    buttonLayout->addWidget(loginButton);
    mainLayout->addLayout(buttonLayout);

    connect(registerButton, &QPushButton::clicked, this, &RegisterDialog::on_registerButton_clicked);
    connect(loginButton, &QPushButton::clicked, this, &RegisterDialog::on_loginButton_clicked);
}

void RegisterDialog::on_registerButton_clicked() {
    QString username = usernameLineEdit->text();
    QString password = passwordLineEdit->text();
    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox warningBox;
        warningBox.setWindowTitle("Error");
        warningBox.setText("Please fill all fields");
        warningBox.setIcon(QMessageBox::Warning);
        warningBox.setStyleSheet("QMessageBox { background-color: white; }");
        warningBox.exec();
        return;
    }

    // Проверяем, существует ли уже такой пользователь
    if (isUsernameExists(username)) {
        QMessageBox warningBox;
        warningBox.setWindowTitle("Registration Error");
        warningBox.setText("User already exists. Please choose a different username.");
        warningBox.setIcon(QMessageBox::Warning);
        warningBox.setStyleSheet("QMessageBox { background-color: white; }");
        warningBox.exec();
        return;
    }

    saveCredentials(username, password);
    QMessageBox infoBox;
    infoBox.setWindowTitle("Registration");
    infoBox.setText("Registration successful!");
    infoBox.setIcon(QMessageBox::Information);
    infoBox.setStyleSheet("QMessageBox { background-color: white; }");
    infoBox.exec();
    accept();
}

bool RegisterDialog::isUsernameExists(const QString &username) {
    QSettings settings("YourOrg", "YourApp");
    return settings.contains(username); // Проверяем, содержит ли QSettings ключ с таким именем пользователя
}

void RegisterDialog::on_loginButton_clicked() {
    // Закрываем текущий диалог и открываем диалог авторизации
    close();
    LoginDialog loginDialog(this->parentWidget());
    loginDialog.exec();
}

void RegisterDialog::saveCredentials(const QString &username, const QString &password) {
    QSettings settings("YourOrg", "YourApp");
    settings.setValue(username, hashPassword(password));
}

QString RegisterDialog::hashPassword(const QString &password) {
    QByteArray hash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    return QString::fromUtf8(hash.toHex());
}
