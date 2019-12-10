// numeric_array.hpp
// Author: Jianqiu Wang
// Inherit from generic class Array

#include "array.hpp"
#include "numeric_array.hpp"
#include "array_exception.hpp"

using namespace DeanWang::Containers;

namespace DeanWang
{
namespace Containers
{
// Default constructor    
template <typename T>
NumericArray<T>::NumericArray(): Array<T>()
{
}

// Constructor with size 
template <typename T>
NumericArray<T>::NumericArray(int size): Array<T>(size)
{
}

// Copy constructor
template <typename T>
NumericArray<T>::NumericArray(const NumericArray<T>& source): Array<T>(source), m_data(source.m_data), m_size(source.m_size)
{
}

// Destructor
template <typename T>
NumericArray<T>::~NumericArray()
{
}


// operator=
template <typename T>
NumericArray<T>& NumericArray<T>::operator= (const NumericArray<T>& source)
{
	if (this == &source)
		return *this;
	// call base class operator
	Array<T>::operator= (source);
	return *this;
}


// operator+
template <typename T>
NumericArray<T> NumericArray<T>::operator+ (const NumericArray<T>& source) const
{
	int size1 = this->Size();
	int size2 = source.Size();

	if (size1 != size2)
	{
		throw SizeInequalityException(size1, size2);
	}
	else
	{
		NumericArray<T> res = NumericArray<T>(size1);
		for (int i=0; i < size1; i++)
		{
			res[i] = (*this)[i] + source[i];
		}
		return res;
	}
}

// operator*, scale by a factor
template <typename T>
NumericArray<T> NumericArray<T>::operator* (double factor) const
{
	NumericArray<T> res = NumericArray<T>(this->Size());
	for (int i=0; i < (this->Size()); i++)
	{
		res[i] = (*this)[i] * factor;
	}
	return res;
}


// calculate dot product
template <typename T>
T NumericArray<T>::DotProduct(const NumericArray<T>& arr2) const
{
	if (this->Size() != arr2.Size())
	{
		throw SizeInequalityException(m_size, arr2.m_size);
	}
	else
	{
		double dot_product = 0;
		for (int i=0; i < arr2.Size(); i++)
		{
			// assume each element of Numeric array has opertor* (multiply by another element)
			// and returns type is T
			dot_product += (*this)[i] * arr2[i];
		}
		return dot_product;
	}
}
}
}