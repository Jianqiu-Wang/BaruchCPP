// array_exception.hpp
// Author: Jianqiu Wang
#include <string>
#include <sstream>

#ifndef ARRAY_EXCEPTION_HPP
#define ARRAY_EXCEPTION_HPP

namespace DeanWang
{
namespace Containers
{
class ArrayException
{
public:
	ArrayException() {};  // constructor
	~ArrayException() {}; // destructor

	virtual std::string GetMessage() = 0; // pure virual member function
};

class OutOfBoundsException: public ArrayException
{
private:
	int m_index; // error index

public:
	// constructor and destructor
	OutOfBoundsException(): ArrayException()
	{
		m_index = -1;
	};
	OutOfBoundsException(int err_index): m_index(err_index) {}; // default inline, constructor
	~OutOfBoundsException() {};

	// override GetMessage
	std::string GetMessage()
	{
		std::ostringstream ss;
		ss << "Wrong index: " << m_index;
		return ss.str();
	};
};

// Array length inequality
class SizeInequalityException: public ArrayException
{
private:
	int m_size1; // size of array1
	int m_size2; // size of array2
public:
	// constructor and destructor
	SizeInequalityException(): ArrayException() 
	{
		m_size1 = 10;
		m_size2 = 10;
	};
	SizeInequalityException(int size1, int size2): m_size1(size1), m_size2(size2) {}; // default inline, constructor
	~SizeInequalityException() {};
	
	// override GetMessage
	std::string GetMessage()
	{
		std::ostringstream ss;
		ss << "Size " << m_size1 << " and size " << m_size2 << "are unequal.";
		return ss.str();
	};
};

} // namespace Containers
} // namespace DeanWang
#endif // ARRAY_EXCEPTION_HPP