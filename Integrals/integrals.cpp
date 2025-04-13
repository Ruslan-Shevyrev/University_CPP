#include"stdafx.h"
#include<glut.h>//Подключение библиотеки glut.h
#include<iostream>
#include<string>
#include<Math.h>


staticGLfloatxRot = 0.0f;
staticGLfloatyRot = 0.0f;
staticGLfloatzRot = 1.0f;
staticbool graphic;
staticbool button1;
staticbool button2;
staticbool button3;
staticbool button4;
staticbool button5;
staticbool button6;
staticbool button7;
staticbool integral=false;
staticboolintegraltrap=false;
staticboolintegralsimp=false;
staticboolabchange;
staticboolFunctionDr;
staticdouble a=-2;
staticdouble b=2;
staticdouble shag=1;
staticdoublesumint=0.0f;
staticdoublesuminttrap=0.0f;
staticcharDrawQuad[20];
staticcharDrawTrap[20];
staticcharDrawSimp[20];
std::stringDrawFunc;
staticintpos=0;
staticintposshag=0;
staticintposshagf=0;
staticstd::string fshag="1.0";
staticstd::string fa="-2";
staticstd::string fb="2";
staticstd::string ffun="exp(x)*sin(x)";
staticboolvvodshag=false;
staticboolvvodab=false;
staticboolprovfunc=false;


/////////////////Обработкафункции(демо)/////////////////////////////////////////////////

double func11(std::string function, double x)
{
	double mass1[100];
	int mass2[100];
	int i=0;
	int nom=1;
	std::stringstr="";
	while (i<function.size())
	{
	if ((function[i]!='+')  & (function[i]!='-') & (function[i]!='*') & (function[i]!='/'))
	{	
		str=str+function[i];
	}
	else
	{
	switch (function[i])
      {
case'+':
		mass2[nom]=3;
			break; 

case'-':
		mass2[nom]=4;
			break;

case'*':
mass2[nom]=1;
break;

	case'/':
mass2[nom]=2;
break;		
      }
			if (str=="x")
			{
			mass1[nom]=x;
			}
			else
			{
			mass1[nom]=atof(str.c_str());
			}
			str="";
			nom++;

	}
	i++;
	}
			if (str=="x")
			{
			mass1[nom]=x;
			}
			else
			{
			mass1[nom]=atof(str.c_str());
			}
	str="";
	mass2[nom]=0;

	int t = nom;
	int k=1;

/////////////////РЕШЕНИЕ/////////////////////////////////////////////////////////////////
while (mass2[k]!=0)
{
switch (mass2[k])
       {
case 1:
		mass1[k]=mass1[k]*mass1[k+1];
		for (int u = k+1; u<t;u++)
		 {
		mass1[u]=mass1[u+1];
		 }
		for (int u = k; u<t;u++)
		 {
		mass2[u]=mass2[u+1]; 
		 }
		 t=t-1;
			break; 

case 2:
		mass1[k]=mass1[k]/mass1[k+1];
		for (int u = k+1; u<t;u++)
		 {
		mass1[u]=mass1[u+1];
		 }
		for (int u = k; u<t;u++)
		 {
		mass2[u]=mass2[u+1]; 
		 }
		 t=t-1;
			break; 

		default:
		k++;
		break;

		}
}

k=1;

while (mass2[k]!=0)
{
switch (mass2[k])
       {
case 3:
		mass1[k]=mass1[k]+mass1[k+1];
		for (int u = k+1; u<t;u++)
		 {
		mass1[u]=mass1[u+1];
		 }
		for (int u = k; u<t;u++)
		 {
		mass2[u]=mass2[u+1]; 
		 }
		 t=t-1;
			break; 

case 4:
		mass1[k]=mass1[k]-mass1[k+1];
		for (int u = k+1; u<t;u++)
		 {
		mass1[u]=mass1[u+1];
		 }
		for (int u = k; u<t;u++)
		 {
		mass2[u]=mass2[u+1]; 
		 }
		 t=t-1;
			break;

		}
}

	return(mass1[1]);

}



////ФУНКЦИЯ//////////////////////////////////////////////////////////////////////////////
doublefunc(doublearg)
{
	//double f = arg*arg*arg;
	//double f =sin(arg)*arg;
	//double f=arg*arg+3*cos(arg);
	//double f=cos(arg*3+5);
	//double f=arg+3; 
	double f=exp(arg)*sin(arg);
	return(f);

}

