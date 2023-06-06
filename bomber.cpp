
#include "bomber.h"



double BOMBER::getPosx() const
{
    return posx;
}

void BOMBER::setPosx(double newPosx)
{
    posx = newPosx;
}

double BOMBER::getPosy() const
{
    return posy;
}

void BOMBER::setPosy(double newPosy)
{
    posy = newPosy;
}

BOMBER::BOMBER()
{
    this->radio=25;
    this->velocidad=1;

}


BOMBER::BOMBER(double x, double y, double r)
{
    // ASIGNACION DE VALORES DE BOMBER
    this->posx=x;
    this->posy=y;
    this->radio=r;
    this->velocidad=5;
    setPos(posx,posy);
}

QRectF BOMBER::boundingRect() const
{
    return QRectF(posx,posy,2*radio,2*radio);
}

void BOMBER::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{



    QPixmap ninja(":/imagens/FERREROROJOPNG.png");
    painter->drawPixmap(boundingRect(),ninja,ninja.rect());


}

void BOMBER::MoveLeft()
{
    posx-=velocidad;
    setPos(posx,posy);
}

void BOMBER::MoveRight()
{
    posx+=velocidad;
    setPos(posx,posy);
}
