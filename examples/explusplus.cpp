#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	a = 5;
	b = ++a;
	cout << a << endl << b << endl;
	c = a++;
	cout << a << endl << c << endl;
}
