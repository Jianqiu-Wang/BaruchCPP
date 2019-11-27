// Test of namespace
// Author: Jianqiu Wang
#include <iostream>
#include "point.hpp"
#include "line.hpp"
#include "circle.hpp"
#include "array.hpp"

int main()
{
	// access full namespace for Point class
	DeanWang::CAD::Point p1(1,2);
	std::cout << p1 << std::endl;

	// use declaration for class Line
	using DeanWang::CAD::Line;
	Line l = Line(); 
	std::cout << l.ToString() << std::endl;
	
	// use declaration for Containers
	using namespace DeanWang::Containers;
	Array arr;
	std::cout << arr[10].ToString() << std::endl;

	// alias for DeanWang::CAD
	namespace cad = DeanWang::CAD;
	using namespace cad;
	Circle c;
	std::cout << c.ToString() << std::endl;
}