/////////////////СЧИТАЕМ ИНТЕГРАЛ ТРАПЕЦИИ////////////////////////////////////////////


double integral2(double c)
{
double d;    
d=0;
doubleast=a;
doublebst=b;
//int k=0;
intzn = int((bst-ast)/c);
for (intqw=1; qw<=zn; qw++)
{
	if(FunctionDr==false)
d=d+(func(ast)+func(ast+c))/2*c;
	else
d=d+(func11(DrawFunc,ast)+func11(DrawFunc,ast+c))/2*c;
	ast=ast+c;
//	k=k+1;
}

return(d);
}


//////////////////////////////////СЧИТАЕМИНТЕГРАЛКВАДРАТ///////////////////////////////

double integral1(double c)
{
double d;    
d=0;
doubleasq=a;
doublebsq=b;
while (asq<bsq)
{
	if (FunctionDr==true)
		d=d+func11(DrawFunc,asq)*c;
	else
		d=d+func(asq)*c;
asq=asq+c;
}
return(d);
}

/////////////////////////////////////////////////СЧИТАЕМИНТЕГРАЛСИМПСОНА/////////////
double integral3(double c)
{
double d;
d=0;
double ass=a;
doublebss=b;
intzn = int(((bss-ass)/c)/2);
double y11=0;
double y22=0;
if(FunctionDr==false)
{
for (intqw=1; qw<=zn; qw++)
{
	y11=y11+func(ass);
	y22=y22+func(ass+c);
	ass=ass+c*2;
}
y11=y11-func(a);
d=(4*y22+2*y11+func(a)+func(b))*c/3;
}
else
{
for (intqw=1; qw<=zn; qw++)
{
	y11=y11+func11(DrawFunc,ass);
	y22=y22+func11(DrawFunc,ass+c);
	ass=ass+c*2;
}
y11=y11-func11(DrawFunc,a);
d=(4*y22+2*y11+func11(DrawFunc,a)+func11(DrawFunc,b))*c/3;
}
std::cout<<d;
return(d);


}
//////////////////////ПРОРИСОВКАТЕКСТА//////////////////////////////////////////////////
voiddraw_string_bitmap(void *font, constchar* string) 
{
while (*string)
glutBitmapCharacter(font, *string++);
}


voiddraw_string_stroke(void *font, constchar* string) 
{
while (*string)
glutStrokeCharacter(font, *string++);
}

///////////////////////////////////СЦЕНА/////////////////////////////////////////////////
voidRenderScene(void)
{
	GLfloatx,y,z,angle;

	glClear(GL_COLOR_BUFFER_BIT);


	glViewport(0, 0, 600, 600);
	glOrtho (-10, 10, -10, 10, -10, 10);
	glColor3f(0.0f,0.0f, 0.0f);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
//////////////////////////Рисуемсистемукоординат//////////////////////////////////////
	glPushMatrix();
	glRotatef(xRot, 1.0f, 0.0f, 0.0f);
	glRotatef(yRot, 0.0f, 1.0f, 0.0f);
	glScalef(zRot, zRot, zRot);

	glColor3f(0.0f, 1.0f, 0.0f);

	glLineWidth(5);
	glBegin(GL_LINES);
	glVertex3f(-10.0f,0.0f,0.0f);
	glVertex3f(10.0f,0.0f,0.0f);
	glVertex3f(0.0f,-10.0f,0.0f);
	glVertex3f(0.0f,10.0f,0.0f);
	glVertex3f(0.0f,0.0f,-10.0f);
	glVertex3f(0.0f,0.0f,10.0f);
	glVertex3f(1.0f,0.5f,0.0f);
	glVertex3f(1.0f,-0.5f,0.0f);
	glVertex3f(-1.0f,0.5f,0.0f);
	glVertex3f(-1.0f,-0.5f,0.0f);
	glEnd();
	




	glLineWidth(1.0f);
	glColor3f(1.0f,0.5f, 0.0f);
	glRasterPos2f(0.0f, 0.0f);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '0');

	glPushMatrix();
	glLineWidth(2.0f);
	glTranslatef(0.08f, 0.07f, 0.0f);
	glScalef(0.005f, 0.005f, 0.005f);
	glutStrokeCharacter(GLUT_STROKE_ROMAN, '1');
	glPopMatrix();

	glPushMatrix();
	glLineWidth(2.0f);
	glTranslatef(-0.16f, 0.07f, 0.0f);
	glScalef(0.005f, 0.005f, 0.005f);
	glutStrokeCharacter(GLUT_STROKE_ROMAN, '-');
	glPopMatrix();

	glPushMatrix();
	glLineWidth(2.0f);
	glTranslatef(-0.11f, 0.07f, 0.0f);
	glScalef(0.005f, 0.005f, 0.005f);
	glutStrokeCharacter(GLUT_STROKE_ROMAN, '1');
	glPopMatrix();


