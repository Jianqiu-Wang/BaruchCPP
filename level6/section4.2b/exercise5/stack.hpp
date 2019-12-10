// stack.hpp
// Author: Jianqiu Wang
// Composition class Stakc

#include "array.hpp"

// using namespace DeanWang::CAD;
using namespace DeanWang::Containers;

#ifndef STACK_HPP
#define STACK_HPP

namespace DeanWang
{
namespace Containers
{
template <typename T>
class Stack
{
private:
	int m_current; // current index in the array
	Array<T> m_array; 

public:
	// constructors and destructor
	Stack();
	Stack(int arr_length);
	Stack(const Stack<T>& stack);
	virtual ~Stack();

	// assigment operator
	Stack<T>& operator= (const Stack<T>& source);

	// modify function
	void Push(const T& element);
	const T& Pop();

	// helper function: verify m_current
	int GetCurrent() const;
};
}
}
#ifndef STACK_CPP
#include "stack.cpp"
#endif // STACK_CPP
#endif // STACK_HPP