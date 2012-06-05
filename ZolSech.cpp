//ZolSech.cpp
#include "ZolSech.h"

using namespace FindOpt;

ZolSech::ZolSech(double i, double j, double k, double m, double f)
{
	a=i;
	b=j;
	x[0]=k;
	d=m;
	E=f;
}

void ZolSech::Calc()
{
	int p=1;		
	double mod;		
	int q0=0;		
	double az,bz;	
	double G=1.618;				
	double xz1,xz2,fz1,fz2;
	az=a;	bz=b;	
	
	xz1=bz-(bz-az)/G;
	xz2=az+(bz-az)/G;
	
	fz1=pow(e,pow(xz1,2))-2;
	fz2=pow(e,pow(xz2,2))-2;

	while(q0!=1)
	{
		if(fz1<=fz2)
		{
			p++;

                        bz=xz2;
			xz2=xz1;
			xz1=bz-(bz-az)/G;
			fz2=fz1;
			fz1=pow(e,pow(xz1,2))-2*pow(xz1,2)+xz1-1;
		}
		else
		{	
			p++;
			az=xz1;
			xz1=xz2;
			xz2=az+(bz-az)/G;
			fz1=fz2;
			fz2=pow(e,pow(xz2,2))-2*pow(xz2,2)+xz2-1;
		}
		mod=fabs(bz-az);
		if(mod<E)
		{
			q0=1;
		}
	}
	xres=(az+bz)/2;
	fres=pow(e,pow(xres,2))-2*pow(xres,2)+xres-1;
	itr=p;
}