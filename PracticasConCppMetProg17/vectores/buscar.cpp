#include <iostream>
#include <cstdlib> // rand, atoi
#include <ctime> // time

using namespace std;

// Genera un valor del intervalo [minimo,maximo]
int Uniforme(int minimo, int maximo)
{
   double u01= std::rand()/(RAND_MAX+1.0); // Uniforme01
   return minimo+(maximo-minimo+1)*u01;
}

// FIXME 1: Rellena el vector con n enteros del 1 a max y los mezcla (ver main)
Generar



// FIXME 4: Cambio de interfaz, devolviendo n si no está.
int Buscar(const int *v, int n, int dato)
{
   for (int i=0;i<n;++i)
      if (v[i]==dato)
         return i;
   return -1;
}

// FIXME 5: Implementar búsqueda garantizada. Pre: el dato está
// FIXME 7: Cambiar la interfaz de la función
int BuscarGarantizada(const int *v, int dato)
{
}


// FIXME 8: Incluir algoritmo OrdenarInsercion

// FIXME 9: Incluir búsqueda binaria recursiva

// FIXME 10: Modificar función para implementar interpolación
int BusquedaBinaria (const int *vec, int n, int dato)
{
   int izq= 0, der= n-1;
   
   while (izq<=der) {
   int centro= (izq+der) / 2;
   if (vec[centro] > dato)
      der= centro-1;
   else if (vec[centro] < dato)
            izq= centro+1;
         else return centro;
   }
   return -1; 
}


int main(int argc, char *argv[])
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
      
      // FIXME 1: prepara el vector v
      
      // FIXME 6: reservar una posición más para garantizar la búsqueda
      
      Generar(v,n,max);
      cout << "Generados: ";
      for (int i=0;i<n;++i)
         cout << v[i] << " "; 
      cout << endl;
      
      // FIXME 8: Ordenar el vector con OrdenarInsercion y listarlos

      
      // FIXME 2: Pregunta por dato a buscar y lo localiza
      
      // FIXME 3: Modificación para localizar todas las ocurrencias
      
      // FIXME 6: Colocar el dato en la posición detrás de la última
      
      // FIXME 7: Cambiar a la nueva interfaz de la búsqueda

      
      // FIXME 9: Preguntar por búsqueda binaria y resolver la posición
      
      // FIXME 1: deja de usarse v
      
   }
}
  
  