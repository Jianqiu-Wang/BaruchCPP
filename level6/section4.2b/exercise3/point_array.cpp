// point_array.hpp
// Author: Jianqiu Wang
// Concreate inheritance from class Array

#include "point_array.hpp"

using namespace std;
using namespace DeanWang::CAD;

namespace DeanWang
{
namespace Containers
{
// Default constructor
PointArray::PointArray(): Array<Point>()
{
}

// Constructor 2
PointArray::PointArray(int arr_length): Array<Point>(arr_length)
{
}

// Copy constructor 
PointArray::PointArray(const PointArray& point_arr): Array<Point>(point_arr)
{
}

// Destructor
PointArray::~PointArray()
{
}

// Assignment operator
PointArray& PointArray::operator= (const PointArray& source)
{
	if (this == &source)
		return *this;

	Array::operator= (source); // call base operator	
	return *this;
}

// calculate total length between points
double PointArray::Length() const
{
	int size = (*this).Size();
	if (size == 1)
	{
		return 0;
	}
	else
	{
		double length = 0;
		for (int i=1; i < size; i++)
		{
			length = length + (*this)[i-1].Distance((*this)[i]);
		}	
		return length;
	}
}

} // namespace Containers
} // namespace DeanWang
