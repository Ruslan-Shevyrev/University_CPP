#include "StdAfx.h"
#include <conio.h>
#include <string>
#include <iostream>

int main()
{
	setlocale(LC_CTYPE, "rus");
	std::string U[5]={"морковь","лук","картофель","огурцы","свекла"};
	int    a[5]={1,0,1,0,1}, 
		b[5]={0,0,1,1,1}, 
		c[5]={1,0,1,0,1};
	std::cout<<"перечень:"<<"\n";
	for (int i = 0; i<5; i++)
	{
	std::cout<<U[i]<<' ';
	}

	std::cout<<"\n"<<"\n"<<"культуры возделываемые во всех колхозах:\n";

	for (int i = 0; i<5; i++)
	{
	if ((a[i] == 1)&& (b[i] == 1) && (c[i] == 1))
	{
	std::cout<<U[i]<<' ';
	}
	}

	std::cout<<"\n"<<"\n"<<"культуры возделываемые в некоторых колхозах:\n";

	for (int i = 0; i<5; i++)
	{
	if ((a[i] == 1) || (b[i] == 1) || (c[i] == 1))
	{
	std::cout<<U[i]<<' '; 
	}
	}
	getch();
	return 0;
}