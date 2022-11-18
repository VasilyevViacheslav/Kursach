#include "Header.h"
#include <Iostream>

using namespace std;

int main()
{
	double a = 0, s = 0, d = 1, f = 1, g = 1, h = 0;
	Triangle First(a, s, d, f, g, h,10);
	Triangle Second(0, 0, 1, 1, -1, 0,10);
	Kit_Triangle AB(First);
	AB.add_Triangle(Second);
	cout << 1;
}