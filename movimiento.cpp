
#include "movimiento.h"

double Movimiento::getPosx() const
{
    return posx;
}

double Movimiento::getPosy() const
{
    return posy;
}


double Movimiento::getMasa() const
{
    return masa;
}

Movimiento::Movimiento()
{

}

Movimiento::Movimiento(double x, double y, double v, double a)
{
    this->posx=x;
    this->posy=y;
    this->velocidad=v;
    this->angulo=((a*3.1415)/180);


}


void Movimiento::calVelocidad()
{
    velx=velocidad*cos(angulo);
    vely=velocidad*sin(angulo)-9.8*tiempo;

}

void Movimiento::calPosicion()
{
    posx=posx+velx*tiempo;
    posy=posy+vely*tiempo-0.5*9.8*pow(tiempo,2);
}

void Movimiento::newPosicion()
{
    velocidad=sqrt(pow(velx,2) + pow(vely,2));
    angulo=atan2(vely,velx);
}


