
#ifndef GALLOENEMY_H
#define GALLOENEMY_H
#include <QPainter>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QGraphicsItem>// CONFERERIR CAPACIDAD DE SER OBJETOS VISIBLES





class GALLOEnemy : public QGraphicsItem

{
public:
    GALLOEnemy();
    int posx,posy,radio;
    GALLOEnemy(int x , int  y , int r);
    QRectF boundingRect() const;//LIMITES DEL RECTANGULO QUE DELIMITA TU OBJETO
    //paint como se mostrara pintado
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget= nullptr);
};

#endif // GALLOENEMY_H
