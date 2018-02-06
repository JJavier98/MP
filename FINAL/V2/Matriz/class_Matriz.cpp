#include "class_Matriz.h"

//______________________________________

Matriz::Matriz(){
	nf = 0;
	nc = 0;

	mtrz = 0;
}

Matriz::Matriz(int nfc){
	if (nfc > 0)
	{
		nf = nfc;
		nc = nfc;

		mtrz = new int[nf*nc];	

		for(int i = 0; i < nfc*nfc ; ++i)
		{
			mtrz[i] = 0;
		}
	}
	else
	{
		Matriz();
	}
}

Matriz::Matriz(int fil, int col){
	if (fil > 0 && col > 0)
	{
		nf = fil;
		nc = col;

		mtrz = new int[nf*nc];

		for(int i = 0; i < nf*nc ; ++i)
		{
			mtrz[i] = 0;
		}
	}
	else
	{
		Matriz();
	}
}

Matriz::Matriz(const Matriz & m)
{
	nf = m.nf;
	nc = m.nc;

	mtrz = new int[nf*nc];

	for(int i = 0; i < nf*nc ; ++i)
	{
		mtrz[i] = m.mtrz[i];
	}
}

Matriz::~Matriz()
{
	delete[] mtrz;
}

//______________________________________

Matriz& Matriz::operator=(const Matriz& ma)
{
	if (this != &ma)
	{
		delete[] mtrz;

		nf = ma.nf;
		nc = ma.nc;

		mtrz = new int[nf*nc];
	
		for(int i = 0; i < nf*nc ; ++i)
		{
			mtrz[i] = ma.mtrz[i];
		}
	}
	return *this;
}

//______________________________________

int Matriz::Filas()const{
	return nf;
}

int Matriz::Columnas()const{
	return nc;
}

int Matriz::Get(int f, int c)const{
	return mtrz[f*Columnas()+c];
}

void Matriz::Set(int fil, int col, int v){
	mtrz[fil*Columnas()+col] = v;
}
