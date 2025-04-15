#include <iostream>
#include "stdafx.h"
#include<stdio.h>
#include<string>
#include<conio.h>
#include <cstdlib>
int main()
{
   void multi_m(char *,char *,char *);
   char a[100],b[100],c[100000];
   memset(b,0,100);
   printf("a=");
   gets(a);
   int l=strlen(a);
   for(int i=0;i<l;i++)
   {
	   b[i] = a[i];
   };
   std::string tr = b;
   int kol = atoi(tr.c_str());
   for (int i=1;i<kol;i++)
   {
   multi_m(a,b,c);
	  int l=strlen(c);
	  memset(a,0,100);
      for(int i=0;i<l;i++)
   {
	   a[i] = c[i];
   };
//   printf("%s\n",a);
   }
   printf("%s^%s=%s\n",b,b,c);
   printf("Press any key ... \n");
   getch();
   return 0;
}
void multi_m(char *a,char *b,char *c)
{
   int i,j,lb;
   char temp[100];
   void multi(char *,char,char *);
   void add(char *,char *,char *);
   void multi10(char *);
   strrev(a);
   strrev(b);
   lb=strlen(b);
   strcpy(c,"0");
   for(i=0;i<lb;i++)
   {
      multi(a,b[i],temp);
      for(j=0;j<i;j++)
	   multi10(temp);
      add(c,temp,c);
   }
   strrev(a);
   strrev(b);
}
void multi(char *a,char b,char *c) 
{
   int i,l,in_mind=0,t;
   l=strlen(a);
   for(i=0;i<l;i++)
   {
      t=(a[i]-'0')*(b-'0')+in_mind;
      if(t<=9)
      {
	   c[i]=t+'0';
	   in_mind=0;
      }
      else
      {
	   c[i]=t%10+'0';
	   in_mind=t/10;
      }
   }
   if(in_mind>0)
   {
      c[i++]=in_mind+'0';
   }
   c[i]='\0';
   strrev(c);
}
void add(char *a,char *b,char *c)
{
   int i,l1,l2,l,in_mind=0;
   char *t;
   strrev(a);
   strrev(b);
   l1=strlen(a);
   l2=strlen(b);
   if(l2>l1)
   {
      l=l1; l1=l2; l2=l; 
      t=a; a=b; b=t;
   }
   for(i=0;i<l2;i++)
   {
      c[i]=(a[i]-'0')+(b[i]-'0')+in_mind;
      in_mind=c[i]/10;
      c[i]=c[i]%10+'0';
   }
   for(i=l2;i<l1;i++)
   {
      c[i]=(a[i]-'0')+in_mind;
      in_mind=c[i]/10;
      c[i]=c[i]%10+'0';
   }
   if(in_mind)
   {
      c[i++]=in_mind+'0';
   }
   c[i]='\0';
   strrev(c);
}
void multi10(char *a)
{
   int l;
   l=strlen(a);
   a[l]='0';
   a[l+1]='\0'; 
}
