#include "Boundaries.h"
#include <algorithm>

void Boundaries::SetUp(double x1, double x2, double y1, double y2, double z1, double z2) {
	Lower.x(std::min(x1, x2));
	Lower.y(std::min(y1, y2));
	Lower.z(std::min(z1, z2));

	
	Higher.x(std::max(x1, x2));
	Higher.y(std::max(y1, y2));
	Higher.z(std::max(z1, z2));
}

