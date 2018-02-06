//#include "matriz_bit2.h"

using namespace std;

//___________

bool Inicializar(MatrizBit& m, int fils, int cols)
{
	int util = fils * cols;
	if (util <= m.MAX_V)
	{
		m.filas = fils;
		m.columnas = cols;

		for(int i = 0 ; i < util ; i++)
		{
			m.matriz[i] = false;
		}
		
		return true;
	}
	
	return false;
}

//___________

int Filas (const MatrizBit& m)
{
	return m.filas;
}

//___________

int Columnas( const MatrizBit& m)
{
	return m.columnas;
}

//___________

bool Get(const MatrizBit& m, int f, int c)
{
	int posicion = ((f * m.columnas) + c);

		return m.matriz[posicion];
}

//___________

void Set(MatrizBit& m, int f, int c, bool v)
{
	int posicion = ((f * m.columnas) + c);

	if(posicion < m.MAX_V)
		m.matriz[posicion] = v;
}

//___________