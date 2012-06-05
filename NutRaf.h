//NutRaf.h
#include "COpt.h"

namespace FindOpt
{
	class NutRaf: virtual public COpt
	{
	public:
		NutRaf(double, double, double, double, double, double);
		virtual void Calc();
	};
}