#include "escenario.h"

Escenario::Escenario(double dist)
{
    distancia = dist;
    c_ofensivo = new Mortero(0, 0);
    c_defensivo = new Mortero(distancia, 0);
}

Escenario::Escenario(double dist, double alt_ofensivo, double alt_defensivo) {
    distancia = dist;
    c_ofensivo = new Mortero(0, alt_ofensivo);
    c_defensivo = new Mortero(distancia, alt_defensivo);
}
