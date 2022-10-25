#ifndef CYL_H
#define CYL_H

#include "mwTPoint3d.hpp"
#include <algorithm>
#include "Boundaries.h"

class Cylinder
{
private:
	Point3d vOM; 
	double cylRad;
	Point3d CylCenter;
	Boundaries CylinderBoundary;
public:
	//Cylinder() {};

	Cylinder(double rad, const Point3d& M, const Point3d& N);
	
	//A vector directed from the center of the axis of the cylinder to one of the bases (due to symmetry, it doesn’t matter which one)
	inline const Point3d& OM() const
	{
		return vOM;
	}

	inline double GetRad() const
	{
		return cylRad;
	}

	inline const Point3d& GetCenter() const
	{
		return CylCenter;
	}

	const Point3d M() const
	{
		return GetCenter() + vOM;
	}

	const Point3d N() const
	{
		return GetCenter() - vOM;
	}

	//checking if a point belongs to a cylinder
	bool CheckCylInside(const Point3d& P) const;

	void EvaluateCylinderBoundary(const Point3d& Center); // â  ñïï
	
	const Boundaries& GetBounds() const
	{
		return CylinderBoundary;
	}
};


#endif