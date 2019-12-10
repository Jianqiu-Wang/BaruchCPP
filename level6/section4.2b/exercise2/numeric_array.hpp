// numeric_array.hpp
// Author: Jianqiu Wang
// Inherit from generic class Array

#include "array.hpp"

#ifndef NUMERIC_ARRAY_HPP
#define NUMERIC_ARRAY_HPP

namespace DeanWang
{
namespace Containers
{
template <typename T>
class NumericArray: public Array<T>
{
private:
	int m_size;
	T* m_data;
public:
    // constructor and deconstructor
    NumericArray();           // default
    NumericArray(int size);   // construct array with size
    NumericArray(const NumericArray<T>& source); // copy
	virtual ~NumericArray();  // destructor

	T DotProduct(const NumericArray<T>& arr2) const;  // calculate dot product

	// operator overload
	NumericArray<T>& operator= (const NumericArray<T>& source);
	NumericArray<T> operator+ (const NumericArray<T>& source) const;
	NumericArray<T> operator* (double factor) const;
};
}
}
#ifndef NUMERIC_ARRAY_CPP 
#include "numeric_array.cpp"
#endif // NUMERIC_ARRAY_CPP
#endif // NUMERIC_ARRAY_HPP