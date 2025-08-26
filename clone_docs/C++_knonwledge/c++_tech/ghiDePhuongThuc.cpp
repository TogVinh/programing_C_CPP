#include <iostream>

using namespace std;

class SuperClass {
public:
	void display() {
		cout << "Hello from SuperClass" << endl;
	}
};

class SubClass : public SuperClass {
public:
	void display() {
		cout << "Hello from SubClass" << endl;
	}
};

int main() {
	SubClass s;
	s.display();
	return 0;
}