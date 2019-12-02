// Test abstract functions
// Author: Jianqiu Wang
#include "line.hpp"
#include "circle.hpp"

#include <string>
using namespace std;
using namespace DeanWang::CAD;

int main()
{
	// cannot create a Shape object, it is an ABC
	// Shape s;
	Shape* shapes[10]; // create array of pointers to 10 shape object
	shapes[0] = new Line;
	shapes[1] = new Point;
	shapes[2] = new Line;
	shapes[3] = new Point;
	shapes[4] = new Line;
	shapes[5] = new Point;
	shapes[6] = new Line;
	shapes[7] = new Point;
	shapes[8] = new Circle;
	shapes[9] = new Line(Point(1.0, 2.5), Point(3.4, 5.2));
	for (int i=0; i!=10; i++) shapes[i]->Draw(); // call derived class Draw() method
	for (int i=0; i!=10; i++) delete shapes[i];
}