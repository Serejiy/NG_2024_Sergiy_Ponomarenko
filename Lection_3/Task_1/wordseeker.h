#ifndef WORDSEEKER_H
#define WORDSEEKER_H

#include <QMainWindow>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui {
class WordSeeker;
}
QT_END_NAMESPACE

class WordSeeker : public QMainWindow {
    Q_OBJECT

public:
    WordSeeker(QWidget *parent = nullptr);
    ~WordSeeker();

private slots:
    void counter();
    void processText();

private:
    Ui::WordSeeker *ui;

    // Новые методы для шифрования и дешифрования
    QString encryptVigenere(const QString &text, const QString &key);
    QString decryptVigenere(const QString &text, const QString &key);
};

#endif
