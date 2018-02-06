#ifndef _JUGADOR_H_
#define _JUGADOR_H_
#include "../Matriz/class_Matriz.h"
#include "../Tablero/class_Tablero.h"
#include <iostream>

class Jugador
{
	private:
		char* nombre;
		int n;
		int puntuacion;

		// PIDE POR TECLADO UNA POSICIÓN DONDE COLOCAR LA FICHA
		void DialogoEscoger(std::istream & is, Tablero & tab);

		// PIDE EL NOMBRE DEL JUGADOR
		void PideNombre(std::istream & is);

		// AÑADEM VALORES AL FINAL DE UN VECTOR
		void arreglar();
	public:
		//CONSTRUCTORES - DESTRUCTOR 
		Jugador(std::istream & is);
		Jugador(const Jugador & j);
		~Jugador();

		// ---OPERADORES---
		// '='
		Jugador & operator=(const Jugador & j);

		// '<<'
		friend std::ostream& operator<<(std::ostream &os, const Jugador &j);

		// '>>'
		friend std::istream& operator>>(std::istream& is, Jugador& j);

		// AÑADE LOS PUNTOS DE LA PARTIDA A LA PUNTUACIÓN TOTAL 
		void SumaPuntos(Tablero & tablero);

		// SE ESCOGE UNA POSICIÓN DONDE COLOCAR LA FICHA
		bool EscogePosicion(std::istream & is, Tablero & tab);

		// CAMBIA DE TURNO Y COMPRUEBA SI LA PARTIDA PUEDE CONTINUAR
		void PasaTurno(Tablero& tab);

		// DEVUELVE UN PUNTERO AL PRINCIPIO DEL NOMBRE DEL JUGADOR
		char * Nombre()const;

		// INDICA LA LONGITUD DE LA CADENA "nombre"
		int Longitud()const;

		// MUESTRA LA PUNTUACION TOTAL DEL JUGADOR
		int ShowMarks()const;

};

#endif
