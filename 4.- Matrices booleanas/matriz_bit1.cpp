//#include "matriz_bit1.h"

using namespace std;

bool Inicializar(MatrizBit& m, int fils, int cols)
{
	if (fils <= m.MAX_F_C && cols <= m.MAX_F_C)
	{
		m.filas = fils;
		m.columnas = cols;

		for(int i = 0 ; i < fils ; i++)
		{
			for(int j = 0 ; j < cols ; j++)
			{
				m.matriz[i][j] = false;
			}
		}
		
		return true;
	}
	
	return false;
}

int Filas (const MatrizBit& m)
{
	return m.filas;
}

int Columnas( const MatrizBit& m)
{
	return m.columnas;
}

bool Get(const MatrizBit& m, int f, int c)
{
		return m.matriz[f][c];
}

void Set(MatrizBit& m, int f, int c, bool v)
{
	if(f < m.MAX_F_C && c < m.MAX_F_C)
	{
		m.matriz[f][c] = v;
	}
}
