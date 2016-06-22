#include "StdAfx.h"
#include "Poziom4.h"

CPoziom4::CPoziom4(void)
{
	gr=6;
	wys=30;
	sz=6;
	os_y=0.5*wys+0.5*gr;
	
	kulka=new CKulka(71,20,-103,1,0,0);

	bonus[0]=new CBonus(-112,16,-97,0.7,0.7,0);
	bonus[1]=new CBonus(-112,16,90,0.7,0.7,0);
	bonus[2]=new CBonus(-76,16,-61,0.7,0.7,0);
	bonus[3]=new CBonus(112,16,-97,0.7,0.7,0);
	bonus[4]=new CBonus(76,16,-61,0.7,0.7,0);
	bonus[5]=new CBonus(105,16,0,0.7,0.7,0);
	bonus[6]=new CBonus(87,16,90,0.7,0.7,0);
	bonus[7]=new CBonus(-25,16,-25,0.7,0.7,0);

	podstawa=new CPodstawa(252,222,gr,0,0,0,1,1,1);

	//poziome:
	sciana[0]=new CSciany(174,sz,wys,-33,os_y,-108,1,1,1);
	sciana[1]=new CSciany(30,sz,wys,105,os_y,-108,1,1,1);
	sciana[2]=new CSciany(78,sz,wys,-51,os_y,-72,1,1,1);
	sciana[3]=new CSciany(72,sz,wys,54,os_y,-72,1,1,1);
	sciana[4]=new CSciany(42,sz,wys,-33,os_y,-36,1,1,1);
	sciana[5]=new CSciany(72,sz,wys,54,os_y,0,1,1,1);
	sciana[6]=new CSciany(108,sz,wys,36,os_y,36,1,1,1);
	sciana[7]=new CSciany(108,sz,wys,36,os_y,72,1,1,1);
	sciana[8]=new CSciany(36,sz,wys,-102,os_y,72,1,1,1);
	sciana[9]=new CSciany(174,sz,wys,-33,os_y,108,1,1,1);
	sciana[10]=new CSciany(30,sz,wys,105,os_y,108,1,1,1);

	//pionowe
	sciana[11]=new CSciany(222,sz,wys,123,os_y,0,1,1,1);
	sciana[12]=new CSciany(222,sz,wys,-123,os_y,0,1,1,1);
	sciana[13]=new CSciany(108,sz,wys,-87,os_y,-15,1,1,1);
	sciana[14]=new CSciany(108,sz,wys,-51,os_y,51,1,1,1);
	sciana[15]=new CSciany(66,sz,wys,-15,os_y,0,1,1,1);
	sciana[16]=new CSciany(36,sz,wys,51,os_y,-21,1,1,1);
	sciana[17]=new CSciany(36,sz,wys,87,os_y,-51,1,1,1);
	sciana[18]=new CSciany(36,sz,wys,21,os_y,-51,1,1,1);
}


CPoziom4::~CPoziom4(void)
{
	delete podstawa;
	for(int i=0;i<19;i++)
		delete sciana[i];
	for(int  i=0;i<8;i++)
		delete bonus[i];
	delete kulka;
}

void CPoziom4::Rysuj(void)
{
	for(int i=11;i<19;i++)
		sciana[i]->rotacja[1]=90;

	podstawa->Rysuj();
	kulka->Rysuj();
	for(int j=0;j<19;j++)
		sciana[j]->Rysuj();
	for(int  i=0;i<8;i++)
		bonus[i]->Rysuj();
}