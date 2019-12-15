// STL containers
// Author: Jianqiu Wang

#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <string>
#include <iterator>

using namespace std;

int main()
{
	// create a list of doubles
	list<double> l1;
	for (int i=0; i < 10; i++)
	{
		l1.push_back(i*i);
	}
	cout << "First element of list l1: " << l1.front() << endl;
	cout << "Last element of list l1 : " << l1.back() << endl;

	// vector of doubles
	vector<double> v1;
	for (int i=0; i < 10; i++)
	{
		v1.push_back(i*i);
	}
	cout << "Second element of vector v1: " << v1[1] << endl;
	cout << "The 5th element of vector v1: " << v1[4] << endl;
	cout << "Size of v1: " << v1.size() << endl;
	v1.push_back(121);
	cout << "Size of v1: " << v1.size() << endl;

	// map of strings
	map<string, double> m1;
	m1["list"] = 1;
	m1["vector"] = 2;
	m1["map"] = 3;
	cout << "Value of key list in map m1: " << m1["list"] << endl;

    return 0;
}