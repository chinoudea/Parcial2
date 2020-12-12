#include "mortero.h"

Mortero::Mortero()
{
    posicionX = 0;
    posicionY = 0;
}

Mortero::Mortero(double posX, double posY)
{
    posicionX = posX;
    posicionY = posY;
}

/*
template <class OBJETIVO>
void Mortero::simu(Disparo disparo, double velocidad, double angulo, OBJETIVO objetivo) {

}

template<class T>
bool Mortero::simularDisparo(double velocidad, double angulo, double rango, T objetivo)
{
    Bala disparo = Bala(posicionX, posicionY,angulo,velocidad,rango);
    //Se itera en tiempo
    for (double t=0.1; t<1000; t+=0.1) {
        Xo = posXo(v,angTest[i]*pi/180,t);
        Yo = posYo(v,angTest[i]*pi/180,t);
        // Se limita para que el escenario tenga piso en 0,
        // asi que si se dan valores negativos no se tienen en cuenta.
        if (Yo<0) continue;
        dist = distancia(Xo,Yo,d,Hd);
        if (dist <=rangoO) {
            tiempo = t;
            Voo = v;
            flag = true;
            break;
        }
    }
}
*/
