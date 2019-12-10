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
template <typename T>
Stack<T>::Stack(): m_current(0)
{
}

// Construct with length
template <typename T>
Stack<T>::Stack(int arr_length): m_current(0), m_array(arr_length)
{
}

// Copy constructor
template <typename T>
Stack<T>::Stack(const Stack<T>& stack)
{
	m_current = stack.m_current;
	m_array = stack.m_array;
}

// Destructor
template <typename T>
Stack<T>::~Stack()
{
}

// Assignment operator
template <typename T>
Stack<T>& Stack<T>::operator= (const Stack& source)
{
	if (this == &source)
		return *this;

	m_current = source.m_current;
	m_array = source.m_array;
	return *this;
}

// Push an element into embedded array
template <typename T>
void Stack<T>::Push(const T& element)
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
template <typename T>
const T& Stack<T>::Pop()
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
template <typename T>
int Stack<T>::GetCurrent() const
{
	return m_current;
}
} // namespace Containers
} // namespace DeanWang
