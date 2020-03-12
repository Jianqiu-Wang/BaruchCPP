// BaseOption.hpp
// Author: Jianqiu Wang
// Base Class of Option

#include <iostream>
#include <vector>

#ifndef BASEOPTION_HPP
class BaseOption
{
public:
	// constructors
    BaseOption();
 	BaseOption(const BaseOption& other);
	virtual ~BaseOption();

	BaseOption& operator = (const BaseOption& option2);
};

// global function to generate mesh array
std::vector<double> GenerateMeshArray(double begin_value, double end_value, double mesh_size);

#define BASEOPTION_HPP
#endif // BASEOPTION_HPP