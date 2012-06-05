//NutRaf.cpp
#include "NutRaf.h"

using namespace FindOpt;

NutRaf::NutRaf(double q, double w, double j, double r, double t, double y)
{
	X0=q;
	d=w;
	a=j;
	b=r;
	E1=t;
	E2=y;
}

void NutRaf::Calc()
{
	bool as=false;	
	double Xp;
	double Fp1;	
	double Fp2;	
	double Fmod;
	double Fx;
	int i=1;
	Xp=X0;
	while(as!=true)
	{	
		Fp1=2*Xp*pow(e,pow(Xp,2))-4*Xp+1;
		Fp2=2*pow(e,pow(Xp,2))+4*Xp*Xp*pow(e,pow(Xp,2))-4;

		Xp=Xp-(Fp1/Fp2);
		Fmod=Fp1;
		if(Fmod<0)
			Fmod=0-Fmod;
		if(Fmod<=E1)
			as=true;
		i++;
	}
	Fx=pow(e,pow(Xp,2))-2*pow(Xp,2)+Xp-1;
	xres=Xp;
	fres=Fx;
	itr=i-1;
}