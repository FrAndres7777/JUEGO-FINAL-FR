#ifndef BOLA_H
#define BOLA_H

#define G 2
class bola
{
public:
    bola(float px_=0, float py_=0, float vx_=0, float vy_=0, float rad_=10);

    float getPx() const;
    void setPx(float value);

    float getPy() const;
    void setPy(float value);

    float getVx() const;
    void setVx(float value);

    float getVy() const;
    void setVy(float value);

    float getAx() const;
    void setAx(float value);

    float getAy() const;
    void setAy(float value);

    float getRad() const;

    void mover(float dt);

private:
    float px;
    float py;
    const float rad;
    float vx;
    float vy;
    float ax;
    float ay;
};

#endif // BOLA_H
