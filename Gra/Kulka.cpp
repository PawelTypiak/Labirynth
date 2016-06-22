#include "StdAfx.h"
#include "Kulka.h"


CKulka::CKulka(void)
{
}

CKulka::CKulka(int x, int y, int z, double r, double g, double b)
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

	step=1.5;

	sfera[0]=new CSfera(0,0,0,8,r,g,b);
	sfera[1]=new CSfera(3.5,4.5,6,1,1,1,1);
	sfera[2]=new CSfera(-3.5,4.5,6,1,1,1,1);
	sfera[3]=new CSfera(3.5,4.5,7,0.5,0,0,0);
	sfera[4]=new CSfera(-3.5,4.5,7,0.5,0,0,0);
}

CKulka::~CKulka(void)
{
	for(int i=0;i<3;i++)
	delete sfera[0];
}
void CKulka::loadTextureFromFile(char *filename) 
{ 

}
int CKulka::spr(int poziom)
{
	if (poziom==1)
	{
		if (translacja[0]<-76 &&translacja[0]>-92 &&translacja[2]>121) 
		{
	
			return 1;
		}
		else return 0;
	}
	else if (poziom==2)
	{
		if (translacja[0]<-100 &&translacja[2]>-11 &&translacja[2]<9) 
		{
	
			return 1;
		}
		else return 0;
	}
	else if (poziom==3)
	{
		if (translacja[0]<78 &&translacja[0]>60 &&translacja[2]>121) 
		{
	
			return 1;
		}
		else return 0;
	}
	else if (poziom==4)
	{
		if (translacja[0]<82 &&translacja[0]>56 &&translacja[2]>103) 
		{
	
			return 1;
		}
		else return 0;
	}
}
void CKulka::Rysuj()
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
	for(int i=0;i<5;i++)
		sfera[i]->Rysuj();
	glPopMatrix(); // restore matrix after transform
}