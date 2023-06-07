
#ifndef MOVIMIENTO_H
#define MOVIMIENTO_H
#include <math.h>


#define tiempo 0.01

class Movimiento

{
    //atributos
    double posx,posy,angulo,velocidad,velx,vely,masa;
public:

    Movimiento();
    Movimiento(double x , double y , double v , double a);
     Movimiento(double x , double y , double v );


    void calVelocidad();
    void calPosicion();
    void newPosicion();

    void calVelocidadBala();
    void calPosicionBala();

    double getPosx() const;
    double getPosy() const;
    double getMasa() const;
    void setVelocidad(double newVelocidad);
    void setAngulo(double newAngulo);
    void setPosx(double newPosx);
    void setPosy(double newPosy);
};

#endif // MOVIMIENTO_H
