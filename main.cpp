#include <iostream>
#include <PriorityQueue.h>

bool function(int a, int b)
{
	return a > b;
}

int main(int argc, char **argv)
{
	Uni::PriorityQueue<int> priorityQueue(function);
	priorityQueue << 5 << 987432 << 15 << 2136 << 654 << 98721 << 0;
	priorityQueue.Erase(5);
	while(priorityQueue.Size())
		std::cout << priorityQueue.Size() << " " << priorityQueue.Next() << std::endl;
	
	return 0;
}