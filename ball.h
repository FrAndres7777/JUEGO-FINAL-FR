
#ifndef BALL_H
#define BALL_H

#include <QPixmap>
#include <QGraphicsItem>
#include <QPainter>
#include <movimiento.h>



class ball :public QGraphicsItem
{
    double posx,posy,radio;
    int velocidad =5;
    int traje=0;

public:
    ball();
    QRectF boundingRect() const;    //necesario definirla, devuelve el rectangulo que encierra el objeto
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget); //define como se pintara el objeto
    ball(double x , double y , double r);
    double getPosy() const;

    void MoveLeft();
    void MoveRight();
    void setTraje(int newTraje);
    double getPosx() const;
    void setPosx(double newPosx);
    void setPosy(double newPosy);
};

#endif // BALL_H
