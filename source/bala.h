#ifndef BALA_H
#define BALA_H


class Bala
{
public:
    double velocidadInicial;
    double angulo;
    double posicionX;
    double posicionY;
    double rangoDetonacion;
    Bala();
    bool sensarCercania();
};

#endif // BALA_H