///////////////////////Рисуемфункцию///////////////////////////////////////////

	glColor3f(1.0f, 0.0f, 0.0f);
	glLineWidth(5.0f);
	glBegin(GL_LINE_STRIP);
	if ((graphic==true) & (FunctionDr==false))
	for(angle=-10.0f; angle<10.0f; angle+=0.1f)
		{
			x=angle;
			y=func(x);
			glVertex3f(x,y,0);
		}
	if ((graphic==true) & (FunctionDr==true))
	for(angle=-10.0f; angle<10.0f; angle+=0.1f)
		{
			x=angle;
			y=func11(DrawFunc,x);
			glVertex3f(x,y,0);
		}

	glEnd();

////////////////////////Рисуеминтегралквадрат///////////////////////////////
	
	if ((integral==true) & (graphic==true))
	{

	doubleaq=a;
	doublebq=b;
	while(aq<bq)
	{

		if (FunctionDr==false)
	y=func(aq);
		else
	y=func11(DrawFunc,aq);
	glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(aq, y, 0.0f);
	glVertex3f(aq+shag, y, 0.0f);
	glVertex3f(aq+shag, 0.0f, 0.0f);
	glVertex3f(aq, 0.0f, 0.0f);
	glEnd();
	aq=aq+shag;
	sumint=sumint+func(aq)*shag;
	}
	sprintf(DrawQuad,"%f",integral1(shag));
	sumint=0;	
	}
////////////////////////Рисуем интеграл методом трапеций/////////////////////////////////

	if ((integraltrap==true) & (graphic==true))
	{
double at=a;
doublebt=b;	
	
	while(at<bt)
	{
	if (FunctionDr==false)
	{
	y=func(at);
	z=func(at+shag);
	}
	else
	{
	y=func11(DrawFunc,at);
	z=func11(DrawFunc,at+shag);
	}
	glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex3f(at, y, 0.0f);
	glVertex3f(at+shag, z, 0.0f);
	glVertex3f(at+shag, 0.0f, 0.0f);
	glVertex3f(at, 0.0f, 0.0f);
	glEnd();
	at=at+shag;
	}
	sprintf(DrawTrap,"%f",integral2(shag));
	suminttrap=0;	
	}

	


/////////////////////////////////////////////////РисуеминтегралСимпсона///////////////
	if ((integralsimp==true) & (graphic==true))
	{
	double x1=a;	
	while (x1<b)
	{	
	double x3=x1+shag;
	double x2=x3-shag/2;
	double y1;
	double y2;
	double y3;

	if (FunctionDr==false)
	{
	y1=func(x1);
	y2=func(x2);
	y3=func(x3);
	}
	else
	{
	y1=func11(DrawFunc,x1);
	y2=func11(DrawFunc,x2);
	y3=func11(DrawFunc,x3);
	
	};


	double a1=(y3-((x3*(y2-y1)+x2*y1-x1*y2)/(x2-x1)))/(x3*(x3-x1-x2)+x1*x2);
	double b1=(y2-y1)/(x2-x1)-a1*(x1+x2);
	double c1=(x2*y1-x1*y2)/(x2-x1)+a1*x1*x2;
	intkkk=0;
	glColor3f(0.0f, 1.0f, 1.0f);
	glLineWidth(5.0f);
	glBegin(GL_LINE_STRIP);
	double angle1=x1;
	for(intnn=1; nn<=51; nn++)
	{   
		x=angle1;
		y=a1*(x*x)+b1*x+c1;
		glVertex3f(x,y,0);
		angle1=angle1+shag/50;
	}
	glEnd();
	x1=x1+shag;
	}
	sprintf(DrawSimp,"%f",integral3(shag));
	}


	glPopMatrix();
