#ifndef PRIORITY_QUEUE_IMPLEMENTATION
#define PRIORITY_QUEUE_IMPLEMENTATION

#include <PriorityQueue.h>

template<class Type> PriorityQueue<Type>::PriorityQueue(bool (*func)(Type, Type)) 
	: startingReserve(100), reserveIncrement(30), currentlyAllocated(0)
{
	determine = func;
	workingArray = new Type[startingReserve];
	currentlyAllocated = startingReserve;
}

template<class Type> PriorityQueue<Type>::PriorityQueue(Type *arr, unsigned int size, bool (*func)(Type, Type)) 
	: startingReserve(100), reserveIncrement(30), currentlyAllocated(0)
{
	determine = func;
	if (size >= startingReserve)
	{
		workingArray = new Type[startingReserve];
		currentlyAllocated = startingReserve;
	} 
	else
	{
		workingArray = new Type[startingReserve];
		currentlyAllocated = startingReserve;
	}

}

template<class Type> PriorityQueue<Type>::PriorityQueue(std::vector<Type> arr, bool (*func)(Type, Type)) 
		: startingReserve(100), reserveIncrement(30)
{
	determine = func;
	if (arr.size() >= startingReserve)
	{
		workingArray = new Type[startingReserve];
		currentlyAllocated = startingReserve;
	}
	else
	{
		workingArray = new Type[startingReserve];
		currentlyAllocated = startingReserve;
	}
}

template<class Type> PriorityQueue<Type>::~PriorityQueue()
{
	delete [] workingArray;
}

#endif // PRIORITY_QUEUE_IMPLEMENTATION