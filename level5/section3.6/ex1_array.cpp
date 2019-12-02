// array.cpp
// Author: Jianqiu Wang
// Manages memory for array of point
#include "ex1_array.hpp"

using namespace DeanWang::Containers;

namespace DeanWang
{
namespace Containers
{
// Default constructor: allocate 10 Point(0,0) into memory
Array::Array()
{
    m_size = 10;
    m_data = new CAD::Point[m_size];
    for (int i = 0; i < m_size; i++)
    {
        m_data[i] = CAD::Point(0,0);
    }
}

// Constructor by giving number of elements
Array::Array(int size)
{
    m_size = size;
    m_data = new CAD::Point[size];
	for (int i = 0; i < m_size; i++)
    {
        m_data[i] = CAD::Point(0,0);
    }
}

// Copy constructor
Array::Array(const Array& arr)
{
	m_data = new CAD::Point[arr.m_size]; // allocate new array
	for (int i=0; i < arr.m_size; i++)
	{
		m_data[i] = arr.m_data[i]; // copy each element
    }
	m_size = arr.m_size;
}

// Destructor
Array::~Array()
{
	delete[] m_data;
}

// Get size of array
int Array::Size() const
{
	return m_size;
}

// Set element at index idx
void Array::SetElement(int index, const CAD::Point& p)
{
	if (index >= 0 && index < m_size)
	{
		m_data[index] = p;
	}
	
}

// Get element at index
CAD::Point& Array::GetElement(int index) const
{
	if (index >= m_size || index < 0)
		throw -1; // index error
	else
		return m_data[index]; 
}

// Override operator []
CAD::Point& Array::operator [] (int index)
{
	if (index >= m_size || index < 0)
		throw -1; // index error
	else
		return m_data[index]; 
}

// read only const [] operator
const CAD::Point& Array::operator [] (int index) const
{
	if (index >= m_size || index < 0)
		throw -1; // index error
	else
		return m_data[index];
}

// assigmnment operator
Array& Array::operator= (const Array& source)
{
	if (this == &source) // assign to myself
		return *this;

	delete[] m_data;
	m_data = new CAD::Point[source.m_size];
	m_size = source.m_size;
	for (int i=0; i < m_size; i++)
	{
		m_data[i] = source.m_data[i]; // copy each element
    }
	return *this;
}

} // namespace Containers
} // namespace DeanWang