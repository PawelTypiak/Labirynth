#include "StdAfx.h"
#include "Stozek.h"


CStozek::CStozek(void)
{
}


CStozek::CStozek(double radius, double height, int x, int y, int z, float r, float g, float b)
{
	translacja[0] = x;
	translacja[1] = y;
	translacja[2] = z;
	
	rotacja[0] = 0;
	rotacja[1] = 0;
	rotacja[2] = 0;

	kolor[0] = r;
	kolor[1] = g;
	kolor[2] = b;

	promien = radius;
	wysokosc = height;
}


CStozek::~CStozek(void)
{
}
void CStozek::loadTextureFromFile(char *filename) 
{ 

}


void CStozek::Rysuj()
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
	glutSolidCone(promien,wysokosc,100,100);
	glPopMatrix(); // restore matrix after transform
}