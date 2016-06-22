#include "StdAfx.h"
#include "Bonus.h"


CBonus::CBonus(void)
{
}

CBonus::CBonus(int x, int y, int z, float r, float g, float b)
{
	step=1,5;
	gora = new CStozek(3,10,0,0,0,r,g,b);
	dol = new CStozek(3,10,0,0,0,r,g,b);

	pozycja[0]=x;
	pozycja[1]=y;
	pozycja[2]=z;

	obrot[0]=0;
	obrot[1]=0;
	obrot[2]=0;

}

CBonus::~CBonus(void)
{
	delete gora;
	delete dol;
}
void CBonus::Przesun(int dx, int dy, int dz)
{ //przesuniecie figury
	pozycja[0]+=dx;
	pozycja[1]+=dy;
	pozycja[2]+=dz;
}
void CBonus::Obroc(double alfa, double beta, double gamma)
{ // obrot figury
	obrot[0]+=alfa;
	obrot[1]+=beta;
	obrot[2]+=gamma;
}
void CBonus::Rysuj(void)
{
	gora->rotacja[0]=obrot[0]+90;
	gora->rotacja[1]=obrot[1];
	gora->rotacja[2]=obrot[2];

	dol->rotacja[0]=obrot[0]+90;
	dol->rotacja[1]=obrot[1]+180;
	dol->rotacja[2]=obrot[2];

	gora->translacja[0]=pozycja[0];
	gora->translacja[1]=pozycja[1];
	gora->translacja[2]=pozycja[2];

	dol->translacja[0]=pozycja[0];
	dol->translacja[1]=pozycja[1];
	dol->translacja[2]=pozycja[2];

	gora->Rysuj();
	dol->Rysuj();
}