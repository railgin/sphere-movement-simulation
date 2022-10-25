#include "CreateSkin.hpp"
#include <mwTPoint3d.hpp>
#include "Cloud.h"
#include "Sphere.h"
#include "UpperLayer.h"
#include "mwDiscreteFunction.hpp"
#include <fstream>
#include <iostream>
#include <ctime>

void CreateSkin(const Point3d refPoint, 
				const unsigned long nx, const unsigned long ny, 
				const unsigned long nz, const double sphereRad, 
				mwDiscreteFunction &func, const double deltaT, 
				const double delta, const std::string &skinFileName)
{

	unsigned int start_time2 = clock();
	Cloud cloud(refPoint, nx, ny, nz, delta);
	Sphere Sph(sphereRad);
	unsigned int end_time2 = clock();
	std::cout << "Allocate array time (ms):" << end_time2 - start_time2 << std::endl;

	bool flag = 1;
	Point3d Previous;

	unsigned int start_time = clock();
	for (double t = func.GetBeginParameter(); t <= func.GetEndParameter(); t += deltaT) //full cycle time ~20 minutes
	{
		//at the first step we subtract only the sphere,
		//at all subsequent steps we subtract the sphere + the cylinder connecting the current and previous spheres
		if (flag)
		{
			Sph.ChangeCenter(func.Evaluate(t));
			cloud.DeletePoints(Sph);
			flag = 0;
		}
		else
		{
			Sph.ChangeCenter(func.Evaluate(t));

			Cylinder C(sphereRad, Sph.GetCenter(), Previous);
			cloud.DeletePoints(Sph, C);
		}
		Previous = Sph.GetCenter(); //remember the center of the previous sphere to build the cylinder in the next step
	}

	unsigned int end_time = clock();
	std::cout << "Calculation time (ms): " << (end_time - start_time) << std::endl;

	UpperLayer layer(nx,ny); 

	cloud.RecordResult(layer); 

	//layer.PrintToConsole();

	//stream output to file
	unsigned int start_time1 = clock();
	std::fstream out(skinFileName.c_str(), std::ios_base::out);
	out << layer;
	out.close();
	unsigned int end_time1 = clock();
	std::cout << "Output stream to file (ms): " << (end_time1 - start_time1) << std::endl;
}
