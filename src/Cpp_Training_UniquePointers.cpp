//============================================================================
// Name        : Cpp_Training_UniquePointers.cpp
// Author      : Nico
// Version     :
// Copyright   : Your copyright notice
// Description : Testing SmartPointers in C++, Ansi-style
//============================================================================

#include <iostream>
#include <memory>


using namespace std;

struct Foo {
	Foo() { cout << "Foo::Foo() constructor called\n";};
	~Foo() { cout << "Foo::~Foo() destructor called\n";};
	void bar(){cout << "Foo::bar() called\n";};
};

void f (const Foo &){
	cout << "f(const Foo &) called\n";
}

int main() {
	unique_ptr<Foo> p1 (new Foo);

	cout << "created a unique pointer p1 to a Foo object\n";
	cout << "p1 pointer address: " << p1.get() << "\n";

	if (p1) p1->bar();

	{
		unique_ptr<Foo> p2 (move(p1));
		cout << "\tmoved the unique pointer p1 to the new one p2\n";
		cout << "\tp1 pointer address: " << p1.get() << "\n";
		cout << "\tp2 pointer address: " << p2.get() << "\n";
		f(*p2);
		if (p2) {
			cout << "\t"; p2->bar();
		};
		p1 = move(p2);
		cout << "\tmoved the unique pointer back from p2 to p1\n";
		cout << "\tdestroying p2...\n";
	}
	if (p1) p1->bar();
	cout << "p1 pointer address: " << p1.get() << "\n";
	return 0;
}
