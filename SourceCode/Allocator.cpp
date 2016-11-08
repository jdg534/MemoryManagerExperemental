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

// remember: Heap can't use new or delete

Heap * Heap::getInstance()
{
	if (AllocatorAnonNameSpace::f_instPtr == nullptr)
	{
		size_t sizeOfAllocator = sizeof(Heap);
		size_t sizeOfAllocatorData = HEAP_SIZE;
		AllocatorAnonNameSpace::f_instPtr = reinterpret_cast<Heap *>(std::malloc(sizeOfAllocator));
		char * heapBuffer = reinterpret_cast<char *>(std::malloc(sizeOfAllocatorData));
		AllocatorAnonNameSpace::f_instPtr->initialise(AllocatorAnonNameSpace::f_instPtr, heapBuffer);
	}
	return AllocatorAnonNameSpace::f_instPtr;
}

void Heap::shutdown()
{
	if (AllocatorAnonNameSpace::f_instPtr)
	{
		AllocatorAnonNameSpace::f_instPtr->shutdownPrivate();
		std::free(AllocatorAnonNameSpace::f_instPtr);
	}
}

void Heap::initialise(void * startingAdress, char * bufferAdress)
{
	// set all memory to be FREE_MEMORY
	m_startingAdress = startingAdress;
	m_rawBytes = bufferAdress;
	char * addressToEdit = m_rawBytes;
	for (int i = 0; i < HEAP_SIZE; ++i)
	{
		addressToEdit = m_rawBytes + i;
		if (i == 0)
		{
			*addressToEdit = START_OF_HEAP;
		}
		else if (i == HEAP_SIZE - 1)
		{
			*addressToEdit = END_OF_HEAP;
		}
		else
		{
			*addressToEdit = FREE_MEMORY;
		}
	}
}

void Heap::shutdownPrivate()
{
	std::free(reinterpret_cast<void *>(m_rawBytes));
}

void * operator new(std::size_t size)
{
	Heap * theHeap = Heap::getInstance();

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