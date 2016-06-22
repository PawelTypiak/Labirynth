#include "StdAfx.h"
#include "Podloga.h"



CPodloga::CPodloga(void)
{
}


CPodloga::~CPodloga(void)
{
}

CPodloga::CPodloga(double dl,double sz, double x, double y, double z, double alfa, double beta, double gamma, float r, float g,float b)
{ 
	dlugosc=dl;
	szerokosc=sz;


	translacja[0]=x;
	translacja[1]=y;
	translacja[2]=z;

	rotacja[0]=alfa;
	rotacja[1]=beta;
	rotacja[2]=gamma;

	kolor[0] = r;
	kolor[1] = g;
	kolor[2] = b;

	
}

void CPodloga::loadTextureFromFile(char *filename) 
{ 
RgbImage theTexMap( filename ); 
glGenTextures(1,&textures); //nazywamy teksturê
glBindTexture(GL_TEXTURE_2D, textures);// aktywujemy teksture 1
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); 
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); 
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); 
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); 
gluBuild2DMipmaps(GL_TEXTURE_2D, 3,theTexMap.GetNumCols(), 
theTexMap.GetNumRows(),GL_RGB, GL_UNSIGNED_BYTE, theTexMap.ImageData() ); 
}

void CPodloga::Rysuj()
{ 
	glPushMatrix();
	 
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHT0);

	glTranslatef(translacja[0],translacja[1],translacja[2]); //translacja I rotacje: 
	glRotatef( rotacja[0], 1.0, 0.0, 0.0 );//rotate about the X axis 
	glRotatef( rotacja[1], 0.0, 1.0, 0.0 );//rotate about the Y axis 
	glRotatef( rotacja[2], 0.0, 0.0, 1.0 );//rotate about the Z axis   
	glEnable(GL_TEXTURE_2D); 
	glBindTexture(GL_TEXTURE_2D, textures); 

	glColor3f(kolor[0],kolor[1],kolor[2]);//ustawienie koloru 
	glScalef(0.5*dlugosc,1,0.5*szerokosc);
	glBegin( GL_QUADS ); //rysujemy czworok¹t 
	glTexCoord2f(0.0f, 0.0f); glVertex3f( -1, 0,-1); 
	glTexCoord2f(1.0f, 0.0f); glVertex3f( -1, 0,1 ); 
	glTexCoord2f(1.0f, 1.0f); glVertex3f( 1, 0,1 ); 
	glTexCoord2f(0.0f, 1.0f); glVertex3f( 1, 0,-1); 
	glEnd(); 

	glDisable(GL_TEXTURE_2D);
	glPopMatrix();// restore matrix after transform, koniec przekszta³cen na wybranym obiekcie 
} 
