#ifndef PRIORITY_QUEUE_IMPLEMENTATION
#define PRIORITY_QUEUE_IMPLEMENTATION

#include <PriorityQueue.h>
#include <iostream>

template<typename Type> Uni::PriorityQueue<Type>::PriorityQueue(bool (*func)(Type, Type)) : pointer(NULL, NULL)
{
	numElements = 0;
	determine = func;
}

template<typename Type> Uni::PriorityQueue<Type>::PriorityQueue(Type *arr, unsigned int size, bool (*func)(Type, Type)) : pointer(NULL, NULL)
{
	numElements = 0;
	determine = func;
	Add(arr, size);
}

template<typename Type> Uni::PriorityQueue<Type>::PriorityQueue(std::vector<Type> arr, bool (*func)(Type, Type)) : pointer(NULL, NULL)
{
	numElements = 0;
	determine = func;
	Add(arr);
}

template<typename Type> Uni::PriorityQueue<Type>::~PriorityQueue()
{
	DeleteListRecursive(pointer.head);
}

template<typename Type> void Uni::PriorityQueue<Type>::DeleteListRecursive(Uni::PriorityQueue<Type>::Node *node)
{
	if (node == NULL) return;
	if (node->next != NULL)
		DeleteListRecursive(node->next);
	delete node;
}

template<typename Type> void Uni::PriorityQueue<Type>::Add(Type a)
{
	Node *newNode;
	try
	{
		newNode = new Node(a);
	}
	catch(std::bad_alloc exception)
	{
		throw exception.what();
	}
	Node *iterator = pointer.head;
	while (iterator != NULL)
	{
		if (!determine(a, iterator->data))
			break;
		iterator = iterator->next;
	}
	if (iterator == NULL && iterator != pointer.head)
	{
		pointer.tail->next = newNode;
		newNode->prev = pointer.tail;
		pointer.tail = newNode;
	} else
	if (iterator == pointer.head)
	{
		if (pointer.head == NULL)
		{
			pointer.head = newNode;
			pointer.tail = newNode;
		}
		else
		{
			newNode->next = pointer.head;
			pointer.head->prev = newNode;
			pointer.head = newNode;
		}
	} else
	{
		newNode->prev = iterator->prev;
		newNode->next = iterator;
		iterator->prev = newNode;
	}
	numElements++;
}

template<typename Type> void Uni::PriorityQueue<Type>::Add(Type *arr, unsigned int num)
{
	for (unsigned int i = 0; i < num; i++)
		Add(arr[i]);
}

template<typename Type> void Uni::PriorityQueue<Type>::Add(std::vector<Type> arr)
{
	for (unsigned int i = 0; i < arr.size(); i++)
		Add(arr[i]);
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

template<typename Type> Type Uni::PriorityQueue<Type>::Next()
{
	if (numElements == 0 || pointer.head == NULL || pointer.tail == NULL) throw "PriorityQueue is empty";
	Type data;
	if (pointer.head == pointer.tail)
	{
		data = pointer.tail->data;
		delete pointer.tail;
		pointer.tail = NULL;
		pointer.head = NULL;
	} else
	{
		Node *temp = pointer.tail->prev;
		data = pointer.tail->data;
		delete pointer.tail;
		temp->next = NULL;
		pointer.tail = temp;
	}
	numElements--;
	return data;
}

template<typename Type> Type Uni::PriorityQueue<Type>::At(unsigned int i)
{
	if (numElements <= i) throw "Index out of bounds";
	unsigned int pos = 0;
	for (Node *node = pointer.head; node != NULL; node = node->next)
	{
		if (pos == i) return pointer.head->data;
		pos++;
	}
	return pointer.tail->data;
}

template<typename Type> Type Uni::PriorityQueue<Type>::operator[](unsigned int i)
{
	return At(i);
}

template<typename Type> void Uni::PriorityQueue<Type>::Clear()
{
	DeleteListRecursive(pointer.head);
	pointer.head = NULL;
	pointer.tail = NULL;
	numElements = 0;
}

template<typename Type> bool Uni::PriorityQueue<Type>::IsEmpty()
{
	return !numElements;
}

template<typename Type> unsigned int Uni::PriorityQueue<Type>::Size()
{
	return numElements;
}

template<typename Type> void Uni::PriorityQueue<Type>::Join(Uni::PriorityQueue<Type> &other)
{
	while (!other.IsEmpty())
		Add(other.Next());
}

template<typename Type> Uni::PriorityQueue<Type>::Node::Node(Type a)
{
	data = a;
	next = NULL;
	prev = NULL;
}

template<typename Type> Uni::PriorityQueue<Type>::Pointer::Pointer()
{
	head = NULL;
	tail = NULL;
}

template<typename Type> Uni::PriorityQueue<Type>::Pointer::Pointer(Node *begin, Node *stop)
{
	head = begin;
	tail = stop;
}

#endif // PRIORITY_QUEUE_IMPLEMENTATION