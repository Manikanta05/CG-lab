/*6. To draw a simple shaded scene consisting of a tea pot on a table. Define suitably the position and properties of the light source along with the properties of the surfaces of the solid object used in the scene.*/

#include<stdio.h>
#include<GL/glut.h>
void wall()
{
glPushMatrix();
glScalef(2,0.05,2);
glutSolidCube(2);
glPopMatrix();

glPushMatrix();
glTranslatef(-2,2,0);
glRotatef(-90,0,0,1);
glScalef(2,0.05,2);
glutSolidCube(2);
glPopMatrix();

glPushMatrix();
glTranslatef(0,2,-2);
glRotatef(90,1,0,0);
glScalef(2,0.05,2);
glutSolidCube(2);
glPopMatrix();
}

void table()
{glPushMatrix();
glTranslatef(0,0.5,0);
glScalef(1,0.05,1);
glutSolidCube(2);
glPopMatrix();

glPushMatrix();
glTranslatef(-0.8,0.2,0.8);
glScalef(0.1,0.25,0.1);
glutSolidCube(2);
glPopMatrix();

glPushMatrix();
glTranslatef(0.8,0.2,0.8);
glScalef(0.1,0.25,0.1);
glutSolidCube(2);
glPopMatrix();

glPushMatrix();
glTranslatef(0.8,0.2,-0.8);
glScalef(0.1,0.25,0.1);
glutSolidCube(2);
glPopMatrix();

glPushMatrix();
glTranslatef(-0.8,0.2,-0.8);
glScalef(0.1,0.25,0.1);
glutSolidCube(2);
glPopMatrix();
}

void teapot()
{
glPushMatrix();
glTranslatef(0,1.3,0);
glRotatef(45,0,1,0);
glutSolidTeapot(1);
glPopMatrix();
}

void display(void)
{
float amb[]={1,0,0,1};
float pos[]={2,4,1};
glMaterialfv(GL_FRONT,GL_AMBIENT,amb);
glLightfv(GL_LIGHT0,GL_POSITION,pos);
glLightfv(GL_LIGHT0,GL_AMBIENT,amb);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-4,4,-4,4,-10,10);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
gluLookAt(2.5,1,2,0,0.5,0,0,1,0);
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
wall();
table();
teapot();
glFlush();
}

int main(int argc,char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_DEPTH|GLUT_RGB);
glutInitWindowSize(600,600);
glutCreateWindow("TEAPOT");
glutDisplayFunc(display);
glEnable(GL_DEPTH_TEST);
glEnable(GL_SMOOTH);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glEnable(GL_NORMALIZE);
glutMainLoop();
}
