#include <cassert>
#include <iostream>
#include "class_Tablero.h"
#include "../Matriz/class_Matriz.h"

using namespace std;

///////////////////////////////////////////////////////

void Tablero::PrettyPrint()
{
	char letra = 'a';
	cout << "  ";
	for (int i = 0 ; i < tablero.Columnas() ; i++)
	{
		cout << letra << " ";
		letra++;
	}
	cout << endl << " -";
	for (int i = 0 ; i < tablero.Columnas() ; i++)
	{
		cout << "--";
	}

	cout << endl;

	for (int i = 0 ; i < tablero.Filas() ; i++)
	{
		int aux=0;
		for (int j = 0 ; j < tablero.Columnas() ; j++)
		{
			if (aux == 0)
			{
				cout << i << "|";
			}
			if(tablero.Get(i,j) == 0)
			{
				cout << " |";
			}
			
			else if (tablero.Get(i,j) == 1)
			{
				cout << "x|";
			}
			else if (tablero.Get(i,j) == 2)
			{
				cout << "o|";
			}
			aux++;
		}
		cout << endl;
	}
	cout << " -";
	for (int i = 0 ; i < tablero.Columnas() ; i++)
	{
		cout << "--";
	}

	cout << endl;
}

///////////////////////////////////////////////////////

Tablero::Tablero():tablero(8)
{
	jugador = false;
	terminada = false;
	Iniciar();
}

Tablero::Tablero(int nfc):tablero(nfc)
{
	jugador = false;
	terminada = false;
	Iniciar();
}

Tablero::Tablero(int f, int c):tablero(f, c)
{
	jugador = false;
	terminada = false;
	Iniciar();
}

Tablero& Tablero::operator=(const Tablero& tab)
{
	if (this != *tab)
	{
		tablero = tab.tablero;
		jugador = tab.jugador;
		terminada = tab.terminada;
	}
	return *this;
}

//////////////////////////////////////////////////////

int Tablero::Opuesta()const
{
	if(jugador)
		return 1;
	else
		return 2;
}

int Tablero::Filas()const
{
	return tablero.Filas();
}
int Tablero::Columnas()const
{
	return tablero.Columnas();
}

int Tablero::Get(int f, int c)const
{

	return tablero.Get(f,c);
}

int Tablero::Turno()const
{
	if(jugador)
		return 2;
	else
		return 1;
}

void Tablero::CambiaTurno()
{
	if(jugador)
		jugador = false;
	else
		jugador = true;
}

bool Tablero::Final()const
{
	return terminada;
}

void Tablero::Finalizar()
{
	terminada = true;
}

int Tablero::Ganador()const
{
	int fil, col;
	int fichas1, fichas2;

	fichas1 = 0;
	fichas2 = 0;

	fil = tablero.Filas();
	col = tablero.Columnas();	

	for (int i = 0 ; i < fil ; i++)
	{
		for(int j = 0 ; j < col ; j++)
		{
			if (tablero.Get(i,j)==1)
			{
				fichas1++;
			}
			else if (tablero.Get(i,j)==2)
				{
					fichas2++;
				}
		}
	}

	if (fichas1 < fichas2)
		return 2; // gana jugador2
	else if (fichas1 > fichas2)
		return 1; // gana jugador1
	else
		return 0; // empate;
}

int Tablero::Puntuacion()const
{
	int fil, col;
	int fichas1, fichas2;

	fichas1 = 0;
	fichas2 = 0;

	fil = tablero.Filas();
	col = tablero.Columnas();	

	for (int i = 0 ; i < fil ; i++)
	{
		for(int j = 0 ; j < col ; j++)
		{
			if (tablero.Get(i,j)==1)
			{
				fichas1++;
			}
			else if (tablero.Get(i,j)==2)
				{
					fichas2++;
				}
		}
	}

	if (Ganador()==1)
		return (fichas1 - fichas2);
	else if (Ganador()==2)
		return (fichas2 - fichas1);
	else
		return 0;
}

bool Tablero::PosicionValida(int f, int c)const
{
	assert(f < Filas() && f >= 0);
	assert(c < Columnas() && c >= 0);

	int i2,j2;

	if(Get(f,c) == 0)
	{
		for(int i = -1 ; i <= 1 ; ++i)
		{
			for (int j = -1; j <= 1; ++j)
			{
	            if(   f+i >=0 && f+i < Filas() && c+j >= 0 && c+j < Columnas() && Get(f+i,c+j) == Opuesta()  )
	            {
					i2 = i+i;
					j2 = j+j;
					while(   f+i2 >=0 && f+i2 < Filas() && c+j2 >= 0 && c+j2 < Columnas()  && Get(f+i2,c+j2) == Opuesta()  )
					{
						i2+=i;
						j2+=j;
					}
	                if (   f+i2 >=0 && f+i2 < Filas() && c+j2 >= 0 && c+j2 < Columnas() && Get(f+i2,c+j2) == Turno() )
						return true;

	            }
			}
		}
	}
	return false;
}

bool Tablero::PasaPalabra()
{
	for (int i = 0 ; i < Filas() ; i++)
	{
		for(int j = 0 ; j < Columnas() ; j++)
		{
			if(PosicionValida(i,j))
			{
				return false;
			}
		}
	}
	return true;
}

void Tablero::Set(int f, int c)
{
	assert(f < Filas() && f >= 0);
	assert(c < Columnas() && c >= 0);

	int i2,j2;

	if(Get(f,c) == 0)
	{
		for(int i = -1 ; i <= 1 ; ++i)
		{
			for (int j = -1; j <= 1; ++j)
			{
                if(   f+i >=0 && f+i < Filas() && c+j >= 0 && c+j < Columnas() && Get(f+i,c+j) == Opuesta()   )
                {
					i2 = i+i;
					j2 = j+j;
					while(   f+i2 >=0 && f+i2 < Filas() && c+j2 >= 0 && c+j2 < Columnas()  && Get(f+i2,c+j2) == Opuesta()  )
					{
						i2+=i;
						j2+=j;
					}
	                if (   f+i2 >=0 && f+i2 < Filas() && c+j2 >= 0 && c+j2 < Columnas() && Get(f+i2,c+j2) == Turno()   )
	                {
						i2 = i;
						j2 = j;
						while(   f+i2 >=0 && f+i2 < Filas() && c+j2 >= 0 && c+j2 < Columnas()  && Get(f+i2,c+j2) == Opuesta()  )
						{
							tablero.Set(f+i2,c+j2,Turno());

							i2+=i;
							j2+=j;
						}
					}
                }
			}
		}
		tablero.Set(f,c,Turno());
	}
}

void Tablero::Iniciar()
{
	jugador = false;
	terminada = false;

	for(int i = 0 ; i < Filas() ; i++)
	{
		for (int j = 0 ; j < Columnas() ; j++)
		{
			tablero.Set(i,j,0);
		}
	}

	//if(Filas() % 2 == 0 && Columnas()%2 == 0)
	//{
	tablero.Set(Filas()/2,Columnas()/2,1);
	tablero.Set(Filas()/2,Columnas()/2-1,2);
	tablero.Set(Filas()/2-1,Columnas()/2,2);
	tablero.Set(Filas()/2-1,Columnas()/2-1,1);
	//}
}
