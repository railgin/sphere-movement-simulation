#ifndef BOUNDARIES_H
#define BOUNDARIES_H

#include "mwTPoint3d.hpp"


class Boundaries
{
private:
	Point3d Lower, Higher;
public:
	/*Boundaries(double x1, double x2, double y1, double y2, double z1, double z2)
	{
		SetUp(x1, x2, y1,  y2, z1, z2);
	}*/

	const Point3d& L() const
	{
		return Lower;
	}

	const Point3d& H() const
	{
		return Higher;
	}

	void SetUp(double x1, double x2, double y1, double y2, double z1, double z2);


};


#endif