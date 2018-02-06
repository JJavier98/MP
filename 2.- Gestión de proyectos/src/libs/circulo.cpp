#include "../../include/circulo.h"
#include "../../include/punto.h"
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

Circulo LeerCirculo()
{
	Circulo cir_1;
	char c;

	cin >> cir_1.radio;
	cin >> c;
	cir_1.centro = LeerPunto();

	return cir_1;
}

void EscribirCirculo(const Circulo& c)
{
	cout << c.radio << "-";
	EscribirPunto(c.centro);
}

void InicializarCirculo (Circulo& c, const Punto& centro, const double& radio)
{
	c.radio = radio;
	c.centro = centro;
}

Punto Centro (const Circulo& c)
{
	return c.centro;
}

double Radio (const Circulo& c)
{
	return c.radio;
}

double Area (const Circulo& c)
{
	return M_PI * c.radio * c.radio;
}

bool Interior (const Punto& p, const Circulo& c)
{
	double distancia;
	
	distancia = Distancia(p , c.centro);

	return distancia <= c.radio;
}

double Distancia (const Circulo& c1, const Circulo& c2)
{
	return Distancia(c1.centro , c2.centro) - (c1.radio + c2.radio);
}

bool LeerCirculoIs(istream& is, Circulo& c)
{
	char car;

	Avanzar(is);
	is >> c.radio;
	Avanzar(is);
	is >> car;
	if (car != '-')
		return false;
	Avanzar(is);

	return LeerPuntoIs(is, c.centro);
}

bool EscribirCirculoOs(ostream& os, const Circulo& c)
{
	return (os << c.radio << "-") && EscribirPuntoOs(os, c.centro);
}

