#ifndef _JUGADOR_H_
#define _JUGADOR_H_
#include "../Matriz/class_Matriz.h"
#include "../Tablero/class_Tablero.h"

class Jugador
{
	private:
		char* nombre;
		int n, reservado;
		int puntuacion;

		// PIDE POR TECLADO UNA POSICIÓN DONDE COLOCAR LA FICHA
		void DialogoEscoger(Tablero & tab);

		// PIDE EL NOMBRE DEL JUGADOR
		void PideNombre();

		// AÑADEM VALORES AL FINAL DE UN VECTOR
		void push_back(char c);
	public:
		//CONSTRUCTORES - DESTRUCTOR 
		Jugador();
		Jugador(const Jugador & j);
		~Jugador();

		// ---OPERADORES---
		// '='
		Jugador & operator=(const Jugador & j);

		// AÑADE LOS PUNTOS DE LA PARTIDA A LA PUNTUACIÓN TOTAL 
		void SumaPuntos(Tablero & tablero);

		// SE ESCOGE UNA POSICIÓN DONDE COLOCAR LA FICHA
		bool EscogePosicion(Tablero & tab);

		// CAMBIA DE TURNO Y COMPRUEBA SI LA PARTIDA PUEDE CONTINUAR
		void PasaTurno(Tablero& tab);

		// DEVUELVE UN PUNTERO AL PRINCIPIO DEL NOMBRE DEL JUGADOR
		char * Nombre();

		// INDICA LA LONGITUD DE LA CADENA "nombre"
		int Longitud()const;

		// MUESTRA LA PUNTUACION TOTAL DEL JUGADOR
		int ShowMarks();

};

#endif
