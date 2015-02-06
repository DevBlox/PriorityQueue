#include <iostream>
#include <PriorityQueue.h>

bool function(int a, int b)
{
	return a ^ b;
}

int main(int argc, char **argv)
{
	PriorityQueue<int> priorityQueue(function);
	std::cout << "It works!" << std::endl;
	return 0;
}