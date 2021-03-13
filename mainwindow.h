#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString Code_Decode(QString text, QString newtext);

private slots:

    void on_Code_pressed();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
