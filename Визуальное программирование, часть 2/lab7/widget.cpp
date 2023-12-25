#include "widget.h"
#include "ui_widget.h"

widget::widget(QWidget *parent) : QWidget(parent), ui(new Ui::widget)
{
    ui->setupUi(this);
    this->resize(530,530);
    this->setFixedSize(530,530);

    scene = new QGraphicsScene();
    Muha = new muha(Lunch);
    Lunch = new lunch();

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scene->setSceneRect(-250,-250,500,500);

    scene->addLine(-250,-250, 250,-250, QPen(Qt::red));
    scene->addLine(-250, 250, 250, 250, QPen(Qt::red));
    scene->addLine(-250,-250,-250, 250, QPen(Qt::red));
    scene->addLine( 250,-250, 250, 250, QPen(Qt::red));

    scene->addItem(Muha);
    scene->addItem(Lunch);
    Muha->setPos(200,0);
    Lunch->setPos(0, 0);

    timer = new QTimer();
    connect(timer, &QTimer::timeout, Muha, &muha::slotGameTimer);
    timer->start(1000 / 50);
}

widget::~widget()
{
    delete ui;
}
