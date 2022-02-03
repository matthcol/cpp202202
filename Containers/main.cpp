#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <iterator>
#include <cstdlib>
#include <string>

#include "display.h"
#include "speeddata.h"

//using namespace std;

void learn_vectors_from_empty() {
	// empty vector created with default constructor
	std::vector<double> speedVector; // shortest syntax
	// std::vector<double> speedVector = std::vector<double>(); // longest syntax
	std::cout << "Size: " << speedVector.size() << std::endl;
	speedVector.push_back(10.5);
	// speedVector[0] = 10.5; // only for replacement
	std::cout << speedVector[0] << std::endl;
	//std::cout << speedVector.at(0) << std::endl;
	std::cout << "Size: " << speedVector.size() << std::endl;
	speedVector[0] = 25.5; // OK here
	std::cout << speedVector[0] << std::endl;
}

void learn_vectors_initialized() {
	// vector created with initialization list
	const std::vector<double> speedVector {10.5, 22.5, 35.7};
	std::cout << "Size: " << speedVector.size() << std::endl;
	std::cout << speedVector[0] << std::endl;
	displayVectorOfDoubles(speedVector);
}

void learn_vectors_sizes() {
	std::vector<double> speedVector(10);
	speedVector[0] = 10.7;
	speedVector[9] = 25.8;
	std::cout << "size: " << speedVector.size() << std::endl;
	std::cout << speedVector[0] << " : " << speedVector[9] << std::endl;
	displayVectorOfDoubles(speedVector);
	speedVector.push_back(50.2);
	displayVectorOfDoubles(speedVector);
	// insert 1 data
	auto first2 = speedVector.begin();
	std::advance(first2, 4);
	speedVector.insert(first2, 80.54);
	auto last2 = speedVector.end();
	std::advance(last2, -1);
	speedVector.insert(last2, 30.56);
	//std::advance(first2, 4);
	displayVectorOfDoubles(speedVector);

	// delete 1 data
	// delete a range of data
	
	// insert a range of data at the begining
	std::vector<double> newData{ 12.3, 23.4, 34.5, 45.6 };
	speedVector.insert(speedVector.begin(), newData.begin(), newData.end());
	displayVectorOfDoubles(speedVector);
	speedVector.clear();
	displayVectorOfDoubles(speedVector);
	displayIterable(speedVector.begin(), speedVector.end());

}

void learn_vectors_iterator() {
	std::vector<double> speedVector{ 10.5, 22.5, 35.7, 23.56, 34.56, 56.23 };

	// foreach uses implicitly iterators
	for (double speed : speedVector) {
		std::cout << " * " << speed << std::endl;
	}

	// using explictly the iterator
	// begin : iterator at the start of the vector
	// end : iterator at the end of the vector (just after the last element)
	// ++it : go the next position
	// *it : element pointed by the iterator
	// type of this iterator : std::vector<double>::iterator
	// note: vector<T>::iterator(s) are at least RandomAccessIterator
	for (auto it = speedVector.begin(); it != speedVector.end(); ++it) {
		double speed = *it;
		std::cout << " # " << speed << std::endl;
	}

	auto first = speedVector.begin();
	first += 2; // advance of 2 positions (ok because here we hae random access)
	auto last = speedVector.end();
	last -= 2; // go back of 2 psotions
	while (first != last) {
		double speed = *first;
		std::cout << " ~ " << speed << std::endl;
		++first;
	}

	auto first2 = speedVector.begin();
	auto last2 = first2 + 3; 
	// auto last2 = std::next(first2, 3);
	while (first2 != last2) {
		double speed = *first2;
		std::cout << " @ " << speed << std::endl;
		++first2;
	}
}

// all about iterators
// https://en.cppreference.com/w/cpp/iterator
// https://en.cppreference.com/w/cpp/header/iterator

void learn_lists_iterator() {
	std::list<double> speedList{ 10.5, 22.5, 35.7, 23.56, 34.56, 56.23 };

	// foreach uses implicitly iterators
	for (double speed : speedList) {
		std::cout << " * " << speed << std::endl;
	}

	// using explictly the iterator
	// begin : iterator at the start of the vector
	// end : iterator at the end of the vector (just after the last element)
	// ++it : go the next position
	// *it : element pointed by the iterator
	// type of this iterator : std::list<double>::iterator
	// note list<T>::iterator is a BidirectionalIterator
	for (auto it = speedList.begin(); it != speedList.end(); ++it) {
		double speed = *it;
		std::cout << " # " << speed << std::endl;
	}

	auto first = speedList.begin();
	// ++first; ++first; // advance of 2 positions one by one
	std::advance(first,2);
	auto last = speedList.end();
	// --last; --last; // go back of 2 psotions one by one
	std::advance(last, -2);
	while (first != last) {
		double speed = *first;
		std::cout << " ~ " << speed << std::endl;
		++first;
	}

	auto first2 = speedList.begin();
	// auto last2 = first2 + 3; // NOK this is not a random access iterator
	auto last2 = std::next(first2, 3);
	while (first2 != last2) {
		double speed = *first2;
		std::cout << " @ " << speed << std::endl;
		++first2;
	}
}

void learn_long_life_data() {
	// auto = std::vector<double>*
	auto speedData_ptr = initSpeedData(100, 20.3);
	std::vector<double>& speedData = *speedData_ptr;
	useSpeedDataReading(speedData);
	useSpeedDataModifying(speedData);
	// in order to clean the data in the head, we NEED the pointer
	cleanSpeedData(speedData_ptr);
	// don't use anymore speedData_ptr after the cleaning
	speedData_ptr = nullptr;

	// DO other things after using the data
	// ....

}

void learn_oldfashion_arrays() {
	// static arrays
	double speedArray[10];
	double speedArray2[] = {12.3, 34.4, 56.7 };
	// arrays with pointers
	double* speedArray3 = speedArray;
	double* speedArray4 = new double[100000000]; // dynamic
	// as a container
	std::array<double, 100000000>* speedArray5_ptr = new std::array<double, 100000000>();
	//auto first= speedArray5_ptr->begin();
	//auto last = first + 100;
	//while (first != last) {
	//	std::cout << *first << ", ";
	//	++first;
	//}
	//std::cout << std::endl;

	// display of all the arrays 
	displayIterable(speedArray, speedArray+10);
	displayIterable(std::begin(speedArray2), std::end(speedArray2));
	displayIterable(speedArray4, speedArray4 + 10);
	displayIterable(speedArray5_ptr->begin(), speedArray5_ptr->begin() + 10);
}

void learn_vectors_strings() {
	std::vector<std::string> cities{ "Pamiers", "Toulouse", "Pau" };
	displayIterable(cities.begin(), cities.end());
	std::vector<std::string> noCities;
	displayIterable(noCities.begin(), noCities.end());
}

class Person {};

void learn_vectors_person() {
	std::vector<Person> persons;
	// displayIterable(persons.begin(), persons.end());
	//	'<<'  : no operator found that accepts a right operandof the type 'Person' (or you don't have any acceptable conversion)

}

int main() {
	// learn_vectors_from_empty();
	// learn_vectors_initialized();
	// learn_vectors_sizes();
	// learn_vectors_iterator();
	// learn_lists_iterator();
	// learn_long_life_data();
	//learn_oldfashion_arrays();
	learn_vectors_strings();
	return EXIT_SUCCESS;
}

