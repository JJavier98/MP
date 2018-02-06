#include "class_Jugador.h"
#include "../Tablero/class_Tablero.h"
#include "../Matriz/class_Matriz.h"
#include <cassert>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>

using namespace std;

//______________________________________

Jugador::Jugador(istream & is)
{
	nombre = new char[50];
	puntuacion = 0;
	PideNombre(is);
	n = strlen(nombre);
	arreglar();
}

Jugador::Jugador(const Jugador & j)
{
	n = j.n;
	puntuacion = j.puntuacion;

	nombre = new char[n];

	for(int i = 0 ; i < n ; ++i)
	{
		nombre[i] = j.nombre[i];
	}
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
		nombre = new char[n];
		for(int i = 0 ; i < n ; ++i)
		{
			nombre[i] = j.nombre[i];
		}
	}
	return *this;
}

ostream& operator<<(ostream& os, const Jugador& j)
{
	for (int i = 0 ; i < j.n ; ++i)
	{
		os << j.Nombre()[i];
	}
	os << endl << j.Longitud() << endl;
	os << j.ShowMarks() << endl;

	return os;
}

istream& operator>>(istream& is, Jugador& j)
{
	is.ignore(65535,'!');
	j.PideNombre(is);
	is >> j.n;
	is >> j.puntuacion;

	return is;
}

//______________________________________

void Jugador::PideNombre(istream & is)
{
	is >> ws; // ws elimina los espacios inicales;
	is.getline(nombre,50,'\n');
}

void Jugador::DialogoEscoger(istream & is, Tablero & tab)
{
	int f, c;
	char col;

	tab.PrettyPrint(cout);

	cout << "Escoja una de entre todas las posiciones válidas visibles en el tablero." << endl << "Formato de entrada: <ColumnaFila>: ";

	is >> col;
	is >> f;

	if (col != '!')
	{

		c= col - 'a';

		while (!tab.PosicionValida(f,c))
		{
			cout << endl << "Posición " << col << f << " No Valida." << endl << "Escoja otra: ";
	    	is >> col;
	    	is >> f;

	    	c = col - 'a';
	    }
	    tab.Set(f,c);
	}
	else
		{
			system("clear");
			cout << "#######Se ha interrumpido la partida por el jugador " << tab.Turno() << " #######";
			tab.Finalizar();
		}
}


void Jugador::arreglar()
{
	if(n < 50)
	{
		char* aux = new char[n];
		for(int i = 0 ; i < n ; ++i)
		{
			aux[i] = nombre[i];
		}
		delete[] nombre;
		nombre = aux;
	}
}


//______________________________________

int Jugador::ShowMarks()const
{
	return puntuacion;
}

void Jugador::SumaPuntos(Tablero & tablero)
{
	puntuacion = puntuacion + tablero.Puntuacion();
}

bool Jugador::EscogePosicion(istream & is, Tablero & tab)
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

		tab.PrettyPrint(cout);

		cout << "La única posición válida es: " << c << v_pos[0] << "\nSe ha colocado su ficha automáticamente." << endl;

		tab.Set(v_pos[0],v_pos[1]);
		exito = true;
	}
	else if(pos_validas > 1)
	{
		DialogoEscoger(is, tab);
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

char* Jugador::Nombre()const
{
	return nombre;
}

int Jugador::Longitud()const
{
	return n;
}
