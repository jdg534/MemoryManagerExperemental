#include <ostream>

#include <iostream>

#include "SimpleHeap.h" // code this later

struct foo
{
	//foo()
	//{

	//	std::cout << "foo() called" << std::endl;

	//	bar = 0;
	//}
	foo(void)
	{
		std::cout << "foo(void) called" << std::endl;

		bar = 1;
	}
	foo(int inBar)
	{

		std::cout << "foo(int) called" << std::endl;

		bar = inBar;
	}

	friend std::ostream & operator<<(std::ostream & out, const foo & a)
	{
		out << a.bar;
		return out;
	}

	int bar;
};

typedef char twoChars[2];

int main()
{
	using namespace std;
	foo a;
	//foo b();
	foo c(3);

	foo * d = new foo;
	foo * e = new foo(5);

	cout << "a.bar = " << a << endl;
	//cout << "b.bar = " << b << endl;
	cout << "c.bar = " << c << endl;

	cout << "d->bar = " << *d << endl;
	cout << "e->bar = " << *e << endl;

	char oneChar = 'A';

	twoChars twoChar;
	twoChar[0] = 'B';
	twoChar[1] = 'C';

	int * aPointer;

	cout << "Size of 1 char " << sizeof(oneChar) << endl;
	cout << "Size of twoChars type " << sizeof(twoChar) << endl;
	cout << "Size of two char variables " << sizeof(oneChar) * 2 << endl;
	cout << "Size of a pointer " << sizeof(aPointer) << endl;


	cout << "DONE:";
	cin.get();

	return 0;
}