// point.hpp
// Defines class Point with privated member x- and y-coordinates
#ifndef POINT_HPP
#define POINT_HPP

// Class Point: a point in geometric with x- and y-coordincates
// Example:
//   Point p1, p2;
//   p1.SetX(2);
//   p1.SetY(3);
//   p2.SetX(1);
//   p2.SetY(3);    // assign coordinates of p1, p2
//   p1.ToString(); // string of point
//   p1.DistanceOriging(); // calcuate distance to origin
//   p1.Distance(p2);
class Point
{
private:
	// x- and y- coordinates of point
	double m_x; 
	double m_y;

public:
	// constructor and deconstructor
	Point();
	Point(const Point& p);      // copy constructor
	Point(double x, double y);  // construct from coordinates directly
	~Point();

	// getter and setter
	double X() const;       // get x coordinate
	double Y() const;       // get y coordinate
	inline void X(double newxval) {m_x = newxval;}; // set the x value
	inline void Y(double newyval) {m_y = newyval;}; // set the y value

	// accessing functions
	std::string ToString() const;    // return string description of point
	double Distance() const;         // calculate distance to origin (0, 0)
	double Distance(const Point& p) const;  // calculate distance between two points
};

// Normal inline for getters
inline double Point::X() const
{
	return m_x;
}

inline double Point::Y() const
{
	return m_y;
}
#endif //POINT_HPP