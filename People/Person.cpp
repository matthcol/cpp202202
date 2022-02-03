#include "Person.h"

Person::Person() : name("John Doe"), age(0) {

}

Person::Person(const std::string& name, int age): name(name), age(age) {
	// here dynamically allocate complex data
}
