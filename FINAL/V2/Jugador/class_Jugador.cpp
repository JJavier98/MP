#include "class_Jugador.h"
#include "../Tablero/class_Tablero.h"
#include "../Matriz/class_Matriz.h"
#include <cassert>
#include <iostream>
//#include <iomanip>
#include <cstring>

using namespace std;

//______________________________________

Jugador::Jugador()
{
	PideNombre();
	n = strlen(nombre);
	puntuacion = reservado = 0;
}

Jugador::Jugador(const Jugador & j)
{
	n = j.n;
	reservado = j.reservado;

	nombre = new char[n];

	for(int i = 0 ; i < n ; ++i)
	{
		nombre[i] = j.nombre[i];
	}
	puntuacion = j.puntuacion;
}

Jugador::~Jugador()
{
	delete[] nombre;
}

//______________________________________

Jugador & Jugador::operator=(const Jugador & j)
{
	if(this != &j)
	{
		delete[] nombre;
		n = j.n;
		reservado = j.reservado;
		nombre = new char[n];
		for(int i = 0 ; i < n ; ++i)
		{
			nombre[i] = j.nombre[i];
		}
	}
	return *this;
}

//______________________________________

void Jugador::PideNombre()
{
	char car;

	cin >> ws; // ws elimina los espacios inicales;
	cin >> car;

	while(car != '\n' && car != '\0')
	{
		push_back(car);
		cin >> car;
	}
}

void Jugador::DialogoEscoger(Tablero & tab)
{
	int f, c;
	char col;

	tab.PrettyPrint();

	cout << "Escoja una de entre todas las posiciones válidas visibles en el tablero." << endl << "Formato de entrada: <ColumnaFila>: ";

	cin >> col;
	cin >> f;

	c= col - 'a';

	while (!tab.PosicionValida(f,c))
	{
		cout << endl << "Posición " << col << f << " No Valida." << endl << "Escoja otra: ";
    	cin >> col;
    	cin >> f;

    	c = col - 'a';
    }
    tab.Set(f,c);
}

void Jugador::push_back(char c)
{
	if(n < reservado)
	{
		nombre[n] = c;
		n++;
	}
	else
	{
		int nt = reservado == 0? 1:2*reservado;
		char* aux = new char[nt];
		for(int i = 0 ; i < n ; ++i)
		{
			aux[i] = nombre[i];
		}
		delete[] nombre;
		nombre = aux;
		reservado = nt;
		nombre[n] = c;
		n++;
	}
}

//______________________________________

int Jugador::ShowMarks()
{
	return puntuacion;
}

void Jugador::SumaPuntos(Tablero & tablero)
{
	puntuacion = puntuacion + tablero.Puntuacion();
}

bool Jugador::EscogePosicion(Tablero & tab)
{
	int pos_validas, v_pos[2];
	bool exito = false;

	pos_validas = 0;

	assert(!tab.PasaPalabra());

	for (int i = 0 ; i < tab.Filas() ; i++)
	{
		for (int j = 0 ; j < tab.Columnas() ; j++)
		{
			if(tab.PosicionValida(i,j))
			{
				pos_validas++;
				if(pos_validas == 1)
				{
					v_pos[0] = i;
					v_pos[1] = j;
				}
			}
		}
	}
	if(pos_validas == 1)
	{
		char c;

		c = (char)('a'+v_pos[1]);

		tab.PrettyPrint();

		cout << "La única posición válida es: " << c << v_pos[0] << "\nSe ha colocado su ficha automáticamente." << endl;

		tab.Set(v_pos[0],v_pos[1]);
		exito = true;
	}
	else if(pos_validas > 1)
	{
		DialogoEscoger(tab);
		exito = true;
	}

	PasaTurno(tab);
	return exito;
}

void Jugador::PasaTurno(Tablero& tab)
{
	tab.CambiaTurno();

	if (tab.PasaPalabra())
	{

		cout << endl << "--------------------------------------------------------------" << endl << endl <<
				"Ups... Parece que el jugador "<< tab.Turno() << " tuvo que pasar.";
		tab.CambiaTurno();

		if ( tab.PasaPalabra() )
		{
			tab.Finalizar();
		}
	}
}

char* Jugador::Nombre()
{
	return nombre;
}

int Jugador::Longitud()const
{
	return n;
}
