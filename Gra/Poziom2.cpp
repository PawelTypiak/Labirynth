#include "StdAfx.h"
#include "Poziom2.h"

CPoziom2::CPoziom2(void)
{
	gr=6;
	wys=30;
	sz=6;
	os_y=0.5*wys+0.5*gr;

	kulka=new CKulka(87,20,-85,1,0,0);

	bonus[0]=new CBonus(-94,16,-79,0.7,0.7,0);
	bonus[1]=new CBonus(-88,16,28,0.7,0.7,0);
	bonus[2]=new CBonus(-8,16,-73,0.7,0.7,0);
	bonus[3]=new CBonus(12,16,0,0.7,0.7,0);
	bonus[4]=new CBonus(94,16,80,0.7,0.7,0);
	bonus[5]=new CBonus(94,16,-44,0.7,0.7,0);
	bonus[6]=new CBonus(0,16,-38,0.7,0.7,0);

	podstawa=new CPodstawa(216,186,gr,0,0,0,1,1,1);

	//poziome:
	sciana[0]=new CSciany(210,sz,wys,-3,os_y,90,1,1,1);
	sciana[1]=new CSciany(180,sz,wys,-18,os_y,-90,1,1,1);
	sciana[2]=new CSciany(72,sz,wys,36,os_y,54,1,1,1);
	sciana[3]=new CSciany(36,sz,wys,-54,os_y,54,1,1,1);
	sciana[4]=new CSciany(36,sz,wys,18,os_y,18,1,1,1);
	sciana[5]=new CSciany(72,sz,wys,36,os_y,-18,1,1,1);
	sciana[6]=new CSciany(42,sz,wys,-87,os_y,18,1,1,1);
	sciana[7]=new CSciany(72,sz,wys,-72,os_y,-18,1,1,1);
	sciana[8]=new CSciany(66,sz,wys,69,os_y,-54,1,1,1);
	sciana[9]=new CSciany(78,sz,wys,-33,os_y,-54,1,1,1);

	//pionowe
	sciana[10]=new CSciany(186,sz,wys,105,os_y,0,1,1,1);
	sciana[11]=new CSciany(66,sz,wys,-105,os_y,54,1,1,1);
	sciana[12]=new CSciany(66,sz,wys,-105,os_y,-54,1,1,1);
	sciana[13]=new CSciany(66,sz,wys,69,os_y,18,1,1,1);
	sciana[14]=new CSciany(30,sz,wys,3,os_y,0,1,1,1);
	sciana[15]=new CSciany(42,sz,wys,-33,os_y,0,1,1,1);
	sciana[16]=new CSciany(30,sz,wys,-69,os_y,36,1,1,1);
	sciana[17]=new CSciany(30,sz,wys,3,os_y,-72,1,1,1);
}

CPoziom2::~CPoziom2(void)
{
	delete podstawa;
	for(int i=0;i<18;i++)
		delete sciana[i];
	for(int  i=0;i<7;i++)
		delete bonus[i];
	delete kulka;
}

void CPoziom2::Rysuj(void)
{
	for(int i=10;i<18;i++)
		sciana[i]->rotacja[1]=90;

	podstawa->Rysuj();
	kulka->Rysuj();

	for(int j=0;j<18;j++)
		sciana[j]->Rysuj();

	for(int  i=0;i<7;i++)
		bonus[i]->Rysuj();
}