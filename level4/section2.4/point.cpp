// Implementation of class Point
// Author: Jianqiu Wang
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include "point.hpp"

// Constructor of class Point
Point::Point()
{
}

// Copy constructor
Point::Point(const Point& p)
{
	m_x = p.m_x;
	m_y = p.m_y;
}

// Constructor giving coordinates x and y
Point::Point(double x, double y)
{
	m_x = x;
	m_y = y;
}

// Construct from same x- and y- coordinate
Point::Point(double xy)
{
	m_x = xy;
	m_y = xy;
}
// Deconstructor of class Point
Point::~Point()
{
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
	std::stringstream ss;
	ss << "(" << m_x << "," << m_y << ")";
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

// Negate the coordinates
Point Point::operator - () const
{
	return Point(-m_x, -m_y);
}

// Scale the coordinates.
Point Point::operator * (double factor) const
{
	return Point(factor*m_x, factor*m_y);
}

// Add coordinates.
Point Point::operator + (const Point& p) const
{
	return Point(m_x+p.m_x, m_y+p.m_y);
}

// Equally compare operator. 
bool Point::operator == (const Point& p) const
{
	if (m_x == p.m_x & m_y == p.m_y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Assignment operator.
Point& Point::operator = (const Point& source)
{
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