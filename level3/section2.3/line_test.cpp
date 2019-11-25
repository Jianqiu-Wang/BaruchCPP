// test run of line.cpp including print line and calculate distances
#include <iostream>
#include <string>
#include "circle.hpp"

int main()
{
	// initialze point p1, p2 and Line l
	Point p1(5, 10);
    Point p2(10, 20);
    Line l(p1, p2);
    
	// get string format of Line object
	std::cout << "Print line" << std::endl;
	std::cout << l.ToString() << std::endl;
    std::cout << "Line length: " << l.Length() << std::endl;
    
    // get start point of Line l
    std::cout << "Line l starts at: " << l.Start().ToString() << std::endl;
    // try to modify returned result of l.Start()
    Point p5;
    p5 = l.Start();
    p5.X(4); // it still works
    // update line start point and end point to p3, p4
    Point p3(-5, -10);
    Point p4(-10, -20);
    l.Start(p3);
    l.End(p4);
    std::cout << "New line" << std::endl;
	std::cout << l.ToString() << std::endl;
    std::cout << "Line length: " << l.Length() << std::endl;
    return 0;
}