#include "StdAfx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
  FILE *fp, *fp1;
  int n, a, k , s=0;
  printf("enter n\n");
	scanf("%d",&n);
	printf("enter k\n");
	scanf("%d",&k);
	  printf("enter numbers\n");
  fp=fopen("file1", "wb+");
  fp1=fopen("file2", "wb+");
  for (int i = 1; i<n; i++)
  {
  scanf("%d",&a);
  fwrite(&a, sizeof(int), 1, fp);
  }; 

  rewind(fp);
  for (int i = 1; i<n; i++)
  {
    fread(&a, sizeof(int), 1, fp);
	if ((a % k)!=0)
	{
	fwrite(&a, sizeof(int), 1, fp1);
	s++;
	}
  }

  rewind(fp1);
  printf("numbers in file2 \n");
    for (int i = 1; i<=s; i++)
  {
    fread(&a, sizeof(int), 1, fp1);
	printf("%d ", a);
  }
  fclose(fp);
  fclose(fp1);
  getch();
  return 0;
}
