// array_test.cpp
// Author: Jianqiu Wang
// Test point array class

#include "point.hpp"
#include "point_array.hpp"

using namespace std;
using namespace DeanWang::Containers;
using namespace DeanWang::CAD;

int main()
{
	PointArray arr1;   // initializa an NumericArray
	cout << "---------------" << endl;
	cout << "Default arr1" << endl;
	for (int i=0; i < arr1.Size(); i++)
	{
		cout << arr1[i] << endl;
	}
	for (int i=0; i < arr1.Size(); i++)
	{
		arr1[i] = Point(i,i);
	}
	
	cout << "Copy arr1 to arr2" << endl;
	PointArray arr2(arr1); // copy 
	for (int i=0; i < arr2.Size(); i++)
	{
		cout << arr2[i] << endl;
	}
	
	PointArray arr3;
	arr3 = arr2; // assign arr3 with arr2
	cout << "Test operator =" << endl;
	for (int i=0; i < arr2.Size(); i++)
	{
		cout << arr2[i] << endl;
	}
	
	// Test point distances in PointArray
	cout << arr3.Length() << endl;
	PointArray arr4(1);
	cout << arr4.Length() << endl;  // should output 0
	return 0;
}