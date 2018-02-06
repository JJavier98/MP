#ifndef _MATRIZ_H_
#define _MATRIZ_H_

class Matriz
{
	private:
		int mtrz[10][10];
		int nf;
		int nc;
	public:
		//CONSTRUCTORES
		Matriz();
		Matriz(int nfc);
		Matriz(int fil, int col);

		// CONSULTA EN Nº DE FILAS
		int Filas()const;

		// CONSULTA EL Nº DE COLUMNAS
		int Columnas()const;

		// CONSULTA QUÉ HAY EN LA POSICIIÓN (f,c)
		// 1 negra ; 2 blanca
		int Get(int f, int c)const;

		// ESTABLECE UN VALOR(ficha) EN LA CASILLA (fil,col)
		void Set(int fil, int col, int v);

		// OPERADOR '='
		Matriz& operator=(const Matriz& mtrz);
};

#endif
