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
    Array<int> intArray1;
	Array<int> intArray2;
	Array<double> doubleArray;
	// 3 arrays will be initialized with default 10
	cout << intArray1.DefaultSize() << endl;   // 10
	cout << intArray2.DefaultSize() << endl;   // 10
	cout << doubleArray.DefaultSize() << endl; // 10
	intArray1.DefaultSize(15);
	// Array<int> default size changed to 15
	// Array<double> is a class different from Array<int>, so default size keep unchanged
	cout << intArray1.DefaultSize() << endl;    // 15
	cout << intArray2.DefaultSize() << endl;    // 15
	cout << doubleArray.DefaultSize() << endl;  // 10
	
	return 0;
}