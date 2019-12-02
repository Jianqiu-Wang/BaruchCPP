// Implementation of class Circle
// Author: Jianqiu Wang
#include <iostream>
#include <sstream>
#include <string>
#define _USE_MATH_DEFINES
#include <cmath>

#include "ex3_point.hpp"
#include "ex3_circle.hpp"

namespace DeanWang
{
namespace CAD
{
// Default constructor of class Circle
Circle::Circle(): Shape(), m_center_point(Point(0,0)), m_radius(1)
{
}

// Construct from center point and radius
Circle::Circle(Point p, double r): Shape(), m_center_point(p), m_radius(r)
{
}

// Copy constructor
Circle::Circle(const Circle& c): Shape(c), m_center_point(c.m_center_point), m_radius(c.m_radius)
{
}

// Deconstructor of class Circle
Circle::~Circle()
{
	std::cout << "Circle Desctructor called" << std::endl;
}

// Get center point of circle
Point Circle::CenterPoint() const
{
	return m_center_point;
}

// Get radius of cricle
double Circle::Radius() const
{
	return m_radius;
}

// Set center point of Circle
void Circle::CenterPoint(const Point& new_center_point)
{
	m_center_point = new_center_point;
}

// Set radius of circle
void Circle::Radius(double new_r)
{
	m_radius = new_r;
}

// Get diameter of circle
double Circle::Diameter() const
{
	return 2 * m_radius;
}

// Get area of circle
double Circle::Area() const
{
	return M_PI * std::pow(m_radius, 2);
}

// Get diameter of circle
double Circle::Circumference() const
{
	return 2 * M_PI * m_radius;
}

// Return a string format of line by using stringstream
std::string Circle::ToString() const
{
	std::string s = Shape::ToString();
	std::stringstream ss;
	ss << "Circle centers at " << m_center_point.ToString() << " with radius " << m_radius << " (Circle" << s << ")";
	return ss.str(); 
}

// Assignment operator
Circle& Circle::operator= (const Circle& source)
{
	// Call base class assignment
	Shape::operator= (source);

	if (this == &source)
		return *this;

	m_center_point = source.m_center_point;
	m_radius = source.m_radius;

	return *this;
}

// Override << 
std::ostream& operator<< (std::ostream& os, const Circle& c)
{
	os << c.ToString();
	return os;
};

} // namespace CAD
} // namespace DeanWang