#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "auth.h"
#include "ui_auth.h"
#include "QFileDialog"
#include "QMenu"
#include "QMenuBar"
#include "QAction"
#include "QTextDocumentWriter"

void MainWindow::About_Lab1()
{
    auth *dg = new auth();
    dg->show();
}
void MainWindow::slotOpen()
{
    QString filename=QFileDialog::getOpenFileName(nullptr,"Открыть файл",QDir::currentPath(),"*.cpp *.txt ");
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly | QIODevice:: Text))
        ui->textEdit->setPlainText(file.readAll());
}

void MainWindow:: slotSave()
{
    QString filename = QFileDialog:: getSaveFileName(nullptr,"Сохранить файл",QDir::currentPath(),"*.cpp *.txt ");
    QTextDocumentWriter writer;
    writer.setFileName(filename);
    writer.write(ui->textEdit->document());
}

void MainWindow:: slotClear()
{
    QTextDocumentWriter clear;
    //writer.setFileName(filename);
    ui->textEdit->clear();

}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->action_3,SIGNAL(triggered()),this,SLOT(About_Lab1()));
    QAction* pactOpen = new QAction("file open action",nullptr);
    pactOpen->setText("&Открыть");
    pactOpen->setShortcut(QKeySequence("CTRL+O"));
    pactOpen->setToolTip("Открытие документа");
    pactOpen->setStatusTip("Открыть файл");
    pactOpen->setIcon(QPixmap("11.png"));
    connect(pactOpen, SIGNAL(triggered()), SLOT(slotOpen()));
    QMenu *pmnuFile;
    pmnuFile= menuBar()->addMenu("&Файл");
    pmnuFile->addAction(pactOpen);

    QAction* pactSave = new QAction("file save action",nullptr);
    pactSave->setText("&Сохранить");
    pactSave->setShortcut(QKeySequence("CTRL+S"));
    pactSave->setToolTip("Сохранение документа");
    pactSave->setStatusTip("Сохранить файл");
    pactSave->setIcon(QPixmap("2.jpg"));
    connect(pactSave, SIGNAL(triggered()), SLOT(slotSave()));
    pmnuFile->addAction(pactSave);

    QAction* pactClear = new QAction("file clear",nullptr);
    pactClear->setText("&Очистить файл");
    pactClear->setShortcut(QKeySequence("CTRL+D"));
    pactClear->setToolTip("Очистка документа");
    pactClear->setStatusTip("Очистить файл");
    pactClear->setIcon(QPixmap("3.jpg"));
    connect(pactClear, SIGNAL(triggered()), SLOT(slotClear()));
    pmnuFile->addAction(pactClear);

    ui->mainToolBar->addAction(pactOpen);
    ui->mainToolBar->addAction(pactSave);
    ui->mainToolBar->addAction(pactClear);
}

MainWindow::~MainWindow()
{
    delete ui;
}
