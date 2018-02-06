SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib
MAIN = main
RVS = rvs


CXX = g++
CXXFLAGS =  -Wall -Wextra -pedantic -std=c++03 -g  -I$(INC)
AR = ar

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Compilación de módulos ************
all : $(BIN)/ocultar $(BIN)/revelar

$(OBJ)/imagenES.o : $(SRC)/$(LIB)/imagenES.cpp $(INC)/imagenES.h
	$(CXX) -c $(CXXFLAGS) $(SRC)/$(LIB)/imagenES.cpp -o $(OBJ)/imagenES.o

$(OBJ)/codificar.o : $(SRC)/$(LIB)/codificar.cpp $(INC)/codificar.h $(INC)/imagenES.h
	$(CXX) -c $(CXXFLAGS) $(SRC)/$(LIB)/codificar.cpp -o $(OBJ)/codificar.o

$(OBJ)/ocultar.o : $(SRC)/$(MAIN)/ocultar.cpp $(INC)/imagenES.h $(INC)/codificar.h
	$(CXX) -c $(CXXFLAGS) $(SRC)/$(MAIN)/ocultar.cpp -o $(OBJ)/ocultar.o

$(OBJ)/revelar.o : $(SRC)/$(MAIN)/revelar.cpp $(INC)/imagenES.h $(INC)/codificar.h
	$(CXX) -c $(CXXFLAGS) $(SRC)/$(MAIN)/revelar.cpp -o $(OBJ)/revelar.o

$(BIN)/ocultar : $(OBJ)/ocultar.o $(LIB)/libdescifra.a
	$(CXX) -o $(BIN)/ocultar $(OBJ)/ocultar.o $(LIB)/libdescifra.a

$(BIN)/revelar : $(OBJ)/revelar.o $(LIB)/libdescifra.a
	$(CXX) -o $(BIN)/revelar $(OBJ)/revelar.o $(LIB)/libdescifra.a

# ************ Creación de la librería ************
$(LIB)/libdescifra.a : $(OBJ)/codificar.o $(OBJ)/imagenES.o
	$(AR) $(RVS) $(LIB)/libdescifra.a $(OBJ)/imagenES.o $(OBJ)/codificar.o

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(LIB)/* #$(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
