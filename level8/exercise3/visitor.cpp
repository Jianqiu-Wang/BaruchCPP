// visitor.hpp
// Author: Jianqiu Wang
// Derived class of boost::static_visitor<T>

#include "visitor.hpp"

namespace DeanWang
{
namespace CAD
{
// Default constructor
Visitor::Visitor(): m_dx(0), m_dy(0)
{
};

// Construct from shift dx and dy
Visitor::Visitor(double dx, double dy):m_dx(dx), m_dy(dy)
{
};

// Copy constructor
Visitor::Visitor(const Visitor& v): m_dx(v.m_dx), m_dy(v.m_dy)
{
}

// Overload =
Visitor& Visitor::operator= (const Visitor& other)
{
	if (this == &other)
		return *this;

	m_dx = other.m_dx;
	m_dy = other.m_dy;
	return *this;
}

// visit a point
void Visitor::operator() (Point& p) const
{
	p.X(p.X() + m_dx);
	p.Y(p.Y() + m_dy);
}

// visit a line
void Visitor::operator() (Line& l) const
{
	Point p(m_dx, m_dy);
	l.Start(l.Start() + p);
	l.End(l.End() + p);
}

// visit a circle
void Visitor::operator() (Circle& c) const
{
	c.CenterPoint(c.CenterPoint() + Point(m_dx, m_dy));
}
} // namespace CAD
} // namespace DeanWang