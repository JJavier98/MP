#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

int main()
{
    double n1 = numeric_limits<double>::quiet_NaN();
    double n2 = numeric_limits<double>::infinity();
    double n3 = -numeric_limits<double>::infinity();
    double n4 = 2.7;

    cout << "n1 vale " << n1 << endl;
    cout << "n2 vale " << n2 << endl;
    cout << "n3 vale " << n3 << endl;
    cout << "n4 vale " << n4 << endl;
    cout << "Raíz de -1 vale " << sqrt(-1.0) << endl;    // NaN
    cout << "0.0/0.0 vale " << 0.0/0.0 << endl;          // NaN
    cout << "1e1000 vale " << 1e1000 << endl;            // Inf
    cout << "-1e1000 vale " << -1e1000 << endl;          // -Inf

    cout << "Representación según el estándar IEEE-754 / IEC-559 : " <<
            (numeric_limits<double>::is_iec559 ? "Si" : "No") << endl;

    cout << "n1 es NaN : " << (n1==n1 ? "No es NaN" : "Si es NaN") << endl;
    cout << "n4 es NaN : " << (n4==n4 ? "No es NaN" : "Si es NaN") << endl;

    cout << "n2 es Inf : " << 
           (n2==numeric_limits<double>::infinity() ? "Si es Inf" : "No es inf") <<
           endl;
    cout << "n4 es Inf : " <<
           (n4==numeric_limits<double>::infinity() ? "Si es Inf" : "No es inf") <<
           endl;
}
