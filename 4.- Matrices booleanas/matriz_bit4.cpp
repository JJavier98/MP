#include <iostream>

using namespace std;

//___________

bool Inicializar(MatrizBit& m, int fils, int cols)
{
	m.f_c = 0;
	int util = fils * cols;
	if (util <= m.MAX_Bit)
	{
		m.f_c = fils << 8 | cols;

		for(int i = 0 ; i < m.MAX_V ; i++)
		{
			m.matriz[i] = 0;
		}
		
		return true;
	}
	
	return false;
}

//___________

int Filas (const MatrizBit& m)
{
	return m.f_c >> 8;
}

//___________

int Columnas( const MatrizBit& m)
{
	return m.f_c & 0xFF;
}

//___________

bool Get(const MatrizBit& m, int f, int c)
{
	int col = Columnas(m);
	int posicion = ((f * col) + c),
		indice = posicion / 32,
		bit = posicion % 32;

	if( ( m.matriz[indice] & (1<<bit) ) != 0 )
		return true;
	else
		return false;
}

//___________

void Set(MatrizBit& m, int f, int c, bool v)
{
	int col = Columnas(m);
	int posicion = ((f * col) + c),
		indice = posicion / 32,
		bit = posicion % 32;

	if(posicion < m.MAX_Bit)
	{
		if(v)
		{
			m.matriz[indice] = m.matriz[indice] | (1<<bit);
		}
		else
		{
			m.matriz[indice] = m.matriz[indice] & ~(1<<bit);
		}
	}
}

//___________