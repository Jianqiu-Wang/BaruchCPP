// array_test.cpp
// Author: Jianqiu Wang
// Test array class
#include "array.hpp"

using namespace DeanWang;

int main()
	{
	Containers::Array arr1(5); // initialize arr1 by using defualt constructor
	for (int i = 0; i < arr1.Size() ; i++)
	{
		arr1[i] = CAD::Point(5,5);
	}

	// try to access 999, should catch ArrayException
	try
	{
		arr1.GetElement(999);
	}
	catch(Containers::ArrayException& e)
	{
		std::cout << e.GetMessage() << std::endl;
	}
	catch(...)
	{
		std::cout << "An unhandled exception has occurred" << std::endl;
	}
    return 0;
}