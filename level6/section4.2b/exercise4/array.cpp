// array.cpp
// Author: Jianqiu Wang
// Implements templated array class
#include "array_exception.hpp"

using namespace DeanWang::Containers;

// namespace DeanWang
// {
// namespace Containers
// {

// Default constructor: allocate 10 T objects into memory
template <typename T>
Array<T>::Array()
{
    m_size = 10;
    m_data = new T[m_size];
    for (int i = 0; i < m_size; i++)
    {
        m_data[i] = T();
    }
}

// Set default size 10
template <typename T>
int Array<T>::m_default_size = 10;


// Constructor by giving number of elements
template <typename T>
Array<T>::Array(int size)
{
    m_size = size;
    m_data = new T[size];
}

// Copy constructor
template <typename T>
Array<T>::Array(const Array& arr)
{
	m_data = new T[arr.m_size]; // allocate new array
	for (int i=0; i < arr.m_size; i++)
	{
		m_data[i] = arr.m_data[i]; // copy each element
    }
	m_size = arr.m_size;
}

// Destructor
template <typename T>
Array<T>::~Array()
{
	delete[] m_data;
}

// Get size of array
template <typename T>
int Array<T>::Size() const
{
	return m_size;
}

// Set element at index idx
template <typename T>
void Array<T>::SetElement(int index, const T& p)
{
	if (index >= 0 && index < m_size)
	{
		m_data[index] = p;
	}
}

template <typename T>
int Array<T>::DefaultSize()
{
	return m_default_size;
}

// Set default size
template <typename T>
void Array<T>::DefaultSize(int new_size)
{
	if (new_size >= 0)
	{
		m_default_size = new_size;
	}
	else
	{
		throw OutOfBoundsException(new_size);
	}
}


// Get element at index
template <typename T>
T& Array<T>::GetElement(int index) const
{
	if (index >= m_size || index < 0)
		throw OutOfBoundsException(index); // index error
	else
		return m_data[index]; 
}

// Override operator []
template <typename T>
T& Array<T>::operator[] (int index)
{
	if (index >= m_size || index < 0)
		throw OutOfBoundsException(index); // index error
	else
		return m_data[index]; 
}

// read only const [] operator
template <typename T>
const T& Array<T>::operator[] (int index) const
{
	if (index >= m_size || index < 0)
		throw OutOfBoundsException(index); // index error
	else
		return m_data[index];
}

// assigmnment operator
template <typename T>
Array<T>& Array<T>::operator= (const Array<T>& source)
{
	if (this == &source) // assign to myself
		return *this;

	delete[] m_data;
	m_data = new T[source.m_size];
	m_size = source.m_size;
	for (int i=0; i < m_size; i++)
	{
		m_data[i] = source.m_data[i]; // copy each element
    }
	return *this;
}
// } // namespace Containers
// } // namespace DeanWang