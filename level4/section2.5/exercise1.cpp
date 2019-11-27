// Dynamically create objects
// Author: Jianqiu Wang
#include <iostream>
#include <string>
#include "point.hpp"

int main()
{

	// initialze point p1, p2, p3
	Point* p3 = new Point;
	Point* p2 = new Point(1,2);
    Point* p1 = new Point(*p2);

	// calculate distance between p2 and origin, p2 and p3(should be 0)
	std::cout << "Distance between p2 and origin: " << (p1->Distance()) << std::endl;
	std::cout << "Distance between p3 and p2    : " << (p1->Distance(*p2)) << std::endl;
	
	// delete Point object
	delete p1;
	delete p2;
	delete p3;	
	// create an array of points, read size from input
	int length;
	std::cout << "Please type length of array you want:";
	std::cin >> length;
	//Point point_array[length*sizeof(Point)];
	// array of points
	Point* point_array = new Point[length]; // cannot use other constructors for Point object in array
	delete[] point_array; // delete array

	return 0;
}