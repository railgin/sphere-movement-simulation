#ifndef SPHERE_H
#define SPHERE_H

#include <mwTPoint3d.hpp>
#include "Boundaries.h"

//Class describing a sphere in terms of radius and center
class Sphere
{
private:
	double SRad;
	Point3d SCenter;
	Boundaries SphereBoundary;
public:
	Sphere(double r) : SRad(r) {};
	//Sphere(double r, const Point3d& cent) : SRad(r), SCenter(cent) {};

	inline double getRad() const
	{
		return SRad;
	}

	inline void ChangeRad(double r)
	{
		SRad = r;
	}
	
	inline const Point3d& GetCenter() const
	{
		return SCenter;
	}

	inline void ChangeCenter(const Point3d& nCenter) //сюда расчёт границ
	{
		SCenter = nCenter;
		EvaluateSphereBoundary(nCenter);
	}

	//function that checks if a point satisfies the equation of a sphere
	bool CheckInside(const Point3d& p) const;

	void EvaluateSphereBoundary(const Point3d& Center);

	inline const Boundaries& GetBounds() const
	{
		return SphereBoundary;
	}

};

#endif
