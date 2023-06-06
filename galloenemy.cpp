
#include "galloenemy.h"

GALLOEnemy::GALLOEnemy()
{

}

GALLOEnemy::GALLOEnemy(int x, int y, int r)
{
    this->posx=x;
    this->posy=y;
    this->radio=r;

    setPos(posx,posy);
}

QRectF GALLOEnemy::boundingRect() const
{
    return QRectF(posx,posy,2*radio,2*radio);
}

void GALLOEnemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{



    QPixmap ninja(":/imagens/GALLOEnemyFr.png");
    painter->drawPixmap(boundingRect(),ninja,ninja.rect());


}
