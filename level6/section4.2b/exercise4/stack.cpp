// point_array.hpp
// Author: Jianqiu Wang
// 
#include <iostream>

#include "stack.hpp"

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
	m_array[m_current] = element;
	m_current++;
}

// Pop an element from embedded array
template <typename T>
const T& Stack<T>::Pop()
{
	// if OutOfBoundsException throws when accessing m_array[m_curent-1]
	// then m_current-- will not be executed, 
	// hence we can always keep m_current>=0 without try... catch .. or if ... else ...
	m_array[m_current-1];
	m_current--;
	return m_array[m_current]; 
}

} // namespace Containers
} // namespace DeanWang
