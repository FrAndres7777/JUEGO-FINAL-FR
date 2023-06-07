
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

void Movimiento::setVelocidad(double newVelocidad)
{
    velocidad = newVelocidad;
}

void Movimiento::setAngulo(double newAngulo)
{
    angulo = newAngulo;
}

void Movimiento::setPosx(double newPosx)
{
    posx = newPosx;
}

void Movimiento::setPosy(double newPosy)
{
    posy = newPosy;
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

Movimiento::Movimiento(double x, double y, double v)
{
    this->posx=x;
    this->posy=y;
    this->velx=v;
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

void Movimiento::calVelocidadBala()
{
    velx=velx;

}

void Movimiento::calPosicionBala()
{

    posx=posx+velx*tiempo;

}




