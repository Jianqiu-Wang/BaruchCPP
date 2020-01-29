// variant.cpp
// Author: Jianqiu Wang

#include "visitor.hpp"

#include <iostream>
#include <boost/variant.hpp>

#include "shape.hpp"
#include "point.hpp"
#include "line.hpp"
#include "circle.hpp"

using namespace std;
using namespace DeanWang::CAD;

// variant of Point, Line or Circle
typedef boost::variant<Point, Line, Circle> ShapeType;

// Returns a ShapeType by user's input
ShapeType RequestUserVariant()
{
	int shape; // shape to be input
	cout << "Enter Shape type 1(Point) 2(Line) 3(Circle):" << endl;
	
	// exception handling
	try
	{
		cin >> shape;
		if (shape != 1 && shape != 2 && shape != 3)
		{
			throw shape;
		}
	}
	catch(int x)
	{
		cout << "Should enter Shape type 1(Point) 2(Line) 3(Circle)" << endl;
	}

	// return ShapeType according to user's input
	switch(shape)
	{
		case 1:
			return Point();
		case 2:
			return Line();
		case 3:
			return Circle();
	}
	return Point(); // default return 
};

int main()
{
	ShapeType s_variant = RequestUserVariant();
	cout << s_variant << endl;	
 
	// assign s_variant to a Line
	Line l;
	try
	{
		l = boost::get<Line>(s_variant);
	}
	catch(const boost::bad_get& err)
	{
		cerr << err.what() << '\n';
	}

	Visitor v(2,2); // move coorinates by (2,2)
	s_variant = Point(0,0);
	cout << "Before visiting, point is: " << s_variant << endl;
	boost::apply_visitor(v, s_variant);
	cout << "After visiting, line is: " << s_variant << endl;

	s_variant = Line();
	cout << "Before visiting, line is: " << s_variant << endl;
	boost::apply_visitor(v, s_variant);
	cout << "After visiting, p is: " << s_variant << endl;

	s_variant = Circle();
	cout << "Before visiting, circle is: " << s_variant << endl;
	boost::apply_visitor(v, s_variant);
	cout << "After visiting, circle is: " << s_variant << endl;
    return 0;
}