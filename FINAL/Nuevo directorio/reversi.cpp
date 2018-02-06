#include "Tablero/class_Tablero.h"
#include "Jugador/class_Jugador.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include <cstdlib>

using namespace std;

//bool Save()

int main(int argc, char const *argv[])
{
	Tablero tablero;
	char selec;
	char elec;
	char form;
	int f,c;
	int tam;
	const char* separador = "--------------------------------------------------------------";

	if(argc == 1)
	{
// STANDAR________________________________________________________________

		cout << "¿Quiere jugar en un tablero estandar 8x8? <s/n>: ";
		cin >> selec;

		while (selec != 's' && selec != 'n')
		{
			cout << "Selección no válida. Introduzca de nuevo: ";
			cin >> selec;
		}

// CUSTOM________________________________________________________________

		if(selec == 's')
		{
			tablero = Tablero();
		}
		else
		{
			cout << "¿Desea un tablero rectangular(r) o cuadrado(c)?: ";
			cin >> form;

			while (form != 'r' && form != 'c')
			{
				cout << "Selección no válida. Introduzca de nuevo: ";
				cin >> form;
			}

			if (form == 'r')
			{
				cout << "Seleccione el tamaño del tablero <filas columnas>: ";
				cin >> f;
				cin >> c;

				tablero = Tablero(f,c);
			}
			else
			{
				cout << "Indique el tamaño: ";
				cin >> tam;

				tablero = Tablero(tam);
			}
		}

// PLAYERS________________________________________________________________

		cout << endl << "Introduzca el nombre del Jugador 1 (NEGRAS): " << endl;
		Jugador j1(cin);
		cout << endl << "Introduzca el nombre del Jugador 2 (BLANCAS): " << endl;
		Jugador j2(cin);

// GAME________________________________________________________________

		elec = 's';
		while(elec == 's')
		{
			while(!tablero.Final())
			{
				if(tablero.Turno()==1 && !tablero.PasaPalabra())
				{
					do{
						cout << endl << endl <<	separador << endl << "Turno de las NEGRAS: ";

						for(int i = 0 ; i < j1.Longitud() ; ++i)
						{
							cout << j1.Nombre()[i];
						}

						cout << endl << endl;
					}while(!j1.EscogePosicion(cin, tablero));
				}
				else if(tablero.Turno()==2 && !tablero.PasaPalabra())
				{
					do{
						cout << endl << endl <<	separador << endl << "Turno de las BLANCAS: ";

						for(int i = 0 ; i < j2.Longitud() ; ++i)
						{
							cout << j2.Nombre()[i];
						}

						cout << endl << endl;
					}while(!j2.EscogePosicion(cin, tablero));
				}
			}
// RESULTS________________________________________________________________

			int winner = tablero.Ganador();

			cout << endl << endl << endl <<	separador << endl << separador << endl << "El tablero al final de la partida ha quedado así: " << endl << endl;

			tablero.PrettyPrint(cout);


			if(winner == 1)
			{
				cout << "Han ganado las NEGRAS con " << tablero.Puntuacion() << " puntos" << endl;
				j1.SumaPuntos(tablero);
			}
			else if (winner == 2)
			{
				cout << "Han ganado las BLANCAS con " << tablero.Puntuacion() << " puntos" << endl;
				j2.SumaPuntos(tablero);
			}
			else
				cout << "Ha habido un empate" << endl;


			cout << separador << endl << separador << endl << endl << endl << endl;

// SAVE________________________________________________________________

			char save;
			char game_name[50];


			cout << "¿Quieres guardar la partida? <s/n>: ";
			cin >> save;

			while(save !='s' && save !='n')
			{
				cout << "Error en la entrada...\n¿Quieres guardar la partida? <s/n>: ";
				cin >> save;
			}

			if (save == 's')
			{
				cout << "Introduzca el nombre de la partida guardada: ";
				cin >> ws;
				cin.getline(game_name,50,'\n');
			}

// END________________________________________________________________

			cout << "¿Quieres volver a jugar? <s/n>: ";
			cin >> elec;

			while (elec != 's' && elec != 'n')
			{
				cout << "Selección no válida. Introduzca de nuevo: ";
				cin >> elec;
			}

			if (elec == 's')
			{
				tablero.Iniciar();
				system("clear");
			}
			else
			{
				system("clear");
				cout << "--ESTADO FINAL DE LA PARTIDA--" << endl << endl;
				cout << "Tablero: " << tablero.Filas() << "x" << tablero.Columnas() << endl;
				cout << "Puntuación Jugador 1 <NEGRAS>: " << j1.ShowMarks() << endl;
				cout << "Puntuación Jugador 2 <BLANCAS>: " << j2.ShowMarks() << endl;
				cout << "Partida terminada" << endl << endl;
			}
		}
		
	}
	else if (argc==2)//////////////////////////////////////////--2 argumentos--/////////////////////////////////////////////////////////
	{
		ifstream file(argv[1]);
		
		file >> selec;
		if(selec == 's')
		{
			tablero = Tablero();
		}
		else if(selec == 'n')
		{
			file >> form;
			if(form == 'r')
			{
				file >> f >> c;
				tablero = Tablero(f,c);
			}
			else if(form == 'c')
			{
				file >> tam;
				tablero = Tablero(tam);
			}
		}

// PLAYERS________________________________________________________________

		Jugador j1(file);
		Jugador j2(file);

// GAME________________________________________________________________

		elec = 's';
		while(elec == 's')
		{
			while(!tablero.Final())
			{
				if(tablero.Turno()==1 && !tablero.PasaPalabra())
				{
					do{
						cout << endl << endl <<	separador << endl << "Turno de las NEGRAS: ";

						for(int i = 0 ; i < j1.Longitud() ; ++i)
						{
							cout << j1.Nombre()[i];
						}

						cout << endl << endl;
					}while(!j1.EscogePosicion(file,tablero));
				}
				else if(tablero.Turno()==2 && !tablero.PasaPalabra())
				{
					do{
						cout << endl << endl <<	separador << endl << "Turno de las BLANCAS: ";

						for(int i = 0 ; i < j2.Longitud() ; ++i)
						{
							cout << j2.Nombre()[i];
						}

						cout << endl << endl;
					}while(!j2.EscogePosicion(file,tablero));
				}
			}

// RESULTS________________________________________________________________

			int winner = tablero.Ganador();

			cout << endl << endl << endl <<	separador << endl << separador << endl << "El tablero al final de la partida ha quedado así: " << endl << endl;

			tablero.PrettyPrint(cout);


			if(winner == 1)
			{
				cout << "Han ganado las NEGRAS con " << tablero.Puntuacion() << " puntos" << endl;
				j1.SumaPuntos(tablero);
			}
			else if (winner == 2)
			{
				cout << "Han ganado las BLANCAS con " << tablero.Puntuacion() << " puntos" << endl;
				j2.SumaPuntos(tablero);
			}
			else
				cout << "Ha habido un empate" << endl;


			cout << separador << endl << separador << endl << endl << endl << endl;

// SAVE________________________________________________________________

			char save;
			char game_name[50];


			file >> save;

			while(save !='s' && save !='n')
			{
				file >> save;
			}

			if (save == 's')
			{
				file >> ws;
				file.getline(game_name,50,'\n');
			}

// END________________________________________________________________

			file >> elec;

			while (elec != 's' && elec != 'n')
			{
				file >> elec;
			}

			if (elec == 's')
			{
				tablero.Iniciar();
				system("clear");
			}
			else
			{
				//system("clear");
				cout << endl << "--ESTADO FINAL DE LA PARTIDA--" << endl << endl;
				cout << "Tablero: " << tablero.Filas() << "x" << tablero.Columnas() << endl;
				cout << "Puntuación Jugador 1 <NEGRAS>: " << j1.ShowMarks() << endl;
				cout << "Puntuación Jugador 2 <BLANCAS>: " << j2.ShowMarks() << endl;
				cout << "Partida terminada" << endl << endl;
			}
		}
	}

	return 0;
}
