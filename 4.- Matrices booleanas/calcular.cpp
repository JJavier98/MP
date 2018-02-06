#include <iostream>
#include <fstream>
#include <string.h>
#include "matriz_bit.h"
#include "matriz_operaciones.h"

using namespace std;

int main(int argc, char const *argv[])
{
	//____________

	const bool 	traspuesta	= !strcmp(argv[1],"TRS"),
				infimo		= !strcmp(argv[1],"AND"),
				supremo 	= !strcmp(argv[1],"OR"),
				negacion	= !strcmp(argv[1],"NOT"),
				unitaria 	= (negacion || traspuesta),
				binaria 	= (infimo || supremo);

	bool 		error 		= false;

	MatrizBit 	mtrz,
				mtrz_1,
				res;

	string 	msj_error_sin_parametros = "...Error...\nNo se ha especificado ninguna operación, o el orden de los parámetros no es correcto.",
			msj_uso 				 = "Uso: \"./calcular OPERACION PARAMETRO_1 PARAMETRO_2(si es op. binaria)\" \npudiendo dejar el campo 'parámetros' vacío.";



	//_______________________________________________________________________________

	if (argc == 1) //____________ Programa ____________
	{
		cout << msj_error_sin_parametros << endl;
		cout << msj_uso << endl;
		error = true;
	}
	else if (argc == 2) //____________ Programa + Operación ____________
	{		
		Leer(cin, mtrz);

		if(binaria)
		{
			Leer(cin, mtrz_1);
		}
	}
	else if (argc == 3) //____________ Programa + Operación + Parámetro 1 ____________
	{
		ifstream f(argv[2]);

		Leer(f, mtrz);

		if(binaria)
		{
			Leer(cin, mtrz_1);
		}
	}
	else if (argc == 4) //____________ Programa + Operación + Parámetro 1 + Parámetro 2 ____________
	{
		if(binaria)
		{
			ifstream f1(argv[2]);
			ifstream f2(argv[3]);

			Leer(f1,mtrz);
			Leer(f2,mtrz_1);
		}
	}
	else // ........a parte de la operacion tiene mas de dos parametros........
	{
		cout << msj_error_sin_parametros << endl;
		cout << msj_uso << endl;
		error = true;
	}

	Inicializar(res,Filas(mtrz),Columnas(mtrz));

	if(unitaria)
	{
		if (negacion) //____________ NOT ____________
		{
			Not(res, mtrz);
		}
		else //____________ TRS ____________
		{
			Traspuesta(res, mtrz);
		}
	}
	else if(binaria)
	{
		if (infimo) //____________ AND ____________
		{
			And(res, mtrz_1, mtrz);
		}
		else //____________ OR ____________
		{
			Or(res, mtrz_1, mtrz);
		}
	}
	else // ........operación no valida.........
	{
		cout << msj_error_sin_parametros << endl;
		cout << msj_uso << endl;
		error = true;
	}

	if(error)
	{
		return 1;
	}
	else
	{
		Escribir(cout, res);
	}
}
