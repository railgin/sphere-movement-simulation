#include <Cloud.h>
#include <algorithm>
#include "Boundaries.h"

Cloud::Cloud(const Point3d& e_Or, int ex, int ey, int ez, double e_d) : Origin(e_Or), o_x(ex), o_y(ey), o_z(ez), Delta(e_d)
{
	using namespace std;
	Arr3D v(o_x, std::vector<vector<bool>>(o_y, vector<bool>(o_z, 1)));
	Grid = v;
}

bool Cloud::CheckPoint(int a, int b, int c)
{
	if ((a < o_x) && (b < o_y) && (c < o_z))
	{
		return Grid[a][b][c];
	}
}

void Cloud::ChangePoint(int a, int b, int c, bool tf)
{
	if ((a < o_x) && (b < o_y) && (c < o_z))
	{
		Grid[a][b][c] = tf;
	}
}

Point3d Cloud::GetPoint(int a, int b, int c)
{
	return Point3d(Origin.x() + a * Delta, Origin.y() + b * Delta, Origin.z() + c * Delta);
}

void Cloud::DeletePoints(const Sphere& Sp)
{
	using namespace std;
	//we mark the points that fall into the sphere with zeros
	const Boundaries& B = Sp.GetBounds();

	int x_min, x_max, y_min, y_max, z_min, z_max;

	Converter(B.L(), x_min, y_min, z_min);
	Converter(B.H(), x_max, y_max, z_max);

	

	for (int i = max(0,x_min); i <= min(o_x - 1, x_max); ++i)
	{
		for (int j = max(0, y_min); j <= min(o_y - 1, y_max); ++j)
		{
			for (int k = max(0, z_min); k <= min(o_z - 1, z_max); ++k)
			{
				if (Grid[i][j][k] && Sp.CheckInside(GetPoint(i, j, k)))
				{
					Grid[i][j][k] = false;
				}
			}
		}
	}
}

void Cloud::DeletePoints(const Sphere& Sp, const Cylinder& Cyl)
{
	using namespace std;
	const Boundaries& B = Cyl.GetBounds();

	int x_min, x_max, y_min, y_max, z_min, z_max;

	Converter(B.L(), x_min, y_min, z_min);
	Converter(B.H(), x_max, y_max, z_max);

	for (int i = max(0, x_min); i <= min(o_x - 1, x_max); ++i)
	{
		for (int j = max(0, y_min); j <= min(o_y - 1, y_max); ++j)
		{
			for (int k = max(0, z_min); k <= min(o_z - 1, z_max); ++k)
			{
				if (Grid[i][j][k] && (Sp.CheckInside(GetPoint(i, j, k)) || Cyl.CheckCylInside(GetPoint(i, j, k))))
				{
					Grid[i][j][k] = false;
				}
			}
		}
	}
	
}

void Cloud::RecordResult(UpperLayer & Layer)
{
	//we are looking for the maximum value along the vertical, 
	//after which we write down the corresponding coordinates in the XY plane and the largest along the Z axis
	for (int i = 0; i < o_x; ++i)
	{
		for (int j = 0; j < o_y; ++j)
		{
			int k = o_z - 1;
			while (!Grid[i][j][k] && k >= 0)
			{
				--k;
			}

			if (k > 0)
			{
				Layer.NewElem(i, j, GetPoint(i, j, k));
			}
		}
	}
}

