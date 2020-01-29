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
	virtual ~Shape();      // desctructor

	// getters
	virtual std::string ToString() const; // get string format of id
	int ID() const;				  // get id

	virtual void Draw() const = 0; // every derived shape should implement this
	void Print() const;            // make polymorphic

	// overload operator =
	Shape& operator= (const Shape& other);
};
} // namespace CAD
} // namespace DeanWang
#endif // SHAPE_HPP