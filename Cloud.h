#ifndef CLOUD_h
#define CLOUD_h

#include "mwTPoint3d.hpp"
#include <vector>
#include "Sphere.h"
#include "UpperLayer.h"
#include "Cylinder.h"

typedef std::vector<bool> Arr1D;
typedef std::vector<Arr1D> Arr2D;
typedef std::vector<Arr2D> Arr3D;


class Cloud
{
private:
	Arr3D Grid;
	int o_x, o_y, o_z;
	double Delta;
	Point3d Origin;
public:
	Cloud(const Point3d& e_Or, int ex, int ey, int ez, double e_d);

	//Checking if a point is in an array
	bool CheckPoint(int a, int b, int c);

	//Changing the state of a point
	void ChangePoint(int a, int b, int c, bool tf);

	//Get a point at the specified coordinates
	Point3d GetPoint(int a, int b, int c);

	//Function to subtract a sphere from an array
	void DeletePoints(const Sphere& Sp);

	//Function to subtract a cylinder and sphere from an array
	void DeletePoints(const Sphere& Sp, const Cylinder& Cyl);

	//Recording the desired point layer
	void RecordResult(UpperLayer& Layer);

	void Converter(const Point3d& P, int& x, int& y, int& z)
	{
		x = P.x();
		y = P.y();
		z = P.z();
	}
};

#endif
