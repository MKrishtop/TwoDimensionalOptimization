//ZolSech.h
#include "COpt.h"

namespace FindOpt
{
	class ZolSech: virtual public COpt
	{
		static const int n=20;
		double x[n];
		double E;
	public:
		ZolSech(double i, double j, double k, double m, double f);
		void Calc();
	};
}