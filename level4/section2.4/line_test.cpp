// test run of line.cpp including print line and calculate distances
#include <iostream>
#include <string>
#include "circle.hpp"

int main()
{
	// initialze point p1, p2 and Line l
	Point p1(5, 10);
    Point p2(10, 20);
    Line l1(p1, p2);
    Line l2 = l1; // assignment operator

    // print lines
    std::cout << l1 << std::endl;
    std::cout << l2 << std::endl;
	return 0;
}