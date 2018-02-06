#include "../../include/punto.h"
#include "../../include/avanzar.h"
#include <fstream>
#include <cmath>
#include <iostream>


using namespace std;

int main(int argc, char* argv[]){

	const int TAMANIO = 100;
	Punto cadena[TAMANIO];
	int n;
	double distancia;
	distancia = 0;
	bool fin_entrada;
	
	////////////////////

	if (argc == 1)
	{
		cout << "1º Indique el número de puntos: " << endl;
		cin >> n;
		if (n < 2)
		{
			cout << "Datos insuficientes." << endl;
			return 1;
		}

		cout << "2º Introduzca los puntos en formato ( x , y ): " << endl;

		for(int i = 0 ; i < n ; i++)
		{
			LeerPuntoIs(cin , cadena[i]);
			fin_entrada = cin.eof();
		}
	}
	else
	{
		ifstream f(argv[1]);
		if (!f)
		{
			cerr << "Error: no se abre " << argv[1] << endl;
      		return 1;
		}

		Avanzar(f);
		f >> n;
		if (n < 2)
		{
			cout << "Datos insuficientes." << endl;
			return 1;
		}

		for(int i = 0 ; i < n ; i++)
		{
			LeerPuntoIs(f , cadena[i]);
			fin_entrada = f.eof();
		}

	}

	if (!fin_entrada)
	{
		cerr << "Error inesperado. No se ha leído toda la entrada" << endl;
        return 1;
	}

	////////////////////

	for (int i = 0 , j = 1 ; j < n ; i++ , j++){
		distancia = distancia + Distancia(cadena[i] , cadena[j]);
	}
	

	////////////////////

	cout << "Distancia: " << distancia << endl;
}