///////////////ВЫВОДДАННЫХ////////////////////////////////////////////////	
	glViewport(600, 0, 200, 600);


	glLineWidth(1.0f);
	glColor3f(1.0f,1.0f, 0.0f);
	glRasterPos2f(-9.7f, 9.0f);
	draw_string_bitmap(GLUT_BITMAP_HELVETICA_18, "quad=");
	glRasterPos2f(0.0f, 9.0f);
	draw_string_bitmap(GLUT_BITMAP_HELVETICA_18, DrawQuad);



	glLineWidth(1.0f);
	glColor3f(1.0f,1.0f, 0.0f);
	glRasterPos2f(-9.7f, 8.0f);
	draw_string_bitmap(GLUT_BITMAP_HELVETICA_18, "trap=");
	glRasterPos2f(0.0f, 8.0f);
	draw_string_bitmap(GLUT_BITMAP_HELVETICA_18, DrawTrap);

		glLineWidth(1.0f);
	glColor3f(1.0f,1.0f, 0.0f);
	glRasterPos2f(-9.7f, 7.0f);
	draw_string_bitmap(GLUT_BITMAP_HELVETICA_18, "simp=");
	glRasterPos2f(0.0f, 7.0f);
	draw_string_bitmap(GLUT_BITMAP_HELVETICA_18, DrawSimp);

//////////////////////////РисуемКнопки/////////////////////////////////////////
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glLineWidth(5);
	glBegin(GL_LINES);
	glColor3f(0.0f,0.0f,1.0f);
	glVertex3f(-10.0f,10.0f,0.0f);
	glVertex3f(-10.0f,-10.0f,0.0f);
	glEnd();

	////////////////////// Рисуемпервуюкнопку/////////////////////////////////////

	if (button1==true)
	glColor3f(1.0f, 0.0f, 0.0f);
	else
	glColor3f(0.0f, 1.0f, 0.0f);

	glBegin(GL_QUADS);
	glVertex3f(-8.0f,-9.0f,0.0f);
	glVertex3f(8.0f,-9.0f,0.0f);
	glVertex3f(8.0f,-10.0f,0.0f);
	glVertex3f(-8.0f,-10.0f,0.0f);

	glEnd();

	glLineWidth(1.0f);
	glColor3f(1.0f,1.0f, 0.0f);
	glRasterPos2f(-6.0f, -9.7f);
	draw_string_bitmap(GLUT_BITMAP_HELVETICA_18, "DRAW FUNC");
//////////////////////////////Рисуемвторуюкнопку////////////////////////////////////
	if (button2==true)
	glColor3f(1.0f, 0.0f, 0.0f);
	else
	glColor3f(0.0f, 1.0f, 0.0f);

	glBegin(GL_QUADS);
	glVertex3f(-8.0f,-7.5f,0.0f);
	glVertex3f(8.0f,-7.5f,0.0f);
	glVertex3f(8.0f,-8.5f,0.0f);
	glVertex3f(-8.0f,-8.5f,0.0f);
	glEnd();

	glLineWidth(1.0f);
	glColor3f(1.0f,1.0f, 0.0f);
	glRasterPos2f(-6.0f, -8.2f);
	draw_string_bitmap(GLUT_BITMAP_HELVETICA_18, "QUAD INTEGR");
	/////////////////////Рисуемтретьюкнопку///////////////////////////////////
	if (button3==true)
	glColor3f(1.0f, 0.0f, 0.0f);
	else
	glColor3f(0.0f, 1.0f, 0.0f);

	glBegin(GL_QUADS);
	glVertex3f(-8.0f,-6.0f,0.0f);
	glVertex3f(8.0f,-6.0f,0.0f);
	glVertex3f(8.0f,-7.0f,0.0f);
	glVertex3f(-8.0f,-7.0f,0.0f);
	glEnd();

	glLineWidth(1.0f);
	glColor3f(1.0f,1.0f, 0.0f);
	glRasterPos2f(-6.0f, -6.8f);
	draw_string_bitmap(GLUT_BITMAP_HELVETICA_18, "TRAP INTEGR");

	

