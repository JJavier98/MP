#include <iostream>
#include "codificar.h"
#include "imagenES.h"

using namespace std;


// _____________________________________________________________________________


int main(int argc, char const *argv[])
{
    // _____________

    TipoImagen      tipo;
    const int       MAX_IMAGEN = 1000000,
                    MAX_FRASE = MAX_IMAGEN/8;
    unsigned char   buffer[MAX_IMAGEN];
    char            msj_oculto[MAX_FRASE],
                    nombre_salida[MAX_FRASE];
    int             filas,
                    columnas;

    // _____________

    string          msj_entrada = "Introduzca el nombre de la imagen de entrada \"directorio/nombre.formato\":",
                    msj_mensaje = "Introduzca el texto a ocultar:",
                    msj_salida = "Introduzca el nombre de la imagen de salida \"directorio/nombre\":",
                    msj_error = "Error de formato de imagen.";

// _____________________________________________________________________________


    if(argc == 1)
    {
        // _____________

        char nombre_entrada[MAX_FRASE];

        // _____________

        cout << endl << msj_entrada << endl;
        cin.getline(nombre_entrada,MAX_FRASE);

        cout << endl << msj_mensaje << endl;
        cin.getline(msj_oculto,MAX_FRASE);

        cout << endl << msj_salida << endl;
        cin.getline(nombre_salida,MAX_FRASE);

        // _____________

        tipo = LeerTipoImagen(nombre_entrada,filas, columnas);

        // _____________

        if(tipo == IMG_DESCONOCIDO)
        {
            cout << msj_error;
            return 1;
        }
        else
        {
            if(tipo == IMG_PPM)
            {
                LeerImagenPPM(nombre_entrada, filas, columnas, buffer);
                Ocultar(buffer, msj_oculto);
                EscribirImagenPPM(nombre_salida, buffer, filas, columnas);
            }
            else
            {
              LeerImagenPGM(nombre_entrada, filas, columnas, buffer);
              Ocultar(buffer, msj_oculto);
              EscribirImagenPGM(nombre_salida, buffer, filas, columnas);
            }
        }
    }
    else    // _____________
    {

        cout << endl << msj_mensaje << endl;
        cin.getline(msj_oculto, MAX_FRASE);

        cout << endl << msj_salida << endl;
        cin.getline(nombre_salida, MAX_FRASE);

        // _____________

        tipo =LeerTipoImagen(argv[1], filas, columnas);

        // _____________

        if(tipo == IMG_DESCONOCIDO)
        {
            cout << msj_error;
            return 1;
        }
        else
        {
            if(tipo == IMG_PPM)
            {
                LeerImagenPPM(argv[1],filas,columnas,buffer);
                Ocultar(buffer,msj_oculto);
                EscribirImagenPPM(nombre_salida,buffer,filas,columnas);
            }
            else
            {
              LeerImagenPGM(argv[1],filas,columnas,buffer);
              Ocultar(buffer,msj_oculto);
              EscribirImagenPGM(nombre_salida,buffer,filas,columnas);
            }
        }
    }

// _____________________________________________________________________________


    cout << endl;
}
