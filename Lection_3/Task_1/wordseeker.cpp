#include "wordseeker.h"
#include "ui_wordseeker.h"

WordSeeker::WordSeeker(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::WordSeeker)
{
    ui->setupUi(this);
    spinBox = ui->spinBox;

    // Подключаем сигналы к слотам
    connect(ui->e_pattern, &QLineEdit::textChanged, this, &WordSeeker::counter);
    connect(ui->t_text, &QTextEdit::textChanged, this, &WordSeeker::counter);
    connect(ui->radioButton, &QRadioButton::clicked, this, &WordSeeker::onEncryptionSelected);
    connect(ui->radioButton_2, &QRadioButton::clicked, this, &WordSeeker::onDecryptionSelected);

}

WordSeeker::~WordSeeker()
{
    delete ui;
}

void WordSeeker::counter()
{
    QString text = ui->t_text->toPlainText();
    QString pattern = ui->e_pattern->text();

    if (text.isEmpty() || pattern.isEmpty()) return;

    int lastIndex = 0;
    int counter = 0;
    do {
        lastIndex = text.indexOf(pattern, lastIndex);
        if (lastIndex != -1) {
            counter++;
            lastIndex++;
        }
    } while (lastIndex != -1);
    ui->l_result->setText(QString("Результат: %1").arg(QString::number(counter)));
}

void WordSeeker::encryptDecrypt(QString& text, int shift)
{
    for (QChar& ch : text) {
        if (ch.isLetter()) {
            QChar base = ch.isUpper() ? 'A' : 'a';
            int newIndex = ((ch.unicode() - base.unicode() + shift) % 26);
            if (newIndex < 0) newIndex += 26;
            ch = QChar(newIndex + base.unicode());
        }
    }

}

void WordSeeker::onEncryptionSelected()
{
    QString text = ui->t_text->toPlainText();
    int shift = spinBox->value();

    encryptDecrypt(text, shift);
    ui->t_text->setPlainText(text);
}

void WordSeeker::onDecryptionSelected()
{
    QString text = ui->t_text->toPlainText();
    int shift = spinBox->value();

    encryptDecrypt(text, -shift);
    ui->t_text->setPlainText(text);
}


