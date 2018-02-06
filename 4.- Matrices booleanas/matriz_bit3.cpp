//#include "matriz_bit3.h"

using namespace std;

//___________

bool Inicializar(MatrizBit& m, int fils, int cols)
{
	int util = fils * cols;
	m.f_c = 0;
	if (util <= m.MAX_V)
	{
		
		m.f_c = fils << 16 | cols;

		for(int i = 0 ; i < util ; i++)
		{
			m.matriz[i] = false;
		}
		
		return true;
	}
	else
	{
		return false;
	}
}

//___________

int Filas (const MatrizBit& m)
{
	return m.f_c >> 16;
}

//___________

int Columnas( const MatrizBit& m)
{
	return m.f_c & 0xFFFF;
}

//___________

bool Get(const MatrizBit& m, int f, int c)
{
	int columnas = Columnas(m);
	int posicion = ((f * columnas) + c);

		return m.matriz[posicion];
}

//___________

void Set(MatrizBit& m, int f, int c, bool v)
{

	int columnas = Columnas(m);
	int posicion = ((f * columnas) + c);

	if(posicion < m.MAX_V)
		m.matriz[posicion] = v;
}

//___________