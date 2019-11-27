// circle.hpp
// Defines class Circle with privated member center point and m_radius
#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "point.hpp"
#include "line.hpp"
// Class Circle: a circle is defined by a center point and a radius
// Example:
//   c = Circel(Point(0,0), 5) // a circle centered at (0,0) with radius 5
class Circle
{
private:
	Point m_center_point;  // center point
	double m_radius;     // radius

public:
	// constructors and deconstructor
	Circle();                   // default constructor
    Circle(Point p, double r);  // construct from centor point and radius
	Circle(const Circle& c);    // copy constructor
    ~Circle();                  // deconstructor

	// getter and setter
	Point CenterPoint() const; // get center point of circle
	double Radius() const;     // get radius of cirlce
	void CenterPoint(const Point& new_center_point); // set center point
	void Radius(double new_r); // set radius of cirlce

	// accessing functions
	double Diameter() const;      // return diameter of cirlce
	double Area() const;          // return area of circle
	double Circumference() const; // return circumference of circle
	std::string ToString() const; // return string description of circle

	// override operator
	Circle& operator = (const Circle& source); // assignment 	
};

// override << 
std::ostream& operator << (std::ostream& os, const Circle& c);
#endif //LINE_HPP