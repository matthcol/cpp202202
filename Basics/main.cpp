#include <iostream>
#include <iomanip>
#include <cstdint>
#include <vector>

#include "algorithms.h"

// std:: something in the std namespace
using namespace std;

void learn_hello() {
	// output with std:: prefix
	std::cout << "Hello it's tuesday !" << std::endl;
	// outut without std:: prefix (with using at the begining of the file)
	cout << "Tomorrow  it will be wednesday !" << endl;
}

void learn_variables() {
	int x; // non initialized integer variable
	x = 7 * (3 + 5); // assignement of variable x
	int y = 4; // with initial value
	y = (x + y) * 2;
	auto z = x + y; // auto here is int
	cout << "x = " << x 
		<< " ; y = " << y
		<< " ; z = " << z
		<< endl;
}

void learn_basic_types_integer() {
	// integers

	// 1 byte or 8 bits signed integer
	// from -128 to +127
	char x8 = 64; 
	x8 = 127;
	x8++;  // incrementing by 1
	cout << "x8 = " << (int) x8 << endl;

	// 1 byte or 8 bits unsigned integer
	// from 0 to 255
	unsigned char xu8 = 255;
	cout << "xu8 = " << (unsigned int) xu8 << endl;

	// often : 16 bit integer
	short xs = -1024;  // short = signed short
	unsigned short xus = 2048;
	
	// often : 32 bit integer
	int xi = 2000000000;
	unsigned xui = 3000000000;

	// which one is the 64 bit version of integer ?
	long xl = 2L;
	long long xll = 8000000000000000000LL;

	cout << "size char = " << sizeof(x8)
		<< " ; size short = " << sizeof(xs)
		<< " ; size int = " << sizeof(xi)
		<< " ; size long = " << sizeof(xl)
		<< " ; size long long = " << sizeof(xll)
		<< endl;

}

void learn_basic_types_integer_aliases() {
	// integers with aliases to choose the right size in memory
	// https://en.cppreference.com/w/cpp/header/cstdint
	

	// 1 byte or 8 bits signed integer
	// from -128 to +127
	int8_t x8 = 64;
	x8 = 127;
	x8++;  // incrementing by 1
	cout << "x8 = " << (int)x8 << endl;

	// 1 byte or 8 bits unsigned integer
	// from 0 to 255
	uint8_t xu8 = 255;
	cout << "xu8 = " << (unsigned int)xu8 << endl;

	// choose exactly : 16 bit integer
	int16_t xs = -1024;  // short = signed short
	uint16_t xus = 2048;

	// choose exactly : 32 bit integer
	int32_t xi = 2000000000;
	uint32_t xui = 3000000000;

	// which one is the 64 bit version of integer ?
	int64_t xl =  8000000000000000000L;

	cout << "size char = " << sizeof(x8)
		<< " ; size short = " << sizeof(xs)
		<< " ; size int = " << sizeof(xi)
		<< " ; size long = " << sizeof(xl)
		<< endl;

}

void learn_basic_types_floating() {
	// https://en.wikipedia.org/wiki/IEEE_754
	// big and small numbers + nan + inf
	float x32 = 3.14F; // 3.14f
	double x64 = 3.14;
	x64 = 3.141592653589793238462643383279E300;
	cout << "PI (double) = " << x64 << endl;
	cout << "PI (double) = " << setprecision(15) << x64 << endl;
	cout << "PI (double) = " << setprecision(30) << x64 << endl; // too much
	x64 *= 1E10; // x64 = x64 * 1E10
	cout << "Big number = " << setprecision(15) << x64 << endl;
	double y = x64 / x64;
	cout << "Unknown number = "  << y << endl;
	// a silly computing
	float price = 0.1; // in base 2 = 0.00011001100110011001100...
	cout << setprecision(8)
		<< "1 sweet : " << price
		<< "; 2 sweet : " << 2*price
		<< "; 3 sweet : " << 3*price
		<< endl;
}

