#pragma once

#include <string>
#include <ostream>

class Person {
public:
	// attributes
	// note : usually, private attributes + accesors
	std::string name;
	int age;

	// constuctors
	Person();
	// Person() = default; // to have back the default one from the compiler
	Person(const std::string& name, int age);

	// note : 1 level copy/move mechanism : gifts
	//Person(const Person& other);
	//Person(Person&& other);
	//Person& operator=(const Person& other);
	//Person& operator=(Person&& other);

	// other operators (with a Person as left operand)
	// bool operator==(const Person& other) const; // C++20 => != is defined
	bool operator==(const Person& other) const = default;
	//bool operator!=(const Person& other) const;
	// std::strong_ordering operator<=>(const Person& other) const = default; // C++20 default <=>
	std::strong_ordering operator<=>(const Person& other) const; // c++20 custom version
	//bool operator<(const Person& other) const;

	// methods

	/**
	* a textual representation of the person
	* @return the textual representation
	*/
	std::string toString() const;

	/**
	* add relative number of years to the age
	* @param years relative number of years to add
	* @return new age of the person
	*/
	int addYears(int years);

};

std::ostream& operator<<(std::ostream& out, const Person& p);

