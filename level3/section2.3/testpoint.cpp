// test run of point.cpp including print points and calculate distances
#include <iostream>
#include <string>
#include "point.hpp"

int main()
{
	double x1, y1;
	std::cout << "Please type value of x and y coordinates for point1:";
	std::cin >> x1 >> y1;

	// initialze point p1, p2
	Point p1(x1, y1); // construct from value
	Point p2(p1);     // copy from p1

	// get string format of Point object
	std::cout << "We have following points:" << std::endl;
	std::cout << p1.ToString() << std::endl;

	// calculate distance between p1 and origin, p1 and p2(should be 0)
	std::cout << "Distance between p1 and origin: " << p1.Distance() << std::endl;
	std::cout << "Distance between p1 and p2    : " << p1.Distance(p2) << std::endl;
	
	// create a const point
	const Point cp(1.5, 3.9);
	// set x-coordinate would generate a compile error
	// cp.X(0.3);
	// if X() is not const, compiler would never know if cp.X() would modify cp
	std::cout << cp.X() << std::endl;
	return 0;
}