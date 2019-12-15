// STL Algorithms
// Author: Jianqiu Wang

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <iterator>

#include "is_smaller.hpp"

using namespace std;

// Returns if a number is smaller than a certain numuber cutoff
bool IsSmaller1(double num) { return num < 10; }


int main()
{
	// create a list of doubles
	list<double> l1;
	for (int i=0; i < 10; i++)
	{
		l1.push_back(i*i);
	}

	// vector of doubles
	vector<double> v1;
	for (int i=0; i < 10; i++)
	{
		v1.push_back(i*i);
	}

	vector<double>::const_iterator vector_start_it = v1.begin() + 2;
	vector<double>::const_iterator vector_end_it = v1.end() - 2;

	int res1 = count_if(l1.begin(), l1.end(), IsSmaller1);
	int res2 = count_if(l1.begin(), l1.end(), IsSmaller<double>(10));
	
	cout << "count_if by global function and generic class are: " << res1 << " " << res2 << endl;
	return 0;
}