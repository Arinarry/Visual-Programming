#ifndef SDIPROGRAM_POPKOVA_RYBAKOVA_H
#define SDIPROGRAM_POPKOVA_RYBAKOVA_H

#include <QMainWindow>
#include <QtWidgets>
#include <docwindow_popkova_rybakova.h>
#include <QStatusBar>
#include <QMessageBox>
#include <QLabel>
#include "ui_sdiprogram_popkova_rybakova.h"

namespace Ui {
class SDIProgram_Popkova_Rybakova;
}

class SDIProgram_Popkova_Rybakova : public QMainWindow
{
    Q_OBJECT

public:
    SDIProgram_Popkova_Rybakova(QWidget *pwgt = 0): QMainWindow(pwgt)
    {
        QMenu* pmnuFile = new QMenu("&File");
        QMenu* pmnuHelp = new QMenu("&Help");
        DocWindow_Popkova_Rybakova* pdoc = new DocWindow_Popkova_Rybakova;

        pmnuFile->addAction("&Open...",
                            pdoc,
                            SLOT(slotLoad()),
                            QKeySequence("CTRL+O")
                            );
        pmnuFile->addAction("&Save",
                            pdoc,
                            SLOT(slotSave()),
                            QKeySequence("CTRL+S")
                            );

        pmnuFile->addAction("&SaveAs",
                            pdoc,
                            SLOT(slotSaveAs()),
                            QKeySequence("CTRL+F")
                            );
        pmnuFile->addAction("&Quit",
                            qApp,
                            SLOT(quit()),
                            QKeySequence("CTRL+Q")
                            );

        pmnuHelp->addAction("&About",
                            this,
                            SLOT(slotAbout()),
                            Qt::Key_F1
                            );

         pmnuFile->addAction("&Color",
                             pdoc,
                             SLOT(slotColor())
                             );

        menuBar()->addMenu(pmnuFile);
        menuBar()->addMenu(pmnuHelp);

        setCentralWidget(pdoc);

        connect(pdoc,
                 SIGNAL(changeWindowTitle(const QString&)),
                 SLOT(slotChangeWindowTitle(const QString&))
                 );

        statusBar()->showMessage("Ready", 2000);
    }

public slots:
    void slotAbout()
    {
        QMessageBox::about(this, "The authors", "Popkova&Rybakova\n\tIP-116");
    }

    void slotChangeWindowTitle(const QString& str)
    {
        setWindowTitle(str);
    }

private:
    Ui::SDIProgram_Popkova_Rybakova *ui;

};

#endif // SDIPROGRAM_POPKOVA_RYBAKOVA_H
