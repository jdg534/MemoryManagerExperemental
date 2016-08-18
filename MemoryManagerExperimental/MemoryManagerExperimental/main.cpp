#include <ostream>

#include <iostream>


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

int main()
{
	using namespace std;
	foo a;
	//foo b();
	foo c(3);

	cout << "a.bar = " << a << endl;
	//cout << "b.bar = " << b << endl;
	cout << "c.bar = " << c << endl;

	cout << "DONE:";
	cin.get();

	return 0;
}