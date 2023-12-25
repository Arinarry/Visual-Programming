#ifndef LUNCH_H
#define LUNCH_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>
#include <QPixmap>
#include <windows.h>

class lunch : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit lunch(QObject *parent = 0);
    ~lunch();

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
private:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

};

#endif // LUNCH_H
