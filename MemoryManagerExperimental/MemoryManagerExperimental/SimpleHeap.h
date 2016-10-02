#pragma once
#ifndef _SIMPLE_HEAP_H_
#define _SIMPLE_HEAP_H_

#define MAX_MEMORY 100 * 1024 * 1024 // 100MB max memory
#define END_OF_MEMORY_FLAG 0xDEADC0DE

struct HeapNode
{
	size_t bytesAllocAtedForNode;
	void * nextNode; // this is to be null if there is room for a node & the above flag if out of memory
	void * startOfNodeData;
};

class SimpleHeap
{
public:
	

	~SimpleHeap();

	static SimpleHeap * getInstanace();

private:
	SimpleHeap();
};

void * operator new(size_t nBytesToAllocate);

void operator delete(void * toDelete);

#endif // _SIMPLE_HEAP_H_