#include <iostream>
#include <fstream>
#include <string.h>
#include "matriz_bit.h"
#include "matriz_operaciones.h"

// _____________________________________________________________________________

void Avanzar(std::istream& is)
{
  while (isspace(is.peek()) || is.peek()=='#') {
    if (is.peek()=='#')
      is.ignore(1024,'\n'); // Suponemos una línea tiene menos de 1024
    else is.ignore();
  }
}

// _____________________________________________________________________________

bool Leer(std::istream& is, MatrizBit& m)
{
	
	if(is.peek() == 'X' || is.peek() == '.')
	{
        char buffer[1024];
        char linea[256];
        int columnas;
        int puntero = 0;
        int filas = 0;

        is.getline(linea,256);
        columnas = strlen(linea);
        filas++;

        for(int i = 0; i <= columnas; i++)
        {
            buffer[i] = linea[i];
        }

        puntero = columnas;

        while(is.peek() == 'X' || is.peek() == '.')
        {
            is.getline(linea,256);

            for(int i = 0; i<= columnas; i++)
            {
            buffer[i+puntero] = linea[i];
            }

            puntero += columnas;    
            filas++;
            
        }

        if( !(Inicializar(m, filas, columnas)) )
        {
          return false;
        }

        for(int i = 0; i < filas; i++)
        {
            for(int j = 0; j < columnas; j++)
            {
                if(buffer[i*columnas+j] == 'X')
                {
                    Set(m, i, j, true);
                }
                else
                {
                    Set(m,i,j,false);
                }
            }
        }
        return true; 
	}
	else
	{	
		int filas,
			columnas;

		bool v;

		is >> filas;
		is >> columnas;

		if (! Inicializar(m, filas, columnas))
		{
			return false;
		}

		for (int i = 0; i < filas; i++)
		{
			for(int j = 0 ; j < columnas ; j++)
			{
				is >> v;
				Set(m,i,j,v);
			}
		}
		return true;
	}
}

// _____________________________________________________________________________

bool Escribir(std::ostream& os, const MatrizBit& m)
{

	int filas,
		columnas;

	bool correcto = false;

	filas = Filas(m);
	columnas = Columnas(m);

	os << "\n";

	for (int i = 0; i < filas; i++)
	{
		for(int j = 0 ; j < columnas ; j++)
		{
			os << Get(m,i,j) << " ";
			correcto = true;
		}
		os << "\n";
	}
	return correcto;
}

// _____________________________________________________________________________

bool Leer(const char nombre[], MatrizBit& m)
{
	std::ifstream f;

	f.open(nombre);
    if(!f)
    {
        return false;
    }
    else
    {
        return Leer(f,m);
	}
}

// _____________________________________________________________________________

bool Escribir(const char nombre[], const MatrizBit& m)
{
	std::ofstream of;

    of.open(nombre);

    if(!of)
    {
        return false;
    }
    else
    {
        return Escribir(of,m);
	}
}

// _____________________________________________________________________________

void And(MatrizBit& res, const MatrizBit& m1, const MatrizBit& m2)
{
	int filas1,
		columnas1,
		filas2,
		columnas2,
		k = 0;


	filas1 = Filas(m1);
	columnas1 = Columnas(m1);
	filas2 = Filas(m2);
	columnas2 = Columnas(m2);

	if(filas1 == filas2 && columnas1 == columnas2)
	{
		for(int i = 0 ; i < filas1 ; i++)
		{
			for(k = 0 ; k < columnas1 ; k++)
			{
				Set( res, i, k, ( Get(m1,i,k) && Get(m2,i,k) ) );
			}
			
		}
	}
}

// _____________________________________________________________________________

void Or(MatrizBit& res, const MatrizBit& m1, const MatrizBit& m2)
{
	int filas1,
		columnas1,
		filas2,
		columnas2,
		k = 0;

	filas1 = Filas(m1);
	columnas1 = Columnas(m1);
	filas2 = Filas(m2);
	columnas2 = Columnas(m2);

	if(filas1 == filas2 && columnas1 == columnas2)
	{
		for(int i = 0 ; i < filas1 ; i++)
		{
			for(k = 0 ; k < columnas1 ; k++)
			{
				Set( res, i, k, ( Get(m1,i,k) || Get(m2,i,k) ) );
			}
			
		}
	}
}

// _____________________________________________________________________________

void Not(MatrizBit& res, const MatrizBit& m)
{
	int filas,
		columnas;

	filas = Filas(m);
	columnas = Columnas(m);

	for (int i = 0; i < filas; i++)
	{
		for(int j = 0 ; j < columnas ; j++)
		{
			Set(res,i,j,!Get(m,i,j));
		}
	}
}

// _____________________________________________________________________________

void Traspuesta(MatrizBit& res, const MatrizBit& m)
{
	int f = Filas(m),
		c = Columnas(m);

	Inicializar(res,c,f);

	for (int i = 0; i < f; i++)
	{
		for(int j = 0 ; j < c ; j++)
		{
			Set(res,j,i,Get(m,i,j));
		}
	}
}

