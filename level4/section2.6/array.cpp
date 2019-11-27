// array.cpp
// Author: Jianqiu Wang
// Manages memory for array of point
#include "array.hpp"
using namespace DeanWang;
using namespace Containers;

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
	delete[] m_data;
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
	m_data[index] = p;
}

// Get element at index
CAD::Point& Array::GetElement(int index) const
{
	if (index >= m_size)
		return m_data[0];
	else
		return m_data[index]; 
}

// Override operator []
CAD::Point& Array::operator [] (int index)
{
	if (index >= m_size)
		return m_data[0];
	else
		return m_data[index]; 
}

// read only const [] operator
const CAD::Point& Array::operator [] (int index) const
{
	if (index >= m_size)
		return m_data[0];
	else
		return m_data[index];
}