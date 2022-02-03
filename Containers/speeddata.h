#pragma once
#include <vector>

/**
* create initial data in the head
*/
std::vector<double>* initSpeedData(int size, double initialSpeed);

void useSpeedDataReading(const std::vector<double>& speedVector);
void useSpeedDataModifying(std::vector<double>& speedVector);

void cleanSpeedData(std::vector<double>* speedVector);
