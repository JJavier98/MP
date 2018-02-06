#include "class_Matriz.h"

using namespace std;

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

ostream& operator<<(ostream& os, const Matriz & m)
{
	os << m.Filas() << m.Columnas() << endl << endl;

	for (int i = 0 ; i < m.Filas() ; ++i)
	{
		for (int j = 0 ; j < m.Columnas() ; ++j)
		{
			os << m.Get(i,j) << ' ';
		}
		os << endl;
	}
	os << endl;

	return os;
}

istream& operator>>(istream& is, Matriz& m)
{
	int fil, col;
	int d;

	is >> fil;
	is >> col;

	if(is && fil > 0 && col > 0)
	{
		Matriz aux(fil,col);

		for (int i = 0 ; i < m.Filas() ; ++i)
		{
			for (int j = 0 ; j < m.Columnas() ; ++j)
			{
				is >> d;
				aux.Set(i,j,d);
			}
		}
		if(is)
			m = aux;
		else
			is.setstate(ios::failbit);
	}
	return is;
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
