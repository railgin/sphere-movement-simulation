#include <Sphere.h>

bool Sphere::CheckInside(const Point3d& p) const
{
	//standard sphere equation
	return ((p.x() - SCenter.x()) * (p.x() - SCenter.x()) +
		(p.y() - SCenter.y()) * (p.y() - SCenter.y()) + (p.z() - SCenter.z()) * (p.z() - SCenter.z()) <= SRad * SRad);
}

void Sphere::EvaluateSphereBoundary(const Point3d& Center)
{
	SphereBoundary.SetUp(Center.x() - getRad(), Center.x() + getRad(), Center.y() - getRad(), Center.y() + getRad(),
		Center.z() - getRad(), Center.z() + getRad());
}