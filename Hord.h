//Hord.h
#include "COpt.h"

namespace FindOpt
{
	class Hord: virtual public COpt
	{
	public:
		Hord(double, double, double, double, double, double);
		virtual void Calc();
	};
}