#ifndef MUHA_H
#define MUHA_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>
#include "lunch.h"

class muha: public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit muha(QObject *parent = 0);
    ~muha();
    muha(lunch* lunchItem, QObject *parent = nullptr);
    bool LEFT;
    bool RIGHT;
    bool UP;
    bool DOWN;
signals:

public slots:
    void slotGameTimer();

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    bool isCollidingWithLunch();
    QRect rect;
    QTimer *timer;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    lunch* lunchItem;
};


#endif // MUHA_H
