#include "Tablero/class_Tablero.h"
#include "Jugador/class_Jugador.h"
#include <iostream>
#include <cassert>
#include <cstdlib>

using namespace std;

int main(int argc, char const *argv[])
{
	Tablero tablero;
	char selec;
	char elec;
	string separador = "--------------------------------------------------------------";

// STANDAR________________________________________________________________

	cout << "¿Quiere jugar en un tablero estandar 8x8? <y/n>: ";
	cin >> selec;

	while (selec != 'y' && selec != 'n')
	{
		cout << "Selección no válida. Introduzca de nuevo: ";
		cin >> selec;
	}

// CUSTOM________________________________________________________________

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

// PLAYERS________________________________________________________________

	cout << endl << "Introduzca el nombre del Jugador 1 (NEGRAS): " << endl;
	Jugador j1;
	cout << endl << "Introduzca el nombre del Jugador 2 (BLANCAS): " << endl;
	Jugador j2;

// GAME________________________________________________________________

	elec = 's';
	while(elec == 's')
	{
		while(!tablero.Final())
		{
			if(tablero.Turno()==1 && !tablero.PasaPalabra())
			{
				do{
					cout << endl << endl <<	separador << endl << "Turno de las NEGRAS: ";

					for(int i = 0 ; i < j1.Longitud() ; ++i)
					{
						cout << j1.Nombre()[i];
					}

					cout << endl << endl;
				}while(!j1.EscogePosicion(tablero));
			}
			else if(tablero.Turno()==2 && !tablero.PasaPalabra())
			{
				do{
					cout << endl << endl <<	separador << endl << "Turno de las BLANCAS: ";

					for(int i = 0 ; i < j2.Longitud() ; ++i)
					{
						cout << j2.Nombre()[i];
					}

					cout << endl << endl;
				}while(!j2.EscogePosicion(tablero));
			}
		}

// RESULTS________________________________________________________________

		int winner = tablero.Ganador();

		cout << endl << endl << endl <<	separador << endl << separador << endl << "El tablero al final de la partida ha quedado así: " << endl << endl;

		tablero.PrettyPrint();


		if(winner == 1)
		{
			cout << "Han ganado las NEGRAS con " << tablero.Puntuacion() << " puntos" << endl;
			j1.SumaPuntos(tablero);
		}
		else if (winner == 2)
		{
			cout << "Han ganado las BLANCAS con " << tablero.Puntuacion() << " puntos" << endl;
			j2.SumaPuntos(tablero);
		}
		else
			cout << "Ha habido un empate" << endl;


		cout << separador << endl << separador << endl << endl << endl << endl;

// END________________________________________________________________

		cout << "Quieres volver a jugar? <y/n>: ";
		cin >> elec;

		while (elec != 'y' && elec != 'n')
		{
			cout << "Selección no válida. Introduzca de nuevo: ";
			cin >> elec;
		}

		if (elec == 'y')
		{
			tablero.Iniciar();
			system("clear");
			elec = 's';
		}
		else
		{
			system("clear");
			cout << "--ESTADO FINAL DE LA PARTIDA--" << endl << endl;
			cout << "Tablero: " << tablero.Filas() << "x" << tablero.Columnas() << endl;
			cout << "Puntuación Jugador 1 <NEGRAS>: " << j1.ShowMarks() << endl;
			cout << "Puntuación Jugador 2 <BLANCAS>: " << j2.ShowMarks() << endl;
			cout << "Partida terminada" << endl << endl;
		}
	}

	return 0;
}
