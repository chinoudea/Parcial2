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
        for (double v=0.1; ; v+=0.1) {
            ofensiva.velocidadInicial = v;
            //Se itera en tiempo
            for (tiempo=0.1; ; tiempo+=0.01) {
                ofensiva.calcularPosicion(&tiempo);
                // Se valida la cercania al objetivo
                if (ofensiva.sensarCercania(c_defensivo.posicionX, c_defensivo.posicionY)) {
                    flag = true;
                    cout << "Para angulo " << angTest[i] << " y velocidad " << v << " se logra generar danio en X=" << ofensiva.posicionX << " y Y=" << ofensiva.posicionY << " en tiempo " << tiempo << " segundos."<<endl;
                    break;
                }
                // Se limita para que el escenario tenga piso en 0, asi que si se dan valores negativos no se tienen en cuenta.
                if (ofensiva.posicionY<0) break;
                // Si la posicion en X ya supera la distancia mas el rango de daño, se aborta la iteracion
                if (ofensiva.posicionX > (c_defensivo.posicionX + ofensiva.rangoDetonacion)) break;
            }
            // Si ya se encontro resultado se deja de iterar en velocidad.
            if (flag) break;
        }
    }
    // Se da tiempo al usuario para que lea los resultados
    cout << endl;
    system("PAUSE");
}

void Escenario::simularDefensivos()
{
    double factor = 0.025;
    // Se crea la bala defensiva
    Bala defensiva = Bala(c_defensivo.posicionX, c_defensivo.posicionY, (factor * distancia));
    bool flag;
    //Para generar los 3 disparon se define un set angulos 45, 50 y 60
    //Se tienen conocidos el angulo y las alturas; Se calcularan los Vo requeridos
    //Se itera en los 3 angulos definidos
    for (int i=0; i<3; i++) {
        flag = false;
        defensiva.anguloInicial = 180 - angTest[i];
        //Se itera en velocidad inicial
        for (double v=0.1; ; v+=0.1) {
            defensiva.velocidadInicial = v;
            //Se itera en tiempo
            for (tiempo=0.1; ; tiempo+=0.01) {
                defensiva.calcularPosicion(&tiempo);
                // Se valida la cercania al objetivo
                if (defensiva.sensarCercania(c_ofensivo.posicionX, c_ofensivo.posicionY)) {
                    flag = true;
                    cout << "Para angulo " << angTest[i] << " y velocidad " << v << " se logra generar danio en X=" << defensiva.posicionX << " y Y=" << defensiva.posicionY << " en tiempo " << tiempo << " segundos."<<endl;
                    break;
                }
                // Se limita para que el escenario tenga piso en 0, asi que si se dan valores negativos no se tienen en cuenta.
                if (defensiva.posicionY<0) break;
                // Si la posicion en X ya supera la distancia mas el rango de daño, se aborta la iteracion
                if (defensiva.posicionX < (c_ofensivo.posicionX + defensiva.rangoDetonacion)) break;
            }
            // Si ya se encontro resultado se deja de iterar en velocidad.
            if (flag) break;
        }
    }
    // Se da tiempo al usuario para que lea los resultados
    cout << endl;
    system("PAUSE");

}

void Escenario::simularDefensivos(bool protegerOfensivo)
{
    double Voo, angO, tiempoOfensivo, tod;
    bool flag = false;
    cout << endl << "Por favor ingrese los parametros de configuracion de disparo ofensivo" << endl;
    cout << "Indique la velocidad inicial (m/s) del disparo: ";
    cin >> Voo;
    cout << "Indique el angulo en grados del disparo: ";
    cin >> angO;
    Bala ofensiva = Bala(c_ofensivo.posicionX, c_ofensivo.posicionY, 0.05*distancia, Voo, angO);
    // Lo primero es saber si el disparo ofensivo con esos parametros puede hacer daño, se itera en tiempo para averiguarlo.
    for (tiempo=0.1; ; tiempo+=0.01) {
        ofensiva.calcularPosicion(&tiempo);
        // Se valida la cercania al objetivo
        if (ofensiva.sensarCercania(c_defensivo.posicionX, c_defensivo.posicionY)) {
            tod = tiempo;
            flag = true;
            break;
        }
        // Se limita para que el escenario tenga piso en 0, asi que si se dan valores negativos no se tienen en cuenta.
        if (ofensiva.posicionY<0) break;
        // Si la posicion en X ya supera la distancia mas el rango de daño, se aborta la iteracion
        if (ofensiva.posicionX > (c_defensivo.posicionX + ofensiva.rangoDetonacion)) break;
    }
    if (flag) { // Si puede hacer daño
        //Se verifica si hay tiempo de reaccionar al ataque
        if (tiempo<=2) {
            cout << "No es posible defenderse de un ataque con esos parametros." << endl;
        } else {
            // Se crea la bala defensiva
            Bala defensiva = Bala(c_defensivo.posicionX, c_defensivo.posicionY, (0.025 * distancia));
            flag = false;
            //Para generar los 3 disparon se define un set angulos 45, 50 y 60
            //Se tienen conocidos el angulo y las alturas; Se calcularan los Vo requeridos
            //Se itera en los 3 angulos definidos
            for (int i=0; i<3; i++) {
                flag = false;
                defensiva.anguloInicial = 180 - angTest[i];
                //Se itera en velocidad inicial
                for (double v=0.1; ; v+=0.1) {
                    defensiva.velocidadInicial = v;
                    //Se itera en tiempo
                    for (tiempo=0.1; ; tiempo+=0.01) {
                        tiempoOfensivo = tiempo + 2;
                        defensiva.calcularPosicion(&tiempo);
                        ofensiva.calcularPosicion(&tiempoOfensivo);
                        // Se valida la cercania al objetivo
                        if (defensiva.sensarCercania(ofensiva.posicionX, ofensiva.posicionY)) {
                            // Si el tiempo logrado es mayor al tiempo en el que el cañon ofensivo logra hacer daño, no sirven estos parametros.
                            if ((tiempo + 2) >= tod ) break;
                            flag = true;
                            cout << "Para angulo " << angTest[i] << " y velocidad " << v << " se logra generar danio en X=" << defensiva.posicionX << " y Y=" << defensiva.posicionY << " en tiempo " << tiempo << " segundos."<<endl;
                            break;
                        }
                        // Se limita para que el escenario tenga piso en 0, asi que si se dan valores negativos no se tienen en cuenta.
                        if (defensiva.posicionY<0) break;
                        // Si la posicion en X ya supera la distancia mas el rango de daño, se aborta la iteracion
                        if (defensiva.posicionX < (c_ofensivo.posicionX + defensiva.rangoDetonacion)) break;
                    }
                    // Si ya se encontro resultado se deja de iterar en velocidad.
                    if (flag) break;
                }
            }
            // Se da tiempo al usuario para que lea los resultados
            cout << endl;
            system("PAUSE");
        }

    } else {
        cout << "Los parametros indicados no pueden hacer danio al canion defensivo" << endl;
        system("PAUSE");
    }

}

void Escenario::simularOfensivoEfectivo()
{

}
