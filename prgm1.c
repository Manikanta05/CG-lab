//1. Implement Brenham’s line drawing algorithm for all types of slope
#include<GL/glut.h>
#include<stdio.h>
int x1,y11,x2,y2;
void minit()
{
glClear(GL_COLOR_BUFFER_BIT);
glClearColor(0.0,0.0,0.0,1.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0,500,0,500);
}
void dp(int x,int y)
{
glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();
}
void dl(int x1,int x2,int y11,int y2)
{
int x,y,cx,cy,dx,dy,c1,c2,i,e;
dx=x2-x1;
dy=y2-y11;
if(dx<0) dx=-dx;
if(dy<0) dy=-dy;
cx=1;
if(x2<x1)
cx=-1;
cy=1;
if(x1==x2)  
cx=0;
if(y2<y11)
cy=-1;
x=x1;
y=y11;
if(dx>dy)
{
printf("%d\t%d\n",x,y);
dp(x,y);
e=2*dy-dx;
c1=2*(dy-dx);
c2=2*dy;
for(i=0;i<dx;i++)
{
if(e>=0)
{
y+=cy;
e+=c1;
}
else
e+=c2;
x+=cx;
printf("%d\t%d\n",x,y);
dp(x,y);
}
}
else
{
printf("%d\t%d\n",x,y);
dp(x,y);
e=2*dy-dx;
c1=2*(dx-dy);
c2=2*dx;
for(i=0;i<dy;i++)
{
if(e>=0)
{
x+=cx;
e+=c1;
}
else
e+=c2;
y+=cy;
printf("%d\t%d\n",x,y);
dp(x,y);
}
}
}
void mdisplay()
{
dl(x1,x2,y11,y2);
glFlush();
}
int main(int argc,char **argv)
{
glutInit(&argc,argv);
printf("enter 1st point\n");
scanf("%d%d", &x1, &y11);
printf("enter 2nd point\n");
scanf("%d%d", &x2, &y2);
printf("\n\n\n\n");
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(1000,1000);
glutInitWindowPosition(0,0);
glutCreateWindow("bresenhams");
minit();
glutDisplayFunc(mdisplay);
glutMainLoop();
}
 





