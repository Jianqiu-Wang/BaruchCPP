// test run of point.cpp including print points and calculate distances
#include <iostream>
#include <string>
#include "point.hpp"

int main()
{
	double x1, y1, x2, y2;
	std::cout << "Please type value of x and y coordinates for point1:";
	std::cin >> x1 >> y1;
	std::cout << "Please type value of x and y coordinates for point2:";
	std::cin >> x2 >> y2;

	// initialze point p1,p2 and set x, y coordinates
	Point p1, p2;
	p1.SetX(x1);
	p1.SetY(y1);
	p2.SetX(x2);
	p2.SetY(y2);

	// get string format of Point object
	std::cout << "We have following points:" << std::endl;
	std::cout << p1.ToString() << std::endl;
	std::cout << p2.ToString() << std::endl;

	// calculate several distances
	std::cout << "Cacluate distances:" << std::endl;
	std::cout << "Distance between p1 and origin: " << p1.DistanceOrigin() << std::endl;
	std::cout << "Distance between p2 and origin: " << p2.DistanceOrigin() << std::endl;
	std::cout << "Distance between p1 and p2:     " << p1.Distance(p2) << std::endl;
	return 0;
}