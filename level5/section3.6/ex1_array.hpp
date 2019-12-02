// array.hpp
// Author: Jianqiu Wang
// Manages memory for array of point
#include "point.hpp"

#ifndef EX1_ARRAY_HPP
#define EX1_ARRAY_HPP

namespace DeanWang
{
namespace Containers
{
class Array
{
private:
	CAD::Point* m_data; // a dynamic C array of Point objects
	int m_size;    // size of array
public:
	// constructor and deconstructor
	Array();         // default constructor
	Array(int size); // constructor by giving number of elements
	Array(const Array& arr); // copy constructor
	~Array();                // destructor

	// getter and setter
	int Size() const; // return size of array
	void SetElement(int index, const CAD::Point& p); // set element at index i with Point p
	CAD::Point& GetElement(int index) const; 		// get element at index 
	CAD::Point& operator [] (int index); 			// override operator [] 
	const CAD::Point& operator [] (int index) const; // override operator [] with const, read only
	Array& operator= (const Array& source);     // assignment operator
};

} // namespace Containers
} // namespace DeanWang
#endif // EX1_ARRAY_HPP
