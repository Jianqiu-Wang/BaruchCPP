// exercise1, test of colon syntax
// Author: Jianqiu Wang
#include "point.hpp"
#include "line.hpp"
#include "circle.hpp"

using namespace DeanWang::CAD;

int main()
{
	// Before colon syntax applied, point constructor was called twice, 
	// assignment operator was called twice, deconstructor was called 4 times
	// After colon syntax applied, constructor and deconstructor were called 
	// twice for each
	Line l;
	
	Circle c; // only one constructor and deconstructor were called
	return 0;
}