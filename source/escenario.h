#ifndef ESCENARIO_H
#define ESCENARIO_H

#include <iostream>
#include <cmath>
#include <mortero.h>

using namespace std;

class Escenario
{
public:
    Escenario();
    Escenario(double);
    Escenario(double,double,double);
    Mortero c_ofensivo;
    Mortero c_defensivo;
    double distancia;
    double tiempo;
    double g = 9.81;
    double pi = 2*acos(0.0);
    void simularOfensivos();
    void simularDefensivos();
    void simularDefensivos(bool);
    void simularOfensivoEfectivo();
private:
    int angTest[3]={45, 50, 60};
};

#endif // ESCENARIO_H
