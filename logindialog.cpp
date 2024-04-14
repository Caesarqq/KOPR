#include "logindialog.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QDialogButtonBox>
#include <QGraphicsDropShadowEffect>

LoginDialog::LoginDialog(QWidget *parent) : QDialog(parent) {
    setFixedSize(610, 265); // Устанавливаем фиксированный размер окна/*
    // setStyleSheet("QDialog { background-color: #37474F; }"); // Фон основного окна*/
    this->setStyleSheet(
        "QDialog { background-color: #37474F; }"
        "QLabel { color: black; font-size: 18px; }"
        "QLineEdit { "
        "    border: 1px solid #a9a9a9; "
        // "    border-radius: 4px; "
        "    padding: 5px; "
        "    margin-bottom: 5px;"
        "    font-size: 18px; "
        "    padding-left: 10px; " // Добавляем отступ слева
        "}"
        "#whitePanel { "
        "    background-color: white; "
        "    border-radius: 10px; "
        "}"
        );
    // Создаем эффект тени для белой панели
    auto *shadowEffect = new QGraphicsDropShadowEffect(this);
    shadowEffect->setBlurRadius(15);
    shadowEffect->setXOffset(0);
    shadowEffect->setYOffset(8);
    shadowEffect->setColor(QColor(0, 0, 0, 150));

    // Белая панель, которая будет включать заголовок и поля ввода
    auto *whitePanel = new QWidget(this);
    whitePanel->setGraphicsEffect(shadowEffect);
    whitePanel->setStyleSheet("background-color: white; border-radius: 10px;");
    whitePanel->setFixedSize(560, 225); // Чуть меньше, чтобы тень была видна
    whitePanel->move(25, 20); // Немного отступаем от краев основного окна

    auto *titleLabel = new QLabel(tr("Авторизация"), whitePanel);
    titleLabel->setStyleSheet("color: black; font-size: 24px; font-weight: bold;");
    titleLabel->setAlignment(Qt::AlignCenter);

    // Настраиваем стили для полей ввода и кнопки
    auto *formLayout = new QFormLayout();
    formLayout->setContentsMargins(10,20,10,20);
    formLayout->setVerticalSpacing(15);
    auto *loginLabel = new QLabel(tr("Логин:"), whitePanel);
    auto *loginEdit = new QLineEdit(whitePanel);
    loginEdit->setPlaceholderText(tr("Введите логин"));
    loginEdit->setFixedSize(400, 40);

    auto *passwordLabel = new QLabel(tr("Пароль:"), whitePanel);
    auto *passwordEdit = new QLineEdit(whitePanel);
    passwordEdit->setPlaceholderText("••••••••");
    passwordEdit->setEchoMode(QLineEdit::Password);
    passwordEdit->setFixedSize(400, 40);

    formLayout->addRow(loginLabel, loginEdit);
    formLayout->addRow(passwordLabel, passwordEdit);

    auto *loginButton = new QPushButton(tr("Войти"), whitePanel);
    loginButton->setFixedSize(165, 45);
    connect(loginButton, &QPushButton::clicked, this, &LoginDialog::handleLogin);
    loginButton->setStyleSheet(
        "QPushButton { "
        "    border: 2px solid #37474F; " // Темно-синяя обводка для кнопки
        "    border-radius: 22px; "
        "    background-color: #37474F; " // Темно-синий фон
        "    color: white; "
        "    font-size: 18px; "
        "    padding: 5px; "
        "}"
        "QPushButton:hover { "
        "    background-color: #455A64; " // Чуть светлее цвет для эффекта наведения
        "}"
        );

    // Создаем главный вертикальный лейаут для белой панели
    auto *mainLayout = new QVBoxLayout(whitePanel);
    mainLayout->addWidget(titleLabel);
    mainLayout->addLayout(formLayout);
    mainLayout->addWidget(loginButton, 0, Qt::AlignCenter);

    setModal(true);
}

void LoginDialog::handleLogin() {
    // Здесь должна быть логика проверки данных для входа
    accept(); // Этот вызов закроет диалог с результатом QDialog::Accepted
}
