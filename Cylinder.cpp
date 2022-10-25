#include "Cylinder.h"

//create a cylinder by two points - the center of the previous and next sphere
Cylinder::Cylinder(double rad, const Point3d& M, const Point3d& N) 
{
	CylCenter = (M + N) / 2.;
	vOM = (M - N) / 2.;
	cylRad = rad;
	EvaluateCylinderBoundary(CylCenter);
}

bool Cylinder::CheckCylInside(const Point3d& P) const
{
	Point3d OP(P - GetCenter());
	const Point3d& OM(this->OM());
	double abs_OM(~(OM)); //OM vector modulus
	

	//a detailed explanation of this is in the presentation
	return (~(OP % OM) / abs_OM < cylRad) && (abs(OP * OM) / abs_OM < abs_OM);
}

void Cylinder::EvaluateCylinderBoundary(const Point3d& Center) // â  ñïï
{
	using namespace std;
	Point3d M(this->M());
	Point3d N(this->N());
	CylinderBoundary.SetUp(
		min(M.x(), N.x()) - GetRad(), max(M.x(), N.x()) + GetRad(),
		min(M.y(), N.y()) - GetRad(), max(M.y(), N.y()) + GetRad(),
		N.z() - GetRad(), N.z() + GetRad());

}