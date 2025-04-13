#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;

float eps; //коэффециент корректировки
float y; // Желаемый выходной параметрс ИНС
float yy; // фактический выходной параметр ИНС 
float	osh; //Ошибка между входным и выходным параметром 
float	sum; //сумма по каждой выборке 
float	k; //корректировка весовых коэффецментов 
float	pogr; // Разрешенная погрешность вычислений
float	l;
int n;
int i,j;
int buff;
float vekt[10000]; // вектор входных параметров
float w[10000]; // вектор весовых коэффециентов


//активационная функция
float func(float x)
{
return x;
}

int main()
{
	cout<<"Parametricheskae identifikaciya perseptrona\n";
	cout<<"vvedite pogreshnost vychislenia\n";
	cin>>pogr;
	ifstream fin("in.txt");
	fin>>n;
	fin >> buff;	
	for (i=0;i<n;i++)
		{
		w[i]=1;
		}
	
	for(j=0;j<buff;j++)
	{
	yy=0;

	for (i=0;i<n;i++)
		{
		fin>>vekt[i];
		}
	eps = 0.0001;


	fin>>y;


	for (i=0;i<n;i++)
		{
		sum=sum+vekt[i]*w[i];
		}

	yy=func(sum);

	l=yy-y;

	while (pogr<abs(l))
	{
		
	osh=y-yy;

	for (i=0;i<n;i++)
 {

  k=eps*osh*vekt[i]*abs(w[i]);

  w[i]=w[i]+k;
 }

sum=0;

for (i=0;i<n;i++)
{
sum=sum+vekt[i]*w[i];
}

yy=func(sum);

l=yy-y;

	}
	}
for (i=0;i<n;i++)
{
cout<<"w"<<i+1<<"="<<w[i]<<"\n";
}


getch();
	return 0;
}
