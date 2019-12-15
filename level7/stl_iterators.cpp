// STL Iterators
// Author: Jianqiu Wang

#include <iostream>
#include <list>
#include <vector>
#include <map>

using namespace std;

// Calculates sum of a complete container
template <typename T> 
double Sum(const T& container)
{
    double sum = 0; // init sum
    typename T::const_iterator it;
    for (it = container.begin(); it != container.end(); it++)
	{
        sum += *it;
	}
	return sum;
};

// Calculates sum for map<string,double>
double Sum(const map<string,double>& m)
{
	double sum = 0; // init sum

    for (map<string,double>::const_iterator it=m.begin(); it != m.end(); it++)
	{
        sum += it->second;
	}
	return sum;
}

// Calculates sum between two iterators
template <typename T> 
double Sum(const T& begin, const T& end)
{
    double sum = 0; // init sum
    T it;
    for (it = begin; it != end; it++)
	{
        sum += *it;
	}
	return sum;
};

// Calculates sum between two map iterators
template <typename T1, typename T2>
double Sum(const typename map<T1,T2>::const_iterator& begin, const typename map<T1,T2>::const_iterator& end)
{
    double sum = 0; // init sum
    typename map<T1,T2>::const_iterator it;
    for (it = begin; it != end; it++)
	{
        sum += it->second;
	}
	return sum;
};

int main()
{
	// list of doubles
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
	
	// map of strings
	map<string, double> m1;
	m1["list"] = 1;
	m1["vector"] = 2;
	m1["map"] = 3;

	cout << "Sum of list l1, vector v1 and map m1 are: " << Sum(l1) << " " << Sum(v1) << " " << Sum(m1) << endl;
	
 	// v1.begin() + number works for random access iterator
	vector<double>::const_iterator vector_start_it = v1.begin() + 2;
	vector<double>::const_iterator vector_end_it = v1.end() - 2;
	cout << "Sum between two iterators: " << Sum(vector_start_it, vector_end_it) << endl;

	// list<double>::const_iterator, cannot add/substract directly, use advance instead
	list<double>::const_iterator list_start_it = l1.begin();
	list<double>::const_iterator list_end_it = l1.end();
	advance(list_start_it, 2); // advance iterator l1 by 2
	advance(list_end_it, -2); 
	cout << "Sum between two iterators: " << Sum(list_start_it, list_end_it) << endl;

	// map sum
	map<string, double>::const_iterator map_start_it = m1.begin();
	map<string, double>::const_iterator map_end_it = m1.end();
	cout << "Sum between two iterators: " << Sum<string, double>(map_start_it, map_end_it) << endl;

    return 0;
}