//Pauell.h
#include "COpt.h"

namespace FindOpt
{
	class Pauell: virtual public COpt
	{
		double* sort(double* i, int j);
	public:
		Pauell(double i, double j, double k, double m);
		virtual void Calc();
	};
}