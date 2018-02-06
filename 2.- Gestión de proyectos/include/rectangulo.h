#ifndef _RECTANGULO
#define _RECTANGULO
#include "punto.h"
#include <iostream>

struct Rectangulo {
    Punto inf_izda;
    Punto sup_dcha;
};

bool Leer(std::istream& is, Rectangulo& r);

bool Escribir(std::ostream& os, const Rectangulo& r);

void InicializarRectangulo (Rectangulo& r, const Punto& p1, const Punto& p2);

Punto InferiorIzquierda (const Rectangulo& r);

Punto SuperiorDerecha (const Rectangulo& r);

double Area(const Rectangulo& r);

bool Interior (const Punto& p, const Rectangulo& r);

void Delimitar (Rectangulo& r, const Punto& p);

#endif
