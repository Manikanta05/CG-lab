/*9. Develop a menu driven program to fill the polygon using scan line algorithm*/
#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
GLfloat x1,y11,x2,y2,x3,y3,x4,y4;
int sb;
int n=30;
int r=0,b=0,g=1;

void cm(int id)
{
switch(id)
{
case 2: r=1;
    g=0;
    b=0;
break;

case 3: r=0;
    g=0;
    b=1;
break;

case 4: r=0;
    g=1;
    b=0;
}
glutPostRedisplay();
}

void tm(int id)
{
switch(id)
{
case 1: exit(1);
break;

default: cm(id);
break;
}
}

void ed(GLfloat x1,GLfloat y11,GLfloat x2,GLfloat y2,int *le,int *re)
{
float t,mx,x;
int i;
if((y2-y11)<0)
{
t=x1;
x1=x2;
x2=t;
t=y11;
y11=y2;
y2=t;
}

if((y2-y11)!=0)
mx=(x2-x1)/(y2-y11);
else
mx=x2-x1;
x=x1;
for(i=y11+1;i<y2;i++)
{
if(x<le[i])
le[i]=x;
if(x>re[i])
re[i]=x;
x+=mx;
}
}

void dp(int x, int y)
{
glColor3f(r,g,b);
glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();
}

void scf(float x1, float y11, float x2, float y2, float x3, float y3, float x4, float y4)
{
int le[500],re[500];
int i,y;
for(i=0;i<500;i++)
{
le[i]=500;
re[i]=0;
}
ed(x1,y11,x2,y2,le,re);
ed(x2,y2,x3,y3,le,re);
ed(x3,y3,x4,y4,le,re);
ed(x4,y4,x1,y11,le,re);
for(y=0;y<500;y++)
{
if(le[y]<=re[y])
for(i=le[y]+1;i<re[y];i++)
dp(i,y);
}
}
void display()
{
glClear(GL_COLOR_BUFFER_BIT);
int x1=200,y11=200,x2=100,y2=300,x3=200,y3=400,x4=300,y4=300;
glBegin(GL_LINE_LOOP);
glVertex2i(x1,y11);
glVertex2i(x2,y2);
glVertex2i(x3,y3);
glVertex2i(x4,y4);
glEnd();
scf(x1,y11,x2,y2,x3,y3,x4,y4);
glFlush();
}

void minit()
{
glClearColor(1,1,1,1);
glColor3f(r,g,b);
glPointSize(1);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0,499,0,499);
}

int main(int argc, char **argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(1500,1500);
glutCreateWindow("SFA");
glutDisplayFunc(display);
minit();
sb=glutCreateMenu(cm);
glutAddMenuEntry("RED",2);
glutAddMenuEntry("BLUE",3);
glutAddMenuEntry("GREEN",4);
glutCreateMenu(tm);
glutAddMenuEntry("QUIT",1);
glutAddSubMenu("COLOR",sb);
glutAttachMenu(GLUT_RIGHT_BUTTON);

glutMainLoop();
}
