#pragma once

#include <string>

class Person {
public:
	// attributes
	std::string name;
	int age;

	// constuctors
	Person();
	Person(const std::string& name, int age);
};

