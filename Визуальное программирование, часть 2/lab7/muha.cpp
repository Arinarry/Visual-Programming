#include "muha.h"
#include <QRandomGenerator>
#include <QPointF>

muha::muha(lunch* lunchItem, QObject* parent) :
    QObject(parent), QGraphicsItem(), lunchItem(lunchItem)
{
    UP = true;
    DOWN = false;
    LEFT = true;
    RIGHT = false;
}

muha::~muha()
{

}

QRectF muha::boundingRect() const
{
      return QRectF(0, 0, 110, 110);
}

void muha::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->setBrush(Qt::gray);
    painter->drawEllipse(60, 10, 40, 60);
    painter->drawEllipse(10, 10, 40, 60);

    painter->setBrush(Qt::black);
    painter->setPen(Qt::NoPen);
    painter->drawEllipse(20, 20, 70, 80);

    painter->setBrush(Qt::white);
    painter->drawEllipse(50, 60, -10, -10);
    painter->drawEllipse(70, 60, -10, -10);


    painter->setPen(Qt::black);
    painter->drawLine(25, 80, 25, 110);
    painter->drawLine(45, 80, 45, 110);
    painter->drawLine(65, 80, 65, 110);
    painter->drawLine(85, 80, 85, 110);

}

void muha::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    this->setPos(mapToScene(event->pos()));
}
void muha::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(Qt::ClosedHandCursor));
    Q_UNUSED(event);
}



void muha::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}
void muha::slotGameTimer()
{

    if(LEFT == true){
        setPos(mapToParent(-5, 0));
    }
    if(RIGHT == true){
        setPos(mapToParent(5, 0));
    }
    if(UP == true){
        setPos(mapToParent(0, -5));
    }
    if(DOWN == true){
        setPos(mapToParent(0, 5));
    }


    if(this->x() - 10 < -265){
        this->setX(-255);
        LEFT = false;
        RIGHT = true;
    }
    if(this->x() + 10 > 160){
        this->setX(150);
        RIGHT = false;
        LEFT = true;
    }

    if(this->y() - 10 < -265){
        this->setY(-255);
        UP = false;
        DOWN = true;

    }
    if(this->y() + 10 > 150){
        this->setY(140);
        UP = true;
        DOWN = false;
    }

    QList<QGraphicsItem*> collidingItemsList = collidingItems();

        foreach (QGraphicsItem* item, collidingItemsList) {
            if (typeid(*item) == typeid(lunch)) {
                QPointF lunchPos = item->pos();
                QPointF muhaPos = pos();

                QPointF directionVector = lunchPos - muhaPos;
                qreal length = std::sqrt(directionVector.x() * directionVector.x() + directionVector.y() * directionVector.y());

                if (length > 0) {
                    directionVector /= length;
                    UP = directionVector.y() > 0;
                    DOWN = directionVector.y() < 0;
                    LEFT = directionVector.x() > 0;
                    RIGHT = directionVector.x() < 0;
                }
            }
        }
}
