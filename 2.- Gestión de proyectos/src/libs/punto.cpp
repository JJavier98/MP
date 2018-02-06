#include "../../include/punto.h"
#include "../../include/circulo.h"
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

Punto LeerPunto()
{
	char c;
	Punto p;

	cin >> c;
	cin >> p.x;
	cin >> c;
	cin >> p.y;
	cin >> c;

	return p;
}

void EscribirPunto (const Punto& p)
{
	cout << "(" << p.x << "," << p.y << ")";
}

void InicializarPunto (Punto& p, const double& cx, const double& cy)
{
	p.x = cx;
	p.y = cy;
}

double GetX (const Punto& p)
{
	return p.x;
}

double GetY (const Punto& p)
{
	return p.y;
}

double Distancia (const Punto& p1, const Punto& p2)
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

Punto PuntoMedio (const Punto& p1, const Punto& p2)
{
	Punto punto_medio;

	punto_medio.x = (p1.x + p2.x) / 2;
	punto_medio.y = (p1.y + p2.y) / 2;

	return punto_medio;
}

bool LeerPuntoIs(istream& is, Punto& p)
{
	char c;

	Avanzar(is);
	is >> c;
	if (c != '(')
		return false;
	Avanzar(is);
	is >> p.x;
	Avanzar(is);
	is >> c;
	if (c != ',')
		return false;
	Avanzar(is);
	is >> p.y;
	Avanzar(is);
	is >> c;
	if (c != ')')
		return false;
	Avanzar(is);

	return true;
}

bool EscribirPuntoOs(ostream& os, const Punto& p)
{
	return os << "(" << p.x << "," << p.y << ")";
}