//Pauell.cpp
#include "Pauell.h"

using namespace FindOpt;

Pauell::Pauell(double i, double j, double k, double m)
{
	X0=i;
	d=j;
	E1=k;
	E2=m;
}

void Pauell::Calc()
{
	int i=1;
	int fl=0;
	double x1=X0,x2,x3,xc,f1,f2,f3,fc,fmin,xmin;
	double a1,a2;
	double kx,kf;
	x2=x1+d;
	f1=pow(e,pow(x1,2))-2*pow(x1,2)+x1-1;
	f2=pow(e,pow(x2,2))-2*pow(x2,2)+x2-1;
	if(f1>f2) 
	{
		x3=x1+2*d;
	}
	else	
	{
		x3=x1-d;
	}

	while(fl!=1)
	{
		f1=pow(e,pow(x1,2))-2*pow(x1,2)+x1-1;
		f2=pow(e,pow(x2,2))-2*pow(x2,2)+x2-1;
		f3=pow(e,pow(x3,2))-2*pow(x3,2)+x3-1;
		
		a1=(f2-f1)/(x2-x1);
		a2=((f3-f1)/(x3-x1)-a1)/(x3-x2);
		xc=(x2+x1)/2-a1/(2*a2);
		fc=pow(e,pow(xc,2))-2*pow(xc,2)+xc-1;

		if(f1<f2&&f1<f3)
		{
			fmin=f1; 
			xmin=x1;
		}
		if(f2<f1&&f2<f3)
		{
			fmin=f2; 
			xmin=x2;
		}
		if(f3<f1&&f3<f2)
		{
			fmin=f3; 
			xmin=x3;
		}
                
		kf=fabs((fmin-fc)/fc);
		kx=fabs((xmin-xc)/xc);

		if(kf<E2&&kx<E1)
		{
			fl=1;
		}
		else
		{
			if(fmin<=fc)
			{
				x2=xmin;
				x1=x2-d;
				x3=x2+d;
			}
			else
			{
				if(xc<x1&&xc<x2&&xc<x3)
				{
					x3=x2;
					x2=x1;
					x1=xc;
				}
				if(xc>x1&&xc>x2&&xc>x3)
				{
					x1=x2;
					x2=x3;
					x3=xc;
				}
				if(xc>x1&&xc<x2&&xc<x3)
				{
					x3=x2;
					x2=xc;
					x1=x1;
				}
				if(xc>x1&&xc>x2&&xc<x3)
				{
					x3=x3;
					x1=x2;
					x2=xc;
				}
			}
			i++;
		}
	}
	xres=xmin;
	fres=pow(e,pow(xres,2))-2*pow(xres,2)+xres-1;
	itr=i-1;
}

double* Pauell::sort(double* i, int j)
{
	double tmp;
	for (int p=0;p<j-1;p++)
		for (int c=p;c<j;c++)
			if (i[p]>i[c])
			{
				tmp=i[p];
				i[p]=i[c];
				i[c]=tmp;
			}
	return (i);
}