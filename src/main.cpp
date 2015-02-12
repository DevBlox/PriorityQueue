#include <iostream>
#include <fstream>

#include <PriorityQueue.h>
#include <TestStruct.h>

bool determineWithInt(int a, int b)
{
	return a > b;
}

bool determineWithTestStruct(TestStruct a, TestStruct b)
{
	if (a.age > b.age) return true;
	else if (a.age == b.age)
	{
		if (a.money > b.money) return true;
		else return false;
	} else return false;
}

std::vector<TestStruct> LoadData();

void InitialisesWithSingleElements(std::vector<TestStruct>);
void InitialisesWithArray(std::vector<TestStruct>);
void InitialisesWithVector(std::vector<TestStruct>);

int main(int argc, char **argv)
{
	std::vector<TestStruct> data = LoadData();
	try
	{
		std::cout << "Testing with array" << std::endl;
		InitialisesWithArray(data);
		std::cout << "Testing with separate elements" << std::endl;
		InitialisesWithSingleElements(data);
		std::cout << "Testing with vector" << std::endl;
		InitialisesWithVector(data);
	}
	catch(std::string exception)
	{
		std::cout << exception << std::endl;
	}
	return 0;
}

void InitialisesWithArray(std::vector<TestStruct> data)
{
	TestStruct *dynArr = new TestStruct[data.size()];
	unsigned int size = (unsigned int)data.size();
	for (unsigned int i = 0; i < size; i++)
		dynArr[i] = data[i];
	Uni::PriorityQueue<TestStruct> testStruct (determineWithTestStruct);
	testStruct.Add(dynArr, size);
	for (unsigned int i = 0; i < testStruct.Size(); i++)
	{
		bool found = false;
		for (unsigned int j = 0; j < size; j++)
			if (testStruct[i] == dynArr[j]) found = true;
		if (!found) throw std::string("Fails to initialise with array");
	}
	delete [] dynArr;
}

void InitialisesWithSingleElements(std::vector<TestStruct> data)
{
	Uni::PriorityQueue<TestStruct> testStruct (determineWithTestStruct);
	for (size_t i = 0; i < data.size(); i++)
		testStruct << data[i];
		
	for (unsigned int i = 0; i < testStruct.Size(); i++)
	{
		bool found = false;
		for (unsigned int j = 0; j < data.size(); j++)
			if (testStruct[i] == data[j]) found = true;
		if (!found) throw std::string("Fails to initialise with single elements");
	}
}

void InitialisesWithVector(std::vector<TestStruct> data)
{
	Uni::PriorityQueue<TestStruct> testStruct (determineWithTestStruct);
	testStruct << data;
	for (unsigned int i = 0; i < testStruct.Size(); i++)
	{
		bool found = false;
		for (unsigned int j = 0; j < data.size(); j++)
			if (testStruct[i] == data[j]) found = true;
		if (!found) throw std::string("Fails to initialise with vector");
	}
	
	while(testStruct.Size())
	{
		TestStruct element = testStruct.Next();
		std::cout << element.name << " " << element.surname << " " << element.age << " " << element.money << std::endl;
	}
	
}

std::vector<TestStruct> LoadData()
{
	std::vector<TestStruct> arr;
	std::ifstream file ("data.txt");
	std::string name, surname;
	unsigned int age, money;
	TestStruct testStruct;
	while (file >> name >> surname >> age >> money)
	{
		testStruct.name = name;
		testStruct.surname = surname;
		testStruct.age = age;
		testStruct.money = money;
		arr.push_back(testStruct);
	}
	return arr;
}