////////////////////////Рисуем четвертую кнопку////////////////////////////////
		if (button4==true)
	glColor3f(1.0f, 0.0f, 0.0f);
	else
	glColor3f(0.0f, 1.0f, 0.0f);

	glBegin(GL_QUADS);
	glVertex3f(-8.0f,-4.5f,0.0f);
	glVertex3f(8.0f,-4.5f,0.0f);
	glVertex3f(8.0f,-5.5f,0.0f);
	glVertex3f(-8.0f,-5.5f,0.0f);
	glEnd();

	glLineWidth(1.0f);
	glColor3f(1.0f,1.0f, 0.0f);
	glRasterPos2f(-6.0f, -5.3f);
	draw_string_bitmap(GLUT_BITMAP_HELVETICA_18, "INPUT STEP");


////////////////////////////Рисуемпятуюкнопку///////////////////////////////////
			if (button5==true)
	glColor3f(1.0f, 0.0f, 0.0f);
	else
	glColor3f(0.0f, 1.0f, 0.0f);

	glBegin(GL_QUADS);
	glVertex3f(-8.0f,-3.0f,0.0f);
	glVertex3f(8.0f,-3.0f,0.0f);
	glVertex3f(8.0f,-4.0f,0.0f);
	glVertex3f(-8.0f,-4.0f,0.0f);
	glEnd();

	glLineWidth(1.0f);
	glColor3f(1.0f,1.0f, 0.0f);
	glRasterPos2f(-6.0f, -3.8f);
	draw_string_bitmap(GLUT_BITMAP_HELVETICA_18, "INPUT A  B");


////////////////////////////////Рисуемшестуюкнопку/////////////////////////////////////
	if ((button6==true) & (FunctionDr==false))
	glColor3f(1.0f, 0.0f, 0.0f);
	if (button6==false)
	glColor3f(0.0f, 1.0f, 0.0f);
	if (FunctionDr==true)
	glColor3f(0.0f, 0.0f, 1.0f);

	glBegin(GL_QUADS);
	glVertex3f(-8.0f,-1.5f,0.0f);
	glVertex3f(8.0f,-1.5f,0.0f);
	glVertex3f(8.0f,-2.5f,0.0f);
	glVertex3f(-8.0f,-2.5f,0.0f);
	glEnd();

	glLineWidth(1.0f);
	glColor3f(1.0f,1.0f, 0.0f);
	glRasterPos2f(-8.0f, -2.2f);
	draw_string_bitmap(GLUT_BITMAP_HELVETICA_18, "FUNCTION(DEMO)");


///////////////////////////////Рисуемседьмуюкнопку////////////////////////////////////
	if (button7==true)
	glColor3f(1.0f, 0.0f, 0.0f);
	else
	glColor3f(0.0f, 1.0f, 0.0f);

	glBegin(GL_QUADS);
	glVertex3f(-8.0f,0.0f,0.0f);
	glVertex3f(8.0f,-0.0f,0.0f);
	glVertex3f(8.0f,-1.0f,0.0f);
	glVertex3f(-8.0f,-1.0f,0.0f);
	glEnd();

	glLineWidth(1.0f);
	glColor3f(1.0f,1.0f, 0.0f);
	glRasterPos2f(-6.0f, -0.7f);
	draw_string_bitmap(GLUT_BITMAP_HELVETICA_18, "SIMP INTEGR");

////////////////////////////////////Шаг(текст)///////////////////////////////////////////

	glLineWidth(1.0f);
		if (vvodshag==true)
		{
		glColor3f(1.0f,0.0f, 0.0f);
		}
		else
		{
	glColor3f(1.0f,1.0f, 0.0f);
		}
	glRasterPos2f(-9.8f, 6.0f);
	draw_string_bitmap(GLUT_BITMAP_HELVETICA_18, "step=");
	glRasterPos2f(-5.0f, 6.0f);
	draw_string_bitmap(GLUT_BITMAP_HELVETICA_18, fshag.c_str()); 

