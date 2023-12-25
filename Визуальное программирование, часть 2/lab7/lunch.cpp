#include "lunch.h"

lunch::lunch(QObject *parent) :
    QObject(parent), QGraphicsItem()
{


}

lunch::~lunch()
{

}


QRectF lunch::boundingRect() const
{
    qreal width = 75;
        qreal height = 75;
        QRectF boundingRect(0, 0, width, height);
        return boundingRect;
}

void lunch::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
        QImage source;
        source.load("C:\\Users\\arina\\Desktop\\7\\lub7\\lunch.png");
        QRect rect(source.rect());
        painter->drawImage(rect, source);
        Q_UNUSED(option);
        Q_UNUSED(widget);
}

void lunch::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    this->setPos(mapToScene(event->pos()));
}
void lunch::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(Qt::ClosedHandCursor));
    Q_UNUSED(event);
}

void lunch::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}
