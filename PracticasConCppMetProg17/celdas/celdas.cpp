#include <iostream>
#include <cstdlib> // rand, atoi
#include <ctime> // time
using namespace std;

struct Celda {
  int dato;
  Celda* sig;
};

// Genera un valor del intervalo [minimo,maximo]
int Uniforme(int minimo, int maximo)
{
  double u01= std::rand()/(RAND_MAX+1.0); // Uniforme01
  return minimo+(maximo-minimo+1)*u01;
}


// FIXME 1: Añadir un elemento a una lista. Se añade como primer elemento

// FIXME 2: Liberar todas las celdas de una lista y dejarla a cero

// FIXME 3: Listar los elementos de una lista entre llaves y separados por comas

// FIXME 4: Crear función Size para calcular el número de elemento de la lista

// FIXME 5: Crear una función Buscar que devuelva la celda donde está un dato. Puntero nulo si no está.

// FIXME 6: Crear una función BuscarPuntero que devuelve un puntero a puntero.

// FIXME 7: Recibe un puntero a celda, la desengancha, y la devuelve como resultado

// FIXME 8: Implementar Begin, Next, End

// FIXME 9: Añada una función Imprimir que recibe un rango e imprime todos los elementos del rango

int main(int argc, char* argv[])
{
  if (argc!=3) {
    cerr << "Uso: " << argv[0] << " <número de datos> <máximo dato>" <<endl;
    return 1;
  }
  
  srand(time(0)); // Inicializamos generador de números
  
  int n= atoi(argv[1]);
  if (n<5) {
    cerr << "Debería especificar al menos 5 elementos" << endl;
    return 2;
  }
  else {
    int max= atoi(argv[2]);
    if (max<5) {
      cerr << "Debería especificar un max de al menos 5" << endl;
      return 3;
    }
    
    Celda* lista= 0; // Lista vacía

    for (int i=0; i<n; ++i) 
      Add(lista, Uniforme(1,max)); // Añadimos un elemento al principio de la lista
      
      
    // FIXME 3: Llamar a listar los elementos
      
    // FIXME 4: Indicar el tamaño de la lista
      
    // FIXME 5: Pregunte un dato a buscar e indique si está en la lista

    // FIXME 6: Buscar el mismo dato con un puntero a puntero en cada lista

    // FIXME 7: Mientras que exista el dato, lo desengancha, lo destruye y busca el siguiente

    // FIXME 9: Listado repetido pero con Imprimir

    
    

    
    // FIXME 2: Llamar a liberar los elementos de la lista

  }  
}
