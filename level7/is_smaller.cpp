// is_smaller.cpp
// Author: Jianqiu Wang

// Default constructor
template <typename T>
IsSmaller<T>::IsSmaller()
{
}

// Constructor with default cutoff
template <typename T>
IsSmaller<T>::IsSmaller(const T& t): cutoff(t)
{
}

// Copy constructor
template <typename T>
IsSmaller<T>::IsSmaller(const IsSmaller<T>& source): cutoff(source.cutoff)
{
}

// Destructor
template <typename T>
IsSmaller<T>::~IsSmaller()
{
}

// Overload operator =
template <typename T>
IsSmaller<T>& IsSmaller<T>::operator= (const IsSmaller<T>& source)
{
    if (this == &source)
    {
		return *this;
    }
	cutoff = source.cutoff;
	return *this;
}

// Overload operator()
template <typename T>
bool IsSmaller<T>::operator() (const T& t) const
{
	return t < cutoff;
}