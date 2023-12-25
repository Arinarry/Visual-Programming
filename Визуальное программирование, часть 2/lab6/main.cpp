#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setStyleSheet("QPushButton { color: #2F4F4F; background-color: #9370db;  border-width: 2px;font: bold 12px;}"
                        "QLineEdit { background-color: #e6e6fa; border-width: 2px; border-color: #9370db; border-style: solid;}"
                        "QTextEdit { background-color: #e6e6fa; border-width: 2px; border-color: #9370db; border-style: solid;}"
                        "QDateEdit { background-color: #e6e6fa; border-width: 2px; border-color: #9370db; border-style: solid;}"
                        "QMainWindow { background-color: #fffaf0;}");


    MainWindow w;
    w.show();

    return a.exec();
}
