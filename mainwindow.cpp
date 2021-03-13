#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QPushButton>
#include <QPlainTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::Code_Decode(QString text, QString newtext)
{
    int i=0;
    do{
        if(text[i] > QChar(64) && text[i] < QChar(91))
            newtext += QChar(155 - text[i].unicode());
            else if(text[i] > QChar(96) && text[i] < QChar(123))
                newtext += QChar(219 - text[i].unicode());
                /*else if((text[i] > QChar(191) && text[i] < QChar(224)))
                    newtext += QChar(415 - text[i].unicode());
                    else if((text[i] > QChar(223) && text[i] < QChar(256)))
                        newtext += QChar(479 - text[i].unicode());
                        */
                        else newtext += text[i];

        i++;
    } while( i!= text.size() );

    return newtext;
}

void MainWindow::on_Code_pressed()
{
    QString Str = ui->textEdit->toPlainText();
    QString Str2 = "";

    QString Ans = Code_Decode(Str, Str2);

    // Создаём окно.
    QMessageBox Res(this);

    // Устанавливаем иконку вопроса.
    Res.setIcon(QMessageBox::Information);

    // Устанавливаем заголовок окна.
    Res.setWindowTitle("Results");

    // Устанавливаем текст окна.
    Res.setText("Получившаяся строка: " + Ans);

    // Добавляем в окно кнопку "Ok".
    Res.setStandardButtons(QMessageBox::Ok);

    switch (Res.exec())
    {
        // При нажатии на неё, это окно закроется, но диалог останется.
        case QMessageBox::Ok:
            break;
    }

}
