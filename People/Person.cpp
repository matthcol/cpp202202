#include "Person.h"

#include <format>
#include <sstream>

Person::Person() : name("John Doe"), age(0) {

}

Person::Person(const std::string& name, int age): name(name), age(age) {
	// here dynamically allocate complex data
}

//bool Person::operator==(const Person& other) const
//{
//	// return (name == other.name) && (age == other.age);
//	return (this->name == other.name) && (this->age == other.age);
//}
//
//bool Person::operator!=(const Person& other) const
//{
//	// Think De Morgan theorem
//	// return (this->name != other.name) || (this->age != other.age);
//	return  !(*this == other);
//}
//
//bool Person::operator<(const Person& other) const
//{
//	if (this->name != other.name) {
//
//		return (this->name < other.name);
//	} else {
//		return (this->age < other.age);
//	}
//}

std::strong_ordering Person::operator<=>(const Person& other) const
{
	auto res = this->age <=> other.age;
	if (std::is_eq(res)) {
		res = this->name <=> other.name;
	}
	return res;
}

std::string Person::toString() const
{
	// since C++20 
	// return std::format("{} ({})", name, age);

	// C++ until 20
	std::ostringstream buf;
	buf << name << " (" << age << ")";
	return buf.str();
}

int Person::addYears(int years)
{
	return age += years;
}

std::ostream& operator<<(std::ostream& out, const Person& p)
{
	return out << p.toString();
}
