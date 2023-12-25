#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "rybakova_popkova.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

signals:
    void sendData(QString str);

 private slots:
    void onButtonSend();
    void on_pushButton_clicked();

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Rybakova_Popkova *myform;


};

#endif // MAINWINDOW_H
