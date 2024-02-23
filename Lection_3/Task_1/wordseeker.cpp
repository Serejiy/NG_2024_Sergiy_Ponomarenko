#include "wordseeker.h"
#include "ui_wordseeker.h"
#include <QDebug>

WordSeeker::WordSeeker(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WordSeeker)
{
    ui->setupUi(this);
    connect(ui->e_pattern, &QLineEdit::textChanged, this, &WordSeeker::counter);
    connect(ui->t_text, &QTextEdit::textChanged, this, &WordSeeker::counter);
    connect(ui->radioButton, &QRadioButton::clicked, this, &WordSeeker::processText);
    connect(ui->radioButton_2, &QRadioButton::clicked, this, &WordSeeker::processText);
}

WordSeeker::~WordSeeker()
{
    delete ui;
}

void WordSeeker::counter()
{
    qDebug() << "Counter triggered...";
    QString text = ui->t_text->toPlainText();
    QString pattern = ui->e_pattern->text();

    if (text.isEmpty() || pattern.isEmpty()) {
        qDebug() << "Text or pattern is empty. Exiting...";
        return;
    }

    int lastIndex = 0;
    int counter = 0;
    do {
        lastIndex = text.indexOf(pattern, lastIndex);
        if (lastIndex != -1) {
            counter++;
            lastIndex++;
        }
    } while (lastIndex != -1);
    qDebug() << "Counter result: " << counter;
    ui->l_result->setText(QString("Результат: %1").arg(QString::number(counter)));
}

void WordSeeker::processText() {
    qDebug() << "Processing text...";
    QString text = ui->t_text->toPlainText();
    QString pattern = ui->e_pattern->text();

    qDebug() << "Text: " << text;
    qDebug() << "Pattern: " << pattern;

    if (text.isEmpty() || pattern.isEmpty()) {
        qDebug() << "Text or pattern is empty. Exiting...";
        return;
    }

    QString result;
    if (ui->radioButton->isChecked()) {
        qDebug() << "Encrypting text...";
        result = encryptVigenere(text, pattern);
    } else if (ui->radioButton_2->isChecked()) {
        qDebug() << "Decrypting text...";
        result = decryptVigenere(text, pattern);
    }

    qDebug() << "Result: " << result;
    ui->t_text->setPlainText(result);
}

QString WordSeeker::encryptVigenere(const QString &text, const QString &key)
{
    qDebug() << "Encrypting text: " << text << " with key: " << key;
    QString result;
    int keyLength = key.length();
    for (int i = 0; i < text.length(); ++i) {
        QChar currentChar = text.at(i);
        if (currentChar.isLetter()) {
            int offset = currentChar.isLower() ? 'a' : 'A';
            int shift = key.at(i % keyLength).toLatin1() - offset;
            result.append(QChar((currentChar.toLatin1() - offset + shift) % 26 + offset));
        } else {
            result.append(currentChar);
        }
    }
    qDebug() << "Encrypted text: " << result;
    return result;
}

QString WordSeeker::decryptVigenere(const QString &text, const QString &key)
{
    qDebug() << "Decrypting text: " << text << " with key: " << key;
    QString result;
    int keyLength = key.length();
    for (int i = 0; i < text.length(); ++i) {
        QChar currentChar = text.at(i);
        if (currentChar.isLetter()) {
            int offset = currentChar.isLower() ? 'a' : 'A';
            int shift = key.at(i % keyLength).toLatin1() - offset;
            result.append(QChar((currentChar.toLatin1() - offset - shift + 26) % 26 + offset));
        } else {
            result.append(currentChar);
        }
    }
    qDebug() << "Decrypted text: " << result;
    return result;
}

