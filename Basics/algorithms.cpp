#include "algorithms.h"

// note: the default value of startIndex is not repeated here

int search(double value, const vector<double>& vector, int startIndex) {
	int indexFound = -1;
	// search algorithm
	for (int i = startIndex; i < vector.size(); i++) {
		if (value == vector[i]) {
			indexFound = i;
			break;
		}
	}
	return indexFound;
}