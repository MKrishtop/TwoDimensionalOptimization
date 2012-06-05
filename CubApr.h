//CubApr.h
#include "COpt.h"

namespace FindOpt
{
	class CubApr: virtual public COpt
	{
	public:
		CubApr(double, double, double, double, double, double);
		virtual void Calc();
	};
}