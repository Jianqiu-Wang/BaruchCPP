// array_test.cpp
// Author: Jianqiu Wang
// Test array class
#include "array.hpp"

int main()
{
    Array arr1; // initialize arr1 by using defualt constructor
    Array arr2 = arr1; // copy arr1 to arr2
    Array arr3(3);  // initialize a 3-element array
    
    // test GetElement and operator []
    Point* p1 = new Point(1,1);
    Point* p2 = new Point(2,2);
    arr3.SetElement(1, *p1); 
    arr3[2] = *p2;
    
    // get elmement of arr3 one by one
    for (int i = 0; i < arr3.Size() ; i++)
    {
        std::cout << arr3.GetElement(i) << std::endl;
    }

    // get element of arr3 by using [] operator
    for (int i = 0; i < arr3.Size() ; i++)
    {
        std::cout << arr3[i] << std::endl;
    }

    arr2[0] = Point(1, 5);
    std::cout << arr2[0] << std::endl;

    // test read only [] operator
    const Array arr4;
    std::cout << arr4[0] << std::endl;
    // this assignment will fail because arr4 is a const Array
    // arr4[1] = Point(2,2);

    // test assignment
    std::cout << "assign arr3 to arr1" << std::endl;
    arr1 = arr3;
    for (int i = 0; i < arr1.Size() ; i++)
    {
        std::cout << arr1[i] << std::endl;
    }
    return 0;
}