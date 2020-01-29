// Implementation of class Point
// Author: Jianqiu Wang
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

#include "point.hpp"

namespace DeanWang
{
namespace CAD
{
// Constructor of class Point
Point::Point(): Shape(), m_x(0), m_y(0)
{
}

// Copy constructor
Point::Point(const Point& p): Shape(p), m_x(p.m_x), m_y(p.m_y)
{
}

// Constructor giving coordinates x and y
Point::Point(double x, double y): Shape(), m_x(x), m_y(y)
{
}

// Construct from same x- and y- coordinate
Point::Point(double xy): m_x(xy), m_y(xy)
{
}
// Destructor of class Point
Point::~Point()
{
	std::cout << "Destruct Point" << std::endl;
}

// Get x coordinate of point
double Point::X() const
{
	return m_x;
}

// Get y coordinate of point
double Point::Y() const
{
	return m_y;
}

// Set x coordinate of point 
void Point::X(double newxval)
{
	m_x = newxval;
}

// Set y coordinate of point 
void Point::Y(double newyval)
{
	m_y = newyval;
}

// Return a string format of (x, y) by using stringstream
std::string Point::ToString() const
{
	// call base class method
	std::string s = Shape::ToString();
	std::stringstream ss;
	ss << "(" << m_x << "," << m_y << ")" << " (Point" << s << ")";
	return ss.str(); 
}

// Calculates distance to the origin (0, 0)
double Point::Distance() const
{
	return std::sqrt(m_x*m_x + m_y*m_y);
}

// Calculates distance to point p
double Point::Distance(const Point& p) const
{
	// calcuate square of x and y difference first
	double x_square = std::pow(p.m_x-m_x, 2);
	double y_square = std::pow(p.m_y-m_y, 2);
	return std::sqrt(x_square + y_square);
}

// Draw point
void Point::Draw() const
{
	std::cout << "Draw point" << std::endl;
}

// Negate the coordinates
Point Point::operator- () const
{
	return Point(-m_x, -m_y);
}

// Scale the coordinates.
Point Point::operator* (double factor) const
{
	return Point(factor*m_x, factor*m_y);
}

// Add coordinates.
Point Point::operator+ (const Point& p) const
{
	return Point(m_x+p.m_x, m_y+p.m_y);
}

// Equally compare operator. 
bool Point::operator == (const Point& p) const
{
	return (m_x == p.m_x && m_y == p.m_y);
}

// Assignment operator.
Point& Point::operator= (const Point& source)
{
	// Call base class assignment
	Shape::operator= (source);

	if (this == &source) // assign to myself
		return *this;

	m_x = source.m_x;
	m_y = source.m_y;

	return *this;
}

// Scale the coordinates & assign
Point& Point::operator *= (double factor)
{
	Point temp = (*this) * factor; // call operator *
	*this = temp;
	
	return *this;
}

// Ostream << operator
std::ostream& operator << (std::ostream& os, const Point& pt)
{
	os << '(' << pt.m_x << "," << pt.m_y << ")";
	return os;
}
} // namespace CAD
} // namespace DeanWan