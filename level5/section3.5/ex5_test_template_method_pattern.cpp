// Test template method pattern
// Author: Jianqiu Wang
#include <string>

#include "line.hpp"
#include "circle.hpp"

using namespace DeanWang::CAD;

int main()
{
	Point p(10, 20);                         // create point
	Line l(Point(1.0, 2.5), Point(3.4, 5.2));// create line
	Circle c(Point(1,2), 10);                // create circle
	// will call Print() method in base class, then it calls ToString() method in derived classes
	p.Print();
	l.Print();
	c.Print();
}