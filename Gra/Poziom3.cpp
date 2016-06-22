#include "StdAfx.h"
#include "Poziom3.h"

CPoziom3::CPoziom3(void)
{
	gr=6;
	wys=30;
	sz=6;
	os_y=0.5*wys+0.5*gr;

	kulka=new CKulka(82,20,-40,1,0,0);

	bonus[0]=new CBonus(-75,16,-115,0.7,0.7,0);
	bonus[1]=new CBonus(69,16,-20,0.7,0.7,0);
	bonus[2]=new CBonus(-40,16,-65,0.7,0.7,0);
	bonus[3]=new CBonus(-40,16,-6,0.7,0.7,0);
	bonus[4]=new CBonus(4,16,35,0.7,0.7,0);
	bonus[5]=new CBonus(-68,16,115,0.7,0.7,0);
	bonus[6]=new CBonus(0,16,-38,0.7,0.7,0);
	bonus[7]=new CBonus(0,16,-38,0.7,0.7,0);
	bonus[8]=new CBonus(-38,16,108,0.7,0.7,0);

	podstawa=new CPodstawa(180,258,gr,0,0,0,1,1,1);

	//poziome:
	sciana[0]=new CSciany(144,sz,wys,-18,os_y,126,1,1,1);
	sciana[1]=new CSciany(180,sz,wys,0,os_y,-126,1,1,1);
	sciana[2]=new CSciany(72,sz,wys,-18,os_y,90,1,1,1);
	sciana[3]=new CSciany(102,sz,wys,-33,os_y,54,1,1,1);
	sciana[4]=new CSciany(36,sz,wys,0,os_y,18,1,1,1);
	sciana[5]=new CSciany(108,sz,wys,0,os_y,-18,1,1,1);
	sciana[6]=new CSciany(72,sz,wys,-18,os_y,-54,1,1,1);
	sciana[7]=new CSciany(78,sz,wys,15,os_y,-90,1,1,1);
	
	//pionowe
	sciana[8]=new CSciany(246,sz,wys,-87,os_y,0,1,1,1);
	sciana[9]=new CSciany(150,sz,wys,87,os_y,54,1,1,1);
	sciana[10]=new CSciany(66,sz,wys,87,os_y,-90,1,1,1);
	sciana[11]=new CSciany(108,sz,wys,51,os_y,69,1,1,1);
	sciana[12]=new CSciany(36,sz,wys,51,os_y,-69,1,1,1);
	sciana[13]=new CSciany(30,sz,wys,15,os_y,36,1,1,1);
	sciana[14]=new CSciany(30,sz,wys,-51,os_y,108,1,1,1);
	sciana[15]=new CSciany(36,sz,wys,-51,os_y,3,1,1,1);
	sciana[16]=new CSciany(30,sz,wys,-51,os_y,-72,1,1,1);
}

CPoziom3::~CPoziom3(void)
{
	delete podstawa;
	for(int i=0;i<17;i++)
		delete sciana[i];
	for(int  i=0;i<9;i++)
		delete bonus[i];
	delete kulka;
}

void CPoziom3::Rysuj(void)
{
	for(int i=8;i<17;i++)
		sciana[i]->rotacja[1]=90;
	

	podstawa->Rysuj();
	kulka->Rysuj();

	for(int i=0;i<17;i++)
		sciana[i]->Rysuj();

	for(int  i=0;i<9;i++)
		bonus[i]->Rysuj();
}