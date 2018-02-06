/**
  * @file central.cpp
  * @brief Calcula círculo con centro en medio de dos círculos y radio la mitad de la distancia
  * @author Agarrido
  * @warning Módulo no definitivo (creado para ser modificado)
  *
  * Un ejemplo de ejecución es:
  *   Introduzca un circulo en formato radio-(x,y): 3-(0,0)
  *   Introduzca otro circulo: 4-(5,0)
  *   El círculo que pasa por los dos centros es: 2.5-(2.5,0)
  */

#include "../../include/punto.h"
#include "../../include/circulo.h"
#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char* argv[])
{
    Circulo c1,c2;
    bool fin_entrada;

    if (argc == 1)
    {
        do {
            cout << "Introduzca un circulo en formato radio-(x,y): ";


            if ( LeerCirculoIs(cin, c1) )
            {
                fin_entrada = cin.eof();
            }


            cout << "Introduzca otro circulo: ";


            LeerCirculoIs(cin, c2);
            fin_entrada = cin.eof();

        } while (Distancia(Centro(c1),Centro(c2))==0);
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
        LeerCirculoIs(f, c2);
        fin_entrada = f.eof();
    }

    if (!fin_entrada)
    {
        cerr << "Error inesperado. No se ha leído toda la entrada" << endl;
        return 1;
    }

    Circulo res;

    InicializarCirculo(res,PuntoMedio(Centro(c1),Centro(c2)),
                     Distancia(Centro(c1),Centro(c2))/2);
    cout << "El círculo que pasa por los dos centros es: ";
    EscribirCirculoOs(cout, res);
    cout << endl;
}

/* Fin: circulomedio.cpp */
