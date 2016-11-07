#include "Allocator.h"

#include <cstdlib>
#include <cstdio>

#ifdef _DEBUG
#include <iostream>
#endif 


namespace AllocatorAnonNameSpace
{
	Heap * f_instPtr = nullptr;
}

// rember Heap can't use new or delete

Heap * Heap::getInstance()
{

}

Heap::Heap()
{

}

Heap::~Heap()
{

}


void * operator new(std::size_t size)
{
	// size_t actualNumBytesToAllocate = size + sizeof(AllocationChunk);
	// std::printf("%zu Bytes requested\n", size);


	void * allocLoc = std::malloc(size);
#ifdef _DEBUG
	std::cout << size << " bytes requested at " << allocLoc << std::endl;
#endif 	
	return allocLoc;
}

void operator delete(void * addressToDelete)
{
	// std::puts("Delete called");
#ifdef _DEBUG
	std::cout << "Freeing the memory at: " << addressToDelete << std::endl;
#endif 
	std::free(addressToDelete);
}