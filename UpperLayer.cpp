#include "UpperLayer.h"
#include <iostream>

//layer initialization
UpperLayer::UpperLayer(int x, int y)
{
	px = x;
	py = y;
	Gr.resize(px);
	for (int i = 0; i < px; ++i)
	{
		Gr[i].assign(y, 0.);
	}
}

//if need to output sequentially to the console

//void UpperLayer::PrintToConsole()
//{
//	for (int i = 0; i < X(); ++i)
//	{
//		for (int j = 0; j < Y(); ++j)
//		{
//			std::cout << i << " " << j << " " << (*this)(i, j) << std::endl; 
//			//if ((*this)(i, j) != 99)
//			//{
//			//	std::cout << i << " " << j << " " << (*this)(i, j) << std::endl;
//			//	//std::cout << (*this)(i, j) << std::endl;
//			//}
//		}
//	}
//}

//putting data into the output stream
void UpperLayer::ToFile(std::ostream& out) const
{
	int n, m;
	n = X();
	m = Y();

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			out << i << " " << j << " " << (*this)(i, j) << '\n'; 
		}
	}
}

std::ostream& operator <<(std::ostream& out, const UpperLayer& Ul)
{
	Ul.ToFile(out);
	return out;
}

