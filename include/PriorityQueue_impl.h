#ifndef PRIORITY_QUEUE_IMPLEMENTATION
#define PRIORITY_QUEUE_IMPLEMENTATION

#include <PriorityQueue.h>

template<typename Type> Uni::PriorityQueue<Type>::PriorityQueue(bool (*func)(Type, Type)) 
	: startingReserve(200), reserveIncrement(100), currentlyAllocated(0)
{
	determine = func;
	workingArray = new Type[startingReserve];
	currentlyAllocated = startingReserve;
	numElements = 0;
}

template<typename Type> Uni::PriorityQueue<Type>::PriorityQueue(Type *arr, unsigned int size, bool (*func)(Type, Type)) 
	: startingReserve(200), reserveIncrement(100), currentlyAllocated(0)
{
	determine = func;
	if (size >= startingReserve)
	{
		unsigned int need = startingReserve;
		while (need < size)
			need += reserveIncrement;
		workingArray = new Type[need];
		currentlyAllocated = need;
	} 
	else
	{
		workingArray = new Type[startingReserve];
		currentlyAllocated = startingReserve;
	}
	for (unsigned int i = 0; i < size; i++)
		workingArray[i] = arr[i];
	numElements = size;
}

template<typename Type> Uni::PriorityQueue<Type>::PriorityQueue(std::vector<Type> arr, bool (*func)(Type, Type)) 
		: startingReserve(200), reserveIncrement(100)
{
	determine = func;
	if (arr.size() >= startingReserve)
	{
		unsigned int need = startingReserve;
		while (need < arr.size())
			need += reserveIncrement;
		workingArray = new Type[need];
		currentlyAllocated = need;
	}
	else
	{
		workingArray = new Type[startingReserve];
		currentlyAllocated = startingReserve;
	}
	for (unsigned int i = 0; i < arr.size(); i++)
		workingArray[i] = arr.at(i);
	numElements = arr.size();
}

template<typename Type> Uni::PriorityQueue<Type>::~PriorityQueue()
{
	delete [] workingArray;
}

template<typename Type> void Uni::PriorityQueue<Type>::Reallocate()
{
	currentlyAllocated += reserveIncrement;
	Type *newArr = new Type[currentlyAllocated];
	for (unsigned int i = 0; i < numElements; i++)
		newArr[i] = workingArray[i];
	delete [] workingArray;
	workingArray = newArr;
}

template<typename Type> void Uni::PriorityQueue<Type>::Add(Type a)
{
	unsigned int i = 0;
	while (determine(a, workingArray[i]) && i < numElements) i++;
	Offset(i);
	workingArray[i] = a;
	numElements++;
}

template<typename Type> void Uni::PriorityQueue<Type>::Add(Type *arr, unsigned int num)
{
	for (unsigned int i = 0; i < num; i++)
	{
		unsigned int j = 0;
		while (determine(arr[i], workingArray[j])) j++;
		Offset(j);
		workingArray[j] = arr[i];
		numElements++;
	}
}

template<typename Type> void Uni::PriorityQueue<Type>::Add(std::vector<Type> arr)
{
	for (unsigned int i = 0; i < arr.size(); i++)
	{
		unsigned int j = 0;
		while (determine(arr.at(i), workingArray[j])) j++;
		Offset(j);
		workingArray[j] = arr.at(i);
		numElements++;
	}
}

template<typename Type> Uni::PriorityQueue<Type>& Uni::PriorityQueue<Type>::operator<<(Type a)
{
	Add(a);
	return *this;
}

template<typename Type> Uni::PriorityQueue<Type>& Uni::PriorityQueue<Type>::operator<<(std::vector<Type> arr)
{
	Add(arr);
	return *this;
}

template<typename Type> void Uni::PriorityQueue<Type>::Offset(unsigned int index)
{
	if (!numElements) return;
	if (numElements + 1 > currentlyAllocated) Reallocate();
	for (unsigned int i = numElements; i > index; i--)
		workingArray[i] = workingArray[i - 1];
}

template<typename Type> Type Uni::PriorityQueue<Type>::Next()
{
	numElements--;
	return workingArray[numElements];
}

template<typename Type> Type Uni::PriorityQueue<Type>::At(unsigned int i)
{
	return workingArray[i];
}

template<typename Type> Type Uni::PriorityQueue<Type>::operator[](unsigned int i)
{
	return At(i);
}

template<typename Type> void Uni::PriorityQueue<Type>::Clear()
{
	delete [] workingArray;
	workingArray = new Type[startingReserve];
	currentlyAllocated = startingReserve;
	numElements = 0;
}

template<typename Type> void Uni::PriorityQueue<Type>::EraseAt(unsigned int index)
{
	numElements--;
	for (unsigned int i = index; i < numElements; i++)
		workingArray[i] = workingArray[i + 1];
}

template<typename Type> void Uni::PriorityQueue<Type>::Erase(Type a)
{
	for (unsigned int i = 0; i < numElements; i++)
	{
		if (workingArray[i] == a) {
			EraseAt(i);
			break;
		}
	}
}

template<typename Type> unsigned int Uni::PriorityQueue<Type>::Size()
{
	return numElements;
}

#endif // PRIORITY_QUEUE_IMPLEMENTATION