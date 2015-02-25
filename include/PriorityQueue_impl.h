#ifndef PRIORITY_QUEUE_IMPLEMENTATION
#define PRIORITY_QUEUE_IMPLEMENTATION

#include <PriorityQueue.h>
#include <iostream>

template<typename Type> Uni::PriorityQueue<Type>::PriorityQueue(bool (*func)(Type, Type))
{
	head = NULL;
	tail = NULL;
	numElements = 0;
	determine = func;
}

template<typename Type> Uni::PriorityQueue<Type>::PriorityQueue(Type *arr, unsigned int size, bool (*func)(Type, Type))
{
	head = NULL;
	tail = NULL;
	numElements = 0;
	determine = func;
	Add(arr, size);
}

template<typename Type> Uni::PriorityQueue<Type>::PriorityQueue(std::vector<Type> arr, bool (*func)(Type, Type)) 
{
	head = NULL;
	tail = NULL;
	numElements = 0;
	determine = func;
	Add(arr);
}

template<typename Type> Uni::PriorityQueue<Type>::~PriorityQueue()
{
	DeleteListRecursive(head);
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
	Node *newNode = new Node(a);
	Node *iterator = head;
	while (iterator != NULL)
	{
		if (!determine(a, iterator->data))
			break;
		iterator = iterator->next;
	}
	if (iterator == NULL && iterator != head)
	{
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	} else
	if (iterator == head)
	{
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
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
	if (numElements == 0 || head == NULL || tail == NULL) throw "PriorityQueue is empty";
	Type data;
	if (head == tail)
	{
		data = tail->data;
		delete tail;
		tail = NULL;
		head = NULL;
	} else
	{
		Node *temp = tail->prev;
		data = tail->data;
		delete tail;
		temp->next = NULL;
		tail = temp;
	}
	numElements--;
	return data;
}

template<typename Type> Type Uni::PriorityQueue<Type>::At(unsigned int i)
{
	if (numElements <= i) throw "Index out of bounds";
	unsigned int pos = 0;
	for (Node *node = head; node != NULL; node = node->next)
	{
		if (pos == i) return head->data;
		pos++;
	}
	return tail->data;
}

template<typename Type> Type Uni::PriorityQueue<Type>::operator[](unsigned int i)
{
	return At(i);
}

template<typename Type> void Uni::PriorityQueue<Type>::Clear()
{
	DeleteListRecursive(head);
	head = NULL;
	tail = NULL;
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

#endif // PRIORITY_QUEUE_IMPLEMENTATION