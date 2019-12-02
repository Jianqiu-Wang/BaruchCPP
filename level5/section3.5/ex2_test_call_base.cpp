// Test base class Shape
// Author: Jianqiu Wang
#include "line.hpp"
#include "circle.hpp"

#include <string>
using namespace std;
using namespace DeanWang::CAD;

int main()
{
	Point p(1, 2);                   // create point
	Line l(p, Point(3, 4));          // create line
	Circle c(p, 10);                 // create circle
	// ID can be printed now
	cout << p.ToString() << endl;    // print point 
	cout << l.ToString() << endl;    // print line
	cout << c.ToString() << endl;    // print circle	
}