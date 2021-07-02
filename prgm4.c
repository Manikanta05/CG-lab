/*4. Draw a color cube and allow the user to move the camera suitably to experiment with perspective viewing*/
#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
float v[8][3]={{0,0,0},{1,0,0},{1,1,0},{0,1,0},{0,0,1},{1,0,1},{1,1,1},{0,1,1}};
float v1[3]={0,0,5};
void polygon(int a, int b, int c, int d);
void polygon1();

void display()
{
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glClearColor(1,1,1,1);
glLoadIdentity();
gluLookAt(v1[0],v1[1],v1[2],0,0,0,0,1,0);     
polygon1();
glFlush();
}

void polygon1()
{
polygon(0,1,2,3);
polygon(4,5,6,7);
polygon(5,1,2,6);
polygon(4,0,3,7);
polygon(4,5,1,0);
polygon(7,6,2,3);
}

void polygon(int a, int b, int c, int d)
{
glBegin(GL_POLYGON);
glColor3fv(v[a]);
glVertex3fv(v[a]);
glColor3fv(v[b]);
glVertex3fv(v[b]);
glColor3fv(v[c]);
glVertex3fv(v[c]);
glColor3fv(v[d]);
glVertex3fv(v[d]);
glEnd();
}

void key(unsigned char f, int mouseX, int mouseY)      
{
if(f=='x')    
v1[0]-=0.1;     
if(f=='X')    
v1[0]+=0.1;
if(f=='y')
v1[1]-=0.1;
if(f=='Y')
v1[1]+=0.1;
if(f=='z')
v1[2]-=0.1;
if(f=='Z')
v1[2]+=0.1;
display();
}

void reshape(int w, int h)
{
glViewport(0,0,w,h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
if(w<=h)
glFrustum(-2.0,2.0,-2.0*h/w,2.0*h/w,2.0,20);
else
glFrustum(-2.0*w/h,2.0*w/h,-2.0,2.0,2.0,20);
glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_DEPTH);
glutInitWindowSize(1500,1500);
glutInitWindowPosition(10,10);
glutCreateWindow("cube presp");
glutDisplayFunc(display);
glutKeyboardFunc(key);
glEnable(GL_DEPTH_TEST);
glutReshapeFunc(reshape);
glutMainLoop();
}
