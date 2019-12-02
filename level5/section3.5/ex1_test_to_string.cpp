// Test base class Shape
// Author: Jianqiu Wang
#include <string>

#include "point.hpp"

using namespace std;
using namespace DeanWang::CAD;

int main()
{
	Point p(10, 20);                 // create point
	Shape* sp;  // Create pointer to a shape variable.
	sp = &p;    // Point in a shape variable
	// it prints Coordinates of Point, calls ToString method in class
	cout << sp->ToString() << endl; 
}