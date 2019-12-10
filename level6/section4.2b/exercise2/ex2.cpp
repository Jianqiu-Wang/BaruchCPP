// array_test.cpp
// Author: Jianqiu Wang
// Test templated array class

#include "point.hpp"
#include "numeric_array.hpp"

using namespace std;
using namespace DeanWang::Containers;
using namespace DeanWang::CAD;

int main()
{
 	cout << "------------------" << endl;
	cout << "Test int array" << endl;   
	NumericArray<int> arr1(10);   // initializa an NumericArray
	for (int i=0; i < arr1.Size(); i++)
	{
		arr1[i] = i * i;
	}
	NumericArray<int> arr2 = arr1;  // test copy constructor
	NumericArray<int> arr3 = arr1 + arr2;  // test operator+ and operator=
	NumericArray<int> arr4 = arr2 * 2; // test operator* and operator=
	
	for (int i=0; i < arr3.Size(); i++)
	{
		cout  <<arr1[i] <<"|" << arr2[i] <<"|"<< arr3[i]<< "|" << arr4[i] << endl;
	}
    cout << "Dot product of arr1 and arr2: " << arr1.DotProduct(arr2) << std::endl;

	cout << "------------------" << endl;
	cout << "Test Point array" << endl;
	// try to create a Point array
	NumericArray<Point> point_arr1(10);
	for (int i=0; i < point_arr1.Size(); i++)
	{
		point_arr1[i] = Point(i,i);
	}
	NumericArray<Point> point_arr2 = NumericArray<Point>(point_arr1);
	for (int i=0; i < point_arr2.Size(); i++)
	{
		cout << point_arr2[i] << endl;
	}
	NumericArray<Point> point_arr3 = point_arr1 + point_arr2;  // test operator+ and operator=
	NumericArray<Point> point_arr4 = point_arr2 * 2; // test operator* and operator=
	for (int i=0; i < arr3.Size(); i++)
	{
		cout <<point_arr1[i]  << point_arr2[i] << point_arr3[i] << point_arr4[i] << endl;
	}
	// DotProduct will fail since Point do not have a operator*(const Point& p) 
	// cout << "Dot product of arr1 and arr2: " << point_arr1.DotProduct(point_arr2) << std::endl;

	// Conclusion: We can create a NumericArray<Point> class, and use all member functions except DotProduct
	// To use NumericArray, the type T can only be numeric  satisfying inner product will generate another numeric value
	return 0;
}