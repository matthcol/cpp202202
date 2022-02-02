#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <cstdlib>
#include "display.h"

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
	std::vector<double> speedVector {10.5, 22.5, 35.7};
	std::cout << "Size: " << speedVector.size() << std::endl;
	std::cout << speedVector[0] << std::endl;
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
	// insert 1 data at the begining
	speedVector.insert(speedVector.begin(), 80.54);
	// insert 1 data at the 4th position
	speedVector.insert(speedVector.begin() + 4, 80.54);
	// insert 1 data at the position previous the last one
	speedVector.insert(speedVector.end() - 1, 30.56);
	displayVectorOfDoubles(speedVector);

	// delete 1 data : TODO
	// delete a range of data : TODO
	
	// insert a range of data at the begining
	std::vector<double> newData{ 12.3, 23.4, 34.5, 45.6 };
	speedVector.insert(speedVector.begin(), newData.begin(), newData.end());
	displayVectorOfDoubles(speedVector);

	// clear the vector
	speedVector.clear();
	displayVectorOfDoubles(speedVector);

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

int main() {
	// learn_vectors_from_empty();
	//learn_vectors_initialized();
	 learn_vectors_sizes();
	// learn_vectors_iterator();
	//learn_lists_iterator();
	return EXIT_SUCCESS;
}

