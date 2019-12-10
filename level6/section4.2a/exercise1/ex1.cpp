// array_test.cpp
// Author: Jianqiu Wang
// Test templated array class

#include "point.hpp"
#include "array.hpp"

using namespace std;
using namespace DeanWang::Containers;
using namespace DeanWang::CAD;

int main()
{
    // initializes points array
    int size = 10;
    Array<Point> points(size);
	Array<Point> points2;
    for (int i=0; i < size; i++)
        points[i] = Point(i,i+1); // test override []
	
	// test GetElement
    cout << "The 1st element of points array by using GetElment: " << points.GetElement(0) << endl;
    
    // set element
    points.SetElement(0, Point(0,0));
    cout << "The 1st element of points array after setting by using operator[]: " << points[0] << endl;
	
	// test assigment operator
	points2 = points;
	cout << "size of points2: " << points2.Size() << endl;
	cout << "ID of 1st point of points: " << points[0].ID() << endl;
	cout << "ID of 1st point of points2: " << points2[0].ID() << endl;
    
	return 0;
}