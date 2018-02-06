#ifndef _PUNTO_H
#define _PUNTO_H
#include <iostream>

struct Punto {
    double x;
    double y;
};

Punto LeerPunto();

void EscribirPunto (const Punto& p);

void InicializarPunto (Punto& p, const double& cx, const double& cy);

double GetX (const Punto& p);

double GetY (const Punto& p);

double Distancia (const Punto& p1, const Punto& p2);

Punto PuntoMedio (const Punto& p1, const Punto& p2);

bool LeerPuntoIs(std::istream& is, Punto& p);

bool EscribirPuntoOs(std::ostream& os, const Punto& p);

#endif

