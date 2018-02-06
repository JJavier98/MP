AR = ar
CC = g++
CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic
LDFLAGS= -L.
LDLIBS= -lformas

SOURCESMAIN = central.cpp area.cpp delimitar.cpp longitud.cpp
SOURCESLIB = punto.cpp circulo.cpp rectangulo.cpp avanzar.cpp
OBJECTS = $(SOURCESMAIN:.cpp=.o) $(SOURCESLIB:.cpp=.o)
EXECUTABLE = $(SOURCESMAIN:.cpp=)

RM = rm

##############################################################################
##############################################################################

all_n_clean : bin/central bin/area bin/longitud bin/delimitar clean_obj clean_lib

all : bin/central bin/area bin/longitud bin/delimitar


##############################################################################
##############################################################################


bin/central : obj/mains/central.o lib/libformas.a
	$(CXX) -o bin/central obj/mains/central.o lib/libformas.a

obj/mains/central.o : include/punto.h include/circulo.h src/mains/central.cpp
	$(CXX) -c $(CXXFLAGS) -o obj/mains/central.o src/mains/central.cpp


##############################################################################
##############################################################################


bin/area : obj/mains/area.o lib/libformas.a
	$(CXX) -o bin/area obj/mains/area.o lib/libformas.a

obj/mains/area.o : include/punto.h include/circulo.h src/mains/area.cpp
	$(CXX) -c $(CXXFLAGS) -o obj/mains/area.o src/mains/area.cpp


##############################################################################
##############################################################################


bin/delimitar : obj/mains/delimitar.o lib/libformas.a
	$(CXX) -o bin/delimitar obj/mains/delimitar.o lib/libformas.a

obj/mains/delimitar.o : include/punto.h include/avanzar.h src/mains/delimitar.cpp
	$(CXX) -c $(CXXFLAGS) -o obj/mains/delimitar.o src/mains/delimitar.cpp


##############################################################################
##############################################################################


bin/longitud : obj/mains/longitud.o lib/libformas.a
	$(CXX) -o bin/longitud obj/mains/longitud.o lib/libformas.a

obj/mains/longitud.o : include/punto.h include/avanzar.h src/mains/longitud.cpp
	$(CXX) -c $(CXXFLAGS) -o obj/mains/longitud.o src/mains/longitud.cpp


##############################################################################
##############################################################################


lib/libformas.a : obj/libs/circulo.o obj/libs/punto.o obj/libs/rectangulo.o obj/libs/avanzar.o
	ar -rvs lib/libformas.a obj/libs/punto.o obj/libs/circulo.o obj/libs/rectangulo.o obj/libs/avanzar.o

obj/libs/punto.o : include/punto.h include/avanzar.h src/libs/punto.cpp
	$(CXX) -c $(CXXFLAGS) -o obj/libs/punto.o src/libs/punto.cpp

obj/libs/circulo.o : include/punto.h include/circulo.h include/avanzar.h src/libs/circulo.cpp
	$(CXX) -c $(CXXFLAGS) -o obj/libs/circulo.o src/libs/circulo.cpp

obj/libs/rectangulo.o : include/punto.h include/rectangulo.h include/avanzar.h src/libs/rectangulo.cpp
	$(CXX) -c $(CXXFLAGS) -o obj/libs/rectangulo.o src/libs/rectangulo.cpp

obj/libs/avanzar.o : include/avanzar.h src/libs/avanzar.cpp
	$(CXX) -c $(CXXFLAGS) -o obj/libs/avanzar.o src/libs/avanzar.cpp


##############################################################################
##############################################################################


clean_obj :
	echo "Limpiando objetos.....      "
	$(RM) obj/libs/*.o obj/mains/*.o

clean_lib :
	echo "Limpiando librerías.....      "
	$(RM) lib/*.a

clean_bin :
	echo "Limpiando ejecutables.....      "
	$(RM) bin/*

clean_all :
	echo "Limpiando objetos, ejecutables y librerías.....      "
	$(RM) obj/libs/*.o obj/mains/*.o bin/* lib/*.a
