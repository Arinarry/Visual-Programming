#include "docwindow_popkova_rybakova.h"
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QLabel>
#include <QColorDialog>
#include "ui_sdiprogram_popkova_rybakova.h"
#include "sdiprogram_popkova_rybakova.h"

DocWindow_Popkova_Rybakova::DocWindow_Popkova_Rybakova(QWidget* pwgt): QTextEdit (pwgt)
{

}

void DocWindow_Popkova_Rybakova::slotLoad()
{
    QString str = QFileDialog::getOpenFileName();
    if (str.isEmpty()){
        return;
    }
    QFile file(str);
    if (file.open(QIODevice::ReadOnly)){
        QTextStream stream(&file);
        setPlainText(stream.readAll());
        file.close();
    }
    m_strFileName=str;
    emit changeWindowTitle(m_strFileName);
}

void DocWindow_Popkova_Rybakova::slotSaveAs()
{
    QString str = QFileDialog::getSaveFileName(0, m_strFileName);
    if (!str.isEmpty()){
        m_strFileName = str;
        slotSave();
    }
}

void DocWindow_Popkova_Rybakova::slotSave()
{
    if (m_strFileName.isEmpty()){
        slotSaveAs();
        return;
    }
    QFile file(m_strFileName);
    if (file.open(QIODevice::WriteOnly)){
        QTextStream(&file)<<toPlainText();
        file.close();
        emit changeWindowTitle(m_strFileName);
        QMessageBox::information(this, "Файл сохранён", "Файл успешно сохранён");
    }
}

void DocWindow_Popkova_Rybakova::slotColor()
{
    setTextColor(QColorDialog::getColor());
}


