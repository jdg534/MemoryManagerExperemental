#ifndef _ALLOCATOR_H_
#define _ALLOCATOR_H_

#include <cstdio>

struct AllocationChunk
{
	void * baseAddress;
	size_t nBytesAllocated;
};

void * operator new(std::size_t size);
void operator delete(void * addressToDelete);



#endif // _ALLOCATOR_H_