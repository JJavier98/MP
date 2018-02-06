#include "../../include/punto.h"
#include "../../include/rectangulo.h"
#include "../../include/avanzar.h"
#include <fstream>
#include <cmath>
#include <iostream>

using namespace std;

/*
void Avanzar(istream& is)
{
  while (isspace(is.peek()) || is.peek()=='#') {
    if (is.peek()=='#')
      is.ignore(1024,'\n'); // Suponemos una línea tiene menos de 1024
    else is.ignore();
  }
}
*/

bool Leer(istream& is, Rectangulo& r)
{
	char c;
	Punto min, max;

	Avanzar(is);
	is >> c;
	if (c != '(')
		return false;
	Avanzar(is);
	is >> min.x;

	Avanzar(is);
	is >> c;
	if (c != ',')
		return false;
	Avanzar(is);
	is >> min.y;

	Avanzar(is);
	is >> c;
	if (c != ')')
		return false;

	Avanzar(is);
	is >> c;
	if (c != '-')
		return false;

	Avanzar(is);
	is >> c;
	if (c != '(')
		return false;
	Avanzar(is);
	is >> max.x;

	Avanzar(is);
	is >> c;
	if (c != ',')
		return false;
	Avanzar(is);
	is >> max.y;

	Avanzar(is);
	is >> c;
	if (c != ')')
		return false;
	Avanzar(is);

	r.inf_izda = min;
	r.sup_dcha = max;

	if(max.x <= min.x && max.y <= min.y)
	{
		r.inf_izda = r.sup_dcha;
		max = min;
		r.sup_dcha = max;
	}

	return true;
}

bool Escribir(ostream& os, const Rectangulo& r)
{
	return (EscribirPuntoOs(os, r.inf_izda) && ( os << "-" ) && ( EscribirPuntoOs(os, r.sup_dcha) ) ) && ( os << endl );
}

void InicializarRectangulo (Rectangulo& r, const Punto& p1, const Punto& p2)
{
	Punto min, max;

	min = p1;
	max = p2;

	if (p2.x <= p1.x && p2.y <= p1.y)
	{
		min = p2;
		max = p1;
	}

	r.inf_izda = min;
	r.sup_dcha = max;
	
}

Punto InferiorIzquierda (const Rectangulo& r)
{
	return r.inf_izda;
}

Punto SuperiorDerecha (const Rectangulo& r)
{
	return r.sup_dcha;
}

double Area(const Rectangulo& r)
{
	return (r.sup_dcha.x - r.inf_izda.x) * (r.sup_dcha.y - r.inf_izda.y);
}

bool Interior (const Punto& p, const Rectangulo& r)
{
	return (p.x <= r.sup_dcha.x) && (p.x >= r.inf_izda.x) && (p.y <= r.sup_dcha.y) && (p.y >= r.inf_izda.y);
}

void Delimitar (Rectangulo& r, const Punto& p)
{
	if (p.x <= r.inf_izda.x)
		r.inf_izda.x = p.x;
	else if (p.x >= r.sup_dcha.x)
		r.sup_dcha.x = p.x;

	if (p.y <= r.inf_izda.y)
		r.inf_izda.y = p.y;
	else if (p.y >= r.sup_dcha.y)
		r.sup_dcha.y = p.y;
}