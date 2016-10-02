#include "SimpleHeap.h"

#ifdef _DEBUG
#include <iostream>
#endif

namespace SimpleHeapAnonNameSpace
{
	SimpleHeap * f_HeapInstPtr;
}



void * operator new(size_t nBytesToAllocate)
{
#ifdef _DEBUG
	std::cout << nBytesToAllocate << " requested" << std::endl;
#endif

}

void operator delete(void * toDelete)
{

}