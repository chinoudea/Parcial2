#ifndef MORTERO_H
#define MORTERO_H


class Mortero
{
public:
    double posicionX;
    double posicionY;
    Mortero();
    Mortero(double, double);
    void disparar(int tipo, double velocidad, double angulo);
};

#endif // MORTERO_H
