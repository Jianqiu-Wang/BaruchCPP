// function_object.hpp
// Author: Jianqiu Wang
// Counts type value less than cutoff

#ifndef ISSMALLER_HPP
#define ISSMALLER_HPP


template <typename T>
class IsSmaller
{
private:
	T cutoff;
public:
	// Constructors and destructor
	IsSmaller(); // default constructor
	IsSmaller(const T& t); // constructor with cutoff
	IsSmaller(const IsSmaller<T>& source); // copy constructor
	~IsSmaller();

	// Overload operators
	IsSmaller<T>& operator= (const IsSmaller<T>& source);
	bool operator() (const T& t) const;
};

#ifndef ISSMALLER_CPP
#include "is_smaller.cpp"
#endif // ISSMALLER_CPP 
#endif // ISSMALLER_HPP