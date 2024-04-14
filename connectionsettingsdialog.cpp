#include "connectionsettingsdialog.h"
#include <QComboBox>
#include <QLabel>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QGraphicsDropShadowEffect>
#include <QWidget>

ConnectionSettingsDialog::ConnectionSettingsDialog(QWidget *parent) :
    QDialog(parent) {
    setWindowTitle(tr("Настройки соединения"));
    setFixedSize(610, 430); // Установка размера окна

    // Стилизация элементов диалога
    QString labelStyle = "QLabel { color: #ffffff; }";
    QString panelStyle = "QWidget { background-color: white; border-radius: 5px; padding: 10px; }";
    QString comboBoxStyle = "QComboBox {"
                            "    background-color: transparent;"
                            "    border: 1px solid gray;"
                            "    border-radius: 3px;"
                            "    padding: 1px 18px 1px 3px;"
                            "    color: black;"
                            "    min-width: 6em;"
                            "}";
    QString buttonStyle = "QPushButton {"
                          "    background-color: #4B5D6A;"
                          "    color: white;"
                          "    border: 5px solid white;"
                          "    border-radius: 15px;"
                          "    padding: 5px 10px;"
                          "    font-size: 17px;"
                          "    margin-right: 10px;"
                          "    margin-left: 10px;"
                          "}";

    QString settingsLabelStyle = "QLabel {"
                                 "    color: white;"
                                 "    font-size: 17px;"
                                 "    text-align: center;"
                                 "    margin-top: 20px;"  // Добавлен верхний отступ для размещения ниже кнопок
                                 "}";

    // Создание и настройка QComboBox
    QComboBox *portComboBox = new QComboBox();
    QComboBox *speedComboBox = new QComboBox();
    QComboBox *dataBitsComboBox = new QComboBox();
    QComboBox *parityComboBox = new QComboBox();
    QComboBox *stopBitsComboBox = new QComboBox();
    QComboBox *addressComboBox = new QComboBox();

    // Добавление элементов в QComboBox
    portComboBox->addItems(QStringList() << "COM3" << "COM1" << "COM2");
    speedComboBox->addItem("115200");
    dataBitsComboBox->addItem("8");
    stopBitsComboBox->addItem("1");
    parityComboBox->addItem(tr("Четный"));
    addressComboBox->addItem("1");

    // Применение стилей к ComboBox
    portComboBox->setStyleSheet(comboBoxStyle);
    speedComboBox->setStyleSheet(comboBoxStyle);
    dataBitsComboBox->setStyleSheet(comboBoxStyle);
    parityComboBox->setStyleSheet(comboBoxStyle);
    stopBitsComboBox->setStyleSheet(comboBoxStyle);
    addressComboBox->setStyleSheet(comboBoxStyle);

    // Панель для элементов управления
    QWidget *controlsPanel = new QWidget();
    controlsPanel->setStyleSheet(panelStyle);
    QFormLayout *formLayout = new QFormLayout(controlsPanel);
    formLayout->addRow(new QLabel(tr("Порт:")), portComboBox);
    formLayout->addRow(new QLabel(tr("Скорость:")), speedComboBox);
    formLayout->addRow(new QLabel(tr("Биты данных:")), dataBitsComboBox);
    formLayout->addRow(new QLabel(tr("Стоповые биты:")), stopBitsComboBox);
    formLayout->addRow(new QLabel(tr("Четность:")), parityComboBox);
    formLayout->addRow(new QLabel(tr("Адрес устройства:")), addressComboBox);

    // Создание кнопок "Подключиться" и "Отмена"
    QPushButton *connectButton = new QPushButton(tr("Подключиться"));
    QPushButton *cancelButton = new QPushButton(tr("Отмена"));
    connectButton->setStyleSheet(buttonStyle);
    cancelButton->setStyleSheet(buttonStyle);
    connectButton->setFixedSize(165, 45);
    cancelButton->setFixedSize(165, 45);

    // Горизонтальный макет для кнопок
    QHBoxLayout *buttonsLayout = new QHBoxLayout();
    buttonsLayout->addStretch();
    buttonsLayout->addWidget(connectButton);
    buttonsLayout->addWidget(cancelButton);
    buttonsLayout->addStretch();

    // Создание надписи "Настройки соединения"
    QLabel *settingsLabel = new QLabel(tr("Настройки соединения"));
    settingsLabel->setStyleSheet(settingsLabelStyle);
    settingsLabel->setAlignment(Qt::AlignCenter);
     settingsLabel->setFixedSize(200, 50);


     QHBoxLayout *titleLayout = new QHBoxLayout();
     titleLayout->addStretch(); // Добавляем растягивающий элемент перед надписью
     titleLayout->addWidget(settingsLabel);
     titleLayout->addStretch(); // Добавляем растягивающий элемент после надписи

    // Слоты для кнопок
    connect(connectButton, &QPushButton::clicked, this, &ConnectionSettingsDialog::accept);
    connect(cancelButton, &QPushButton::clicked, this, &ConnectionSettingsDialog::reject);

    // Вертикальный макет для размещения кнопок, надписи и панели управления
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(buttonsLayout); // Добавляем горизонтальный макет с кнопками
    mainLayout->addLayout(titleLayout);   // Добавляем горизонтальный макет с надписью "Настройки соединения"
    mainLayout->addWidget(controlsPanel); // Добавляем панель управления


    setLayout(mainLayout); // Установка главного макета для диалога
}
