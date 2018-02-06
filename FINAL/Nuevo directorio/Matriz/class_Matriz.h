#ifndef _MATRIZ_H_
#define _MATRIZ_H_

#include <iostream>

class Matriz
{
	private:
		int* mtrz;
		int nf;
		int nc;
	public:
		//CONSTRUCTORES - DESTRUCTOR
		Matriz();
		Matriz(int nfc);
		Matriz(int fil, int col);
		Matriz(const Matriz & m);
		~Matriz();

		//---OPERADORES---
		// '='
		Matriz& operator=(const Matriz& mtrz);

		// '<<'
		friend std::ostream& operator<<(std::ostream& os, const Matriz & m);

		// '>>'
		friend std::istream& operator>>(std::istream& is, Matriz& m);

		// CONSULTA EN Nº DE FILAS
		int Filas()const;

		// CONSULTA EL Nº DE COLUMNAS
		int Columnas()const;

		// CONSULTA QUÉ HAY EN LA POSICIIÓN (f,c)
		// 1 negra ; 2 blanca
		int Get(int f, int c)const;

		// ESTABLECE UN VALOR(ficha) EN LA CASILLA (fil,col)
		void Set(int fil, int col, int v);
};

#endif
