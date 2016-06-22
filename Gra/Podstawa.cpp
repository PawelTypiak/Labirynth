#include "StdAfx.h"
#include "Podstawa.h"


CPodstawa::CPodstawa(void)
{
}

CPodstawa::CPodstawa(double dl,double sz, double wys, double x, double y, double z,float r, float g, float b)
{
	
	translacja[0]=x;
	translacja[1]=y;
	translacja[2]=z;

	rotacja[0]=0;
	rotacja[1]=0;
	rotacja[2]=0;

	kolor[0] = r;
	kolor[1] = g;
	kolor[2] = b;

	podloga[0]=new CPodloga(dl,sz,0,-0.5*wys,0,0,0,0,r,g,b); //podstawa dolna
	podloga[1]=new CPodloga(dl,sz,0,0.5*wys,0,0,0,0,r,g,b); //podstawa gorna
	podloga[2]=new CPodloga(dl,wys,0,0,-0.5*sz,90,0,0,r,g,b); //sciana przednia
	podloga[3]=new CPodloga(dl,wys,0,0,0.5*sz,90,0,0,r,g,b); //sciana tylnia
	podloga[4]=new CPodloga(wys,sz,0.5*dl,0,0,0,0,90,r,g,b); //sciana boczna1
	podloga[5]=new CPodloga(wys,sz,-0.5*dl,0,0,0,0,90,r,g,b); //sciana boczna2


}
CPodstawa::~CPodstawa(void)
{

	for(int i=0;i<6;i++)
		delete podloga[i];

}
void CPodstawa::loadTextureFromFile(char *filename) 
{ 

}
void CPodstawa::Rysuj()
{
	
	glPushMatrix(); // save matrix prior to transform

	glTranslatef(translacja[0], translacja[1], translacja[2]);  
	glRotatef( rotacja[0], 1.0, 0.0, 0.0 ); // rotate about the X axis
	glRotatef( rotacja[1], 0.0, 1.0, 0.0 ); // rotate about the Y axis
	glRotatef( rotacja[2], 0.0, 0.0, 1.0 ); // rotate about the Z axis
	glColor3f(kolor[0],kolor[1],kolor[2]);

	for(int i=0;i<6;i++)
		podloga[i]->Rysuj();

	glPopMatrix(); // restore matrix after transform
}