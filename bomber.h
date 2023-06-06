
#ifndef BOMBER_H
#define BOMBER_H




#include <QPainter>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QGraphicsItem>// CONFERERIR CAPACIDAD DE SER OBJETOS VISIBLES


//con QGraficsItem Volvemos BOMBER un Item GRafico
class BOMBER: public QGraphicsItem
{
    //ATRIBUTOs
    double posx,posy,radio,velocidad; //radio tamaño de la figura
    int numero=1;


public:
    BOMBER();


    BOMBER(double x , double y , double r);
    QRectF boundingRect() const;//LIMITES DEL RECTANGULO QUE DELIMITA TU OBJETO
    //paint como se mostrara pintado
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget= nullptr);


    void MoveLeft();
    void MoveRight();




    double getPosx() const;
    void setPosx(double newPosx);
    double getPosy() const;
    void setPosy(double newPosy);
};
#endif // BOMBER_H
