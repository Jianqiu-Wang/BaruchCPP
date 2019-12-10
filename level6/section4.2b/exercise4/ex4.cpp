// stack_test.cpp
// Author: Jianqiu Wang
// Test class Stack

#include "stack.hpp"
#include "array.hpp"

using namespace std;
using namespace DeanWang::Containers;

int main()
{
	// test Stack<double>
	Stack<double> stack;
	// test push
	for (int i=0; i < 10; i++)
	{
		stack.Push(i*i);
		cout << i << endl;	
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
		catch(OutOfBoundsException& e)
		{
			cout << e.GetMessage() << endl;
		}
	}

	return 0;
}