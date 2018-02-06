#ifndef _MATRIZ_BIT1_
#define _MATRIZ_BIT1_

struct MatrizBit
{
	static const int MAX_F_C = 10;
	int filas,
		columnas;
	bool matriz[MAX_F_C][MAX_F_C];
};

bool Inicializar(MatrizBit& m, int fils, int cols);

int Filas (const MatrizBit& m);

int Columnas( const MatrizBit& m);

bool Get(const MatrizBit& m, int f, int c);

void Set(MatrizBit& m, int f, int c, bool v);

#endif
