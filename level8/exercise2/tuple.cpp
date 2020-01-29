// tuple.cpp
// Author: Jianqiu Wang

#include "boost/tuple/tuple.hpp"
#include "boost/tuple/tuple_io.hpp"

#include <string>
#include <iostream>

using namespace std;

// typedef Person as a tuple composed of name, age and length
typedef boost::tuple<string, int, double> Person;

// Print a person's name, age and length
inline void PrintPerson(const Person& p)
{
    cout << "Name: " << p.get<0>() << ", age: " << p.get<1>() << ", length: " << p.get<2>() << endl;
}

int main()
{
    Person p1(string("Dean"), 25, 175);
    Person p2(string("Jane"), 25, 162);
    
    PrintPerson(p1);
    PrintPerson(p2);

    // Add age of p2
    boost::tuples::get<1>(p2) = 28; // returns reference by using get
    PrintPerson(p2);
    return 0;
}