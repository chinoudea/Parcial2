#ifndef MORTERO_H
#define MORTERO_H
#include <vector>
#include <bala.h>

using namespace std;

class Mortero
{
public:
    double posicionX;
    double posicionY;
    vector<Bala> disparos;
    Mortero();
    Mortero(double, double);
    void simularDisparo(int tipo, double velocidad, double angulo);
    template<class T>
    bool simularDisparo(double velocidad, double angulo, T objetivo);
};

#endif // MORTERO_H
