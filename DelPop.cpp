//DelPop.cpp
#include "DelPop.h"

using namespace FindOpt;

DelPop::DelPop(double i, double j, double k, double m, double f)
{
	a=i;
	b=j;
	x[0]=k;
	d=m;
	E=f;
}

void DelPop::Calc()
{	
	int p=1;		
	int q=0;		
	double a1=a,b1=b;	
	double xm;		
	double L;		
	double x1,x2;	
	double f1,f2,fm;	
	while(q!=1)
	{
		xm=(a1+b1)/2; 
		L=b1-a1;		
	
		x1=a1+L/4;
		x2=b1-L/4;
		f1=pow(e,pow(x1,2))-2*pow(x1,2)+x1-1;
		f2=pow(e,pow(x2,2))-2*pow(x2,2)+x2-1;
		fm=pow(e,pow(xm,2))-2*pow(xm,2)+xm-1;
		
		if(f1>fm)
		{
			a1=x1;
		}
		if(f2>fm)
		{
			b1=x2;
		}
		if(f1<fm)
		{
			b1=xm;
		}
		if(f2<fm)
		{
			a1=xm;
		}
		if(L<E)
		{
			q=1;
		}
	p++;
	}
	xres=(a1+b1)/2;
	fres=pow(e,pow(xres,2))-2*pow(xres,2)+xres-1;
	itr=p-1;
}