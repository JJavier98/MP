#include <iostream>
#include "ventana.h"

int main()
{
    Ventana* w= &Ventana::win;

    if (!w->init("../../otelo/otelo/resources", 5, 6)) { // Directorio con recursos, filas, columnas
        std::cerr << "No se ha podido inicializar la ventana del juego... " << std::endl;
        return 1;
    }

    // Lo de w es por escribir menos, se podría llamar también:
    Ventana::win.setEstado("Pulse para comenzar", true); // true para que espere a pulsación

    // También se podría usar una referencia
    Ventana& win= Ventana::win; // Observe que hay dos identificados win del mismo objeto
    win.setEstado("Preparado para recibir entradas... La primera casilla simula que \"pasa\", la segunda que finaliza" );

    char tablero[]= // Observe que una cadena-C se puede poner "a trozos"
            "00?000"
            "0?1200"
            "0021?0"
            "000?00"
            "000000";

    w->setTablero(1, tablero); // Turno y cadena con contenido

    Ventana::Input entrada= w->input();
    while (entrada.tipo!=Ventana::Cerrar) {
        if (entrada.tipo== Ventana::Ayuda) {
            w->setError("Pides ayuda... ponemos el mensaje con setError");
        }if (entrada.tipo== Ventana::Interrumpir) {
            w->setEstado("Pides interrumpir...");
        }
        else if (entrada.tipo== Ventana::Casilla) {
            if (entrada.fila==0){
                if (entrada.columna==0)
                    w->paso(1); // Sonido de que "pasa" y juega el 1
                else if (entrada.columna==1)
                    w->final(1); // Animación final, suponemos que gana 1
            }
            else {
                char cadena[] = "Casilla XX";
                cadena[8]= 'a' + entrada.columna;
                cadena[9]= '0' + entrada.fila ;
                w->setEstado(cadena);
            }
        }

        int i= 0;
        while (tablero[i]!='\0') {
            if (tablero[i]=='1')
                tablero[i]= '2';
            else if (tablero[i]=='2') tablero[i]= '1';
            ++i;
        }
        w->setTablero(1, tablero); // Turno y cadena con contenido

        entrada= w->input();
    }

}
