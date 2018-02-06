SRC = src
INC = include
OBJ = obj
BIN = bin

CXX = g++
CXXFLAGS =  -Wall -Wextra -pedantic -std=c++03 -g  -I$(INC)

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Compilación de módulos ************
$(OBJ)/imagenES.o : $(SRC)/imagenES.cpp $(INC)/imagenES.h
	$(CXX) -c $(CXXFLAGS) $(SRC)/imagenES.cpp -o $(OBJ)/imagenES.o

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
