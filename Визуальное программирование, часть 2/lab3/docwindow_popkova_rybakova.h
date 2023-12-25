#ifndef DOCWINDOW_POPKOVA_RYBAKOVA_H
#define DOCWINDOW_POPKOVA_RYBAKOVA_H

#include <QTextEdit>

class DocWindow_Popkova_Rybakova: public QTextEdit
{
    Q_OBJECT

private:
    QString m_strFileName;

public:
    DocWindow_Popkova_Rybakova(QWidget* pwgt = 0);

signals:
    void changeWindowTitle(const QString&);

public slots:
    void slotLoad();
    void slotSave();
    void slotSaveAs();
    void slotColor();
};

#endif // DOCWINDOW_POPKOVA_RYBAKOVA_H
