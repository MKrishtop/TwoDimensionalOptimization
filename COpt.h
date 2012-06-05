//COpt.h
#include "MainIncludes.h"

using namespace std;

#ifndef FL
#define FL 1
namespace FindOpt
{ 
	const double e=M_E;
	class COpt
	{
	protected:
		double X0;
		double E1;
		double E2;
		double d;
		double a;
		double b;
		double xres,fres;
		int itr;
	public:
		virtual void Calc();
		double GetX();
		double GetFX(); 
		int GetI();
	};
}
#endif