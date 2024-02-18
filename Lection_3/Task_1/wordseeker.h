#ifndef WORDSEEKER_H
#define WORDSEEKER_H

#include <QMainWindow>
#include <QLineEdit>
#include <QTextEdit>
#include <QRadioButton>
#include <QSpinBox>

QT_BEGIN_NAMESPACE
namespace Ui { class WordSeeker; }
QT_END_NAMESPACE

class WordSeeker : public QMainWindow
{
    Q_OBJECT

public:
    WordSeeker(QWidget *parent = nullptr);
    ~WordSeeker();

private slots:
    void counter();
    void onEncryptionSelected();
    void onDecryptionSelected();

private:
    Ui::WordSeeker *ui;
    QSpinBox *spinBox; // Добавляем указатель на QSpinBox
    void encryptDecrypt(QString& text, int shift);
};

#endif // WORDSEEKER_H
