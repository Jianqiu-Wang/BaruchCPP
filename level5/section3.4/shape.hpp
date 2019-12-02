// Base class of Point, Line
// Author: Jianqiu Wang
#include "stdlib.h"

#include <string>
#include <iostream>
#include <sstream>

#ifndef SHAPE_HPP
#define SHAPE_HPP
namespace DeanWang
{
namespace CAD
{

class Shape
{
private:
	int id;

public:
	// constructors and deconstructor
	Shape();               // default
	Shape(const Shape& s); // copy

	// getters
	std::string ToString() const; // get string format of id
	int ID() const;				  // get id

	// overload operator =
	Shape& operator= (const Shape& other);
};

} // namespace CAD
} // namespace DeanWang
#endif // SHAPE_HPP