// Shape class
#include "shape.hpp"
namespace DeanWang
{
namespace CAD
{
// Default constructor: initializes id using a random number
Shape::Shape(): id(rand())
{
}

// Copy constructor: create Shape with same id
Shape::Shape(const Shape& s): id(s.id)
{
}

// Return id as string
std::string Shape::ToString() const
{
	std::stringstream ss;
	ss << "ID: " << id;
	return ss.str();
}

// Return id
int Shape::ID() const
{
	return id;
}

// Overload operator =
Shape& Shape::operator=(const Shape& other)
{
	if (this == &other)
		return *this;

	id = other.id;
	return *this;
}
}
}