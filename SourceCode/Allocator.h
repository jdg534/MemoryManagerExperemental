#ifndef _ALLOCATOR_H_
#define _ALLOCATOR_H_

#include <cstdio>

#define FREE_MEMORY 0xFFFFFFFF
#define ALLOCATION_GUARD 0xDEADCODE

// 5MB heap
#define HEAP_SIZE 1024 * 1024 * 5


struct AllocationChunk
{
	unsigned int startingGuard;
	size_t nBytesAllocated;
	void * baseAddress;
};

class Heap
{
private:
	static Heap * getInstance();
	Heap()
	{
	}

	~Heap()
	{
	}
	char m_rawBytes[HEAP_SIZE];
	void * m_startingAdress;
};


void * operator new(std::size_t size);
void operator delete(void * addressToDelete);

#endif // _ALLOCATOR_H_