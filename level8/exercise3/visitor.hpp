// visitor.hpp
// Author: Jianqiu Wang
// Derived class of boost::static_visitor<T>

#include <boost/variant/static_visitor.hpp>

#include "point.hpp"
#include "line.hpp"
#include "circle.hpp"

using namespace DeanWang::CAD;

#ifndef VISITOR_HPP
#define VISITOR_HPP

namespace DeanWang
{
namespace CAD
{
// class Visitor
class Visitor:public boost::static_visitor<>
{
private:
	double m_dx;
	double m_dy;

public:
	Visitor(); // default constructor
	Visitor(double dx, double dy); // construct from dx and dy
	Visitor(const Visitor& v);

	Visitor& operator= (const Visitor& other); // overload =
    void operator() (Point& p) const; // visit a point 
	void operator() (Line& l) const; // visit a line	
	void operator() (Circle& c) const; // visit a circle
};
} // namespace CAD
} // namespace DeanWang
#endif // VISITOR_HPP