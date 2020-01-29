// smart_pointers.cpp
// Author: Jianqiu Wang

#include "boost/shared_ptr.hpp"

#include "array.hpp"
#include "shape.hpp"
#include "point.hpp"
#include "line.hpp"
#include "circle.hpp"

using namespace std;
using namespace DeanWang::CAD;
// using namespace DeanWang::Containers;

// Typedef for a shared pointer to shape and
// a typedef for an array with shapes stored as shared pointers. 
typedef boost::shared_ptr<Shape> ShapePtr;
typedef Array<ShapePtr> ShapeArray;

// Show use count of each element of shared ptr array 
void ShowUseCount(const ShapeArray& shape_array)
{
	cout << "Print objects pointed by shared_ptrs" << endl; 
	cout << "Reference count:" << endl;
	cout << "Point|Line|Circle" << endl; 
	cout << "  "<< shape_array[0].use_count() << "  |  " << shape_array[1].use_count() << " |  " << shape_array[2].use_count() << endl;
}
	
int main()
{
	{
		// initializes an Array<ShapePtr>, append Point, Line and Circle
		ShapeArray shape_array(3);
		{
			shape_array[0] = ShapePtr(new Point());;
			shape_array[1] = ShapePtr(new Line());
			shape_array[2] = ShapePtr(new Circle());
			
			for (int i=0; i < 3; i++)
			{
				shape_array[i]->Print();
			}
			ShowUseCount(shape_array);

			// 
			{
				ShapePtr p1;
				ShapePtr l1;
				ShapePtr c1;
				p1 = shape_array[0];
				l1 = shape_array[1];
				c1 = shape_array[2];
				ShowUseCount(shape_array);
			}
		}
		ShowUseCount(shape_array);
	}
	return 0;
}

