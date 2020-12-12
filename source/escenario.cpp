#include "escenario.h"

Escenario::Escenario(double dist)
{
    distancia = dist;
    c_ofensivo =  Mortero();
    c_defensivo = Mortero(distancia, 0);
}

Escenario::Escenario(double dist, double alt_ofensivo, double alt_defensivo) {
    distancia = dist;
    c_ofensivo = Mortero(0, alt_ofensivo);
    c_defensivo = Mortero(distancia, alt_defensivo);
}

void Escenario::simularOfensivos()
{

}

void Escenario::simularDefensivos()
{

}

void Escenario::simularDefensivos(bool)
{

}

void Escenario::simularOfensivoEfectivo()
{

}
