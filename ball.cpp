
#include "ball.h"

double ball::getPosy() const
{
    return posy;
}

void ball::setTraje(int newTraje)
{
    traje = newTraje;
}

double ball::getPosx() const
{
    return posx;
}

void ball::setPosx(double newPosx)
{
    posx = newPosx;
}

void ball::setPosy(double newPosy)
{
    posy = newPosy;
}

ball::ball()
{

}
QRectF ball::boundingRect() const
{
    //return QRect(posx,posy,2*radio,2*radio);
    return QRect(posx ,2*radio,2*radio,2*radio);

}

void ball::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    QPixmap ninja(":/imagens/BALLGame.png");
    painter->drawPixmap(boundingRect(),ninja,ninja.rect());

}

ball::ball(double x, double y, double r)
{
    this->posx=x;
    this->posy=y;
    this->radio=r;

    setPos(posx,posy);
}

void ball::MoveLeft()
{
    posx-=velocidad;
    setPos(posx, posy);
}

void ball::MoveRight()
{
    posx+=velocidad;
    setPos(posx, posy);
}


