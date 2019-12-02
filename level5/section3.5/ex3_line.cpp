// Implementation of class Line
// Author: Jianqiu Wang
#include <iostream>
#include <sstream>
#include <string>

#include "ex3_line.hpp"

namespace DeanWang
{
namespace CAD
{
// Default constructor of class Line
Line::Line(): Shape(), start_point(Point(0,0)), end_point(Point(0,0))
{
}

// Construct from start and end point
Line::Line(Point p1, Point p2): Shape(), start_point(p1), end_point(p2)
{
}

// Copy constructor
Line::Line(const Line& l): Shape(), start_point(l.start_point), end_point(l.end_point)
{
}

// Destructor of class Line
Line::~Line()
{
	std::cout << "Line Destructor called" << std::endl;
}

// Get start point of line
const Point& Line::Start() const
{
	return start_point;
}

// Get end point of line
const Point& Line::End() const
{
	return end_point;
}

// Set start point of Line
void Line::Start(const Point& p1)
{
	start_point = p1;
}

// Set end point of Line
void Line::End(const Point& p2)
{
	end_point = p2;
}

// Return a string format of line by using stringstream
std::string Line::ToString() const
{
	std::string s = Shape::ToString();
	std::stringstream ss;
	ss << "Line starts at " << start_point.ToString() << ", ends at " << end_point.ToString() << " (Line" <<s <<")";
	return ss.str(); 
}

// Calculates length of line
double Line::Length() const
{
	return start_point.Distance(end_point);
}

// Overload assignment operator
Line& Line::operator= (const Line& source)
{
	// Call base class assignment
	Shape::operator= (source);

	if (this == &source)
		return *this;

	start_point = source.start_point;
	end_point = source.end_point;

	return *this;
}

// Ostream <<
std::ostream& operator << (std::ostream& os, const Line& l)
{
	os << "Line starts at " << l.start_point << ", ends at " << l.end_point;
	return os;
}
} // namespace CAD
} // namespace DeanWang