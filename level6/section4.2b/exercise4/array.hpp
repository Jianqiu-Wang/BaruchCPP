// array.cpp
// Author: Jianqiu Wang
// Templated array class

#ifndef ARRAY_HPP
#define ARRAY_HPP

namespace DeanWang
{
namespace Containers
{

template <typename T>
class Array
{
private:
	T* m_data;
	int m_size;
	static int m_default_size;  // default size of Array

public:
	// constructor and deconstructor
	Array();          // default constructor
	Array(int size);  // construct with size
	Array(const Array<T>& arr); // copy constructor
	virtual ~Array();                   // destructor

	// getter and setter
	int Size() const;                       // return size of array
	void SetElement(int index, const T& t); // set element at index i with type t
	T& GetElement(int index) const; 		// get element at index 

	// static member function
	static int DefaultSize();              // get default size
	static void DefaultSize(int new_size); // set default size

	// operator overload
	T& operator[] (int index); 			// override operator [] 
	const T& operator[] (int index) const; // override operator [] with const, read only
	Array<T>& operator= (const Array<T>& source);     // assignment operator
};

} // namespace Containers
} // namespace DeanWang

// include array.cpp so compiler could determine template type
#ifndef ARRAY_CPP 
#include "array.cpp"
#endif // ARRAY_CPP
#endif // ARRAY_HPP