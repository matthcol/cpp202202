#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

#include "Person.h"
#include "../Containers/display.h"

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

void learn_methods() {
	Person p("Matthias", 46);
	std::cout << p.toString() << std::endl;
	int newAge = p.addYears(10);
	std::cout << "New age: " << newAge << std::endl;
	std::cout << p.toString() << std::endl;
}

void learn_operators_copy() {
	Person p;
	Person p2("Matthias", 46);
	std::cout << "P: " << p.toString() << std::endl;

	// operator= : copy
	p = p2; // 1 level copy (not a deep level)
	std::cout << "P: " << p.toString() << std::endl;
	p.addYears(10);
	p.name[0] = 'Z';
	std::cout << "P: " << p.toString() << std::endl;
	std::cout << "P2: " << p2.toString() << std::endl;

	// constructor by copy
	Person p3(p);
	Person* p4_ptr = new Person(p);
	std::cout << "P3: " << p3.toString() << std::endl;
	std::cout << "P4: " << p4_ptr->toString() << std::endl;

	delete  p4_ptr;
}

void learn_comparisons() {
	Person p1("Matthias", 46);
	Person p2;
	Person p3(p1);
	Person p4("Matthias", 30);
	Person p5("Gupta", 30);
	std::cout << "P1: " << p1.toString() << std::endl;
	std::cout << "P2: " << p2.toString() << std::endl;
	std::cout << "P3: " << p3.toString() << std::endl;
	std::cout << "P4: " << p4.toString() << std::endl;
	std::cout << "P5: " << p5.toString() << std::endl;
	std::cout << std::boolalpha
		<< "p1 == p2 : " << (p1 == p2) << std::endl // p1.operator==(p2)
		<< "p1 == p3 : " << (p1 == p3) << std::endl
		<< "p1 == p4 : " << (p1 == p4) << std::endl
		<< "p4 == p5 : " << (p1 == p4) << std::endl
		<< "p1 != p2 : " << (p1 != p2) << std::endl
		<< "p1 != p3 : " << (p1 != p3) << std::endl
		<< "p1 != p4 : " << (p1 != p4) << std::endl
		<< "p4 != p5 : " << (p1 != p4) << std::endl
		<< "p1 < p4 : " << (p1 < p4) << std::endl
		<< "p1 < p5 : " << (p1 < p5) << std::endl
	;
	std::vector<Person> persons{ p1,p2,p3,p4,p5};
	// look for p5 in the vector
	auto res = std::find(persons.begin(), persons.end(), p5);
	if (res != persons.end()) {
		cout << "iteartor is :" << res->toString() << endl;
	}
	else {
		cout << "No person found" << endl;
	}

	
	std::sort(persons.begin(), persons.end());
	cout << p1 << endl;  // functional mode : operator<<(cout, p1)
	cerr << p1 << endl;
	displayIterable(persons.begin(), persons.end());
	//p1 != p2;
	//p1 < p2;
	//p1 <=> p2;
}

void learn_functional_programming() {
	Person p1("Matthias", 46);
	Person p2;
	Person p3("Not Famous", 25);
	Person p4("Famous", 30);
	Person p5("Gupta", 30);

	std::vector<Person> persons{ p1,p2,p3,p4,p5 };
	displayIterable(persons.begin(), persons.end());

	// look for data with a partial content
	// in a lambda function, [] is for capturing external data
	string nameSearched = "Gupta";
	auto res = std::find_if(persons.begin(), persons.end(),
		[nameSearched](const auto& p) { return p.name == nameSearched; }
		// [](const auto& p) { return p.name == "Gupta"; }
		// [](const auto& p) { return p.name.starts_with("G"); }
	);
	if (res != persons.end()) {
		cout << "Person found :" << res->toString() << endl;
	}
	else {
		cout << "No person found" << endl;
	}

	//std::sort(persons.begin(), persons.end(), "byName");
	//std::sort(persons.begin(), persons.end(), "byAge");
	std::sort(persons.begin(), persons.end(), std::greater<Person>());
	std::sort(persons.begin(), persons.end(),
		// [](const auto& pe1, const auto& pe2) { return pe1.name < pe2.name; }
		[](const auto& pe1, const auto& pe2) { return pe1.age > pe2.age; }
 	);
	displayIterable(persons.begin(), persons.end());


}

void learn_export() {
	// initial data
	Person p1("Matthias", 46);
	Person p2;
	Person p3("Not Famous", 25);
	Person p4("Famous", 30);
	Person p5("Gupta", 30);
	std::vector<Person> persons{ p1,p2,p3,p4,p5 };
	
	// open a file
	ofstream out("persons.txt"); // by default out mode (and trunc)
	// ofstream out("persons.txt", ios_base::app | ios_base::out);
	
	out << persons.size() << endl;

	//  write in the file
	//for (const auto& p : persons) {
	//	out << p << endl;
	//}
	std::for_each(persons.begin(), persons.end(),
		[&out](const auto& p) { out << p.name << "," << p.age << endl; }
	);

	// don't forget to close the file
	out.close();
}

void learn_loading() {
	ifstream in("persons.txt");
	char buf[255];
	int count;
	in >> count;
	cout << "Nb of persons: " << count << endl;
	for (int i = 0; i < count; i++) {
		in.getline(buf, 255);
		string line(buf);
		cout << line << endl;
		// TODO : parse the line and create an Person object with it
	}
	// int count = 1000;
	// std::vector<Person> persons(count);
}

int main() {
	// learn_oop_create_default_constructor();
	// learn_oop_create_complete_constructor();
	// learn_methods();
	// learn_operators_copy();
	// learn_comparisons();
	// learn_functional_programming();
	learn_export();
	learn_loading();
	return EXIT_SUCCESS;
}