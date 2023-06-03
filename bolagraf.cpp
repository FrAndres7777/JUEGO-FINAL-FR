#include "bolagraf.h"

bolagraf::bolagraf(float px_, float py_, float vx_, float vy_, float rad_, float escala_)
{
    esfera =  new bola(px_,py_,vx_,vy_,rad_);
    escala = escala_;
}


QRectF bolagraf::boundingRect() const
{
        return QRectF(-1*escala*esfera->getRad(),-1*escala*esfera->getRad(),2*escala*esfera->getRad(),2*escala*esfera->getRad());
}

//QPainterPath bolagraf::shape() const
//{
//    return path;
//}

//QPainterPath bolagraf::setupPath(){
//    path = QPainterPath();
//    path.addEllipse(boundingRect());
//    return path;
//}

void bolagraf::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::darkBlue);        //asigna el color
    painter->drawEllipse(boundingRect());    //dibuja una elipse encerrada en la boundingRect
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void bolagraf::pos(int v_lim)
{
    setPos(esfera->getPx(),v_lim-(esfera->getPy()));
}

bola *bolagraf::getEsfera() const
{
    return esfera;
}

void bolagraf::setEsfera(bola *value)
{
    esfera = value;
}

float bolagraf::getEscala() const
{
    return escala;
}

void bolagraf::setEscala(float value)
{
    escala = value;
}

void bolagraf::actualizar(float dt, int v_lim)
{
    esfera->mover(dt);
    pos(v_lim);
}

