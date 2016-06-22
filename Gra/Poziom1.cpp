#include "StdAfx.h"
#include "Poziom1.h"

CPoziom1::CPoziom1(void)
{
	gr=6;
	wys=40;
	sz=6;
	os_y=0.5*wys+0.5*gr;

	kulka=new CKulka(84,20,-121,1,0,0);

	bonus[0]=new CBonus(-91,16,-115,0.7,0.7,0);
	bonus[1]=new CBonus(-84,16,52,0.7,0.7,0);
	bonus[2]=new CBonus(-55,16,-79,0.7,0.7,0);
	bonus[3]=new CBonus(-25,16,7,0.7,0.7,0);
	bonus[4]=new CBonus(92,16,-36,0.7,0.7,0);
	bonus[5]=new CBonus(91,16,115,0.7,0.7,0);
	bonus[6]=new CBonus(-55,16,109,0.7,0.7,0);

	podstawa=new CPodstawa(210,258,gr,0,0,0,1,1,1);

	//poziome:
	sciana[0]=new CSciany(174,sz,wys,18,os_y,126,1,1,1);
	sciana[1]=new CSciany(174,sz,wys,-18,os_y,-126,1,1,1);
	sciana[2]=new CSciany(138,sz,wys,0,os_y,-90,1,1,1);
	sciana[3]=new CSciany(129,sz,wys,34.5,os_y,-52,1,1,1);
	sciana[4]=new CSciany(102,sz,wys,48,os_y,-18,1,1,1);
	sciana[5]=new CSciany(102,sz,wys,15,os_y,18,1,1,1);
	sciana[6]=new CSciany(102,sz,wys,-18,os_y,54,1,1,1);
	sciana[7]=new CSciany(102,sz,wys,-18,os_y,90,1,1,1);

	//pionowe
	sciana[8]=new CSciany(252,sz,wys,-102,os_y,3,1,1,1);
	sciana[9]=new CSciany(252,sz,wys,102,os_y,-3,1,1,1);
	sciana[10]=new CSciany(138,sz,wys,-66,os_y,-18,1,1,1);
	sciana[11]=new CSciany(70,sz,wys,-33,os_y,-20,1,1,1);
	sciana[12]=new CSciany(70,sz,wys,63,os_y,55,1,1,1);
	sciana[13]=new CSciany(30,sz,wys,-66,os_y,108,1,1,1);
}

CPoziom1::~CPoziom1(void)
{
	delete podstawa;
	for(int i=0;i<14;i++)
		delete sciana[i];
	for(int  i=0;i<7;i++)
		delete bonus[i];
	delete kulka;
}

void CPoziom1::Rysuj(void)
{
	for(int i=8;i<14;i++)
		sciana[i]->rotacja[1]=90;

	podstawa->Rysuj();
	kulka->Rysuj();

	for(int i=0;i<14;i++)
		sciana[i]->Rysuj();
	for(int  i=0;i<7;i++)
		bonus[i]->Rysuj();
}