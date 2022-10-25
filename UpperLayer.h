#ifndef XY_LAYER
#define XY_LAYER

#include <vector>
#include "mwTPoint3d.hpp"

//class describing the upper desired layer
class UpperLayer
{
private:
	typedef std::vector<std::vector<int>> Grid2D;
	Grid2D Gr; //two - dimensional array of heights
	int px, py;
public:
	UpperLayer(int x, int y);

	inline int X() const
	{
		return px;
	}

	inline int Y() const
	{
		return py;
	}

	inline int operator()(int a, int b) const
	{
		return Gr[a][b];
	}

	//writing the x-coordinate into a two-dimensional array at the corresponding x,y coordinates
	inline void NewElem(int a, int b, const Point3d& p)
	{
		Gr[a][b] = p.z();
	}

	//void PrintToConsole();

	//function to write data to a file
	void ToFile(std::ostream& out) const;

};

//output operator overload
std::ostream& operator <<(std::ostream& out, const UpperLayer& Ul);
#endif
