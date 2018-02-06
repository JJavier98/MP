#include <iostream>
#include <cstdlib> // rand, atoi
#include <ctime> // time
// FIXME 1: Crear módulo util_celdas y añadir la cabecera aquí

using namespace std;

// Genera un valor del intervalo [minimo,maximo]
int Uniforme(int minimo, int maximo)
{
   double u01= std::rand() / (RAND_MAX+1.0); // Uniforme01
   return minimo + (maximo-minimo+1) * u01;
}



// FIXME 2: Crear funciones BuscarMaximo y OrdenarSeleccion
// FIXME 3: Función Mezcla que mezcla dos listas ordenadas en una nueva, dejando las dos originales vacías
// FIXME 4: Función MergeSort para ordenar una lista


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
      
      Celda* lista1= 0;
      Celda* lista2= 0; // Listas vacías

      for (int i=0; i<n; ++i) {
         // Añadimos un elemento al principio de lista1 y otro a lista2
         Add(lista1, Uniforme(1,max));
         Add(lista2, Uniforme(1,max));
      }
      
      cout << "Lista1: ";
      Listar(lista1);
      cout << "Lista2: ";
      Listar(lista2);
      
      
      // FIXME 2: Llamar a ordenar las dos listas y listarlas ordenadas
      // FIXME 4: Ordenar la primera lista con MergeSort

      // FIXME 3: Llamar a mezclar las dos listas y guardar el resultado en la lista1
      
      
      
      
      
      Liberar(lista1);
      Liberar(lista2);
   }  
}
