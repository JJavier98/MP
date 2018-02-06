#ifndef _TABLERO_H_
#define _TABLERO_H_

#include "../Matriz/class_Matriz.h"
#include <iostream>

class Tablero{
	private:
		Matriz tablero;
		bool jugador;
		bool terminada;

		// LA FICHA COMPROVADA ES CONTRARIA A LA DEL JUGADOR ACTIVO
		int Opuesta()const;
	public:
		//CONSTRUCTORES
		Tablero();
		Tablero(int nfc);
		Tablero(int f, int c);

		//IMPRIME EL TABLERO CON EL ESTADO ACTUAL DE LA PARTIDA
		void PrettyPrint(std::ostream& os);

		//CONSULTA Nº FILAS
		int Filas()const;

		// CAMBIA EL TURNO DEL JUGADOR
		void CambiaTurno();

		//CONSULTA Nº COLUMNAS
		int Columnas()const;

		//CONSULTA QUÉ HAY EN LA POSICIÓN (f,c)
		// 1 negra ; 2 blanca
		int Get(int f, int c)const;

		//CONSULTA DE QUIÉN ES EL TURNO
		// false = turno jugador 1 ; true = turno jugador 2
		int Turno()const;

		// MUESTRA SI LA PARTIDA ESTÁ ACABADA O NO
		bool Final()const;

		//FINALIZA LA PARTIDA
		void Finalizar();

		// INDICA QUIÉN ES EL GANADOR O SI HA SIDO EMPATE
		int Ganador()const;

		// DEVUELVE LA PUNTUACIÓN DEL GANADOR
		// fichas ganador - fichas perdedor
		int Puntuacion()const;

		// CONSULTA SI LA POSICIÓN INDICADA ES VÁLIDA PARA EL JUGADOR CORRESPONDIENTE
		bool PosicionValida(int f, int c)const;

		// COMPRUEBA SI UN JUGADOR HA DE PASAR TURNO
		bool PasaPalabra();

		// PONE UNA FICHA EN EL LUGAR SELECCIONADO
		void Set(int f, int c);

		// RESTABLECE EL TABLERO
		void Iniciar();

		//OPERADOR '='
		Tablero& operator=(const Tablero& tab);

		// OPERADOR '<<'
		friend std::ostream& operator<<(std::ostream& os, const Tablero& tab);

		// OPERADOR '>>'
		friend std::istream& operator>>(std::istream& is, Tablero& tab);
};

#endif
