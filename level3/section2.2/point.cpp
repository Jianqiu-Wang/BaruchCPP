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

// Deconstructor of class Point
Point::~Point()
{
}

// Get x coordinate of point
double Point::GetX()
{
	return m_x;
}

// Get y coordinate of point
double Point::GetY()
{
	return m_y;
}

// Set x coordinate of point 
void Point::SetX(double newxval)
{
	m_x = newxval;
}

// Set y coordinate of point 
void Point::SetY(double newyval)
{
	m_y = newyval;
}

// Return a string format of (x, y) by using stringstream
std::string Point::ToString()
{
	std::stringstream ss;
	ss << "Point(" << m_x << ", " << m_y << ")";
	return ss.str(); 
}

// Calculates distance to the origin (0, 0)
double Point::DistanceOrigin()
{
	return std::sqrt(m_x*m_x + m_y*m_y);
}

// Calculates distance to point p
double Point::Distance(Point p)
{
	// calcuate square of x and y difference first
	double x_square = std::pow(p.m_x-m_x, 2);
	double y_square = std::pow(p.m_x-m_y, 2);
	return std::sqrt(x_square + y_square);
}
