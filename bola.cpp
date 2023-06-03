#include "bola.h"

bola::bola(float px_, float py_, float vx_, float vy_, float rad_):
    px(px_), py(py_),vx(vx_),vy(vy_),rad(rad_)
{

}

float bola::getPx() const
{
    return px;
}

void bola::setPx(float value)
{
    px = value;
}

float bola::getPy() const
{
    return py;
}

void bola::setPy(float value)
{
    py = value;
}

float bola::getVx() const
{
    return vx;
}

void bola::setVx(float value)
{
    vx = value;
}

float bola::getVy() const
{
    return vy;
}

void bola::setVy(float value)
{
    vy = value;
}

float bola::getAx() const
{
    return ax;
}

void bola::setAx(float value)
{
    ax = value;
}

float bola::getAy() const
{
    return ay;
}

void bola::setAy(float value)
{
    ay = value;
}

float bola::getRad() const
{
    return rad;
}

void bola::mover(float dt)
{
    //if(py<=0) vy = -vy;
    vy = vy - G*dt;
    if (int(vy) <= 0 && int(py) <= rad){ py=rad; vy=1;}
    px += vx*dt;
    py += vy*dt;
}
