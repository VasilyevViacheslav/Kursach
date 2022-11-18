#include "Header.h"
#include <Iostream>

using namespace std;

int main()
{
	double a = 0, s = 0, d = 5, f = 0, g = 0, h = 5;
	Triangle First(a, s, d, f, g, h,10);
	Triangle Second(0, 0, -5, 0, 0, -6,10);
	Kit_Triangle AB(First);
	AB.add_Triangle(Second);
	cout<<AB.Get_mInertiea();
}