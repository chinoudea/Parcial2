#include "escenario.h"


Escenario::Escenario()
{

}
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
    double factor = 0.05;
    // Se crea la bala ofensiva
    Bala ofensiva = Bala(c_ofensivo.posicionX, c_ofensivo.posicionY, (factor * distancia));
    bool flag;
    //Para generar los 3 disparon se define un set angulos 45, 50 y 60
    //Se tienen conocidos el angulo y las alturas; Se calcularan los Vo requeridos
    //Se itera en los 3 angulos definidos
    for (int i=0; i<3; i++) {
        flag = false;
        ofensiva.anguloInicial = angTest[i];
        //Se itera en velocidad inicial
        for (double v=0.5; v<1000; v+=0.5) {
            ofensiva.velocidadInicial = v;
            //Se itera en tiempo
            for (tiempo=0.1; tiempo<1000; tiempo+=0.1) {
                ofensiva.calcularPosicion(&tiempo);
                // Se limita para que el escenario tenga piso en 0,
                // asi que si se dan valores negativos no se tienen en cuenta.
                if (ofensiva.posicionY<0)
                    break;
                // Si la posicion en X ya supera la distancia mas el rango de daño, se aborta la iteracion
                if (ofensiva.posicionX > (c_defensivo.posicionX + ofensiva.rangoDetonacion))
                    break;
                // Se valida la cercania al objetivo
                if (ofensiva.sensarCercania(c_defensivo.posicionX, c_defensivo.posicionY)) {
                    flag = true;
                    cout << "Para angulo " << angTest[i] << " y velocidad " << v << " se logra generar danio en X=" << ofensiva.posicionX << " y Y=" << ofensiva.posicionY << " en tiempo " << tiempo << " segundos."<<endl;
                    break;
                }
            }
            if (flag) break;
        }
        //cout << "Para angulo " << angTest[i] << " y velocidad " << Voo << " se logra generar danio en X=" << Xo << " y Y=" << Yo << " en tiempo " << tiempo << endl;
    }
        system("PAUSE");

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
