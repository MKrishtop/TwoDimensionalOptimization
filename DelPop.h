//DelPop.h
#include "COpt.h"

namespace FindOpt
{
	class DelPop: virtual public COpt
	{
		static const int n=20;
		double x[n];
		double E;
	public:
		DelPop(double i, double j, double k, double m, double f);
		void Calc();
	};
}