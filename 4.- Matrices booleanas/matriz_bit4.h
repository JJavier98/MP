#ifndef _MATRIZ_BIT4_
#define _MATRIZ_BIT4_

struct MatrizBit
{
	static const int 	MAX_V = 4,
						MAX_Bit = 128;

	unsigned short int f_c;

	unsigned int matriz[MAX_V];
};

bool Inicializar(MatrizBit& m, int fils, int cols);

int Filas (const MatrizBit& m);

int Columnas( const MatrizBit& m);

bool Get(const MatrizBit& m, int f, int c);

void Set(MatrizBit& m, int f, int c, bool v);

#endif
