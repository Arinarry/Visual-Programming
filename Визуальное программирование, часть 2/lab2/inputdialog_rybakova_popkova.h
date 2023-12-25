#ifndef INPUTDIALOG_RYBAKOVA_POPKOVA_H
#define INPUTDIALOG_RYBAKOVA_POPKOVA_H

#include <QDialog>
#include <QLineEdit>

class QLineEdit;

class InputDialog_rybakova_popkova: public QDialog
{
    Q_OBJECT
private:
    QLineEdit * m_ptxtFirstName;
    QLineEdit * m_ptxtLastName;
public:
    InputDialog_rybakova_popkova(QWidget* pwgt = 0);

    QString firstName() const;
    QString lastName() const;
};

#endif // INPUTDIALOG_RYBAKOVA_POPKOVA_H
