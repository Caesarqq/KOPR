#ifndef CONNECTIONSETTINGSDIALOG_H
#define CONNECTIONSETTINGSDIALOG_H

#include <QDialog>

class QComboBox;
class QLineEdit;
class QLabel;

class ConnectionSettingsDialog : public QDialog {
    Q_OBJECT

public:
    explicit ConnectionSettingsDialog(QWidget *parent = nullptr);

private:
    QComboBox *portComboBox;
    QComboBox *speedComboBox;
    QComboBox *dataBitsComboBox;
    QComboBox *parityComboBox;
    QComboBox *stopBitsComboBox;
    QComboBox *addressComboBox;
    QLineEdit *deviceAddressEdit;

};

#endif // CONNECTIONSETTINGSDIALOG_H
