//Bolts.cpp
#include "Bolts.h"

using namespace FindOpt;

Bolts::Bolts(double q, double w, double j, double r, double t, double y)
{
	X0=q;
	d=w;
	a=j;
	b=r;
	E1=t;
	E2=y;
}

void Bolts::Calc()
{
	bool as=false;
	double L;
	double R;
	double z;
	int i=1;
	double FpZ;	
	double FpL,FpR;	
	double Fmod;
	double Fx;
	L=a;
	R=b;
	z=(L+R)/2;

	FpL=2*L*pow(e,pow(L,2))-4*L+1;
	FpR=2*R*pow(e,pow(R,2))-4*R+1;

	if(!(FpL>=0||FpR<=0))
	{
		while(as!=true)
		{	
			z=(L+R)/2;
			FpZ=2*z*pow(e,pow(z,2))-4*z+1;
			if(FpZ>=0)
			{
				R=z;
			}
			else
			{
				L=z;
			}
			Fmod=FpZ;
			if(Fmod<0)
				Fmod=0-Fmod;
			if(Fmod<=E1)
				as=true;
			i++;
		}

	}
	Fx=pow(e,pow(z,2))-2*pow(z,2)+z-1;
	xres=z;
	fres=Fx;
	itr=i-1;
}