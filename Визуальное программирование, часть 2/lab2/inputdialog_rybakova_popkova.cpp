#include "inputdialog_rybakova_popkova.h"
#include <QLabel>
#include <QLayout>
#include <QString>
#include <QPushButton>

InputDialog_rybakova_popkova::InputDialog_rybakova_popkova(QWidget* pwgt): QDialog (pwgt)
{
    m_ptxtFirstName = new QLineEdit;
    m_ptxtLastName = new QLineEdit;

    QLabel* plblFirstName = new QLabel("&Имя");
    QLabel* plblLastName = new QLabel("&Фамилия");

    plblFirstName->setBuddy(m_ptxtFirstName);
    plblLastName->setBuddy(m_ptxtLastName);

    QPushButton* pcmOk = new QPushButton("&Ок");
    QPushButton* pcmCancel = new QPushButton("&Cancel");

    connect(pcmOk, SIGNAL(clicked()), SLOT(accept()));
    connect(pcmCancel, SIGNAL(clicked()), SLOT(reject()));

    QGridLayout* ptopLayout = new QGridLayout;
    ptopLayout->addWidget(plblFirstName, 0, 0);
    ptopLayout->addWidget(plblLastName, 1, 0);
    ptopLayout->addWidget(m_ptxtFirstName, 0, 1);
    ptopLayout->addWidget(m_ptxtLastName, 1, 1);
    ptopLayout->addWidget(pcmOk, 2, 0);
    ptopLayout->addWidget(pcmCancel, 2, 1);
    setLayout(ptopLayout);
}

QString InputDialog_rybakova_popkova::firstName() const
{
    return m_ptxtFirstName->text();
}

QString InputDialog_rybakova_popkova::lastName() const
{
    return m_ptxtLastName->text();
}
