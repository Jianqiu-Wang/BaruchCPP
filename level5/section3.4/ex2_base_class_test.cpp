// Test base class Shape
// Author: Jianqiu Wang
#include "line.hpp"

#include <string>
using namespace std;
using namespace DeanWang::CAD;

int main()
{
	Shape s;                         // create shape
	Point p(10, 20);                 // create point
	Line l(Point(1,2), Point(3, 4)); // create line
	cout << s.ToString() << endl;    // print shape
	cout << p.ToString() << endl;    // print point 
	cout << l.ToString() << endl;    // print line
	cout << "Shape ID: " << s.ID() << endl;  // ID of the shape.
	cout << "Point ID: " << p.ID() << endl;  // ID of the point, this works, gives point id
	cout << "Line ID: " << l.ID() << endl;   // ID of the line, this works, gives line id
	Shape* sp;  // Create pointer to a shape variable.
	sp = &p;    // Point in a shape variable, it works
	cout << sp->ToString() << endl; // it prints ID of point
	
	// Create and copy Point p to new point.
	Point p2;
	p2 = p;
	// id copied if base class assignment operator called
	// if base class assigment operator was not called, new id will be generated.
	cout << p2 << ", " << p2.ID() << endl; 
}