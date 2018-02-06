#include <iostream>
#include <limits>
using namespace std;

int main(){
	cout << numeric_limits<int>::min() << endl;
	cout << numeric_limits<int>::max() << endl;
	cout << numeric_limits<short int>::min() << endl;
	cout << numeric_limits<short int>::max() << endl;
	cout << numeric_limits<unsigned int>::min() << endl;
	cout << numeric_limits<unsigned int>::max() << endl;
	cout << numeric_limits<double>::min() << endl;
	cout << numeric_limits<double>::max() << endl;
}
