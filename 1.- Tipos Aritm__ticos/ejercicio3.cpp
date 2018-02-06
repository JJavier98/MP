#include <iostream>
#include <limits>
using namespace std;

int main(){
	int a = numeric_limits<int>::min();
	int b = numeric_limits<int>::max();
	
	cout << a-1 << endl;
	cout << b+1 << endl;
}
