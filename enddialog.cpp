#include "enddialog.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QGraphicsDropShadowEffect>

EndDialog::EndDialog(QWidget *parent) : QDialog(parent) {
    setWindowTitle(tr("В группе все испытания завершены!")); // Заголовок окна
    setFixedSize(600, 300); // Фиксированный размер окна

    // Эффект тени для окна
    auto shadowEffect = new QGraphicsDropShadowEffect(this);
    shadowEffect->setBlurRadius(10);
    shadowEffect->setXOffset(0);
    shadowEffect->setYOffset(0);
    shadowEffect->setColor(Qt::black);
    setGraphicsEffect(shadowEffect);

    QVBoxLayout *layout = new QVBoxLayout(this);

    // Label для отображения текста
    QLabel *label = new QLabel("Количество испытаний в данной группе завершено, хотите создать новую группу испытаний?\n\n(В случае отказа, результаты испытаний не будут записаны)", this);
    label->setStyleSheet("QLabel { color : white; }");
    label->setAlignment(Qt::AlignCenter);
    layout->addWidget(label);

    // Горизонтальный макет для кнопки
    QHBoxLayout *hLayout = new QHBoxLayout();
    hLayout->addStretch(1); // Растяжка, чтобы кнопка оказалась справа

    // Кнопка для закрытия диалога
    QPushButton *yesButton = new QPushButton(tr("Да"), this);
    yesButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    yesButton->setStyleSheet(
        "QPushButton {"
        "  color: white;"
        "  background-color: #1c3545;"
        "  border: 1px solid white;"
        "  border-radius: 10px;"
        "  padding: 5px;"
        "}"
        "QPushButton:hover {"
        "  background-color: #4b5d6a;"
        "  color: white;"
        "}"
        );
    connect(yesButton, &QPushButton::clicked, this, &EndDialog::accept);
    hLayout->addWidget(yesButton); // Добавляем кнопку в горизонтальный макет

    QPushButton *noButton = new QPushButton(tr("Нет"), this);
    noButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    noButton->setStyleSheet(
        "QPushButton {"
        "  color: white;"
        "  background-color: #1c3545;"
        "  border: 1px solid white;"
        "  border-radius: 10px;"
        "  padding: 5px;"
        "}"
        "QPushButton:hover {"
        "  background-color: #4b5d6a;"
        "  color: white;"
        "}"
        );
    connect(noButton, &QPushButton::clicked, this, &EndDialog::accept);
    hLayout->addWidget(noButton); // Добавляем кнопку в горизонтальный макет
    layout->addLayout(hLayout); // Добавляем горизонтальный макет в вертикальный

    // Установка основного макета для диалога
    setLayout(layout);

    // Установка цвета фона окна
    QPalette pal = palette();
    pal.setColor(QPalette::Window, QColor("#34495e"));
    setAutoFillBackground(true);
    setPalette(pal);
}
