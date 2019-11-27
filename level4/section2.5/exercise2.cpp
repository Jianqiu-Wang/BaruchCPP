// Create array of pointers
// Author: Jianqiu Wang
#include <iostream>
#include "point.hpp"
int main()
{
	// array of pointers
	Point** pointer_array = new Point*[3];
	// initialize pointers
	for (int i=0; i < 3; i++)
	{
		Point* p = new Point(i, i*i);
		pointer_array[i] = p;
	}
	
	// print each elment of array	
	for (int i=0; i < 3; i++)
	{
		// print by dereference element of pointer array(which is a pointer to Point)
		std::cout << *pointer_array[i] << std::endl;
	}
	
	std::cout << sizeof(pointer_array);
	// delete each point in the array
	for (int i=0; i < 3; i++)
	{
		delete pointer_array[i];
	}
	delete[] pointer_array; // delete pointer of array
}