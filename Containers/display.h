#pragma once
#include <vector>
#include <iterator>
#include <iostream>

/**
* display the content of a vector of doubles
* @param vector : a vector to display
*/
void displayVectorOfDoubles(const std::vector<double>& aVector);

/**
* Display iterable data if you have an overload of operator<< for the type of the elements
* Examples:
*  for a vector of doubles we have 4 kinds of iterators :
*		- std::vector<double>::iterator 
*		- std::vector<double>::const_iterator 
*		- std::vector<double>::reverse_iterator 
*		- std::vector<double>::const_reverse_iterator 
* for a vector of Person we have 4 kinds of iterators :
* 		- std::vector<Person>::iterator 
*		- std::vector<Person>::const_iterator 
*		- std::vector<Person>::reverse_iterator 
*		- std::vector<Person>::const_reverse_iterator 
* for a list of double we have iterators : std::list<double>::iterator, ...
* for an array of double (with pointer or []) we have iterators : a double * pointer
*/
template<class InputIterator>
void displayIterable(InputIterator first, InputIterator last);

#include "display.tpp"


