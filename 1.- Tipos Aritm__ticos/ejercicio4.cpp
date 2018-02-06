#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    char son_iguales;
    double x;
    cout << "Dime un número y comprobaré si se cumple "
            "que la raíz cuadrada al cuadrado da el número: ";
    cin >> x;
    son_iguales = fabs(sqrt(x)*sqrt(x) - x < 1e-6) ? 'S' : 'N';
    cout << "Son iguales: " << son_iguales << endl;
}
