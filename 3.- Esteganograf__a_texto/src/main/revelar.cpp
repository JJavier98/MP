#include <iostream>
#include <cmath>
#include "codificar.h"
#include "imagenES.h"

using namespace std;


// _____________________________________________________________________________


int main(int argc, char const *argv[])
{
    // _____________

    const int       MAX_IMAGEN = 1000000,
                    MAX_FRASE = MAX_IMAGEN/8;
    unsigned char   buffer[MAX_IMAGEN];
    char            msj_oculto[MAX_FRASE];
    int             filas,
                    columnas;
    TipoImagen      tipo;

    // _____________

    string          msj_error = "Error de formato de imagen.\n",
                    msj_entrada = "Indique el nombre completo de la imagen a descodificar: \n";

// _____________________________________________________________________________


    if(argc == 1)
    {
        // _____________

        char imagen_salida[MAX_FRASE];

        // _____________

        cout << endl << msj_entrada << endl;
        cin.getline(imagen_salida, MAX_FRASE);

        // _____________

        tipo = LeerTipoImagen(imagen_salida, filas, columnas);

        // _____________

        if(tipo == IMG_DESCONOCIDO)
        {
            cout << endl << endl << msj_error << endl;
        }
        else
        {
            if( tipo == IMG_PGM)
            {
                LeerImagenPGM(imagen_salida, filas, columnas, buffer);
            }
            else
            {
                LeerImagenPPM(imagen_salida, filas, columnas, buffer);
            }
        }
    }
    else    // _____________
    {
        tipo = LeerTipoImagen(argv[1], filas, columnas);

        // _____________

        if(tipo == IMG_DESCONOCIDO)
        {
            cout << msj_error;
        }
        else{
            if( tipo == IMG_PGM)
            {
                LeerImagenPGM(argv[1], filas,columnas, buffer);
            }
            else
            {
                LeerImagenPPM(argv[1], filas,columnas, buffer);
            }
        }
    }

    // _____________

    Revelar(buffer, msj_oculto, MAX_FRASE);

    // _____________

    for(int i = 0; (msj_oculto[i] | 0) != '\0'; i++)
    {
        cout << msj_oculto[i];
    }

// _____________________________________________________________________________

    cout << endl;
}
