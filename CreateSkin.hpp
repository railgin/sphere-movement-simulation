#ifndef CREATESKIN_HPP
#define CREATESKIN_HPP

#include "mwTPoint3d.hpp"
#include "mwDiscreteFunction.hpp"

void CreateSkin(const Point3d refPoint, 
				const unsigned long nx, const unsigned long ny, 
				const unsigned long nz, const double sphereRad, 
				mwDiscreteFunction &func, const double deltaT, 
				const double delta, const std::string &skinFileName);

#endif /* CREATESKIN_HPP */
