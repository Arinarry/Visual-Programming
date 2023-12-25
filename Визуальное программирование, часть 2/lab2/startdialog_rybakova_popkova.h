#ifndef STARTDIALOG_RYBAKOVA_POPKOVA_H
#define STARTDIALOG_RYBAKOVA_POPKOVA_H

#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include "inputdialog_rybakova_popkova.h"


class StartDialog_Rybakova_Popkova: public QPushButton
{
    Q_OBJECT

public:
    StartDialog_Rybakova_Popkova(QWidget* pwgt = 0) : QPushButton("Нажми", pwgt)
    {
        connect(this, SIGNAL(clicked()),SLOT(slotButtonClicked()));
    }
public slots:
    void slotButtonClicked()
    {
           InputDialog_rybakova_popkova* pInputDialog = new  InputDialog_rybakova_popkova;
          if (pInputDialog->exec() == QDialog::Accepted) {
              QMessageBox::information(0,
                                       "Ваша информация: ",
                                       "Имя: "
                                       + pInputDialog->firstName()
                                       + "\nФамилия: "
                                       + pInputDialog->lastName()
                                       );
          }
          delete pInputDialog;
    }
};

#endif // STARTDIALOG_RYBAKOVA_POPKOVA_H
