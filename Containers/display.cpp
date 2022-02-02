#include "display.h"
#include <iostream>

void displayVectorOfDoubles(std::vector<double> aVector) {
	std::cout << aVector.size() << "/[ ";
	for (double element : aVector) {
		// display one element here
		std::cout << element << ", ";
	}
	std::cout << "]" << std::endl;
}