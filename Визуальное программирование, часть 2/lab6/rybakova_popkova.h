#ifndef RYBAKOVA_POPKOVA_H
#define RYBAKOVA_POPKOVA_H

#include <QWidget>
#include <QAbstractButton>

namespace Ui {
class Rybakova_Popkova;
}

class Rybakova_Popkova : public QWidget
{
    Q_OBJECT

public slots:
    void recieveData(QString str);

public:
    explicit Rybakova_Popkova(QWidget *parent = nullptr);
    ~Rybakova_Popkova();

private slots:
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    Ui::Rybakova_Popkova *ui;
};

#endif // RYBAKOVA_POPKOVA_H
