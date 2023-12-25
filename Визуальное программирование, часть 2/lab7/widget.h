#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QShortcut>
#include <QTimer>
#include "muha.h"
#include "lunch.h"

QT_BEGIN_NAMESPACE
namespace Ui { class widget; }
QT_END_NAMESPACE

class widget : public QWidget
{
    Q_OBJECT

public:
   explicit widget(QWidget *parent = 0);
    ~widget();

private:
    Ui::widget *ui;
    QGraphicsScene          *scene;
    muha                    *Muha;
    lunch                   *Lunch;
    QTimer                  *timer;

};
#endif // WIDGET_H
