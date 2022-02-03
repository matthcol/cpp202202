#include <iostream>
#include <vector>

#include "Person.h"

using namespace std;

void learn_oop_create_default_constructor() {
	// creating data with default constructor
	Person person;
	Person* person_ptr = new Person();

	cout << person.name << ", " << person.age << endl;

	person.name = "Matthias";
	person.age = 46;

	person_ptr->name = "Gupta";
	person_ptr->age = 30;

	cout << person.name << ", " << person.age << endl;
	cout << person_ptr->name << ", " << person_ptr->age << endl;

	delete person_ptr;

}

void learn_oop_create_complete_constructor() {
	// creating data with complete constructor
	Person person("Matthias", 46);
	Person* person_ptr = new Person("Gupta", 30);

	cout << "p1: " << person.name << ", " << person.age << endl;
	cout << "p2: " << person_ptr->name << ", " << person_ptr->age << endl;

	std::vector<Person> persons {person, *person_ptr};
	// for (const Person& p : persons) {
	for (const auto& p : persons) {
		cout << " - " << p.name << ", " << p.age << endl;
	}
	for (auto& p : persons) {
		p.age++;
	}
	for (const auto& p : persons) {
		cout << " - " << p.name << ", " << p.age << endl;
	}
	cout << "p1: " << person.name << ", " << person.age << endl;
	cout << "p2: " << person_ptr->name << ", " << person_ptr->age << endl;

	delete person_ptr;

}

int main() {
	//learn_oop_create_default_constructor();
	learn_oop_create_complete_constructor();
	return EXIT_SUCCESS;
}