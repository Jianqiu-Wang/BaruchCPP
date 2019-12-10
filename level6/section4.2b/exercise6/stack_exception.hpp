// stack_exception.hpp
// Author: Jianqiu Wang
#include <string>
#include <sstream>

#ifndef STACK_EXCEPTION_HPP
#define STACK_EXCEPTION_HPP

namespace DeanWang
{
namespace Containers
{
class StackException
{
public:
    StackException() {}; // constructor
    ~StackException() {}; // destructor
};

class StackFullException: public StackException
{
public:
    StackFullException(): StackException() {};
    ~StackFullException() {};
};

class StackEmptyException: public StackException
{
public:
    StackEmptyException(): StackException() {};
    ~StackEmptyException() {};
};


} // namespace Containers
} // namespace DeanWang

#endif // STACK_EXCEPTION_HPP