// stack_test.cpp
// Author: Jianqiu Wang
// Test class Stack and StackException

#include "stack.hpp"
#include "array.hpp"
#include "stack_exception.hpp"

using namespace std;
using namespace DeanWang::Containers;

int main()
{
	// test Stack<double>
	Stack<double> stack;
	// test push
	for (int i=0; i < 15; i++)
	{
		try
		{
			stack.Push(i*i);
			cout << i << endl;	
		}
		catch(const StackFullException& e)
		{
			cout << "Catch StackFull Exception" << endl;
		}
		
	}
	
	// test copy constructor
	Stack<double> stack2(stack);
	
	// pop from stack2
	for (int i=0; i < 15; i++)
	{
		try
		{
			cout << "Pop: " << stack2.Pop() << endl;;
		}
		catch(const StackEmptyException& e)
		{
			cout << "Catch StackEmpty exception" << endl;
			cout << stack2.GetCurrent() << endl;
		}
	}

	return 0;
}