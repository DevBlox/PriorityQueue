#ifndef TEST_STRUCT_H
#define TEST_STRUCT_H

#include <string>
#include <vector>

struct TestStruct
{
	bool operator==(TestStruct a)
	{
		if (a.name == name &&
			a.surname == surname &&
			a.age == age &&
			a.money == money) return true;
			else return false;
	}

	std::string name, surname;
	unsigned int age, money;
};

#endif // TEST_STRUCT_H