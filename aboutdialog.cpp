#include "aboutdialog.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QGraphicsDropShadowEffect>

AboutDialog::AboutDialog(QWidget *parent) : QDialog(parent) {
    setWindowTitle(tr("О программе")); // Заголовок окна
    setFixedSize(400, 200); // Фиксированный размер окна

    // Эффект тени для окна
    auto shadowEffect = new QGraphicsDropShadowEffect(this);
    shadowEffect->setBlurRadius(10);
    shadowEffect->setXOffset(0);
    shadowEffect->setYOffset(0);
    shadowEffect->setColor(Qt::black);
    setGraphicsEffect(shadowEffect);

    QVBoxLayout *layout = new QVBoxLayout(this);

    // Label для отображения текста
    QLabel *label = new QLabel("Gost_Test 7fb218f4\nВерсия ПО 2.0", this);
    label->setStyleSheet("QLabel { color : white; }");
    label->setAlignment(Qt::AlignCenter);
    layout->addWidget(label);

    // Горизонтальный макет для кнопки
    QHBoxLayout *hLayout = new QHBoxLayout();
    hLayout->addStretch(1); // Растяжка, чтобы кнопка оказалась справа

    // Кнопка для закрытия диалога
    QPushButton *closeButton = new QPushButton(tr("Закрыть"), this);
    closeButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    closeButton->setStyleSheet(
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
    connect(closeButton, &QPushButton::clicked, this, &AboutDialog::accept);
    hLayout->addWidget(closeButton); // Добавляем кнопку в горизонтальный макет

    layout->addLayout(hLayout); // Добавляем горизонтальный макет в вертикальный

    // Установка основного макета для диалога
    setLayout(layout);

    // Установка цвета фона окна
    QPalette pal = palette();
    pal.setColor(QPalette::Window, QColor("#34495e"));
    setAutoFillBackground(true);
    setPalette(pal);
}
