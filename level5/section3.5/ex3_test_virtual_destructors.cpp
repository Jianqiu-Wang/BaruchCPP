// Test virtual destructors
// Author: Jianqiu Wang
#include "ex3_line.hpp"

#include <string>
using namespace std;
using namespace DeanWang::CAD;

int main()
{
	// before3 virtual added to base class destructor, base class desctructor is called
	// but derived class destructors will not be called
	// after virtual added, both base and derived class destructors will be called
	Shape* shapes[3];
	shapes[0] = new Shape; 
	shapes[1] = new Point;
	shapes[2] = new Line;
	for (int i=0; i!=3; i++)
		delete shapes[i];
}