//CubApr.cpp
#include "CubApr.h"

using namespace FindOpt;

CubApr::CubApr(double q, double w, double j, double r, double t, double y)
{
	X0=q;
	d=w;
	a=j;
	b=r;
	E1=t;
	E2=y;
}

void CubApr::Calc()
{
	double X1;	
	double X2;	
	double Fx1;	
	double Fx2;	
	double Fdx1;		
	double Fdx2;
	X1=X0;
	Fdx1=2*X1*pow(e,pow(X1,2))-4*X1+1;
	int i;
	if(Fdx1<0)
	{
		X2=X1+d;
		for(double i=0;;i++)
		{
			Fdx2=2*X2*pow(e,pow(X2,2))-4*X2+1;
			if(Fdx1*Fdx2>0)
			{
				X1=X2;
				X2=X1+d*pow(2,i);
				Fdx1=2*X1*pow(e,pow(X1,2))-4*X1+1;
			}
			else break;
		}
	}
	else 
	{
		X2=X1-d;
		for(double i=0;;i++)
		{
			Fdx2=2*X2*pow(e,pow(X2,2))-4*X2+1;
			if(Fdx1*Fdx2>0)
			{
				X1=X2;
				X2=X1-d*pow(2,i);
				Fdx1=2*X1*pow(e,pow(X1,2))-4*X1+1;
			}
			else break;
		}
	}
	Fx1=pow(e,pow(X1,2))-2*pow(X1,2)+X1-1;
	Fx2=pow(e,pow(X2,2))-2*pow(X2,2)+X2-1;
	Fdx1=2*X1*pow(e,pow(X1,2))-4*X1+1;
	Fdx2=2*X2*pow(e,pow(X2,2))-4*X2+1;
	double z;
	double m;
	double w;
	double X;
	double Fx;
	double Fdx;
	int count=0;
	while(1)
	{
		count++;
		z=3*(Fx1-Fx2)/(X2-X1)+Fdx1+Fdx2;
		if(X1<X2) w=sqrt(pow(z,2)-Fdx1*Fdx2);
		else w=-sqrt(pow(z,2)-Fdx1*Fdx2);
		m=(Fdx2+w-z)/(Fdx2-Fdx1+2*w);
		if(m<0) X=X2;
		else if(m>=0 && m<=1) X=X2-m*(X2-X1);
		else X=X1;
		Fx=pow(e,pow(X,2))-2*pow(X,2)+X-1;

		while(Fx>Fx1)
		{
			X=X+0.5*(X-X1);
			Fx=pow(e,pow(X,2))-2*pow(X,2)+X-1;
		}
		Fdx=2*X*pow(e,pow(X,2))-4*X+1;
		if(fabs(Fdx)<=E1 && fabs((X-X1)/X)) 
		{
			 break;
		}
		else if(Fdx*Fdx1<0) 
		{
			X2=X1;
			X1=X;
			Fx1=pow(e,pow(X1,2))-2*pow(X1,2)+X1-1;
			Fx2=pow(e,pow(X2,2))-2*pow(X2,2)+X2-1;
			Fdx1=2*X1*pow(e,pow(X1,2))-4*X1+1;
			Fdx2=2*X2*pow(e,pow(X2,2))-4*X2+1;
		}
		else if(Fdx*Fdx2<0)
		{
			X1=X;
			Fx1=pow(e,pow(X1,2))-2*pow(X1,2)+X1-1;
			Fdx1=2*X1*pow(e,pow(X1,2))-4*X1+1;
		}
	}
	Fx=pow(e,pow(X,2))-2*pow(X,2)+X-1;
	xres=X;
	fres=Fx;
	itr=count;
}