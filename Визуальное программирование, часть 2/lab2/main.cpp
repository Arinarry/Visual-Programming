#include "StartDialog_Rybakova_Popkova.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartDialog_Rybakova_Popkova startDialog;
    startDialog.show();

    return a.exec();
}
