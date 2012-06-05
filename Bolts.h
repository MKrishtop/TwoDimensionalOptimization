//Bolts.h
#include "COpt.h"

namespace FindOpt
{
	class Bolts: virtual public COpt
	{
	public:
		Bolts(double, double, double, double, double, double);
		virtual void Calc();
	};
}