void learn_basic_operators() {
	int x = 64;
	// warning int/int => int (quotient)
	double y = (x + 1) * 4 - x / 5.0;
	int z = x % 5;
	cout << "Res = " << y << endl
		<< "Remaining part of division : " << z
		<< endl;
	// comparisons until c++20
	bool c1 = x > 3; //  >=  <  <=
	bool c2 = x == 3;
	bool c3 = x != 3;
	cout << "Some tests : " << boolalpha
		<< c1 << ", " << c2 << ", " << c3
		<< endl;
	// comparison since c++20 : three-way-comparison (spaceship)
	auto c4 = x <=> 3;
	cout << "General comparison : " << is_gt(c4) << endl;
	// combine 2 tests : or || , and &&
	bool c1and2 = c1 && c2; // if c1 is False the 2nd part is not evaluated
	bool c1or2 = c1 || c2; // if c1 is True, the 2nd part is not evaluated

	// binary operators : 
	// ~ : not bitwise
	// ^ : xor bitwise
	// | : or bitwise
	// & : and bitwise
	// << : left shift
	// >> : right shift
	int encryptedX = x << 2;
	cout << "encrypted X : " << encryptedX << endl;
	
	int data = x | 5;
	// x    : 0...0 0100 0000
	// 5    : 0...0 0000 0101
	// data : 0...0 0100 0101 => 69
	cout << "data : " << data << endl;
}

void learn_assign_contracted_operators() {
	int x = 1;
	int y, z;
	// 2 ways of incrementing by 1
	// (same thing --)
	y = 5 * x++; // x is incremented after using its value 
	z = 5 * ++x; // x is incremented before using its value
	cout << "At the end : " << endl 
		<< "- x = " << x << endl // equals 3
		<< "- y = " << y << endl // equals  5
		<< "- z = " << z << endl; // equals  15
	x--;	// decrement by 1
	--x;
	x += 2;  // increment by 2
	x -= 10; // decrement by 10
	x *= 3;
	x /= 5;
	x %= 2;
	x |= 2;
	// etc.
}

void learn_conditonal_structure_flow_if() {
	int x = 17;
	// is x a even number
	if ((x % 2) == 0) cout << "OK x is a even number" << endl;

	if (x > 15) {
		x++;
		cout << "x was above 15, I increment it by 1: " << x << endl;
	} else if (x > 10) {
		cout << "x is in ]10, 15]: " << x << endl;
	} else {
		cout << "x is under or equals 10: " << x << endl;
	}

	// only to compute new value : ternary if expression
	int y = x > 15 ? 55 : 77;
	cout << "y: " << y << endl;
}

void learn_conditonal_structure_flow_switch() {
	// switch .. case
	int choice = 2;
	switch (choice) {
	case 0:
		cout << "You've chosen the door 0 : lost" << endl;
		break;
	case 1:
		cout << "You've chosen the door 1 : fortune" << endl;
		break;
	case 2:
	case 3:
		cout << "You've chosen the door 2-3 : joy" << endl;
		break;
	default:
		cout << "You've chosen the default door : surprise" << endl;
	}
}

void learn_loops_for() {
	for (int cpt = 0; cpt < 10; cpt++) {
		cout << cpt << endl;
	}

	vector<double> temperatures { 12.3, 4.5, -2.3, 45.7 };
	// oldschool for loop
	for (int i = 0; i < temperatures.size(); i++) {
		double t = temperatures[i]; // at operator
		cout << " * Temperature [" << i << "] = " << t << endl;
	}

	// foreach loop : C++11
	for (double t : temperatures) {
		cout << " # Temperature = " << t << endl;
	}
}

void learn_loops_while() {
	// while : 0 to n times
	// do .. while : 1 to n times
	int cpt = 0;  // compteur (fr) counter (en)
	while (cpt < 10) {
		cout << " * " << cpt << endl;
		cpt++;
	}

	do {
		cout << " # " << cpt << endl;
		cpt--;
	} while (cpt>=0);

}



void exercice_research_value() {
	vector<double> temperatures{ 3.3, 4.5, 6.89, 4.5, 23.4 };
	double value = 4.5;
	int indexFound;
	int startIndex = 0;
	do {
		indexFound = search(value, temperatures, startIndex);
		// display the result
		if (indexFound >= 0) {
			cout << "Index of value found: " << indexFound << endl;
			startIndex = indexFound + 1;
		} else {
			cout << "Value not found" << endl;
		}
	} while (indexFound >= 0);
}


int main() {
	// learn_hello();
	// learn_variables();
	// learn_basic_types_integer();
	// learn_basic_types_integer_aliases();
	// learn_basic_types_floating();
	// learn_basic_operators();
	// learn_assign_contracted_operators();
	// learn_conditonal_structure_flow_if();
	// learn_conditonal_structure_flow_switch();
	// learn_loops_for();
	// learn_loops_while();
	exercice_research_value();
	return EXIT_SUCCESS;
}