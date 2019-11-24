// test run of point.cpp including print points and calculate distances
#include <iostream>
#include <string>
#include "point.hpp"

int main()
{
	double x1, y1;
	std::cout << "Please type value of x and y coordinates for point1:";
	std::cin >> x1 >> y1;

	// initialze point p1, p2, p3
	Point p1;
	p1.X(x1);
	p1.Y(y1);
	Point p2(x1+1, y1+1); // construct from value
	Point p3(p1);     // copy from p1

	// get string format of Point object
	std::cout << "Point p1:" << std::endl;
	std::cout << p1.ToString() << std::endl;
	std::cout << "Point p2 set by add 1 to x- and y-corordinates of p1:" << std::endl;
	std::cout << p2.ToString() << std::endl;
	std::cout << "Point p3 copied from p1:" << std::endl;
	std::cout << p3.ToString() << std::endl;
		

	// calculate distance between p1 and origin, p1 and p2(should be 0)
	std::cout << "Distance between p1 and origin: " << p1.Distance() << std::endl;
	std::cout << "Distance between p1 and p2    : " << p1.Distance(p2) << std::endl;
	
	// create a const point
	const Point cp(1.5, 3.9);
	std::cout << "A const point cp:" << std::endl;
	std::cout << cp.ToString() << std::endl;

	// set x-coordinate would generate a compile error
	// cp.X(0.3);
	// if X() is not const, compiler would never know if cp.X() would modify cp
	std::cout << "x-coordinate of cp: " << cp.X() << std::endl;
	return 0;
}