// array_test.cpp
// Author: Jianqiu Wang
// Test array class
#include "ex1_array.hpp"

using namespace DeanWang::Containers;
using namespace DeanWang::CAD;

int main()
	{
	Array arr1(5); // initialize arr1 by using defualt constructor
	// get element of arr3 by using [] operator
	for (int i = 0; i < arr1.Size() ; i++)
	{
		arr1[i] = Point(5,5);
	}

	// try access arr1[-1], returns terminating with uncaught exception of type int
	try
	{
		arr1.GetElement(999);
	}
	catch(int err)
	{
		if (err == -1)
			std::cout << "Index error" << std::endl;
	}
	catch(...)
	{
		std::cout << "An unhandled exception has occurred" << std::endl;
	}

    return 0;
}