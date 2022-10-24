#include <vector>
#include <iostream>
#include <stdexcept>
class TriangleIntrsection
{
public:

	typedef std::pair<double, double> TriPoint;

	inline double Det2D(TriPoint& p1, TriPoint& p2, TriPoint& p3)
	{
		return +p1.first * (p2.second - p3.second)
			+ p2.first * (p3.second - p1.second)
			+ p3.first * (p1.second - p2.second);
	}

	void CheckTriWinding(TriPoint& p1, TriPoint& p2, TriPoint& p3, bool allowReversed)
	{
		double detTri = Det2D(p1, p2, p3);
		if (detTri < 0.0)
		{
			if (allowReversed)
			{
				TriPoint a = p3;
				p3 = p2;
				p2 = a;
			}
			else throw std::runtime_error("triangle has wrong winding direction");
		}
	}

	bool BoundaryCollideChk(TriPoint& p1, TriPoint& p2, TriPoint& p3, double eps)
	{
		return Det2D(p1, p2, p3) < eps;
	}



	bool TriTri2D(TriPoint* t1,
		TriPoint* t2,
		double eps = 0.0, bool allowReversed = false, bool onBoundary = true)
	{
		//Trangles must be expressed anti-clockwise
		CheckTriWinding(t1[0], t1[1], t1[2], allowReversed);
		CheckTriWinding(t2[0], t2[1], t2[2], allowReversed);


		//For edge E of trangle 1,
		for (int i = 0; i < 3; i++)
		{
			int j = (i + 1) % 3;

			//Check all points of trangle 2 lay on the external side of the edge E. If
			//they do, the triangles do not collide.
			if (BoundaryCollideChk(t1[i], t1[j], t2[0], eps) &&
				BoundaryCollideChk(t1[i], t1[j], t2[1], eps) &&
				BoundaryCollideChk(t1[i], t1[j], t2[2], eps))
				return false;
		}

		//For edge E of trangle 2,
		for (int i = 0; i < 3; i++)
		{
			int j = (i + 1) % 3;

			//Check all points of trangle 1 lay on the external side of the edge E. If
			//they do, the triangles do not collide.
			if (BoundaryCollideChk(t2[i], t2[j], t1[0], eps) &&
				BoundaryCollideChk(t2[i], t2[j], t1[1], eps) &&
				BoundaryCollideChk(t2[i], t2[j], t1[2], eps))
				return false;
		}
		
		//The triangles collide
		return true;
	};
	
};
/*
* var t1 = new Triangle(new Tuple<double, double>(0.0, 0.0), new Tuple<double, double>(5.0, 0.0), new Tuple<double, double>(0.0, 5.0));
  var t2 = new Triangle(new Tuple<double, double>(0.0, 0.0), new Tuple<double, double>(5.0, 0.0), new Tuple<double, double>(0.0, 6.0));
  Console.WriteLine("{0} and\n{1}", t1, t2);
  Overlap(t1, t2);
  Console.WriteLine();

*/


