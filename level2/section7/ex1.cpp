// author: Jianqiu Wang
// Function: Swap(), exchange value of two varibales by using pointers

#include <stdio.h>

// Swaps two integers 
void Swap(int* a, int* b)
{
	int temp = *a; // create a temp variable, copy value of a
	*a = *b;       // copy value b to a
	*b = temp;     // copy value of temp to b
}

int main()
{
	int a = 123; 
	int b = 456;
	printf("a is %d, b is %d\n", a, b);
	Swap(&a, &b);
	printf("Swap a and b, a is %d, b is %d\n", a, b);

	return 0;
}
