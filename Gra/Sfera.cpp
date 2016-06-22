#include "StdAfx.h"
#include "Sfera.h"


CSfera::CSfera(void)
{
}

CSfera::CSfera(int x, int y, int z, double radius, double r, double g, double b)
{
	translacja[0]=x;
	translacja[1]=y;
	translacja[2]=z;

	rotacja[0]=0;
	rotacja[1]=0;
	rotacja[2]=0;

	kolor[0]=r;
	kolor[1]=g;
	kolor[2]=b;

	promien=radius;
}

CSfera::~CSfera(void)
{
}
void CSfera::loadTextureFromFile(char *filename) 
{ 
 
}
void CSfera::Rysuj()
{
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHT0);
	glPushMatrix(); // save matrix prior to transform
	glTranslatef(translacja[0], translacja[1], translacja[2]);
	glRotatef( rotacja[0], 1.0, 0.0, 0.0 ); // rotate about the X axis
	glRotatef( rotacja[1], 0.0, 1.0, 0.0 ); // rotate about the Y axis
	glRotatef( rotacja[2], 0.0, 0.0, 1.0 ); // rotate about the Z axis
	glColor3f(kolor[0],kolor[1],kolor[2]);
	glutSolidSphere(promien,100,100);
	glPopMatrix(); // restore matrix after transform
}