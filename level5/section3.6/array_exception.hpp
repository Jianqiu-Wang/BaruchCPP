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
	OutOfBoundsException(): ArrayException() {
		m_index = -1;
	};
	OutOfBoundsException(int err_index): m_index(err_index) {};; // default inline, constructor
	~OutOfBoundsException() {};

	// override GetMessage
	std::string GetMessage()
	{
		std::ostringstream ss;
		ss << "Wrong index: " << m_index;
		return ss.str();
	};
};

} // namespace Containers
} // namespace DeanWang
#endif // ARRAY_EXCEPTION_HPP