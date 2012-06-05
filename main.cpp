//main.cpp
#include "COpt.h"
#include "DelPop.h"
#include "ZolSech.h"
#include "Pauell.h"
#include "NutRaf.h"
#include "Bolts.h"
#include "Hord.h"
#include "CubApr.h"

using namespace FindOpt;

int main()
{
	const int n=7;
	timeval timer[n+1];
	long t[n];
	double x[n];
	double fx[n];

	DelPop A(-3,3,1,0.5,0.001);
	ZolSech B(-3,3,1,0.5,0.001);
	Pauell C(1,0.5,0.001,0.001);
	NutRaf D(1,0.5,-3,3,0.001,0.001);
	Bolts E(1,0.5,-3,3,0.001,0.001);
	Hord F(1,0.5,-3,3,0.001,0.001);
	CubApr G(1,0.5,-3,3,0.001,0.001);

	COpt *Z[n];
	Z[0]=&A;
	Z[1]=&B;
	Z[2]=&C;
	Z[3]=&D;
	Z[4]=&E;
	Z[5]=&F;
	Z[6]=&G;

        gettimeofday(&timer[0], 0);
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<1;j++) Z[i]->Calc();
		gettimeofday(&timer[i+1], 0);
		t[i]=((timer[i+1].tv_sec  - timer[i].tv_sec) * 1000000 
                        + (timer[i+1].tv_usec - timer[i].tv_usec)) + 0.5;
	}
        
	int sw[]={25,10,10,10,15};
	int k=sw[0]+sw[1]+sw[2]+sw[3]+sw[4]+5;
	char ctmp[64];
	cout << endl ;
	for (int i=0;i<k;i++) cout << "=";
	cout << endl << "|" << setw(sw[0]) << "Method's name" 
				 << "|" << setw(sw[1]) << "Iteration"
				 << "|" << setw(sw[2]) << "Time (us)" 
				 << "|" << setw(sw[3]) << "X value" 
				 << "|" << setw(sw[4]) << "F(X) value" << "|";
	for (int j=0;j<n;j++)
	{
		switch (j)
		{
                case 0: strcpy(ctmp,"Division by two"); break;
		case 1: strcpy(ctmp,"Gold ration"); break;
		case 2: strcpy(ctmp,"Pauell's"); break;
		case 3: strcpy(ctmp,"Nuton-Rafson's"); break;
		case 4: strcpy(ctmp,"Bolt's"); break;
		case 5: strcpy(ctmp,"Chord"); break;
		case 6: strcpy(ctmp,"Cubic approximation"); break;
		}
		cout << endl;
		for (int i=0;i<k;i++) cout << "-";
		cout << endl << "|" << setw(sw[0]) << ctmp 
					 << "|" << setw(sw[1]) << Z[j]->GetI()
					 << "|" << setw(sw[2]) << t[j] 
					 << "|" << setw(sw[3]) << Z[j]->GetX() 
					 << "|" << setw(sw[4]) << Z[j]->GetFX()  << "|";
	}
	cout << endl;
	for (int i=0;i<k;i++) cout << "=";
        
        return 0;
}