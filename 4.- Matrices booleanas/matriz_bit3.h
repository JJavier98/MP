#ifndef _MATRIZ_BIT3_
#define _MATRIZ_BIT3_

struct MatrizBit
{
	static const int MAX_V = 100;
	unsigned int f_c;
	bool matriz[MAX_V];
};

bool Inicializar(MatrizBit& m, int fils, int cols);

int Filas (const MatrizBit& m);

int Columnas( const MatrizBit& m);

bool Get(const MatrizBit& m, int f, int c);

void Set(MatrizBit& m, int f, int c, bool v);

#endif
