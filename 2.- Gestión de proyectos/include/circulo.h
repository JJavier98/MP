#ifndef _CIRCULO_H
#define _CIRCULO_H
#include "punto.h"
#include <iostream>

struct Circulo {
    Punto centro;
    double radio;
};

//void Avanzar(std::istream& is);

Circulo LeerCirculo();

void EscribirCirculo(const Circulo& c);

void InicializarCirculo (Circulo& c, const Punto& centro, const double& radio);

Punto Centro (const Circulo& c);

double Radio (const Circulo& c);

double Area (const Circulo& c);

bool Interior (const Punto& p, const Circulo& c);

double Distancia (const Circulo& c1, const Circulo& c2);

bool LeerCirculoIs(std::istream& is, Circulo& c);

bool EscribirCirculoOs(std::ostream& os, const Circulo& c);

#endif
