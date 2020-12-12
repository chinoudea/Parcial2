#include "bala.h"



Bala::Bala()
{

}

Bala::Bala(double posIniX, double posIniY, double rango)
{
    posicionX = posIniX;
    posicionY = posIniY;
    posInicialX = posIniX;
    posInicialY = posIniY;
    rangoDetonacion = rango;
}

bool Bala::sensarCercania(double X, double Y)
{
        double deltaX = posicionX - X;
        double deltaY = posicionY - Y;
        if (abs(sqrt(pow(deltaX,2)+pow(deltaY,2))) <= rangoDetonacion) {
            return true;
        } else {
            return false;
        }
    }


void Bala::calcularPosicion(double* t) {
    posicionX = posInicialX + velocidadInicial * cos(anguloInicial) * *t;
    posicionY = posInicialY + velocidadInicial * sin(anguloInicial) - (g*pow(*t,2))/2;
}

double Bala::calcularX(double t) {
    posicionX = posInicialX + velocidadInicial*cos(anguloInicial)*t; //Dada la configuracion del escenario se considera Xo(inicial) = 0
    return posicionX;
}

double Bala::calcularY(double t) {
    posicionY = posInicialY + velocidadInicial * sin(anguloInicial) - (g*pow(t,2))/2;
    return posicionY;
}


