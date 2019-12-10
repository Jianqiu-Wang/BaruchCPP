// point_array.hpp
// Author: Jianqiu Wang
// Concreate inheritance from class Arra y s

#include "array.hpp"
#include "point.hpp"

using namespace DeanWang::CAD;

#ifndef POINT_ARRAY_HPP
#define POINT_ARRAY_HPP

namespace DeanWang
{
namespace Containers
{
class PointArray: public Array<Point>
{
private:
	Point* m_data;
	int m_size;

public:
	// constructors and destructor
	PointArray();
	PointArray(int arr_length);
	PointArray(const PointArray& point_arr);
	~PointArray();

	// assigment operator
	PointArray& operator= (const PointArray& source);

	// access function
	double Length() const; // total length between points in the array
};
}
}
#endif // POINT_ARRAY_HPP