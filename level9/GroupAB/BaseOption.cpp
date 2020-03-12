// BaseOption.cpp
// Author: Jianqiu Wang
// Base Class of Option

#include "BaseOption.hpp"

// Generate mesh array between values giving mesh size
// if mod(end_value - begin_value, mesh_size) != 0
// will not push end_value into array 
std::vector<double> GenerateMeshArray(double begin_value, double end_value, double mesh_size)
{
	std::vector<double> mesh_array;
	double value = begin_value;
	while (value <= end_value)
	{
		mesh_array.push_back(value);
		value += mesh_size;
	}
	return mesh_array;
}

// Default constructor
BaseOption::BaseOption()
{
}

// Copy constructor
BaseOption::BaseOption(const BaseOption& other)
{
}


BaseOption::~BaseOption()
{
}

BaseOption& BaseOption::operator= (const BaseOption& option2)
{
	return *this;
}

