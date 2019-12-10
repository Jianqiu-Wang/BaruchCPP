// point_array.hpp
// Author: Jianqiu Wang
// 
#include <iostream>

#include "stack.hpp"
#include "stack_exception.hpp"

using namespace std;
using namespace DeanWang::Containers;

namespace DeanWang
{
namespace Containers
{
// Default constructor
template <typename T, int size>
Stack<T, size>::Stack(): m_current(0), m_array(size)
{
}


// Copy constructor
template <typename T, int size>
Stack<T, size>::Stack(const Stack<T,size>& stack)
{
	m_current = stack.m_current;
	m_array = stack.m_array;
}

// Destructor
template <typename T, int size>
Stack<T, size>::~Stack()
{
}

// Assignment operator
template <typename T, int size>
Stack<T,size>& Stack<T,size>::operator= (const Stack& source)
{
	if (this == &source)
		return *this;

	m_current = source.m_current;
	m_array = source.m_array;
	return *this;
}

// Push an element into embedded array
template <typename T, int size>
void Stack<T,size>::Push(const T& element)
{
	try
	{
		m_array[m_current] = element;
	}
	catch(const ArrayException& e)
	{
		throw StackFullException();
	}
	m_current++;
}

// Pop an element from embedded array
template <typename T, int size>
const T& Stack<T,size>::Pop()
{
	try
	{
		m_current--;
		return m_array[m_current];
	}
	catch(const ArrayException& e)
	{
		m_current = 0;
		throw StackEmptyException();
	}
}

// Returns m_current value
template <typename T, int size>
int Stack<T,size>::GetCurrent() const
{
	return m_current;
}
} // namespace Containers
} // namespace DeanWang
