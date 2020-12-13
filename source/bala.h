#ifndef BALA_H
#define BALA_H

#include <cmath>

using namespace std;

class Bala
{
public:
    double velocidadInicial;
    double anguloInicial;
    double posicionX;
    double posicionY;
    double rangoDetonacion;
    double g = 9.81;
    double pi = 2*acos(0.0);
    Bala();
    Bala(double posIniX, double posIniY, double rango);
    bool sensarCercania(double X, double Y);
    void calcularPosicion(double *t);
private:
    double posInicialX;
    double posInicialY;
};

#endif // BALA_H
