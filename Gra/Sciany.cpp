#include "StdAfx.h"
#include "Sciany.h"


CSciany::CSciany(void)
{
}

CSciany::CSciany(double dl,double sz, double wys, double x, double y, double z,float r, float g, float b)
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

	boki[0]=new CBoki(dl,sz,0,-0.5*wys,0,0,0,0,r,g,b); //podstawa dolna
	boki[1]=new CBoki(dl,sz,0,0.5*wys,0,0,0,0,r,g,b); //podstawa gorna
	boki[2]=new CBoki(dl,wys,0,0,-0.5*sz,90,0,0,r,g,b); //sciana przednia
	boki[3]=new CBoki(dl,wys,0,0,0.5*sz,90,0,0,r,g,b); //sciana tylnia
	boki[4]=new CBoki(wys,sz,0.5*dl,0,0,0,0,90,r,g,b); //sciana boczna1
	boki[5]=new CBoki(wys,sz,-0.5*dl,0,0,0,0,90,r,g,b); //sciana boczna2


}
CSciany::~CSciany(void)
{

	for(int i=0;i<6;i++)
		delete boki[i];

}
void CSciany::loadTextureFromFile(char *filename) 
{ 

}
void CSciany::Rysuj()
{
	
	glPushMatrix();

	glTranslatef(translacja[0], translacja[1], translacja[2]);  
	glRotatef( rotacja[0], 1.0, 0.0, 0.0 );
	glRotatef( rotacja[1], 0.0, 1.0, 0.0 ); 
	glRotatef( rotacja[2], 0.0, 0.0, 1.0 ); 
	glColor3f(kolor[0],kolor[1],kolor[2]);
	
	for(int i=0;i<6;i++)
		boki[i]->Rysuj();
	glPopMatrix(); 
}