// point.hpp
// Author: Jianqiu Wang
// Put class point into namespace DeanWang::CAD
#ifndef POINT_HPP
#define POINT_HPP

#include <string>
using namespace std;
namespace DeanWang
{
	namespace CAD
	{
		// Class Point: a point in geometric with x- and y-coordincates
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
			explicit Point(double xy);  // construct from same x- and y- coordinates
			~Point();

			// getter and setter
			double X() const;       // get x coordinate
			double Y() const;       // get y coordinate
			void X(double newxval); // set the x value
			void Y(double newyval); // set the y value

			// accessing functions
			std::string ToString() const;    // return string description of point
			double Distance() const;         // calculate distance to origin (0, 0)
			double Distance(const Point& p) const;  // calculate distance between two points

			// operator overriding
			Point operator - () const;               // negate the coordinates 
			Point operator * (double factor) const;  // scale the coordinates
			Point operator + (const Point& p) const; // add coordinates
			bool operator == (const Point& p) const; // equally compare operator
			Point& operator = (const Point& source); // assignment operator
			Point& operator *= (double factor);      // scale the coordinates & assign
		};
	}
}

// Ostream << operator
ostream& operator << (ostream& os, const DeanWang::CAD::Point& pt);
#endif // POINT_HPP