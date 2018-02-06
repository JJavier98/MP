#include "codificar.h"
#include <iostream>
#include "imagenES.h"
//#include <cmath>                                      **-----------------Método Alternativo-----------------**

using namespace std;


// _____________________________________________________________________________


void Ocultar(unsigned char buffer[], const char ocultar[])
{
    // _____________

    int j = 0,
        c = 0;

    // _____________

    while(ocultar[c] != '\0')
    {
        for(int i = 7 ; i >= 0 ; i--, j++)
        {
            if( (ocultar[c] & (1<<i)) != '\0')
            {
                buffer[j] = buffer[j] | 1;
            }
            else
            {
                buffer[j] = buffer[j] & (~1);
            }
        }
        c++;
    }

    // _____________

    cout << endl << "......Ocultado......" << endl;
}


// _____________________________________________________________________________


void Revelar(unsigned char buffer[],char revelar[], const int MAX)   //decodifica el mensaje oculto en el buffer
{
    // _____________

    int j = 0,
        i = 0;

    // _____________


    do{
        //int suma = 0;                                 **-----------------Método Alternativo-----------------**

        revelar[j] = 0;

        for(int k = 7; k >= 0; i++,k--)
        {
            if( (buffer[i] & 1) != '\0')
            {
                //suma = suma + pow(2,k) ;               **-----------------Método Alternativo-----------------**
                revelar[j] = revelar[j] | (1<<k);
            }
        }

        //revelar[j] = suma;                           **-----------------Método Alternativo-----------------**
        j++;
    }while(revelar[j-1] != '\0' && j < MAX);

    // _____________
    
    cout << endl << "......Revelado......"  << endl;
}
