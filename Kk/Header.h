#include <vector>
#include <iostream>
#include <stdexcept>
#include <GLFW/glfw3.h>
#include <vector>
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
class Triangle:: TriangleIntrsection {};
{
	float x1, y1, x2, y2, x3, y3;
	float mass;
	float d12 = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	float d23 = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
	float d13 = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
	float P = d12 + d23 + d13;
	float S = sqrt((P / 2) * ((P / 2) - d12) * ((P / 2) - d23) * ((P / 2) - d13));
	float Destiny = mass / S;
	float x_CenterOfMass = ((x1 + x2 + x3) / 3);
	float y_CenterOfMass = ((y1 + y2 + y3) / 3);
	float height = 2 * S / d12;
	float mInertia = d12 * pow(height, 3) / 12;

};
class Kit_Triangle :: public Triangle {};
{
	float mInertia = 0;
	float Kit_Mass = 0;
	float SOfAllTriangles = 0;
	float AverageDesttiny = 0;
	float CenterMassKit_x = 0;
	float CenterMassKit_y = 0;

	std::vector<Triangle> Massive_Of_TRiangle;
	Kit_Triangle(Triangle tr)
	{
		Massive_Of_TRiangle.push_back(tr);
		CenterMassKit_x += (tr.x_CenterOfMass * tr.mass + CenterMassKit_x * Kit_Mass) / (Kit_Mass + tr.mass);
		CenterMassKit_y += (tr.y_CenterOfMass * tr.mass + CenterMassKit_y * Kit_Mass) / (Kit_Mass + tr.mass);
		Kit_Mass += tr.mass;
		SOfAllTriangles += tr.S;
		AverageDesttiny = Kit_Mass / SOfAllTriangles;
		mInertia += tr.mInertia;
	}
	~Kit_Triangle()
	{
		Massive_Of_TRiangle.clear();
	}
public:
	void add_Triangle(Triangle tr)
	{
		Massive_Of_TRiangle.push_back(tr);
		SOfAllTriangles += tr.S;
		AverageDesttiny = Kit_Mass / SOfAllTriangles;
		CenterMassKit_x += (tr.x_CenterOfMass * tr.mass + CenterMassKit_x * Kit_Mass) / (Kit_Mass + tr.mass);
		CenterMassKit_y += (tr.y_CenterOfMass * tr.mass + CenterMassKit_y * Kit_Mass) / (Kit_Mass + tr.mass);
		Kit_Mass += tr.mass;
	}
};

/*
* var t1 = new Triangle(new Tuple<double, double>(0.0, 0.0), new Tuple<double, double>(5.0, 0.0), new Tuple<double, double>(0.0, 5.0));
  var t2 = new Triangle(new Tuple<double, double>(0.0, 0.0), new Tuple<double, double>(5.0, 0.0), new Tuple<double, double>(0.0, 6.0));
  Console.WriteLine("{0} and\n{1}", t1, t2);
  Overlap(t1, t2);
  Console.WriteLine();

*/


