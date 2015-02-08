#include <iostream>
#include <PriorityQueue.h>

bool function(int a, int b)
{
	return a ^ b;
}

int main(int argc, char **argv)
{
	Uni::PriorityQueue<int> priorityQueue(function);
	priorityQueue << 5 << 10 << 5 << 64 << 80;
	
	std::cout << "It works!: " << priorityQueue.Next() << std::endl;
	return 0;
}