///////////////////ИНТЕРВАЛ (текст)///////////////////////////////////////////////

	glLineWidth(1.0f);
		if ((vvodab==true) & (abchange==false))
		{
		glColor3f(1.0f,0.0f, 0.0f);
		}
		else
		{
	glColor3f(1.0f,1.0f, 0.0f);
		}
	glRasterPos2f(-9.8f, 5.0f);
	draw_string_bitmap(GLUT_BITMAP_HELVETICA_18, "a=");
	glRasterPos2f(-7.5f, 5.0f);
	draw_string_bitmap(GLUT_BITMAP_HELVETICA_18, fa.c_str()); 

	glLineWidth(1.0f);
		if ((vvodab==true) & (abchange==true))
		{
	glColor3f(1.0f,0.0f, 0.0f);
		}
		else
		{
	glColor3f(1.0f,1.0f, 0.0f);
		}
	glRasterPos2f(-3.0f, 5.0f);
	draw_string_bitmap(GLUT_BITMAP_HELVETICA_18, "b=");
	glRasterPos2f(0.0f, 5.0f);
	draw_string_bitmap(GLUT_BITMAP_HELVETICA_18, fb.c_str()); 

		//////////////////////////////////////////Функция (текст)//////////
	glLineWidth(1.0f);
		if (FunctionDr==true)
		{
		glColor3f(1.0f,0.0f, 0.0f);
		}
		else
		{
		glColor3f(1.0f,1.0f, 0.0f);
		}
	glRasterPos2f(-9.8f, 4.0f);
	draw_string_bitmap(GLUT_BITMAP_HELVETICA_18, "Func=");
	glRasterPos2f(-4.5f, 4.0f);
	draw_string_bitmap(GLUT_BITMAP_HELVETICA_18, ffun.c_str()); 

	glutSwapBuffers();
	}



voidSetupRC()
	{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f );

	glColor3f(0.0f, 1.0f, 0.0f);
	}
	
voidSpecialKeys(int key, int x, int y)
	{
	if(key == GLUT_KEY_UP)
		xRot-= 5.0f;

	if(key == GLUT_KEY_DOWN)
		xRot += 5.0f;

	if(key == GLUT_KEY_LEFT)
		yRot -= 5.0f;

	if(key == GLUT_KEY_RIGHT)
		yRot += 5.0f;

	if(key== GLUT_KEY_PAGE_UP)
		zRot +=0.1f;

	if(key== GLUT_KEY_PAGE_DOWN)
		zRot -=0.1f;

	if(key > 356.0f)
		xRot = 0.0f;

	if(key < -1.0f)
		xRot = 355.0f;

	if(key > 356.0f)
		yRot = 0.0f;

	if(key < -1.0f)
		yRot = 355.0f;

		
	glutPostRedisplay();
	}


/////////////////////////////////////////////////////////////////////////////////////////
voidMouseCallback(int button, int state, int x, int y)
	{

	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && x > 620 && x < 780 && y > 570 &&  y <600)
		{
			integral=false;
			integraltrap=false;
			integralsimp=false;
			graphic=true;
			RenderScene();
		}


	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && x > 620 && x < 780 && y > 525 &&  y <555)
		{
			sumint=0;
			integraltrap=false;
			integral=true;
			integralsimp=false;
			RenderScene();
		}


	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && x > 620 && x < 780 && y > 480 &&  y <510)
		{
			suminttrap=0;
			integral=false;
			integraltrap=true;
			RenderScene();
		}

	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && x > 620 && x < 780 && y > 435 &&  y <465)
		{
			provfunc=false;
			vvodshag=true;
			fshag="";
		}

	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && x > 620 && x < 780 && y > 390 &&  y <420)
		{
			provfunc=false;
			vvodab=true;
			fa="";
			fb="";
		}

	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && x > 620 && x < 780 && y > 345 &&  y <375)
		{	
			if (FunctionDr==false)
			{
				integral=false;
				integraltrap=false;
				provfunc=true;
				ffun="";
			FunctionDr=true;
			graphic=false;
			}
			else
			{
				integral=false;
				integraltrap=false;
				ffun="exp(x)*sin(x)";
			FunctionDr=false;
			graphic=false;
			}

		}
		if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && x > 620 && x < 780 && y > 300 &&  y <330)
		{
			integraltrap=false;
			integral=false;
			integralsimp=true;
			RenderScene();
		}

	}



/////////////////////////////////////////////////////////////////////////////////////////
voidMouseMotion (int x, int y)

