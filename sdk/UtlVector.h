#ifndef UTLVECTOR_H
#define UTLVECTOR_H

struct UtlVector
{
	int *memory;
	int allocationCount;
	int growSize;
	int size;
	void *elements;
};

#endif
