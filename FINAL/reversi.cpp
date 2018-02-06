#include "Tablero/class_Tablero.h"
#include "Jugador/class_Jugador.h"
#include <iostream>
#include <cassert>

using namespace std;

int main(int argc, char const *argv[])
{
	char selec;
	int num1, num2;
	Tablero tablero;

	cout << "¿Quiere jugar en un tablero estandar 8x8? <y/n>: ";
	cin >> selec;

	while (selec != 'y' && selec != 'n')
	{
		cout << "Selección no válida. Introduzca de nuevo: ";
		cin >> selec;
	}

	if(selec == 'y')
	{
		tablero = Tablero();
	}
	else
	{
		char form;

		cout << "¿Desea un tablero rectangular(r) o cuadrado(c)?: ";
		cin >> form;

		while (form != 'r' && form != 'c')
		{
			cout << "Selección no válida. Introduzca de nuevo: ";
			cin >> form;
		}

		if (form == 'r')
		{
			int f,c;

			cout << "Seleccione el tamaño del tablero <filas columnas>: ";
			cin >> f;
			cin >> c;

			tablero = Tablero(f,c);
		}
		else
		{
			int tam;
			cout << "Indique el tamaño: ";
			cin >> tam;

			tablero = Tablero(tam);
		}
	}
	
	tablero.PrettyPrint();

	cout << "Indique el número del jugador NEGRAS y del jugador BLANCAS en ese orden: ";
	cin >> num1;
	cin >> num2;

	Jugador j1(num1), j2(num2);

	while()


	return 0;
}
