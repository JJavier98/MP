bin/reversi : obj/reversi.o obj/class_Tablero.o obj/class_Matriz.o obj/class_Jugador.o
	g++ -Wall -Wextra -pedantic -o bin/reversi obj/reversi.o obj/class_Tablero.o obj/class_Matriz.o obj/class_Jugador.o

obj/reversi.o : reversi.cpp Tablero/class_Tablero.h Jugador/class_Jugador.h
	g++ -Wall -Wextra -pedantic -c reversi.cpp -o obj/reversi.o

obj/class_Tablero.o : Tablero/class_Tablero.cpp Tablero/class_Tablero.h Matriz/class_Matriz.h
	g++ -Wall -Wextra -pedantic -c Tablero/class_Tablero.cpp -o obj/class_Tablero.o

obj/class_Jugador.o : Jugador/class_Jugador.cpp Tablero/class_Tablero.h Matriz/class_Matriz.h Jugador/class_Jugador.h
	g++ -Wall -Wextra -pedantic -c Jugador/class_Jugador.cpp -o obj/class_Jugador.o

obj/class_Matriz.o : Matriz/class_Matriz.cpp Matriz/class_Matriz.h
	g++ -Wall -Wextra -pedantic -c Matriz/class_Matriz.cpp -o obj/class_Matriz.o

clean:
	rm obj/* bin/*