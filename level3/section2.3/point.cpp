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
	// std::cout << "----Naive constructor called." << std::endl;
}

// Copy constructor
Point::Point(const Point& p)
{
	// std::cout << "----COPY constructor called." << std::endl;
	m_x = p.m_x;
	m_y = p.m_y;
}

// Constructor giving coordinates x and y
Point::Point(double x, double y)
{
	// std::cout << "----Constructor given values" << std::endl;
	m_x = x;
	m_y = y;
}

// Deconstructor of class Point
Point::~Point()
{
	// At the beginning, destructor was called one more time than constructor 
	// before modification; 
	// When calling distance function:
	// If call by value, a point was copied, implicitly called copy constructor once.
	// If call by reference, no copy constructor will be called.
	// std::cout << "----Deconstructor called." << std::endl;
}

// // Set x coordinate of point 
// void Point::X(double newxval)
// {
// 	m_x = newxval;
// }

// // Set y coordinate of point 
// void Point::Y(double newyval)
// {
// 	m_y = newyval;
// }

// Return a string format of (x, y) by using stringstream
std::string Point::ToString() const
{
	std::stringstream ss;
	ss << "Point(" << m_x << ", " << m_y << ")";
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
	// would generate compile error: assignment of member ‘Point::m_x’ in read-only object
	// p.m_x = p.m_x + 1;
	return std::sqrt(x_square + y_square);
}