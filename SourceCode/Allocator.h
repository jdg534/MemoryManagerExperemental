#ifndef _ALLOCATOR_H_
#define _ALLOCATOR_H_

#include <cstdio>

#define FREE_MEMORY 0xFFFFFFFF
#define START_OF_HEAP 0xBADF00D
#define ALLOCATION_GUARD 0xDEADCODE
#define END_OF_HEAP 0xDEADBEEF

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
public:
	static Heap * getInstance();
	static void shutdown();

	
private:
	void initialise(void * startingAdress, char * bufferAdress);
	void shutdownPrivate();
	char * m_rawBytes; //  this is to be treated as a buffer
	void * m_startingAdress; // kind of a version of the "this" pointer. this member variable might not be needed
	void * m_nextFreeMemoryAddress;
};


void * operator new(std::size_t size);
void operator delete(void * addressToDelete);

#endif // _ALLOCATOR_H_