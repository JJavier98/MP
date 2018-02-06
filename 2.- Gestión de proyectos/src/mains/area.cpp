#include "../../include/punto.h"
#include "../../include/circulo.h"
#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char* argv[]){

	Circulo c1;
	bool fin_entrada;

	if (argc == 1)
	{
		cout << "Introduzca un circulo en formato radio-(x,y): ";
		LeerCirculoIs(cin, c1);
		fin_entrada = cin.eof();
	}
	else
	{
		ifstream f(argv[1]);

		if (!f)
		{
	     	cerr << "Error: no se abre " << argv[1] << endl;
	      	return 1;
    	}

    	LeerCirculoIs(f, c1);
		fin_entrada = f.eof();
	}

	if (!fin_entrada)
	{
     	cerr << "Error inesperado. No se ha leído toda la entrada" << endl;
     	return 1;
  	}

  	cout << "Area: " << Area(c1) << endl;
}