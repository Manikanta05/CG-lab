//PROGRAM -5
 
//5. Clip a lines using Cohen-Sutherland algorithm.

//program to clip a line using Cohen Sutherland algorithm
#include<stdio.h>
#include<GL/glut.h>
float xmin=50,ymin=50,xmax=100,ymax=100;
float xvmin=200,yvmin=200,xvmax=400,yvmax=400;
int right=2,left=1,top=8,bottom=4;
float sx,sy,vx1,vy1,vx2,vy2;
float x1,y_1,x2,y2;
int compute(float x,float y)
{
int code=0;
if(y>ymax)
code=top;
else if(y<ymin)
code=bottom;
if(x>xmax)
code=right;
else if(x<xmin)
code=left;
return code;
}

void cohen(float x1,float y_1,float x2,float y2)
{
float x,y;
int a=0,d=0,cp,cq;
int code;
cp=compute(x1,y_1);
cq=compute(x2,y2);
do
{
if(!(cp | cq))
{
a=1;
d=1;
}
else if(cp & cq)
d=1;
else
{
code=cp ? cp : cq;
if(code & top)
{
x=x1+(x2-x1)*(ymax-y_1)/(y2-y_1);
y=ymax;
}
else if(code & bottom)
{
x=x1+(x2-x1)*(ymin-y_1)/(y2-y_1);
y=ymin;
}
else if(code & right)
{
y=y_1+(y2-y_1)*(xmax-x1)/(x2-x1);
x=xmax;
}
else
{
y=y_1+(y2-y_1)*(xmin-x1)/(x2-x1);
x=xmin;
}
if(code==cp)
{
x1=x;
y_1=y;
cp=compute(x1,y_1);
}
else
{
x2=x;
y2=y;
cq=compute(x2,y2);
}
}
}while(!d);
if(a)
{
sx=(xvmax-xvmin)/(xmax-xmin);
sy=(yvmax-yvmin)/(ymax-ymin);
vx1=xvmin+(x1-xmin)*sx;
vy1=xvmin+(y_1-ymin)*sy;
vx2=xvmin+(x2-xmin)*sx;
vy2=xvmin+(y2-ymin)*sy;
}
}

void display()
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1,0,1);
glLineWidth(2);

glBegin(GL_LINES);
glVertex2f(x1,y_1);
glVertex2f(x2,y2);
glEnd();

glColor3f(1,0,0);

glBegin(GL_LINE_LOOP);
glVertex2f(xmin,ymin);
glVertex2f(xmax,ymin);
glVertex2f(xmax,ymax);
glVertex2f(xmin,ymax);
glEnd();

cohen(x1,y_1,x2,y2);

glColor3f(0,0,1);

glBegin(GL_LINE_LOOP);
glVertex2f(xvmin,yvmin);
glVertex2f(xvmax,yvmin);
glVertex2f(xvmax,yvmax);
glVertex2f(xvmin,yvmax);
glEnd();

glColor3f(0,1,0);
glBegin(GL_LINES);
glVertex2f(vx1,vy1);
glVertex2f(vx2,vy2);
glEnd();
glFlush();
}

void minit()
{
glClearColor(1,1,1,1);
gluOrtho2D(0,500,0,500);
}

int main(int argc,char **argv)
{glutInit(&argc, argv);
 printf("enter pts\n");
 scanf("%f%f%f%f",&x1,&y_1,&x2,&y2);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowSize(1500,1500);
 glutCreateWindow("Cohen Sutherland Line Clipping Algorithm");
 glutDisplayFunc(display);
 minit();
 glutMainLoop();
 return 0;
}






