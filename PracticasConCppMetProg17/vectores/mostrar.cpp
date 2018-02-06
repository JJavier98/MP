#include <iostream>
#include <fstream> // ifstream
using namespace std;

// FIXME 5: añadir un nuevo campo
struct VecDin {
   int *datos;
   int n;
};

// FIXME 1: Redimensions v para que se quede con "nuevo" elementos
// FIXME 5: tener en cuenta un nuevo campo en v
void ReSize(VecDin& v,int nuevo)
{
	int * p = new int[nuevo];	

	if (v.n < nuevo) // Agrandar vector
	{
		for(int i = 0 ; i < v.n ; i++)
		{
			p[i] = v.datos[i];
		}
	}
	else if(v.n > nuevo) //Minimizar vector
	{
		for(int i = 0 ; i < nuevo : i++)
		{
			p[i] = v.datos[i];
		}
	}
	else
		cerr << "El vector ya tiene ese tamaño";

	delete[] v.datos;

	v.datos = p;
}

// FIXME 2: Lee objetos int hasta final de flujo y devuelve VecDin con los datos (usa ReSize)
VecDin LeerVecDin(istream& flujo)
{
	int dato;
	bool fin_entrada = flujo.eof();


	VecDin v;
	v.n = 0;

	while (!fin_entrada)
	{
		flujo >> dato;
		Add(v,dato);
	}

	return v;
}

// FIXME 3: Muestra en un flujo de salida los datos enteros de un VecDin (ver main)

void Mostrar(VecDin& v, ostream os)
{
	for (int i = 0 ; i < v.n ; i++)
	{
		os << v.datos[i] << " ";
	}
}

// FIXME 3: Libera la memoria reservada en un VecDin (ver main)

void Liberar(VecDin& v)
{
	delete[] v.datos;
}


// FIXME 4: Añade un dato al final del vector
// FIXME 6: Mejora de eficiencia con reservados
void Add(VecDin& v,int dato)
{
	Resize(v,v.n+1);
	v.datos[v.n] = dato;
}

// FIXME 7: Ordena v con "Selección" implementado recursivo
void SeleccionRecursivo(int *v, int n)
{
}

// FIXME 7: Usa SeleccionRecursivo para ordenar v
void Ordenar(VecDin& v)
{
}


int main(int argc, char *argv[])
{
   VecDin v= {0,0};
   
   if (argc==1)
      v= LeerVecDin(cin);
   else {
      ifstream f(argv[1]);
      if (!f) {
         cerr << "Error: Fichero " << argv[1] << " no válido." << endl;
         return 1;
      }
      v= LeerVecDin(f);
   }

   Mostrar(v,cout);
   Liberar(v); // Libera la memoria reservada
}  
