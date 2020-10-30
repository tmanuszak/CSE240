#include <iostream>
using namespace std;

class Base {
	public:
		Base(int n) {
			cout << "Base constructor" <<endl;
		}
		void function() {
			cout << "funtion" << endl;
		}
		~Base() {
			cout << "Base destructor" << endl;
		}
};

class Derived : public Base {
	public:

		//Constructor calls constructor base
		Derived(int n) : Base(n) {
			cout << "Derived constructor" << endl;
		}

		~Derived () {
			cout << "Derived destructor" << endl;
		}
};

int main() {
	Derived myPQ1(50);
	myPQ1.function(); //inherited
	myPQ1.function(); //inherited

	Derived *myPQ2;
	myPQ2 = new Derived(50);
	myPQ2->function(); //inherited
	myPQ2->function(); //inherited
	delete myPQ2;
}
