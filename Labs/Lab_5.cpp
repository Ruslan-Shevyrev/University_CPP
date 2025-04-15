#include "stdafx.h"
#include <stdio.h>
#include <conio.h>

using namespace std;
int recurs (int a, int b)
{
if (a > 0) {
         recurs (a / b, b);
         printf ("%d", a % b);
	    }
	return 0;
}
int main()
{
	int numb;
	int syst;
	printf ("enter number \n");
	scanf("%d",&numb);
	printf ("enter scale \n");
	scanf("%d",&syst);
    if (syst > 9)
	{
		printf ("scale not in 2<n<9 \n");
	}
	else
	{
		recurs(numb,syst);
	}
	printf ("\n");
	getch();
	return 0;
}
