// test run of circle.cpp
// g++ circle_test.cpp circle.cpp line.cpp point.cpp -o circle
#include <iostream>
#include <string>
#include "circle.hpp"

int main()
{
	// initialze point p1, p2 and Line l
	Point p1(5, 10);
	double r1 = 10;
	Circle c1(p1, r1);
    
	// get string format of Line object
	std::cout << "Print Circle" << std::endl;
	std::cout << c1.ToString() << std::endl;
	std::cout << "Diameter:     " << c1.Diameter() << std::endl;
	std::cout << "Area:         " << c1.Area() << std::endl;
	std::cout << "Circumference:" << c1.Circumference() << std::endl;
     
	// update circle centered at p2 with radius r2
    Point p2(-5,-10);
    double r2 = 5;
	c1.CenterPoint(p2);
	c1.Radius(r2);
	std::cout << "New Circle" << std::endl;
	std::cout << c1.ToString() << std::endl;
	std::cout << "Diameter:     " << c1.Diameter() << std::endl;
	std::cout << "Area:         " << c1.Area() << std::endl;
	std::cout << "Circumference:" << c1.Circumference() << std::endl;
	return 0;
}