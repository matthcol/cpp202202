#include "speeddata.h"
#include <iostream>
#include "display.h"

std::vector<double>* initSpeedData(int size, double initialSpeed) {
	std::vector<double>* res = new std::vector<double>(size, initialSpeed);
	// here perhaps you want to complete the data allocated
	return res;
}

void useSpeedDataReading(const std::vector<double>& speedVector) {
	std::cout << "Reading speed data" << std::endl;
	displayVectorOfDoubles(speedVector);
	std::cout << "I am done reading the data" << std::endl;
}

void useSpeedDataModifying(std::vector<double>& speedVector) {
	 std::cout << "Modifying some data" << std::endl;
	 speedVector.insert(speedVector.begin(), 30.78);
	 displayVectorOfDoubles(speedVector);
	 std::cout << "I am done with modifying data" << std::endl;
}

void cleanSpeedData(std::vector<double>* speedVector) {
	// by calling delete
	// 1-  the destructor of vector is called
	// 2 - the memory in the heap is given back
	delete speedVector; 
}