{
		if (x > 620 && x < 780 && y > 570 &&  y <600)
	{
	button1=false;
	RenderScene();
	}
	else
	{
	button1=true;
	RenderScene();
	}

		if (x > 620 && x < 780 && y > 525 &&  y <555)
	{
	button2=false;
	RenderScene();
	}
	else
	{
	button2=true;
	RenderScene();
	}

		if (x > 620 && x < 780 && y > 480 &&  y <510)
	{
	button3=false;
	RenderScene();
	}
	else
	{
	button3=true;
	RenderScene();
	}

		if (x > 620 && x < 780 && y > 435 &&  y <465)
	{
	button4=false;
	RenderScene();
	}
	else
	{
	button4=true;
	RenderScene();
	}
		
		if (x > 620 && x < 780 && y > 390 &&  y <420)
	{
	button5=false;
	RenderScene();
	}
	else
	{
	button5=true;
	RenderScene();
	}

	if (x > 620 && x < 780 && y > 345 &&  y <375)
	{
	button6=false;
	RenderScene();
	}
	else
	{
	button6=true;
			
	if (x > 620 && x < 780 && y > 300 &&  y <330)
	{
	button7=false;
	RenderScene();
	}
	else
	{
	button7=true;
	RenderScene();
	}
	RenderScene();
	}

}




voidVvod(unsignedchar key, int x, int y)
{	if (key==13)
	{
	if (vvodshag==true)
	{
	vvodshag=false;

	shag = atof(fshag.c_str());
	posshag=0;
	}

	if ((vvodab==true) & (abchange==true))
	{
	provfunc=true;
	abchange=false;
	vvodab=false;

	b = atof(fb.c_str());
	posshag=0;
	}

	if ((vvodab==true) & (abchange==false))
	{
	abchange=true;

	a = atof(fa.c_str());

	posshag=0;
	}

	if (FunctionDr==true) 
	{
	DrawFunc=ffun;
	posshagf=0;
	}
	}
/////////////////////////Вводимшаг///////////////////////////////////////////
	if (vvodshag == true)
	{
	if ((key=='1') || (key=='2') || (key=='3') || (key=='4') || (key=='5') || (key=='6') || (key=='7') ||(key=='8') ||(key=='9') ||(key=='0') || (key=='.'))
	{
	fshag+=key;
	posshag=posshag+1;
	}
	if ((key==8) & (posshag>0))
	{
	fshag.erase(posshag-1,1);
	posshag=posshag-1;
	}
	}

	if (vvodab == true)
	{
	if ((key=='1') || (key=='2') || (key=='3') || (key=='4') || (key=='5') || (key=='6') || (key=='7') ||(key=='8') ||(key=='9') ||(key=='0') || (key=='.') || (key=='-'))
	{
		if (abchange==true)
		{
	fb+=key;
	posshag=posshag+1;
		}
		else
		{
	fa+=key;
	posshag=posshag+1;
		
		}
	}
	if ((key==8) & (posshag>0))
	{
		if (abchange==true)
		{
	fb.erase(posshag-1,1);
	posshag=posshag-1;
		}
		else
		{
	fa.erase(posshag-1,1);
	posshag=posshag-1;
		}
	}
	}


/////////////////////////////////вводфункции////////////////////////////////////
	if ((FunctionDr == true) & (provfunc==true))
	{
	if ((key=='1') || (key=='2') || (key=='3') || (key=='4') || (key=='5') || (key=='6') || (key=='7') ||(key=='8') ||(key=='9') ||(key=='0') || (key=='.') || (key=='+') || (key=='-') || (key=='*') || (key=='/') || (key=='x'))
	{
	ffun+=key;
	posshagf=posshagf+1;
	}
	if ((key==8) & (posshagf>0))
	{
	ffun.erase(posshagf-1,1);
	posshagf=posshagf-1;
	}
	}
	



	RenderScene();
}

int main()
	{


	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800,600);
	glutCreateWindow("Line Strips Example");
	glutSpecialFunc(SpecialKeys);
	glutKeyboardFunc(Vvod);
	glutMouseFunc(MouseCallback);
	glutPassiveMotionFunc(MouseMotion);
	glutDisplayFunc(RenderScene);
	SetupRC();
	glutMainLoop();
	return 0;
	}
