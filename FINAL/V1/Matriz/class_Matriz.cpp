#include "class_Matriz.h"

//______________________________________

Matriz::Matriz(){
	nf = 8;
	nc = 8;
	for(int i = 0; i < 8 ; ++i)
	{
		for(int j = 0; j < 8;++j)
		{
			mtrz[i][j] = 0;
		}
	}
}

Matriz::Matriz(int nfc){
	nf = nfc;
	nc = nfc;
	for(int i = 0; i < nfc ; ++i)
	{
		for(int j = 0; j < nfc;++j)
		{
			mtrz[i][j] = 0;
		}
	}
}

Matriz::Matriz(int fil, int col){
	nf = fil;
	nc = col;
	for(int i = 0; i < fil ; ++i)
	{
		for(int j = 0; j < col;++j)
		{
			mtrz[i][j] = 0;
		}
	}
}

Matriz& Matriz::operator=(const Matriz& ma)
{
	for(int i = 0; i < 10 ; ++i)
	{
		for(int j = 0; j < 10;++j)
		{
			mtrz[i][j] = ma.mtrz[i][j];
		}
	}
	nf = ma.nf;
	nc = ma.nc;
}

//______________________________________

int Matriz::Filas()const{
	return nf;
}

int Matriz::Columnas()const{
	return nc;
}

int Matriz::Get(int f, int c)const{
	return mtrz[f][c];
}

void Matriz::Set(int fil, int col, int v){
	mtrz[fil][col] = v;
}
