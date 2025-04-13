#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;



float osh;
float osh1;
float y; 
float	sum;
float	sum1;
int n =3;
int i,j,k;
float arr[10000]; 
int arr1[10000]; 


//активационные функции
float func1(float x)
{
return x;
}

float func2(float x)
{
return x*x;
}

float func3(float x)
{
return x*x*x;
}

float func4(float x)
{
return 1-x;
}

void proc(int x, float s)
{

switch (arr1[i])
{
 case 1 : sum1=sum1-s;
	break;
 case 2: sum1=sum1-s*s;
	 break;
 case 3: sum1=sum1-s*s*s;
	 break;
}

switch (x)
{
 case 2 : sum1=sum1+func2(s);
	break;
 case 3: sum1=sum1+func3(s);
	 break;
 case 4: sum1=sum1+func4(s);
	 break;
}


}

int main()
{
cout<<"Strukturnaya identifikaciya\n";

	for (i=0;i<n;i++)
		{
		cout<<"vvedite "<<i+1<<"-oe znachenie\n";
		cin>>arr[i];
		}
	cout<<"vvedite vyhodnoy parametr\n";
	cin>>y;

	for (i=0;i<n;i++)
		{
		arr1[i]=1;
		}

	for (i=0;i<n;i++)
		{
	sum=sum+arr[i];
	sum1=sum1+arr[i];
		}

	osh=abs(sum-y);

	for (i=0;i<n;i++)
	{
	for (j=1;j<5;j++)
		{	
			proc(j,arr[i]);
			osh1=abs(sum1-y);
			if (osh1<osh)
			{
			 arr1[i]=j;
			 osh=osh1;
			 sum=sum1;
			}
			else
			{
			sum1=sum;
			}
		}
	}

	for (i=0;i<3;i++)
	{
		switch (arr1[i])
			{
				case 1 :cout<<i+1<<"-j neyron = x\n";
				break;
				case 2: cout<<i+1<<"-j neyron = x*x\n";
				break;
				case 3: cout<<i+1<<"-j neyron = x*x*x\n";
				break;
				case 4: cout<<i+1<<"-j neyron = 1-x\n";
				break;
}
	
	}

getch();
	return 0;
}
