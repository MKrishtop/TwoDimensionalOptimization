//Hord.cpp
#include "Hord.h"

using namespace FindOpt;

Hord::Hord(double q, double w, double j, double r, double t, double y)
{
	X0=q;
	d=w;
	a=j;
	b=r;
	E1=t;
	E2=y;
}

void Hord::Calc()
{
	double z;
	double L;
	double R;
	double Fdz;	
	double Fdl;
	double Fdr;	
	double Fx;
	L=X0;	
	Fdl=2*L*pow(e,pow(L,2))-4*L+1;
	if(Fdl<0)
	{		
		R=L+1;	
		Fdr=2*R*pow(e,pow(R,2))-4*R+1;
		if(Fdr<Fdl) R=L-1;
		Fdr=2*R*pow(e,pow(R,2))-4*R+1;
		if(Fdr<0)
		{
			do
			{
				if(Fdr>Fdl) {R++; L++;}
				else {R--; L--;}
				Fdr=2*R*pow(e,pow(R,2))-4*R+1;
			}
			while(Fdr<0);
		}
	}
	else 
	{
		R=L;
		Fdr=2*R*pow(e,pow(R,2))-4*R+1;
		L=R-1;
		Fdl=2*L*pow(e,pow(L,2))-4*L+1;
		if(Fdl>0)
		{
			do
			{
				if(Fdl<Fdr) {R--; L--;}
				else {R++; L++;}
				Fdl=2*L*pow(e,pow(L,2))-4*L+1;
			}
			while(Fdl>0);
		}
	}

	int i=0;
	while(1)
	{
		i++;
		Fdl=2*L*pow(e,pow(L,2))-4*L+1;
		Fdr=2*R*pow(e,pow(R,2))-4*R+1;
		z=R-Fdr/((Fdr-Fdl)/(R-L));
		Fdz=2*z*pow(e,pow(z,2))-4*z+1;
                
		if(Fdz<=E1) break;	
		else if(Fdz<0) L=z;	
		else if(Fdz>0) R=z;
	}
	Fx=pow(e,pow(z,2))-2*pow(z,2)+z-1;
	xres=z;
	fres=Fx;
	itr=i;
}