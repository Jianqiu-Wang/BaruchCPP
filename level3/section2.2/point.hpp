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
	~Point();

	// getter and setter
	double GetX();			   // get x coordinate
	double GetY();             // get y coordinate
	void SetX(double newxval); // set the x value
	void SetY(double newyval); // set the y value

	// accessing functions
	std::string ToString();    // return string description of point
	double DistanceOrigin();   // calculate distance to origin (0, 0)
	double Distance(Point p);  // calculate distance between two points
};
#endif //POINT_HPP