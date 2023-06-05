
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


    void calVelocidad();
    void calPosicion();
    void newPosicion();

    double getPosx() const;
    double getPosy() const;
    double getMasa() const;
};

#endif // MOVIMIENTO_H
