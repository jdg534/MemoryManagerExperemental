#include "Allocator.h"

#include <iostream>



int main()
{
	std::cout << "Hello World." << std::endl;

	int * anInt = new int;
	*anInt = 5;

	delete anInt;

	int * someInts = new int[10];

	delete[] someInts;

	return 0;
}