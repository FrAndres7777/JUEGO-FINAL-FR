#ifndef BOLAGRAF_H
#define BOLAGRAF_H

#include <QGraphicsItem>
#include <QPainter>
#include "bola.h"

class bolagraf: public QGraphicsItem

{
public:
    bolagraf(float px_=0, float py_=0, float vx_=0, float vy_=0, float rad_=10, float escala_ = 1);
    QRectF boundingRect() const;    //necesario definirla, devuelve el rectangulo que encierra el objeto
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //define como se pintara el objeto
    void pos(int v_lim);

    bola *getEsfera() const;
    void setEsfera(bola *value);

    float getEscala() const;
    void setEscala(float value);

    void actualizar(float dt, int v_lim);

    void setTraje(int newTraje);

private:
    bola *esfera;
    float escala;
    int traje=0;
};

#endif // BOLAGRAF_H
