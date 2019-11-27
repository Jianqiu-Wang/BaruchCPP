// line.hpp
// Author: Jianqiu Wang
// Put Line in namespace DeanWang::CAD
#ifndef LINE_HPP
#define LINE_HPP
#include <string>
#include "point.hpp"
using namespace std;
namespace DeanWang
{
	namespace CAD
	{
		// Class Line: a line defines by 2 points
		class Line
		{
		private:
			Point start_point; 
			Point end_point;

		public:
			// constructors and deconstructor
			Line();                    // default constructor
			Line(Point p1, Point p2);  // construct from start and end points
			Line(const Line& l);       // copy constructor
			~Line();                   // deconstructor

			// getter and setter
			const Point& Start() const;  // get start point of line
			const Point& End() const;    // get end point of line
			void Start(const Point& p1); // set start point
			void End(const Point& p2);   // set end point

			// accessing functions
			std::string ToString() const; // return string description of point
			double Length() const;        // calculate distance to origin (0, 0)

			// operator overriding
			Line& operator = (const Line& source); // assignment operator
			// ostream << override using friend, still a global function, not a member function
			friend ostream& operator << (ostream& os, const Line& l); 
		};
	}
}
#endif // LINE_HPP