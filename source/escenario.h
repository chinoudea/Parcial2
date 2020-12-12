#ifndef ESCENARIO_H
#define ESCENARIO_H
#include <mortero.h>


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
    void simularOfensivos();
    void simularDefensivos();
    void simularDefensivos(bool);
    void simularOfensivoEfectivo();
};

#endif // ESCENARIO_H
