// test run of point.cpp including print points and calculate distances
#include <iostream>
#include <string>
#include "point.hpp"

int main()
{
	using namespace DeanWang::CAD;
	// initialze point p1, p2
	Point p1(4, 5);
	Point p2(6, 7);
	Point p3(4, 5);

	// negate p1
	std::cout << "negate "<< p1 << " gives: " <<  -p1 << std::endl;
	// scale p1
	std::cout << "scale " << p1 << "by 2 gives " << p1*2 << std::endl;
	// add p1
	std::cout << "add " << p2 << " to " << p1 << " gives " << p1 + p2 << std::endl;
	// test equally compare operater
	std::cout << p1 << "==" << p2 << " gives " << (p1 == p2) << std::endl;
	std::cout << p1 << "==" << p3 << " gives " << (p1 == p3) << std::endl;
	// assign p2 to p4
	Point p4 = p2;
	std::cout << "assign " << p2 << " to p4 gives: p4 = " << p4 << std::endl;
	// scale p4 and assign
	std::cout << "scale p4 by 0.5 and assign gives p4 = " << (p4 *= 0.5) << std::endl;

	// test single input double constructor
	// implicit conversion used so it will compile
	// after "explicit" added, will generate a compile error:
	// invalid operands to binary expression ('Point' and 'double')
	Point p(1.0, 1.0);
	if (p==(Point)1.0) // use conversion operator explicitly
		std::cout << "Equal!" << std::endl;  
	else 
		std::cout << "Not equal" << std::endl;

	return 0;
}