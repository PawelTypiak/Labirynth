#include "StdAfx.h"
#include "openGLview.h"
#include <time.h>
#include <windows.h>

openGLview::openGLview(void)
{ 
	czasGL = 0;
	czas1 = 0;
	czas2 = 0;
	czas3 = 0;
	czas4 = 0;
	srand(GetTickCount());
	tmp=0;
	poziom[0]=new CPoziom1;
	poziom[1]=new CPoziom2;
	poziom[2]=new CPoziom3;
	poziom[3]=new CPoziom4;
	v=2;
	poz=0; 
}


openGLview::~openGLview(void)
{
	for(int i=0;i<4;i++)
		delete poziom[i];
	
}


void openGLview::display(void)
{ 
glClearColor(0,0,0,0);   //ustawiamy kolor t³a na czarny 
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //czyœcimy bufory 
glEnable(GL_DEPTH_TEST); //uruchamiamy bufor g³êbi 
rysuj_figury();

if(poz==0)
{
	glLoadIdentity();
	gluLookAt( // ustawienie pocz¹tkowe kamery 
	0, 300, 0, 0, 0, 0, 0, 0,1 );
}
if(poz==1)
{	
	if(tmp==0)
	{
	glLoadIdentity();
	gluLookAt( // ustawienie pocz¹tkowe kamery 
	0, 300, 0, 0, 0, 0, 0, 0,1 );
	}
	if(tmp==1)
	{
	glLoadIdentity();
	gluLookAt( // ustawienie pocz¹tkowe kamery 
	poziom[0]->kulka->translacja[0], 100, poziom[0]->kulka->translacja[2]-25, poziom[0]->kulka->translacja[0], 0, poziom[0]->kulka->translacja[2], 0, 1,0 );
	}
	if(tmp==2)
	{
	glLoadIdentity();
	gluLookAt( // ustawienie pocz¹tkowe kamery 
	0, 300, 0, 0, 0, 0, 0, 0,1 );
	}
	if(tmp==3)
	{
	glLoadIdentity();
	gluLookAt( // ustawienie pocz¹tkowe kamery 
	poziom[0]->kulka->translacja[0], 50, poziom[0]->kulka->translacja[2]-25, poziom[0]->kulka->translacja[0], 0, poziom[0]->kulka->translacja[2], 0, 1,0 );
	}
}
if(poz==2)
{
	if(tmp==0)
	{
	glLoadIdentity();
	gluLookAt( // ustawienie pocz¹tkowe kamery 
	0, 300, 0, 0, 0, 0, 0, 0,1 );
	}
	if(tmp==1)
	{
	glLoadIdentity();
	gluLookAt( // ustawienie pocz¹tkowe kamery 
	poziom[1]->kulka->translacja[0], 100, poziom[1]->kulka->translacja[2]-25, poziom[1]->kulka->translacja[0], 0, poziom[1]->kulka->translacja[2], 0, 1,0 );
	}
	if(tmp==2)
	{
	glLoadIdentity();
	gluLookAt( // ustawienie pocz¹tkowe kamery 
	0, 300, 0, 0, 0, 0, 0, 0,1 );
	}
	if(tmp==3)
	{
	glLoadIdentity();
	gluLookAt( // ustawienie pocz¹tkowe kamery 
	poziom[1]->kulka->translacja[0], 50, poziom[1]->kulka->translacja[2]-25, poziom[1]->kulka->translacja[0], 0, poziom[1]->kulka->translacja[2], 0, 1,0 );
	}
}
if(poz==3)
{
	if(tmp==0)
	{
	glLoadIdentity();
	gluLookAt( // ustawienie pocz¹tkowe kamery 
	0, 300, 0, 0, 0, 0, 0, 0,1 );
	}
	if(tmp==1)
	{
	glLoadIdentity();
	gluLookAt( // ustawienie pocz¹tkowe kamery 
	poziom[2]->kulka->translacja[0], 100, poziom[2]->kulka->translacja[2]-25, poziom[2]->kulka->translacja[0], 0, poziom[2]->kulka->translacja[2], 0, 1,0 );
	}
	if(tmp==2)
	{
	glLoadIdentity();
	gluLookAt( // ustawienie pocz¹tkowe kamery 
	0, 300, 0, 0, 0, 0, 0, 0,1 );
	}
	if(tmp==3)
	{
	glLoadIdentity();
	gluLookAt( // ustawienie pocz¹tkowe kamery 
	poziom[2]->kulka->translacja[0], 50, poziom[2]->kulka->translacja[2]-25, poziom[2]->kulka->translacja[0], 0, poziom[2]->kulka->translacja[2], 0, 1,0 );
	}
}
if(poz==4)
{
	if(tmp==0)
	{
	glLoadIdentity();
	gluLookAt( // ustawienie pocz¹tkowe kamery 
	0, 300, 0, 0, 0, 0, 0, 0,1 );
	}
	if(tmp==1)
	{
	glLoadIdentity();
	gluLookAt( // ustawienie pocz¹tkowe kamery 
	poziom[3]->kulka->translacja[0], 100, poziom[3]->kulka->translacja[2]-25, poziom[3]->kulka->translacja[0], 0, poziom[3]->kulka->translacja[2], 0, 1,0 );
	}
	if(tmp==2)
	{
	glLoadIdentity();
	gluLookAt( // ustawienie pocz¹tkowe kamery 
	0, 300, 0, 0, 0, 0, 0, 0,1 );
	}
	if(tmp==3)
	{
	glLoadIdentity();
	gluLookAt( // ustawienie pocz¹tkowe kamery 
	poziom[3]->kulka->translacja[0], 50, poziom[3]->kulka->translacja[2]-25, poziom[3]->kulka->translacja[0], 0, poziom[3]->kulka->translacja[2], 0, 1,0 );
	}
}
if(poz==5)
{
	glLoadIdentity();
	gluLookAt( // ustawienie pocz¹tkowe kamery 
	0, 300, 0, 0, 0, 0, 0, 0,1 );
}
if(poz==6)
{
	glLoadIdentity();
	gluLookAt( // ustawienie pocz¹tkowe kamery 
	0, 300, 0, 0, 0, 0, 0, 0,1 );
}
if(poz==7)
{
	glLoadIdentity();
	gluLookAt( // ustawienie pocz¹tkowe kamery 
	0, 300, 0, 0, 0, 0, 0, 0,1 );

}
glutSwapBuffers();//przerzuca bufor do okna u¿ywanego 
glutPostRedisplay(); // oznacz  okno jako to, które bêdzie aktualizowane. 
}
	
void openGLview::resize(int width, int height)
 { 
glViewport(0, 0, width, height);  //parametry okna
glMatrixMode(GL_PROJECTION); //ustawienie kontekstu obliczeñ macierzowych na stos projekcji
 //za³adowanie macierzy jednostkowej jako aktulanej macierzy 
gluPerspective(90.0, (float)width / (float)height, 0.1, 1000.0); //ustawienie macierzy projekcji
glMatrixMode(GL_MODELVIEW); //ustawienie kontekstu obliczeñ macierzowych na stos modelu
glLoadIdentity();  //za³adowanie macierzy jednostkowej jako aktulanej macierzy

}
void openGLview::animacja(void) 
{

	if(poz==1)
	{
		for(int i=0;i<7;i++)
		{ 
			if(	(poziom[0]->bonus[i]->pozycja[0]+11>poziom[0]->kulka->translacja[0]) && (poziom[0]->bonus[i]->pozycja[0]-11<poziom[0]->kulka->translacja[0]) 
			  &&(poziom[0]->bonus[i]->pozycja[2]+11>poziom[0]->kulka->translacja[2]) && (poziom[0]->bonus[i]->pozycja[2]-11<poziom[0]->kulka->translacja[2])) 
			{ 
				los=1 + rand() % (6 - 1);
				
				
				if(los==1)
				{
					poziom[0]->kulka->translacja[0]=84;
					poziom[0]->kulka->translacja[2]=-121;
				}
				else if(los==2)
				{
					poziom[0]->kulka->translacja[0]=-83;
					poziom[0]->kulka->translacja[2]=115;

				}
				else if(los==3)
				{
					tmp=2;
				}
				else if(los==4)
				{
					tmp=3;
				}
				else if(los==5)
				{
					v=1;

				}
			}

		}
	}
	if(poz==2)
	{
		for(int i=0;i<7;i++)
		{ 
			if(	(poziom[1]->bonus[i]->pozycja[0]+11>poziom[1]->kulka->translacja[0]) && (poziom[1]->bonus[i]->pozycja[0]-11<poziom[1]->kulka->translacja[0]) 
			  &&(poziom[1]->bonus[i]->pozycja[2]+11>poziom[1]->kulka->translacja[2]) && (poziom[1]->bonus[i]->pozycja[2]-11<poziom[1]->kulka->translacja[2])) 
			{ 

				los=1 + rand() % (6 - 1);
			
				if(los==1)
				{
					poziom[1]->kulka->translacja[0]=87;
					poziom[1]->kulka->translacja[2]=-85;
				}
				else if(los==2)
				{
					poziom[1]->kulka->translacja[0]=-95;
					poziom[1]->kulka->translacja[2]=-2;

				}
				else if(los==3)
				{
					tmp=2;
				}
				else if(los==4)
				{
					tmp=3;
				}
				else if(los==5)
				{
					v=1;

				}
			}

		}
	}
	if(poz==3)
	{
		for(int i=0;i<9;i++)
		{ 
			if(	(poziom[2]->bonus[i]->pozycja[0]+11>poziom[2]->kulka->translacja[0]) && (poziom[2]->bonus[i]->pozycja[0]-11<poziom[2]->kulka->translacja[0]) 
			  &&(poziom[2]->bonus[i]->pozycja[2]+11>poziom[2]->kulka->translacja[2]) && (poziom[2]->bonus[i]->pozycja[2]-11<poziom[2]->kulka->translacja[2])) 
			{ 

				los=1 + rand() % (6 - 1);
				
				if(los==1)
				{
					poziom[2]->kulka->translacja[0]=82;
					poziom[2]->kulka->translacja[2]=-40;
				}
				else if(los==2)
				{
					poziom[2]->kulka->translacja[0]=67;
					poziom[2]->kulka->translacja[2]=115;

				}
				else if(los==3)
				{
					tmp=2;
				}
				else if(los==4)
				{
					tmp=3;
				}
				else if(los==5)
				{
					v=1;

				}
			}

		}
	}
	if(poz==4)
	{
		for(int i=0;i<8;i++)
		{ 
			if(	(poziom[3]->bonus[i]->pozycja[0]+11>poziom[3]->kulka->translacja[0]) && (poziom[3]->bonus[i]->pozycja[0]-11<poziom[3]->kulka->translacja[0]) 
			  &&(poziom[3]->bonus[i]->pozycja[2]+11>poziom[3]->kulka->translacja[2]) && (poziom[3]->bonus[i]->pozycja[2]-11<poziom[3]->kulka->translacja[2])) 
			{ 

				los=1 + rand() % (6 - 1);
				
				v=1;
				if(los==1)
				{
					poziom[3]->kulka->translacja[0]=71;
					poziom[3]->kulka->translacja[2]=-103;
				}
				else if(los==2)
				{
					poziom[3]->kulka->translacja[0]=75;
					poziom[3]->kulka->translacja[2]=102;

				}
				else if(los==3)
				{
					tmp=2;
				}
				else if(los==4)
				{
					tmp=3;
				}
				else if(los==5)
				{
					v=1;

				}
			}

		}
	}
	
	for(int i=0;i<4;i++)
	{	
		if(poziom[i]->kulka->translacja[1]<15 || poziom[i]->kulka->translacja[1]>20)
		poziom[i]->kulka->step=-poziom[i]->kulka->step;

		poziom[i]->kulka->translacja[1]+=poziom[i]->kulka->step; 
	}
	for(int i=0;i<7;i++)
	{
		if(poziom[0]->bonus[i]->pozycja[1]<15 || poziom[0]->bonus[i]->pozycja[1]>20)
		poziom[0]->bonus[i]->step=-poziom[0]->bonus[i]->step;
	
		poziom[0]->bonus[i]->pozycja[1]+=poziom[0]->bonus[i]->step;
	}

	for(int i=0;i<7;i++)
	{
		if(poziom[1]->bonus[i]->pozycja[1]<15 || poziom[1]->bonus[i]->pozycja[1]>20)
		poziom[1]->bonus[i]->step=-poziom[1]->bonus[i]->step;
	
		poziom[1]->bonus[i]->pozycja[1]+=poziom[1]->bonus[i]->step;
	}
	for(int i=0;i<9;i++)
	{
		if(poziom[2]->bonus[i]->pozycja[1]<15 || poziom[2]->bonus[i]->pozycja[1]>20)
		poziom[2]->bonus[i]->step=-poziom[2]->bonus[i]->step;
	
		poziom[2]->bonus[i]->pozycja[1]+=poziom[2]->bonus[i]->step;
	}

	for(int i=0;i<8;i++)
	{
		if(poziom[3]->bonus[i]->pozycja[1]<15 || poziom[3]->bonus[i]->pozycja[1]>20)
		poziom[3]->bonus[i]->step=-poziom[3]->bonus[i]->step;
	
		poziom[3]->bonus[i]->pozycja[1]+=poziom[3]->bonus[i]->step;
	}
	
	
} 


void openGLview::keyboard(unsigned char key, int x, int y) 
{ 
if(poz==0)
{
	rysuj_figury();
	if(key==110)
	{
		zapisPoziom(0,0,0,0);
		tmp=0;
		poz=1;
		
	}
	if(key==119)
	{
		tmp=0;
		poz=odczytPoziom(1)+1;
		czas1=odczytPoziom(2);
		czas2=odczytPoziom(3);
		czas3=odczytPoziom(4);
		
	}
}

if(poz==1)
{
	rysuj_figury();
	if(tmp==0)
	{
		time(&start1);
	}
	if(key==13)
			tmp=1;
	if(key==27)
		exit(0);

	int odp = poziom[0]->kulka->spr( poz );
	if ( odp == 1 ) 
	{
		time ( &stop1 );
		czas1 = difftime ( stop1, start1 );
		
		if(czas1>20)
		{
			poz=6;
			rysuj_figury();
		}
		else
		{
		zapisRekord( czas1, 1 );
		zapisPoziom(1,czas1,czas2,czas3);
		v=2;
		tmp=0;
		poz=2;
		
		}
	}
	if(tmp==1 || tmp==2 || tmp==3)
	{
		if(    (poziom[0]->kulka->translacja[0]>-92 && poziom[0]->kulka->translacja[0]<90  && poziom[0]->kulka->translacja[2]<=-100 && poziom[0]->kulka->translacja[2]>=-119 )
			|| (poziom[0]->kulka->translacja[0]>76  && poziom[0]->kulka->translacja[0]<90  && poziom[0]->kulka->translacja[2]<-63   && poziom[0]->kulka->translacja[2]>-122)
			|| (poziom[0]->kulka->translacja[0]<90  && poziom[0]->kulka->translacja[0]>-56 && poziom[0]->kulka->translacja[2]<-63   && poziom[0]->kulka->translacja[2]>-83 )
			|| (poziom[0]->kulka->translacja[0]>-56 && poziom[0]->kulka->translacja[0]<-44 && poziom[0]->kulka->translacja[2]<43    && poziom[0]->kulka->translacja[2]>-83 )
			|| (poziom[0]->kulka->translacja[0]<52  && poziom[0]->kulka->translacja[0]>-56 && poziom[0]->kulka->translacja[2]<44    && poziom[0]->kulka->translacja[2]>26 )
			|| (poziom[0]->kulka->translacja[0]<52  && poziom[0]->kulka->translacja[0]>40  && poziom[0]->kulka->translacja[2]<117   && poziom[0]->kulka->translacja[2]>27 )
			|| (poziom[0]->kulka->translacja[0]<90  && poziom[0]->kulka->translacja[0]>-56 && poziom[0]->kulka->translacja[2]<117   && poziom[0]->kulka->translacja[2]>98 )
			|| (poziom[0]->kulka->translacja[0]<52  && poziom[0]->kulka->translacja[0]>-91 && poziom[0]->kulka->translacja[2]<82    && poziom[0]->kulka->translacja[2]>60 )
			|| (poziom[0]->kulka->translacja[0]<-78 && poziom[0]->kulka->translacja[0]>-92 && poziom[0]->kulka->translacja[2]<122   && poziom[0]->kulka->translacja[2]>-122 )
			|| (poziom[0]->kulka->translacja[0]<90  && poziom[0]->kulka->translacja[0]>74  && poziom[0]->kulka->translacja[2]<119   && poziom[0]->kulka->translacja[2]>-10 )
			|| (poziom[0]->kulka->translacja[0]<90  && poziom[0]->kulka->translacja[0]>-24 && poziom[0]->kulka->translacja[2]<8     && poziom[0]->kulka->translacja[2]>-10 )
			|| (poziom[0]->kulka->translacja[0]<90  && poziom[0]->kulka->translacja[0]>-24 && poziom[0]->kulka->translacja[2]<-28   && poziom[0]->kulka->translacja[2]>-46 )
			|| (poziom[0]->kulka->translacja[0]<-12 && poziom[0]->kulka->translacja[0]>-24 && poziom[0]->kulka->translacja[2]<8     && poziom[0]->kulka->translacja[2]>-46 )
		  )
		{
			if (key == 97) 
			{
				poziom[0]->kulka->rotacja[1]=90;
				poziom[0]->kulka->Przesun(v,0,0);
			}  //key a
		}

		if(    (poziom[0]->kulka->translacja[0]>-90  && poziom[0]->kulka->translacja[2]<=-100 && poziom[0]->kulka->translacja[2]>=-119 && poziom[0]->kulka->translacja[0]<92 )
			|| (poziom[0]->kulka->translacja[0]>78   && poziom[0]->kulka->translacja[0]<92    && poziom[0]->kulka->translacja[2]<-63   && poziom[0]->kulka->translacja[2]>-122)
			|| (poziom[0]->kulka->translacja[0]>-54  && poziom[0]->kulka->translacja[0]<91    && poziom[0]->kulka->translacja[2]<-63   && poziom[0]->kulka->translacja[2]>-83 )
			|| (poziom[0]->kulka->translacja[0]>-54  && poziom[0]->kulka->translacja[0]<-42   && poziom[0]->kulka->translacja[2]<43    && poziom[0]->kulka->translacja[2]>-83 )
			|| (poziom[0]->kulka->translacja[0]>-54  && poziom[0]->kulka->translacja[0]<54    && poziom[0]->kulka->translacja[2]<44    && poziom[0]->kulka->translacja[2]>26 )
			|| (poziom[0]->kulka->translacja[0]<50   && poziom[0]->kulka->translacja[0]>41    && poziom[0]->kulka->translacja[2]<43    && poziom[0]->kulka->translacja[2]>27 )
			|| (poziom[0]->kulka->translacja[0]<54   && poziom[0]->kulka->translacja[0]>42    && poziom[0]->kulka->translacja[2]<117   && poziom[0]->kulka->translacja[2]>27 )
			|| (poziom[0]->kulka->translacja[0]<92   && poziom[0]->kulka->translacja[0]>-54   && poziom[0]->kulka->translacja[2]<117   && poziom[0]->kulka->translacja[2]>98 )
			|| (poziom[0]->kulka->translacja[0]<52   && poziom[0]->kulka->translacja[0]>-90   && poziom[0]->kulka->translacja[2]<82	   && poziom[0]->kulka->translacja[2]>60 )
			|| (poziom[0]->kulka->translacja[0]<-76  && poziom[0]->kulka->translacja[0]>-90   && poziom[0]->kulka->translacja[2]<122   && poziom[0]->kulka->translacja[2]>-122 )
			|| (poziom[0]->kulka->translacja[0]<92   && poziom[0]->kulka->translacja[0]>76    && poziom[0]->kulka->translacja[2]<119   && poziom[0]->kulka->translacja[2]>-10 )
			|| (poziom[0]->kulka->translacja[0]<92   && poziom[0]->kulka->translacja[0]>-22   && poziom[0]->kulka->translacja[2]<8     && poziom[0]->kulka->translacja[2]>-10 )
			|| (poziom[0]->kulka->translacja[0]<92   && poziom[0]->kulka->translacja[0]>-22   && poziom[0]->kulka->translacja[2]<-28   && poziom[0]->kulka->translacja[2]>-46 )
			|| (poziom[0]->kulka->translacja[0]<-10  && poziom[0]->kulka->translacja[0]>-22   && poziom[0]->kulka->translacja[2]<8     && poziom[0]->kulka->translacja[2]>-46 )
		 ) 
		{
			if (key == 100) 
			{ 
				poziom[0]->kulka->rotacja[1]=270;
				poziom[0]->kulka->Przesun(-v,0,0); 
			}  //key d
		} 

		if(	   (poziom[0]->kulka->translacja[2]>-119 && poziom[0]->kulka->translacja[2]<-102 && poziom[0]->kulka->translacja[0]<78  && poziom[0]->kulka->translacja[0]>=-91 )
			|| (poziom[0]->kulka->translacja[2]>-122 && poziom[0]->kulka->translacja[2]<-65	 && poziom[0]->kulka->translacja[0]<92  && poziom[0]->kulka->translacja[0]>76 )
			|| (poziom[0]->kulka->translacja[2]<-65  && poziom[0]->kulka->translacja[2]>-83	 && poziom[0]->kulka->translacja[0]<91  && poziom[0]->kulka->translacja[0]>-56 )
			|| (poziom[0]->kulka->translacja[2]<42   && poziom[0]->kulka->translacja[2]>-83  && poziom[0]->kulka->translacja[0]<-42 && poziom[0]->kulka->translacja[0]>-56)
			|| (poziom[0]->kulka->translacja[2]<42   && poziom[0]->kulka->translacja[2]>26   && poziom[0]->kulka->translacja[0]<54  && poziom[0]->kulka->translacja[0]>-56 )
			|| (poziom[0]->kulka->translacja[0]<54   && poziom[0]->kulka->translacja[0]>40   && poziom[0]->kulka->translacja[2]<114 && poziom[0]->kulka->translacja[2]>27 )
			|| (poziom[0]->kulka->translacja[0]<92   && poziom[0]->kulka->translacja[0]>-56  && poziom[0]->kulka->translacja[2]<115 && poziom[0]->kulka->translacja[2]>98 )

			|| (poziom[0]->kulka->translacja[0]<54   && poziom[0]->kulka->translacja[0]>-91  && poziom[0]->kulka->translacja[2]<80  && poziom[0]->kulka->translacja[2]>60 )
			|| (poziom[0]->kulka->translacja[0]<-76  && poziom[0]->kulka->translacja[0]>-92  && poziom[0]->kulka->translacja[2]<130 && poziom[0]->kulka->translacja[2]>-122 )
			|| (poziom[0]->kulka->translacja[0]<92   && poziom[0]->kulka->translacja[0]>74   && poziom[0]->kulka->translacja[2]<117 && poziom[0]->kulka->translacja[2]>-10 )
			|| (poziom[0]->kulka->translacja[0]<92   && poziom[0]->kulka->translacja[0]>-24  && poziom[0]->kulka->translacja[2]<6   && poziom[0]->kulka->translacja[2]>-10 )
			|| (poziom[0]->kulka->translacja[0]<92   && poziom[0]->kulka->translacja[0]>-24  && poziom[0]->kulka->translacja[2]<-30 && poziom[0]->kulka->translacja[2]>-46 )
			|| (poziom[0]->kulka->translacja[0]<-10  && poziom[0]->kulka->translacja[0]>-24  && poziom[0]->kulka->translacja[2]<6   && poziom[0]->kulka->translacja[2]>-46 )
		)
		{
			if (key == 119)
			{
				poziom[0]->kulka->rotacja[1]=0;
				poziom[0]->kulka->Przesun(0,0,v); 
			} //key w
		} 

		if(    (poziom[0]->kulka->translacja[2]>-118 && poziom[0]->kulka->translacja[2]<-100 && poziom[0]->kulka->translacja[0]<92  && poziom[0]->kulka->translacja[0]>=-91)
			|| (poziom[0]->kulka->translacja[0]<92	 && poziom[0]->kulka->translacja[0]>76   && poziom[0]->kulka->translacja[2]<-63 && poziom[0]->kulka->translacja[2]>-120 )
			|| (poziom[0]->kulka->translacja[2]>-82  && poziom[0]->kulka->translacja[2]<-63  && poziom[0]->kulka->translacja[0]<91  && poziom[0]->kulka->translacja[0]>-56 )
			|| (poziom[0]->kulka->translacja[2]>-82  && poziom[0]->kulka->translacja[2]<43   && poziom[0]->kulka->translacja[0]<-42 && poziom[0]->kulka->translacja[0]>-56 )
			|| (poziom[0]->kulka->translacja[2]>28   && poziom[0]->kulka->translacja[2]<44   && poziom[0]->kulka->translacja[0]<54  && poziom[0]->kulka->translacja[0]>-56)
			|| (poziom[0]->kulka->translacja[0]<54   && poziom[0]->kulka->translacja[0]>40   && poziom[0]->kulka->translacja[2]<117 && poziom[0]->kulka->translacja[2]>29 )
			|| (poziom[0]->kulka->translacja[0]<92   && poziom[0]->kulka->translacja[0]>-56  && poziom[0]->kulka->translacja[2]<117 && poziom[0]->kulka->translacja[2]>100 )
			|| (poziom[0]->kulka->translacja[0]<54   && poziom[0]->kulka->translacja[0]>-91  && poziom[0]->kulka->translacja[2]<82  && poziom[0]->kulka->translacja[2]>62 )
			|| (poziom[0]->kulka->translacja[0]<-76  && poziom[0]->kulka->translacja[0]>-92  && poziom[0]->kulka->translacja[2]<122 && poziom[0]->kulka->translacja[2]>-118 )
			|| (poziom[0]->kulka->translacja[0]<92   && poziom[0]->kulka->translacja[0]>74   && poziom[0]->kulka->translacja[2]<119 && poziom[0]->kulka->translacja[2]>-8 )
			|| (poziom[0]->kulka->translacja[0]<92   && poziom[0]->kulka->translacja[0]>-24  && poziom[0]->kulka->translacja[2]<8   && poziom[0]->kulka->translacja[2]>-8 )
			|| (poziom[0]->kulka->translacja[0]<92   && poziom[0]->kulka->translacja[0]>-24  && poziom[0]->kulka->translacja[2]<-28 && poziom[0]->kulka->translacja[2]>-44 )
			|| (poziom[0]->kulka->translacja[0]<-10  && poziom[0]->kulka->translacja[0]>-24  && poziom[0]->kulka->translacja[2]<8   && poziom[0]->kulka->translacja[2]>-44 )
		)
		{
			if (key == 115) 
			{ 
				poziom[0]->kulka->rotacja[1]=180;
				poziom[0]->kulka->Przesun(0,0,-v); 
			} //key s
		}
	}
}


if(poz==2)
{
	rysuj_figury();
	if(tmp==0)
	{
		time(&start2);

	}
	if(key==13)
			tmp=1;

	if(key==27)
		exit(0);

	int odp = poziom[1]->kulka->spr( poz );
	if ( odp == 1 ) 
	{
		time ( &stop2 );
		czas2 = difftime ( stop2, start2 );
		if(czas2>(20+20-czas1))
		{
			poz=6;
			rysuj_figury();
		}
		else
		{
			zapisRekord( czas2, 2 );
			zapisPoziom(2,czas1,czas2,czas3);
			v=2;
			tmp=0;
			poz=3;
			
		}
	}

	if(tmp==1 || tmp==2 || tmp==3)
	{
		if(    (poziom[1]->kulka->translacja[0]<94  && poziom[1]->kulka->translacja[0]>78   && poziom[1]->kulka->translacja[2]<-63 && poziom[1]->kulka->translacja[2]>-89 )
			|| (poziom[1]->kulka->translacja[0]<94  && poziom[1]->kulka->translacja[0]>12   && poziom[1]->kulka->translacja[2]<-63 && poziom[1]->kulka->translacja[2]>-82 )
			|| (poziom[1]->kulka->translacja[0]<28  && poziom[1]->kulka->translacja[0]>12   && poziom[1]->kulka->translacja[2]<-27 && poziom[1]->kulka->translacja[2]>-82 )
			|| (poziom[1]->kulka->translacja[0]<94  && poziom[1]->kulka->translacja[0]>-96  && poziom[1]->kulka->translacja[2]<-27 && poziom[1]->kulka->translacja[2]>-47 )
			|| (poziom[1]->kulka->translacja[0]<-80 && poziom[1]->kulka->translacja[0]>-96  && poziom[1]->kulka->translacja[2]<-27 && poziom[1]->kulka->translacja[2]>-82 )
			|| (poziom[1]->kulka->translacja[0]<-8  && poziom[1]->kulka->translacja[0]>-96  && poziom[1]->kulka->translacja[2]<-63 && poziom[1]->kulka->translacja[2]>-82 )
			|| (poziom[1]->kulka->translacja[0]<94  && poziom[1]->kulka->translacja[0]>78   && poziom[1]->kulka->translacja[2]<79  && poziom[1]->kulka->translacja[2]>-47 )
			|| (poziom[1]->kulka->translacja[0]<94  && poziom[1]->kulka->translacja[0]>-86  && poziom[1]->kulka->translacja[2]<79  && poziom[1]->kulka->translacja[2]>57 )
			|| (poziom[1]->kulka->translacja[0]<-80 && poziom[1]->kulka->translacja[0]>-96  && poziom[1]->kulka->translacja[2]<79  && poziom[1]->kulka->translacja[2]>23 )
			|| (poziom[1]->kulka->translacja[0]<-8  && poziom[1]->kulka->translacja[0]>-24  && poziom[1]->kulka->translacja[2]<79  && poziom[1]->kulka->translacja[2]>-47 )
			|| (poziom[1]->kulka->translacja[0]<-8  && poziom[1]->kulka->translacja[0]>-30  && poziom[1]->kulka->translacja[2]<79  && poziom[1]->kulka->translacja[2]>23 )
			|| (poziom[1]->kulka->translacja[0]<58  && poziom[1]->kulka->translacja[0]>-60  && poziom[1]->kulka->translacja[2]<45  && poziom[1]->kulka->translacja[2]>23 )
			|| (poziom[1]->kulka->translacja[0]<58  && poziom[1]->kulka->translacja[0]>42   && poziom[1]->kulka->translacja[2]<45  && poziom[1]->kulka->translacja[2]>-11 )
			|| (poziom[1]->kulka->translacja[0]<58  && poziom[1]->kulka->translacja[0]>12   && poziom[1]->kulka->translacja[2]<7   && poziom[1]->kulka->translacja[2]>-11 )
			|| (poziom[1]->kulka->translacja[0]<-44 && poziom[1]->kulka->translacja[0]>-60  && poziom[1]->kulka->translacja[2]<45  && poziom[1]->kulka->translacja[2]>-11 )
			|| (poziom[1]->kulka->translacja[0]<-44 && poziom[1]->kulka->translacja[0]>-100 && poziom[1]->kulka->translacja[2]<9   && poziom[1]->kulka->translacja[2]>-11 )
		  )
		{
			if (key == 97) 
			{
				poziom[1]->kulka->rotacja[1]=90;
				poziom[1]->kulka->Przesun(v,0,0);
			}  //key a
		}

		if(	   (poziom[1]->kulka->translacja[0]<96  && poziom[1]->kulka->translacja[0]>80  && poziom[1]->kulka->translacja[2]<-63 && poziom[1]->kulka->translacja[2]>-89 )
			|| (poziom[1]->kulka->translacja[0]<96  && poziom[1]->kulka->translacja[0]>14  && poziom[1]->kulka->translacja[2]<-63 && poziom[1]->kulka->translacja[2]>-82 )
			|| (poziom[1]->kulka->translacja[0]<30  && poziom[1]->kulka->translacja[0]>14  && poziom[1]->kulka->translacja[2]<-27 && poziom[1]->kulka->translacja[2]>-82 )
			|| (poziom[1]->kulka->translacja[0]<92  && poziom[1]->kulka->translacja[0]>-94 && poziom[1]->kulka->translacja[2]<-27 && poziom[1]->kulka->translacja[2]>-47 )
			|| (poziom[1]->kulka->translacja[0]<-78 && poziom[1]->kulka->translacja[0]>-94 && poziom[1]->kulka->translacja[2]<-27 && poziom[1]->kulka->translacja[2]>-82 )
			|| (poziom[1]->kulka->translacja[0]<-6  && poziom[1]->kulka->translacja[0]>-94 && poziom[1]->kulka->translacja[2]<-63 && poziom[1]->kulka->translacja[2]>-82 )
			|| (poziom[1]->kulka->translacja[0]<96  && poziom[1]->kulka->translacja[0]>80  && poziom[1]->kulka->translacja[2]<79  && poziom[1]->kulka->translacja[2]>-47 )
			|| (poziom[1]->kulka->translacja[0]<96  && poziom[1]->kulka->translacja[0]>-94 && poziom[1]->kulka->translacja[2]<79  && poziom[1]->kulka->translacja[2]>57 )
			|| (poziom[1]->kulka->translacja[0]<-78 && poziom[1]->kulka->translacja[0]>-94 && poziom[1]->kulka->translacja[2]<79  && poziom[1]->kulka->translacja[2]>23 )
			|| (poziom[1]->kulka->translacja[0]<-6  && poziom[1]->kulka->translacja[0]>-22 && poziom[1]->kulka->translacja[2]<79  && poziom[1]->kulka->translacja[2]>-47 )
			|| (poziom[1]->kulka->translacja[0]<-10 && poziom[1]->kulka->translacja[0]>-28 && poziom[1]->kulka->translacja[2]<79  && poziom[1]->kulka->translacja[2]>23 )
			|| (poziom[1]->kulka->translacja[0]<60  && poziom[1]->kulka->translacja[0]>-58 && poziom[1]->kulka->translacja[2]<45  && poziom[1]->kulka->translacja[2]>23 )
			|| (poziom[1]->kulka->translacja[0]<60  && poziom[1]->kulka->translacja[0]>44  && poziom[1]->kulka->translacja[2]<45  && poziom[1]->kulka->translacja[2]>-11 )
			|| (poziom[1]->kulka->translacja[0]<60  && poziom[1]->kulka->translacja[0]>14  && poziom[1]->kulka->translacja[2]<7   && poziom[1]->kulka->translacja[2]>-11 )
			|| (poziom[1]->kulka->translacja[0]<-42 && poziom[1]->kulka->translacja[0]>-58 && poziom[1]->kulka->translacja[2]<45  && poziom[1]->kulka->translacja[2]>-11 )
			|| (poziom[1]->kulka->translacja[0]<-42 && poziom[1]->kulka->translacja[0]>-108 && poziom[1]->kulka->translacja[2]<9   && poziom[1]->kulka->translacja[2]>-11 )
		 )
		{
			if (key == 100) 
			{ 
				poziom[1]->kulka->rotacja[1]=270;
				poziom[1]->kulka->Przesun(-v,0,0); 
			}  //key d
		}

		if(    (poziom[1]->kulka->translacja[0]<96  && poziom[1]->kulka->translacja[0]>78   && poziom[1]->kulka->translacja[2]<-65 && poziom[1]->kulka->translacja[2]>-89 )
			|| (poziom[1]->kulka->translacja[0]<96  && poziom[1]->kulka->translacja[0]>12   && poziom[1]->kulka->translacja[2]<-65 && poziom[1]->kulka->translacja[2]>-82 )
			|| (poziom[1]->kulka->translacja[0]<30  && poziom[1]->kulka->translacja[0]>12   && poziom[1]->kulka->translacja[2]<-29 && poziom[1]->kulka->translacja[2]>-82 )
			|| (poziom[1]->kulka->translacja[0]<96  && poziom[1]->kulka->translacja[0]>-96  && poziom[1]->kulka->translacja[2]<-29 && poziom[1]->kulka->translacja[2]>-47 )
			|| (poziom[1]->kulka->translacja[0]<-78 && poziom[1]->kulka->translacja[0]>-96  && poziom[1]->kulka->translacja[2]<-29 && poziom[1]->kulka->translacja[2]>-82 )
			|| (poziom[1]->kulka->translacja[0]<-6  && poziom[1]->kulka->translacja[0]>-96  && poziom[1]->kulka->translacja[2]<-65 && poziom[1]->kulka->translacja[2]>-82 )
			|| (poziom[1]->kulka->translacja[0]<96  && poziom[1]->kulka->translacja[0]>78   && poziom[1]->kulka->translacja[2]<77  && poziom[1]->kulka->translacja[2]>-47 )
			|| (poziom[1]->kulka->translacja[0]<96  && poziom[1]->kulka->translacja[0]>-86  && poziom[1]->kulka->translacja[2]<77  && poziom[1]->kulka->translacja[2]>57 )
			|| (poziom[1]->kulka->translacja[0]<-78 && poziom[1]->kulka->translacja[0]>-96  && poziom[1]->kulka->translacja[2]<77  && poziom[1]->kulka->translacja[2]>23 )
			|| (poziom[1]->kulka->translacja[0]<-6  && poziom[1]->kulka->translacja[0]>-24  && poziom[1]->kulka->translacja[2]<77  && poziom[1]->kulka->translacja[2]>-47 )
			|| (poziom[1]->kulka->translacja[0]<-10 && poziom[1]->kulka->translacja[0]>-30  && poziom[1]->kulka->translacja[2]<77  && poziom[1]->kulka->translacja[2]>25 )
			|| (poziom[1]->kulka->translacja[0]<60  && poziom[1]->kulka->translacja[0]>-60  && poziom[1]->kulka->translacja[2]<43  && poziom[1]->kulka->translacja[2]>25 )
			|| (poziom[1]->kulka->translacja[0]<60  && poziom[1]->kulka->translacja[0]>42   && poziom[1]->kulka->translacja[2]<43  && poziom[1]->kulka->translacja[2]>-11 )
			|| (poziom[1]->kulka->translacja[0]<60  && poziom[1]->kulka->translacja[0]>12   && poziom[1]->kulka->translacja[2]<5   && poziom[1]->kulka->translacja[2]>-11 )
			|| (poziom[1]->kulka->translacja[0]<-42 && poziom[1]->kulka->translacja[0]>-60  && poziom[1]->kulka->translacja[2]<43  && poziom[1]->kulka->translacja[2]>-11 )
			|| (poziom[1]->kulka->translacja[0]<-42 && poziom[1]->kulka->translacja[0]>-100 && poziom[1]->kulka->translacja[2]<7   && poziom[1]->kulka->translacja[2]>-11 )
			)
		{
			if (key == 119)
			{
				poziom[1]->kulka->rotacja[1]=0;
				poziom[1]->kulka->Przesun(0,0,v);
			} //key w
		}

		if(    (poziom[1]->kulka->translacja[0]<96   && poziom[1]->kulka->translacja[0]>78   && poziom[1]->kulka->translacja[2]<-63 && poziom[1]->kulka->translacja[2]>-87 )
			|| (poziom[1]->kulka->translacja[0]<96   && poziom[1]->kulka->translacja[0]>12   && poziom[1]->kulka->translacja[2]<-63 && poziom[1]->kulka->translacja[2]>-80 )
			|| (poziom[1]->kulka->translacja[0]<30   && poziom[1]->kulka->translacja[0]>12   && poziom[1]->kulka->translacja[2]<-27 && poziom[1]->kulka->translacja[2]>-80 )
			|| (poziom[1]->kulka->translacja[0]<92   && poziom[1]->kulka->translacja[0]>-96  && poziom[1]->kulka->translacja[2]<-27 && poziom[1]->kulka->translacja[2]>-45 )
			|| (poziom[1]->kulka->translacja[0]<-78  && poziom[1]->kulka->translacja[0]>-96  && poziom[1]->kulka->translacja[2]<-27 && poziom[1]->kulka->translacja[2]>-80 )
			|| (poziom[1]->kulka->translacja[0]<-6   && poziom[1]->kulka->translacja[0]>-96  && poziom[1]->kulka->translacja[2]<-63 && poziom[1]->kulka->translacja[2]>-80 )
			|| (poziom[1]->kulka->translacja[0]<96   && poziom[1]->kulka->translacja[0]>78   && poziom[1]->kulka->translacja[2]<79  && poziom[1]->kulka->translacja[2]>-45 )
			|| (poziom[1]->kulka->translacja[0]<96   && poziom[1]->kulka->translacja[0]>-96  && poziom[1]->kulka->translacja[2]<79  && poziom[1]->kulka->translacja[2]>59 )
			|| (poziom[1]->kulka->translacja[0]<-78  && poziom[1]->kulka->translacja[0]>-96  && poziom[1]->kulka->translacja[2]<79  && poziom[1]->kulka->translacja[2]>25 )
			|| (poziom[1]->kulka->translacja[0]<-6   && poziom[1]->kulka->translacja[0]>-24  && poziom[1]->kulka->translacja[2]<79  && poziom[1]->kulka->translacja[2]>-45 )
			|| (poziom[1]->kulka->translacja[0]<-10  && poziom[1]->kulka->translacja[0]>-30  && poziom[1]->kulka->translacja[2]<79  && poziom[1]->kulka->translacja[2]>27 )
			|| (poziom[1]->kulka->translacja[0]<60   && poziom[1]->kulka->translacja[0]>-60  && poziom[1]->kulka->translacja[2]<45  && poziom[1]->kulka->translacja[2]>27 )
			|| (poziom[1]->kulka->translacja[0]<60   && poziom[1]->kulka->translacja[0]>42   && poziom[1]->kulka->translacja[2]<45  && poziom[1]->kulka->translacja[2]>-9 )
			|| (poziom[1]->kulka->translacja[0]<60   && poziom[1]->kulka->translacja[0]>12   && poziom[1]->kulka->translacja[2]<7   && poziom[1]->kulka->translacja[2]>-9 )
			|| (poziom[1]->kulka->translacja[0]<-42  && poziom[1]->kulka->translacja[0]>-60  && poziom[1]->kulka->translacja[2]<45  && poziom[1]->kulka->translacja[2]>-9 )
			|| (poziom[1]->kulka->translacja[0]<-42  && poziom[1]->kulka->translacja[0]>-100 && poziom[1]->kulka->translacja[2]<9   && poziom[1]->kulka->translacja[2]>-9 )
		 )
		{
			if (key == 115) 
			{ 
				poziom[1]->kulka->rotacja[1]=180;
				poziom[1]->kulka->Przesun(0,0,-v); 
			} //key s
		}
	}
}

if(poz==3)
{
	rysuj_figury();

	if(tmp==0)
	{
		time(&start3);

	}
	if(key==13)
			tmp=1;
	if(key==27)
		exit(0);

	int odp = poziom[2]->kulka->spr( poz );
	if ( odp == 1 ) 
	{
		time ( &stop3 );
		czas3 = difftime ( stop3, start3 );
		if(czas3>(20+20-czas2))
		{
			poz=6;
			
		}
		else
		{
			zapisRekord( czas3, 3 );
			zapisPoziom(3,czas1,czas2,czas3);
			v=2;
			tmp=0;
			poz=4;
			
		}
	}

	if(tmp==1 || tmp==2 || tmp==3)
	{
		if(    (poziom[2]->kulka->translacja[0]<82  && poziom[2]->kulka->translacja[0]>60   && poziom[2]->kulka->translacja[2]<-26 && poziom[2]->kulka->translacja[2]>-52 )
			|| (poziom[2]->kulka->translacja[0]<82  && poziom[2]-> kulka->translacja[0]>-78 && poziom[2]->kulka->translacja[2]<-26 && poziom[2]->kulka->translacja[2]>-46)
			|| (poziom[2]->kulka->translacja[0]<-62 && poziom[2]->kulka->translacja[0]>-78  && poziom[2]-> kulka->translacja[2]<46 && poziom[2]->kulka->translacja[2]>-118)
			|| (poziom[2]->kulka->translacja[0]<76  && poziom[2]->kulka->translacja[0]>-78  && poziom[2]->kulka->translacja[2]<-98 && poziom[2]->kulka->translacja[2]>-118)
			|| (poziom[2]->kulka->translacja[0]<76  && poziom[2]->kulka->translacja[0]>60   && poziom[2]->kulka->translacja[2]<124 && poziom[2]->kulka->translacja[2]>-118)
			|| (poziom[2]->kulka->translacja[0]<40  && poziom[2]->kulka->translacja[0]>24   && poziom[2]->kulka->translacja[2]<-26 && poziom[2]->kulka->translacja[2]>-82)
			|| (poziom[2]->kulka->translacja[0]<40  && poziom[2]->kulka->translacja[0]>-44  && poziom[2]->kulka->translacja[2]<-62 && poziom[2]->kulka->translacja[2]>-82)
			|| (poziom[2]->kulka->translacja[0]<-32 && poziom[2]->kulka->translacja[0]>-42  && poziom[2]->kulka->translacja[2]<-62 && poziom[2]->kulka->translacja[2]>-118)
			|| (poziom[2]->kulka->translacja[0]<-32 && poziom[2]->kulka->translacja[0]>-78  && poziom[2]->kulka->translacja[2]<-94 && poziom[2]->kulka->translacja[2]>-118)
			|| (poziom[2]->kulka->translacja[0]<76  && poziom[2]->kulka->translacja[0]>-40  && poziom[2]->kulka->translacja[2]<8   && poziom[2]->kulka->translacja[2]>-12)
			|| (poziom[2]->kulka->translacja[0]<-26 && poziom[2]->kulka->translacja[0]>-44  && poziom[2]->kulka->translacja[2]<46  && poziom[2]->kulka->translacja[2]>-12)
			|| (poziom[2]->kulka->translacja[0]<4   && poziom[2]->kulka->translacja[0]>-78  && poziom[2]->kulka->translacja[2]<46  && poziom[2]->kulka->translacja[2]>24)
			|| (poziom[2]->kulka->translacja[0]<40  && poziom[2]->kulka->translacja[0]>24   && poziom[2]->kulka->translacja[2]<118 && poziom[2]->kulka->translacja[2]>-12)
			|| (poziom[2]->kulka->translacja[0]<40  && poziom[2]->kulka->translacja[0]>-78  && poziom[2]->kulka->translacja[2]<78  && poziom[2]->kulka->translacja[2]>60)
			|| (poziom[2]->kulka->translacja[0]<40  && poziom[2]->kulka->translacja[0]>-42  && poziom[2]->kulka->translacja[2]<118 && poziom[2]->kulka->translacja[2]>98)
			|| (poziom[2]->kulka->translacja[0]<-62 && poziom[2]->kulka->translacja[0]>-78  && poziom[2]->kulka->translacja[2]<118 && poziom[2]->kulka->translacja[2]>60)
		 )
		{
			if (key == 97) 
			{
				poziom[2]->kulka->rotacja[1]=90;
				poziom[2]->kulka->Przesun(v,0,0);
			}  //key a
		}

		if(	   (poziom[2]->kulka->translacja[0]<84  && poziom[2]->kulka->translacja[0]>62  && poziom[2]->kulka->translacja[2]<-26 && poziom[2]->kulka->translacja[2]>-52 )
			|| (poziom[2]->kulka->translacja[0]<84  && poziom[2]->kulka->translacja[0]>-76 && poziom[2]->kulka->translacja[2]<-26 && poziom[2]->kulka->translacja[2]>-46)
			|| (poziom[2]->kulka->translacja[0]<-60 && poziom[2]->kulka->translacja[0]>-76 && poziom[2]->kulka->translacja[2]<46  && poziom[2]->kulka->translacja[2]>-118)
			|| (poziom[2]->kulka->translacja[0]<78  && poziom[2]->kulka->translacja[0]>-76 && poziom[2]->kulka->translacja[2]<-98 && poziom[2]->kulka->translacja[2]>-118)
			|| (poziom[2]->kulka->translacja[0]<78  && poziom[2]->kulka->translacja[0]>62  && poziom[2]->kulka->translacja[2]<124 && poziom[2]->kulka->translacja[2]>-118)
			|| (poziom[2]->kulka->translacja[0]<42  && poziom[2]->kulka->translacja[0]>26  && poziom[2]->kulka->translacja[2]<-26 && poziom[2]->kulka->translacja[2]>-82)
			|| (poziom[2]->kulka->translacja[0]<42  && poziom[2]->kulka->translacja[0]>-40 && poziom[2]->kulka->translacja[2]<-62 && poziom[2]->kulka->translacja[2]>-82)
			|| (poziom[2]->kulka->translacja[0]<-30 && poziom[2]->kulka->translacja[0]>-40 && poziom[2]->kulka->translacja[2]<-62 && poziom[2]->kulka->translacja[2]>-118)
			|| (poziom[2]->kulka->translacja[0]<-30 && poziom[2]->kulka->translacja[0]>-76 && poziom[2]->kulka->translacja[2]<-94 && poziom[2]->kulka->translacja[2]>-118)
			|| (poziom[2]->kulka->translacja[0]<78  && poziom[2]->kulka->translacja[0]>-40 && poziom[2]->kulka->translacja[2]<8   && poziom[2]->kulka->translacja[2]>-12)
			|| (poziom[2]->kulka->translacja[0]<-24 && poziom[2]->kulka->translacja[0]>-40 && poziom[2]->kulka->translacja[2]<46  && poziom[2]->kulka->translacja[2]>-12)
			|| (poziom[2]->kulka->translacja[0]<6   && poziom[2]->kulka->translacja[0]>-76 && poziom[2]->kulka->translacja[2]<46  && poziom[2]->kulka->translacja[2]>24)
			|| (poziom[2]->kulka->translacja[0]<42  && poziom[2]->kulka->translacja[0]>26  && poziom[2]->kulka->translacja[2]<118 && poziom[2]->kulka->translacja[2]>-12)
			|| (poziom[2]->kulka->translacja[0]<42  && poziom[2]->kulka->translacja[0]>-76 && poziom[2]->kulka->translacja[2]<78  && poziom[2]->kulka->translacja[2]>60)
			|| (poziom[2]->kulka->translacja[0]<42  && poziom[2]->kulka->translacja[0]>-40 && poziom[2]->kulka->translacja[2]<118 && poziom[2]->kulka->translacja[2]>98)
			|| (poziom[2]->kulka->translacja[0]<-60 && poziom[2]->kulka->translacja[0]>-76 && poziom[2]->kulka->translacja[2]<118 && poziom[2]->kulka->translacja[2]>60)
		 )
		{
			if (key == 100) 
			{ 
				poziom[2]->kulka->rotacja[1]=270;
				poziom[2]->kulka->Przesun(-v,0,0); 
			}  //key d
		}

		if(	   (poziom[2]->kulka->translacja[0]<84  && poziom[2]->kulka->translacja[0]>60  && poziom[2]->kulka->translacja[2]<-28  && poziom[2]->kulka->translacja[2]>-52 )
			|| (poziom[2]->kulka->translacja[0]<84  && poziom[2]->kulka->translacja[0]>-78 && poziom[2]->kulka->translacja[2]<-28  && poziom[2]->kulka->translacja[2]>-46)
			|| (poziom[2]->kulka->translacja[0]<-60 && poziom[2]->kulka->translacja[0]>-78 && poziom[2]->kulka->translacja[2]<44   && poziom[2]->kulka->translacja[2]>-118)
			|| (poziom[2]->kulka->translacja[0]<78  && poziom[2]->kulka->translacja[0]>-78 && poziom[2]->kulka->translacja[2]<-100 && poziom[2]->kulka->translacja[2]>-118)
			|| (poziom[2]->kulka->translacja[0]<78  && poziom[2]->kulka->translacja[0]>60  && poziom[2]->kulka->translacja[2]<135  && poziom[2]->kulka->translacja[2]>-118)
			|| (poziom[2]->kulka->translacja[0]<42  && poziom[2]->kulka->translacja[0]>24  && poziom[2]->kulka->translacja[2]<-28  && poziom[2]->kulka->translacja[2]>-82)
			|| (poziom[2]->kulka->translacja[0]<42  && poziom[2]->kulka->translacja[0]>-42 && poziom[2]->kulka->translacja[2]<-64  && poziom[2]->kulka->translacja[2]>-82)
			|| (poziom[2]->kulka->translacja[0]<-30 && poziom[2]->kulka->translacja[0]>-42 && poziom[2]->kulka->translacja[2]<-64  && poziom[2]->kulka->translacja[2]>-118)
			|| (poziom[2]->kulka->translacja[0]<-30 && poziom[2]->kulka->translacja[0]>-78 && poziom[2]->kulka->translacja[2]<-96  && poziom[2]->kulka->translacja[2]>-118)
			|| (poziom[2]->kulka->translacja[0]<78  && poziom[2]->kulka->translacja[0]>-40 && poziom[2]->kulka->translacja[2]<6    && poziom[2]->kulka->translacja[2]>-12)
			|| (poziom[2]->kulka->translacja[0]<-24 && poziom[2]->kulka->translacja[0]>-44 && poziom[2]->kulka->translacja[2]<44   && poziom[2]->kulka->translacja[2]>-12)
			|| (poziom[2]->kulka->translacja[0]<6   && poziom[2]->kulka->translacja[0]>-78 && poziom[2]->kulka->translacja[2]<44   && poziom[2]->kulka->translacja[2]>24) 
			|| (poziom[2]->kulka->translacja[0]<42  && poziom[2]->kulka->translacja[0]>24  && poziom[2]->kulka->translacja[2]<116  && poziom[2]->kulka->translacja[2]>-12)
			|| (poziom[2]->kulka->translacja[0]<42  && poziom[2]->kulka->translacja[0]>-78 && poziom[2]->kulka->translacja[2]<76   && poziom[2]->kulka->translacja[2]>60)
			|| (poziom[2]->kulka->translacja[0]<42  && poziom[2]->kulka->translacja[0]>-42 && poziom[2]->kulka->translacja[2]<116  && poziom[2]->kulka->translacja[2]>98)
			|| (poziom[2]->kulka->translacja[0]<-60 && poziom[2]->kulka->translacja[0]>-78 && poziom[2]->kulka->translacja[2]<116  && poziom[2]->kulka->translacja[2]>60)
		)
		{
			if (key == 119)
			{
				poziom[2]->kulka->rotacja[1]=0;
				poziom[2]->kulka->Przesun(0,0,v); 
			} //key w
		}

		if(	   (poziom[2]->kulka->translacja[0]<84  && poziom[2]->kulka->translacja[0]>60   && poziom[2]->kulka->translacja[2]<-26 && poziom[2]->kulka->translacja[2]>-50 )
			|| (poziom[2]->kulka->translacja[0]<84  && poziom[2]->kulka->translacja[0]>-78  && poziom[2]->kulka->translacja[2]<-26 && poziom[2]->kulka->translacja[2]>-44)
			|| (poziom[2]->kulka->translacja[0]<-60 && poziom[2]->kulka->translacja[0]>-78  && poziom[2]->kulka->translacja[2]<46  && poziom[2]->kulka->translacja[2]>-116)
			|| (poziom[2]->kulka->translacja[0]<78  && poziom[2]->kulka->translacja[0]>-78  && poziom[2]->kulka->translacja[2]<-98 && poziom[2]->kulka->translacja[2]>-116)
			|| (poziom[2]->kulka->translacja[0]<78  && poziom[2]->kulka->translacja[0]>60   && poziom[2]->kulka->translacja[2]<124 && poziom[2]->kulka->translacja[2]>-116)
			|| (poziom[2]->kulka->translacja[0]<42  && poziom[2]->kulka->translacja[0]>24   && poziom[2]->kulka->translacja[2]<-26 && poziom[2]->kulka->translacja[2]>-80)
			|| (poziom[2]->kulka->translacja[0]<42  && poziom[2]->kulka->translacja[0]>-44  && poziom[2]->kulka->translacja[2]<-62 && poziom[2]->kulka->translacja[2]>-80)
			|| (poziom[2]->kulka->translacja[0]<-30 && poziom[2]->kulka->translacja[0]>-42  && poziom[2]->kulka->translacja[2]<-62 && poziom[2]->kulka->translacja[2]>-116)
			|| (poziom[2]->kulka->translacja[0]<-30 && poziom[2]->kulka->translacja[0]>-78  && poziom[2]->kulka->translacja[2]<-94 && poziom[2]->kulka->translacja[2]>-116)
			|| (poziom[2]->kulka->translacja[0]<78  && poziom[2]->kulka->translacja[0]>-40  && poziom[2]->kulka->translacja[2]<8   && poziom[2]->kulka->translacja[2]>-10)
			|| (poziom[2]->kulka->translacja[0]<-24 && poziom[2]-> kulka->translacja[0]>-44 && poziom[2]->kulka->translacja[2]<46  && poziom[2]->kulka->translacja[2]>-10)
			|| (poziom[2]->kulka->translacja[0]<6   && poziom[2]->kulka->translacja[0]>-78  && poziom[2]->kulka->translacja[2]<46  && poziom[2]->kulka->translacja[2]>26)
			|| (poziom[2]->kulka->translacja[0]<42  && poziom[2]->kulka->translacja[0]>24   && poziom[2]->kulka->translacja[2]<118 && poziom[2]->kulka->translacja[2]>-10)
			|| (poziom[2]->kulka->translacja[0]<42  && poziom[2]->kulka->translacja[0]>-78  && poziom[2]->kulka->translacja[2]<78  && poziom[2]->kulka->translacja[2]>62)
			|| (poziom[2]->kulka->translacja[0]<42  && poziom[2]->kulka->translacja[0]>-42  && poziom[2]->kulka->translacja[2]<118 && poziom[2]->kulka->translacja[2]>100)
			|| (poziom[2]->kulka->translacja[0]<-60 && poziom[2]->kulka->translacja[0]>-78  && poziom[2]->kulka->translacja[2]<118 && poziom[2]->kulka->translacja[2]>62)
		 )
		{
			if (key == 115) 
			{ 
				poziom[2]->kulka->rotacja[1]=180;
				poziom[2]->kulka->Przesun(0,0,-v); 
			} //key s 
		}
	}
}
if(poz==4)
{
	rysuj_figury();
	if(tmp==0)
	{
		time(&start4);


	}
	if(key==13)
			tmp=1;

	if(key==27)
		exit(0);

	int odp = poziom[3]->kulka->spr( poz );
	if ( odp == 1 ) 
	{
		time ( &stop4 );
		
		czas4 = difftime ( stop4, start4);
		czasGL = czas1+czas2+czas3+czas4;
		zapisRekord( czas4, 4 );
		if(czas4>(20+20-czas3))
		{
			poz=6;
			
		}
		else
		{
			zapisRekord( czas4, 4 );
			v=2;
			poz=5;
			
		}
	}

	if(tmp==1 || tmp==2 || tmp==3)
	{
		if(	   (poziom[3]->kulka->translacja[0]<82  && poziom[3]->kulka->translacja[0]>60   && poziom[3]->kulka->translacja[2]<-80 && poziom[3]->kulka->translacja[2]>-106 )
			|| (poziom[3]->kulka->translacja[0]<112 && poziom[3]->kulka->translacja[0]>-114 && poziom[3]->kulka->translacja[2]<-80 && poziom[3]->kulka->translacja[2]>-100 )
			|| (poziom[3]->kulka->translacja[0]<112 && poziom[3]->kulka->translacja[0]>96   && poziom[3]->kulka->translacja[2]<100 && poziom[3]->kulka->translacja[2]>-100 )
			|| (poziom[3]->kulka->translacja[0]<-98 && poziom[3]->kulka->translacja[0]>-114 && poziom[3]->kulka->translacja[2]<64  && poziom[3]->kulka->translacja[2]>-100 )
			|| (poziom[3]->kulka->translacja[0]<-62 && poziom[3]->kulka->translacja[0]>-114 && poziom[3]->kulka->translacja[2]<64  && poziom[3]->kulka->translacja[2]>44 )
			|| (poziom[3]->kulka->translacja[0]<-62 && poziom[3]->kulka->translacja[0]>-78  && poziom[3]->kulka->translacja[2]<100 && poziom[3]->kulka->translacja[2]>-64 )
			|| (poziom[3]->kulka->translacja[0]<-62 && poziom[3]->kulka->translacja[0]>-114 && poziom[3]->kulka->translacja[2]<100 && poziom[3]->kulka->translacja[2]>80 )
			|| (poziom[3]->kulka->translacja[0]<112 && poziom[3]->kulka->translacja[0]>60   && poziom[3]->kulka->translacja[2]<-10 && poziom[3]->kulka->translacja[2]>-28 )
			|| (poziom[3]->kulka->translacja[0]<112 && poziom[3]->kulka->translacja[0]>-6   && poziom[3]->kulka->translacja[2]<28  && poziom[3]->kulka->translacja[2]>6 )
			|| (poziom[3]->kulka->translacja[0]<10  && poziom[3]->kulka->translacja[0]>-6   && poziom[3]->kulka->translacja[2]<28  && poziom[3]->kulka->translacja[2]>-100 )
			|| (poziom[3]->kulka->translacja[0]<10  && poziom[3]->kulka->translacja[0]>-76  && poziom[3]->kulka->translacja[2]<-44 && poziom[3]->kulka->translacja[2]>-64 )
			|| (poziom[3]->kulka->translacja[0]<40  && poziom[3]->kulka->translacja[0]>-6   && poziom[3]->kulka->translacja[2]<-10 && poziom[3]->kulka->translacja[2]>-28 )
			|| (poziom[3]->kulka->translacja[0]<40  && poziom[3]->kulka->translacja[0]>30   && poziom[3]->kulka->translacja[2]<-10 && poziom[3]->kulka->translacja[2]>-64 )
			|| (poziom[3]->kulka->translacja[0]<76  && poziom[3]->kulka->translacja[0]>30   && poziom[3]->kulka->translacja[2]<-44 && poziom[3]->kulka->translacja[2]>-64 )
			|| (poziom[3]->kulka->translacja[0]<76  && poziom[3]->kulka->translacja[0]>60   && poziom[3]->kulka->translacja[2]<-10 && poziom[3]->kulka->translacja[2]>-62 )
			|| (poziom[3]->kulka->translacja[0]<-26 && poziom[3]->kulka->translacja[0]>-78  && poziom[3]->kulka->translacja[2]<-10 && poziom[3]->kulka->translacja[2]>-26 )
			|| (poziom[3]->kulka->translacja[0]<-26 && poziom[3]->kulka->translacja[0]>-42  && poziom[3]->kulka->translacja[2]<100 && poziom[3]->kulka->translacja[2]>-26 )
			|| (poziom[3]->kulka->translacja[0]<112 && poziom[3]->kulka->translacja[0]>-42  && poziom[3]->kulka->translacja[2]<100 && poziom[3]->kulka->translacja[2]>80 )
			|| (poziom[3]->kulka->translacja[0]<112 && poziom[3]->kulka->translacja[0]>-42  && poziom[3]->kulka->translacja[2]<64  && poziom[3]->kulka->translacja[2]>44 )
			|| (poziom[3]->kulka->translacja[0]<82  && poziom[3]->kulka->translacja[0]>60   && poziom[3]->kulka->translacja[2]<106 && poziom[3]->kulka->translacja[2]>80 )
		 )
		{
			if (key == 97) 
			{
				poziom[3]->kulka->rotacja[1]=90;
				poziom[3]->kulka->Przesun(v,0,0);
			}  //key a
		}

		if(    (poziom[3]->kulka->translacja[0]<84  && poziom[3]->kulka->translacja[0]>62   && poziom[3]->kulka->translacja[2]<-80 && poziom[3]->kulka->translacja[2]>-106 )
			|| (poziom[3]->kulka->translacja[0]<114 && poziom[3]->kulka->translacja[0]>-112 && poziom[3]->kulka->translacja[2]<-80 && poziom[3]->kulka->translacja[2]>-100 )
			|| (poziom[3]->kulka->translacja[0]<114 && poziom[3]->kulka->translacja[0]>98   && poziom[3]->kulka->translacja[2]<100 && poziom[3]->kulka->translacja[2]>-100 )
			|| (poziom[3]->kulka->translacja[0]<-96 && poziom[3]->kulka->translacja[0]>-112 && poziom[3]->kulka->translacja[2]<64  && poziom[3]->kulka->translacja[2]>-100 )
			|| (poziom[3]->kulka->translacja[0]<-60 && poziom[3]->kulka->translacja[0]>-112 && poziom[3]->kulka->translacja[2]<64  && poziom[3]->kulka->translacja[2]>44 )
			|| (poziom[3]->kulka->translacja[0]<-60 && poziom[3]->kulka->translacja[0]>-76  && poziom[3]->kulka->translacja[2]<100 && poziom[3]->kulka->translacja[2]>-64 )
			|| (poziom[3]->kulka->translacja[0]<-60 && poziom[3]->kulka->translacja[0]>-112 && poziom[3]->kulka->translacja[2]<100 && poziom[3]->kulka->translacja[2]>80 )
			|| (poziom[3]->kulka->translacja[0]<114 && poziom[3]->kulka->translacja[0]>62   && poziom[3]->kulka->translacja[2]<-10 && poziom[3]->kulka->translacja[2]>-28 )
			|| (poziom[3]->kulka->translacja[0]<114 && poziom[3]->kulka->translacja[0]>-4   && poziom[3]->kulka->translacja[2]<28  && poziom[3]->kulka->translacja[2]>6 )
			|| (poziom[3]->kulka->translacja[0]<12  && poziom[3]->kulka->translacja[0]>-4   && poziom[3]->kulka->translacja[2]<28  && poziom[3]->kulka->translacja[2]>-100 )
			|| (poziom[3]->kulka->translacja[0]<12  && poziom[3]->kulka->translacja[0]>-74  && poziom[3]->kulka->translacja[2]<-44 && poziom[3]->kulka->translacja[2]>-64 )
			|| (poziom[3]->kulka->translacja[0]<42  && poziom[3]->kulka->translacja[0]>-4   && poziom[3]->kulka->translacja[2]<-10 && poziom[3]->kulka->translacja[2]>-28 )
			|| (poziom[3]->kulka->translacja[0]<42  && poziom[3]->kulka->translacja[0]>32   && poziom[3]->kulka->translacja[2]<-10 && poziom[3]->kulka->translacja[2]>-64 )
			|| (poziom[3]->kulka->translacja[0]<78  && poziom[3]->kulka->translacja[0]>32   && poziom[3]->kulka->translacja[2]<-44 && poziom[3]->kulka->translacja[2]>-64 )
			|| (poziom[3]->kulka->translacja[0]<78  && poziom[3]->kulka->translacja[0]>62   && poziom[3]->kulka->translacja[2]<-10 && poziom[3]->kulka->translacja[2]>-64 )
			|| (poziom[3]->kulka->translacja[0]<-24 && poziom[3]->kulka->translacja[0]>-76  && poziom[3]->kulka->translacja[2]<-10 && poziom[3]->kulka->translacja[2]>-26 )
			|| (poziom[3]->kulka->translacja[0]<-24 && poziom[3]->kulka->translacja[0]>-40  && poziom[3]->kulka->translacja[2]<100 && poziom[3]->kulka->translacja[2]>-26 )
			|| (poziom[3]->kulka->translacja[0]<114 && poziom[3]->kulka->translacja[0]>-40  && poziom[3]->kulka->translacja[2]<100 && poziom[3]->kulka->translacja[2]>80 )
			|| (poziom[3]->kulka->translacja[0]<114 && poziom[3]->kulka->translacja[0]>-40  && poziom[3]->kulka->translacja[2]<64  && poziom[3]->kulka->translacja[2]>44 )
			|| (poziom[3]->kulka->translacja[0]<84  && poziom[3]->kulka->translacja[0]>62   && poziom[3]->kulka->translacja[2]<106 && poziom[3]->kulka->translacja[2]>80 )
		  )
		{
			if (key == 100) 
			{ 
				poziom[3]->kulka->rotacja[1]=270;
				poziom[3]->kulka->Przesun(-v,0,0); 
			}  //key d
		}

		if(    (poziom[3]->kulka->translacja[0]<84  && poziom[3]->kulka->translacja[0]>60   && poziom[3]->kulka->translacja[2]<-84 && poziom[3]->kulka->translacja[2]>-106 )
			|| (poziom[3]->kulka->translacja[0]<114 && poziom[3]->kulka->translacja[0]>-114 && poziom[3]->kulka->translacja[2]<-84 && poziom[3]->kulka->translacja[2]>-100 )
			|| (poziom[3]->kulka->translacja[0]<114 && poziom[3]->kulka->translacja[0]>96   && poziom[3]->kulka->translacja[2]<96  && poziom[3]->kulka->translacja[2]>-100 )
			|| (poziom[3]->kulka->translacja[0]<-96 && poziom[3]->kulka->translacja[0]>-114 && poziom[3]->kulka->translacja[2]<60  && poziom[3]->kulka->translacja[2]>-100 )
			|| (poziom[3]->kulka->translacja[0]<-60 && poziom[3]->kulka->translacja[0]>-114 && poziom[3]->kulka->translacja[2]<60  && poziom[3]->kulka->translacja[2]>44 )
			|| (poziom[3]->kulka->translacja[0]<-60 && poziom[3]->kulka->translacja[0]>-78  && poziom[3]->kulka->translacja[2]<96  && poziom[3]->kulka->translacja[2]>-64 )
			|| (poziom[3]->kulka->translacja[0]<-60 && poziom[3]->kulka->translacja[0]>-114 && poziom[3]->kulka->translacja[2]<96  && poziom[3]->kulka->translacja[2]>80 )
			|| (poziom[3]->kulka->translacja[0]<114 && poziom[3]->kulka->translacja[0]>60   && poziom[3]->kulka->translacja[2]<-12 && poziom[3]->kulka->translacja[2]>-28 )
			|| (poziom[3]->kulka->translacja[0]<114 && poziom[3]->kulka->translacja[0]>-6   && poziom[3]->kulka->translacja[2]<24  && poziom[3]->kulka->translacja[2]>6 )
			|| (poziom[3]->kulka->translacja[0]<12  && poziom[3]->kulka->translacja[0]>-6   && poziom[3]->kulka->translacja[2]<24  && poziom[3]->kulka->translacja[2]>-100 )
			|| (poziom[3]->kulka->translacja[0]<12  && poziom[3]->kulka->translacja[0]>-76  && poziom[3]->kulka->translacja[2]<-48 && poziom[3]->kulka->translacja[2]>-64 )
			|| (poziom[3]->kulka->translacja[0]<42  && poziom[3]->kulka->translacja[0]>-6   && poziom[3]->kulka->translacja[2]<-12 && poziom[3]->kulka->translacja[2]>-28 )
			|| (poziom[3]->kulka->translacja[0]<42  && poziom[3]->kulka->translacja[0]>30   && poziom[3]->kulka->translacja[2]<-12 && poziom[3]->kulka->translacja[2]>-64 )
			|| (poziom[3]->kulka->translacja[0]<78  && poziom[3]->kulka->translacja[0]>30   && poziom[3]->kulka->translacja[2]<-48 && poziom[3]->kulka->translacja[2]>-64 )
			|| (poziom[3]->kulka->translacja[0]<78  && poziom[3]->kulka->translacja[0]>60   && poziom[3]->kulka->translacja[2]<-12 && poziom[3]->kulka->translacja[2]>-64 )
			|| (poziom[3]->kulka->translacja[0]<-24 && poziom[3]->kulka->translacja[0]>-78  && poziom[3]->kulka->translacja[2]<-12 && poziom[3]->kulka->translacja[2]>-26 )
			|| (poziom[3]->kulka->translacja[0]<-24 && poziom[3]->kulka->translacja[0]>-42  && poziom[3]->kulka->translacja[2]<96  && poziom[3]->kulka->translacja[2]>-26 )
			|| (poziom[3]->kulka->translacja[0]<114 && poziom[3]->kulka->translacja[0]>-42  && poziom[3]->kulka->translacja[2]<96  && poziom[3]->kulka->translacja[2]>80 )
			|| (poziom[3]->kulka->translacja[0]<114 && poziom[3]->kulka->translacja[0]>-42  && poziom[3]->kulka->translacja[2]<60  && poziom[3]->kulka->translacja[2]>44 )
			|| (poziom[3]->kulka->translacja[0]<84  && poziom[3]->kulka->translacja[0]>60   && poziom[3]->kulka->translacja[2]<112 && poziom[3]->kulka->translacja[2]>80 )
		  )
		{
			if (key == 119)
			{
			poziom[3]->kulka->rotacja[1]=0;
			poziom[3]->kulka->Przesun(0,0,v); 

			} //key w
		}

		if(    (poziom[3]->kulka->translacja[0]<84  && poziom[3]->kulka->translacja[0]>60   && poziom[3]->kulka->translacja[2]<-80 && poziom[3]->kulka->translacja[2]>-104 )
			|| (poziom[3]->kulka->translacja[0]<114 && poziom[3]->kulka->translacja[0]>-114 && poziom[3]->kulka->translacja[2]<-80 && poziom[3]->kulka->translacja[2]>-98 )
			|| (poziom[3]->kulka->translacja[0]<114 && poziom[3]->kulka->translacja[0]>96   && poziom[3]->kulka->translacja[2]<100 && poziom[3]->kulka->translacja[2]>-98 )
			|| (poziom[3]->kulka->translacja[0]<-96 && poziom[3]->kulka->translacja[0]>-114 && poziom[3]->kulka->translacja[2]<64  && poziom[3]->kulka->translacja[2]>-98 )
			|| (poziom[3]->kulka->translacja[0]<-60 && poziom[3]->kulka->translacja[0]>-114 && poziom[3]->kulka->translacja[2]<64  && poziom[3]->kulka->translacja[2]>46 )
			|| (poziom[3]->kulka->translacja[0]<-60 && poziom[3]->kulka->translacja[0]>-78  && poziom[3]->kulka->translacja[2]<100 && poziom[3]->kulka->translacja[2]>-62 )
			|| (poziom[3]->kulka->translacja[0]<-60 && poziom[3]->kulka->translacja[0]>-114 && poziom[3]->kulka->translacja[2]<100 && poziom[3]->kulka->translacja[2]>82 )
			|| (poziom[3]->kulka->translacja[0]<114 && poziom[3]->kulka->translacja[0]>60   && poziom[3]->kulka->translacja[2]<-10 && poziom[3]->kulka->translacja[2]>-26 )
			|| (poziom[3]->kulka->translacja[0]<114 && poziom[3]->kulka->translacja[0]>-6   && poziom[3]->kulka->translacja[2]<28  && poziom[3]->kulka->translacja[2]>8 )
			|| (poziom[3]->kulka->translacja[0]<12  && poziom[3]->kulka->translacja[0]>-6   && poziom[3]->kulka->translacja[2]<26  && poziom[3]->kulka->translacja[2]>-98 )
			|| (poziom[3]->kulka->translacja[0]<12  && poziom[3]->kulka->translacja[0]>-76  && poziom[3]->kulka->translacja[2]<-46 && poziom[3]->kulka->translacja[2]>-62 )
			|| (poziom[3]->kulka->translacja[0]<42  && poziom[3]->kulka->translacja[0]>-6   && poziom[3]->kulka->translacja[2]<-10 && poziom[3]->kulka->translacja[2]>-26 )
			|| (poziom[3]->kulka->translacja[0]<42  && poziom[3]->kulka->translacja[0]>30   && poziom[3]->kulka->translacja[2]<-10 && poziom[3]->kulka->translacja[2]>-62 )
			|| (poziom[3]->kulka->translacja[0]<78  && poziom[3]->kulka->translacja[0]>30   && poziom[3]->kulka->translacja[2]<-44 && poziom[3]->kulka->translacja[2]>-62 )
			|| (poziom[3]->kulka->translacja[0]<78  && poziom[3]->kulka->translacja[0]>60   && poziom[3]->kulka->translacja[2]<-10 && poziom[3]->kulka->translacja[2]>-62 )
			|| (poziom[3]->kulka->translacja[0]<-24 && poziom[3]->kulka->translacja[0]>-78  && poziom[3]->kulka->translacja[2]<-10 && poziom[3]->kulka->translacja[2]>-24 )
			|| (poziom[3]->kulka->translacja[0]<-24 && poziom[3]->kulka->translacja[0]>-42  && poziom[3]->kulka->translacja[2]<100 && poziom[3]->kulka->translacja[2]>-24 )
			|| (poziom[3]->kulka->translacja[0]<114 && poziom[3]->kulka->translacja[0]>-42  && poziom[3]->kulka->translacja[2]<100 && poziom[3]->kulka->translacja[2]>82 )
			|| (poziom[3]->kulka->translacja[0]<114 && poziom[3]->kulka->translacja[0]>-42  && poziom[3]->kulka->translacja[2]<64  && poziom[3]->kulka->translacja[2]>46 )
			|| (poziom[3]->kulka->translacja[0]<84  && poziom[3]->kulka->translacja[0]>60   && poziom[3]->kulka->translacja[2]<106 && poziom[3]->kulka->translacja[2]>82 )
		 )
		{
			if (key == 115) 
			{ 
				poziom[3]->kulka->rotacja[1]=180;
				poziom[3]->kulka->Przesun(0,0,-v); 
			} //key s
		}
	}

}

if(poz==5)
{
	rysuj_figury();
	zapisPoziom(0,0,0,0);
	if(key==27)
		exit(0);
	if(key==114)
	{
		poz=7;
	}

}
if(poz==6)
{
	rysuj_figury();
	if(key==27)
		exit(0);

}
if(poz==7)
{

	rysuj_figury();
	if(key==27)
		exit(0);

}

}
void openGLview::drawText(int x, int y, int z,char *string) // rysuje napis "string" w pozycji x, y 
{ 
glRasterPos3f(x, y, z);//pozycja napisu 
for (int i = 0; i < strlen (string); i++)//literka po literce 
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]); 
}; 
void openGLview::rysuj_figury(void) 
{ 
	if(poz==0)
	{
		sprintf(napis, "Gra 'Labirynt'"); 
		drawText(70,60,100,napis);
		sprintf(napis, "Aby rozpoczac nowa gre wcisnij 'n'"); 
		drawText(140,60,60,napis);
		sprintf(napis, "Aby wczytac gre wcisnij 'w'"); 
		drawText(120,60,30,napis);

	}
	if (poz==1)
	{
		
		poziom[0]->Rysuj();
		if(tmp==0)
		{
			sprintf(napis, "Poziom 1"); 
		    drawText(40,60,190,napis);
			sprintf(napis, "Masz 20 s"); 
		    drawText(50,60,170,napis);
			sprintf(napis, "Wcisnij 'enter' aby rozpoczac"); 
		    drawText(100,60,150,napis);
			sprintf(napis, "Wcisnij 'esc' aby wyjsc"); 
		    drawText(90,60,130,napis);
		}
		if(tmp==1||tmp==3)
		{
			sprintf(napis, "Poziom 1"); 
		    drawText(poziom[0]->kulka->translacja[0]-10,60,poziom[0]->kulka->translacja[2]+30,napis);
		}
		if(tmp==2)
		{
			sprintf(napis, "Poziom 1"); 
		    drawText(40,60,200,napis);
		}

	}
	else if(poz==2)
	{
		
		poziom[1]->Rysuj();
		if(tmp==0)
		{
			sprintf(napis, "Poziom 2"); 
		    drawText(40,60,190,napis);
			sprintf(napis, "Masz 20 s + %d",20-czas1); 
		    drawText(60,60,170,napis);
			sprintf(napis, "Wcisnij 'enter' aby rozpoczac"); 
		    drawText(100,60,150,napis);
			sprintf(napis, "Wcisnij 'esc' aby wyjsc"); 
		    drawText(90,60,130,napis);
		}
		if(tmp==1||tmp==3)
		{
			sprintf(napis, "Poziom 2"); 
		    drawText(poziom[1]->kulka->translacja[0]-10,60,poziom[1]->kulka->translacja[2]+30,napis);
		}
		if(tmp==2)
		{
			sprintf(napis, "Poziom 2"); 
		    drawText(40,60,200,napis);
		}
	}
	else if(poz==3)
	{
		
		poziom[2]->Rysuj();
		if(tmp==0)
		{
			sprintf(napis, "Poziom 3"); 
		    drawText(40,60,190,napis);
			sprintf(napis, "Masz 20 s + %d",20-czas2); 
		    drawText(60,60,170,napis);
			sprintf(napis, "Wcisnij 'enter' aby rozpoczac"); 
		    drawText(100,60,150,napis);
			sprintf(napis, "Wcisnij 'esc' aby wyjsc"); 
		    drawText(90,60,130,napis);
		}
		if(tmp==1||tmp==3)
		{
			sprintf(napis, "Poziom 3"); 
		    drawText(poziom[2]->kulka->translacja[0]-10,60,poziom[2]->kulka->translacja[2]+30,napis);
		}
		if(tmp==2)
		{
			sprintf(napis, "Poziom 3"); 
		    drawText(40,60,200,napis);
		}
		
	}
	else if(poz==4)
	{
		
		poziom[3]->Rysuj();
		if(tmp==0)
		{
			sprintf(napis, "Poziom 4"); 
		    drawText(40,60,190,napis);
			sprintf(napis, "Masz 20 s + %d",20-czas3); 
		    drawText(60,60,170,napis);
			sprintf(napis, "Wcisnij 'enter' aby rozpoczac"); 
		    drawText(100,60,150,napis);
			sprintf(napis, "Wcisnij 'esc' aby wyjsc"); 
		    drawText(90,60,130,napis);
		}
		if(tmp==1||tmp==3)
		{
			sprintf(napis, "Poziom 4"); 
		    drawText(poziom[3]->kulka->translacja[0]-10,60,poziom[3]->kulka->translacja[2]+30,napis);
		}
		if(tmp==2)
		{
			sprintf(napis, "Poziom 4"); 
		    drawText(40,60,200,napis);
		}
	
	}
	else if(poz==5)
	{

		
		sprintf(napis, "Ukonczyles gre 'Labirynt'"); 
		drawText(100,60,200,napis);
		sprintf(napis, "Twoje wyniki: "); 
		drawText(70,60,170,napis);
		sprintf(napis, "Poziom 1: %d s",czas1); 
		drawText(70,60,140,napis);
		sprintf(napis, "Poziom 2: %d s",czas2); 
		drawText(70,60,110,napis);
		sprintf(napis, "Poziom 3: %d s",czas3); 
		drawText(70,60,80,napis);
		sprintf(napis, "Poziom 4: %d s",czas4); 
		drawText(70,60,50,napis);
		sprintf(napis, "Czas Ogolny: %d s",czasGL); 
		drawText(80,60,20,napis);
		sprintf(napis, "Aby wyjsc nacisnij 'esc'"); 
		drawText(100,60,-10,napis);
		sprintf(napis, "Aby zobaczyc rekordy nacisnij 'r'"); 
		drawText(120,60,-40,napis);
	}
	else if(poz==6)
	{
		sprintf(napis, "Niestety, przekroczyles czas"); 
		drawText(100,60,200,napis);
		sprintf(napis, "Wrota sie zamknely!"); 
		drawText(80,60,150,napis);
		sprintf(napis, "GAME OVER"); 
		drawText(40,60,100,napis);
		sprintf(napis, "Aby wyjsc nacisnij 'esc'"); 
		drawText(70,60,50,napis);
	}
	else if(poz==7)
	{
		sprintf(napis, "Rekordy: "); 
		drawText(70,60,170,napis);
		sprintf(napis, "Poziom 1: %d s",odczytRekord(1)); 
		drawText(70,60,140,napis);
		sprintf(napis, "Poziom 2: %d s",odczytRekord(2)); 
		drawText(70,60,110,napis);
		sprintf(napis, "Poziom 3: %d s",odczytRekord(3)); 
		drawText(70,60,80,napis);
		sprintf(napis, "Poziom 4: %d s",odczytRekord(4)); 
		drawText(70,60,50,napis);
		sprintf(napis, "Aby wyjsc nacisnij 'esc'"); 
		drawText(100,60,20,napis);
	}

}
void openGLview::zapisPoziom(int level, int time1, int time2, int time3)
{
       FILE *strumien;
       strumien = fopen( "ostPoziom.txt", "r+t" ); 
       
       fprintf( strumien, "%d %d %d %d", level , time1, time2, time3);
       fclose( strumien );
}

int openGLview::odczytPoziom (int opcja)
{
       int tempPoziom; //tu wrzucam numer poziomu odczytanego z pliku
	   int tempCzas1,tempCzas2,tempCzas3;
       FILE *strumien;
       strumien = fopen( "ostPoziom.txt", "r+t" ); 
       fscanf( strumien, "\%d \%d \%d \%d", &tempPoziom, &tempCzas1, &tempCzas2, &tempCzas3 );
       
       fclose( strumien );

	   if(opcja==1)
			return tempPoziom;
	   else if(opcja==2)
		   return tempCzas1;
	   else if(opcja==3)
		   return tempCzas2;
	   else if(opcja==4)
		   return tempCzas3;
}

void openGLview::zapisRekord ( int czas, int level )
{
       FILE *strumien;
       int zapisanyRekord1, zapisanyRekord2, zapisanyRekord3;

       if ( level == 1 )
       {
               strumien = fopen( "rekord1p1.txt", "r+t" );
               fscanf( strumien, "\%d", &zapisanyRekord1 );
               fclose( strumien );
               
               if ( czas <zapisanyRekord1 )
               {
               strumien = fopen( "rekord1p1.txt", "w+t" );
                       fprintf( strumien, "%d", czas );
                       fclose( strumien );
               }
       }

       else if ( level == 2 )
       {
               strumien = fopen( "rekord1p2.txt", "r+t" );
               fscanf( strumien, "\%d", &zapisanyRekord1 );
               fclose( strumien );
              
               if ( czas <zapisanyRekord1 )
               {
               strumien = fopen( "rekord1p2.txt", "w+t" );
                       fprintf( strumien, "%d", czas );
                       fclose( strumien );
               }
       }

       else if ( level == 3 )
       {
               strumien = fopen( "rekord1p3.txt", "r+t" );
               fscanf( strumien, "\%d", &zapisanyRekord1 );
               fclose( strumien );
               
               if ( czas <zapisanyRekord1 )
               {
               strumien = fopen( "rekord1p3.txt", "w+t" );
                       fprintf( strumien, "%d", czas );
                       fclose( strumien );
               }
       }

       else if ( level == 4 )
       {
               strumien = fopen( "rekord1p4.txt", "r+t" );
               fscanf( strumien, "\%d", &zapisanyRekord1 );
               fclose( strumien );
            
               if ( czas <zapisanyRekord1 )
               {
               strumien = fopen( "rekord1p4.txt", "w+t" );
                       fprintf( strumien, "%d", czas );
                       fclose( strumien );
               }
       }
}

int openGLview::odczytRekord (int level )
{
		int time1,time2,time3,time4;

       FILE *strumien;
      
       

	   if ( level == 1 )
       {
               strumien = fopen( "rekord1p1.txt", "r+t" );
               fscanf( strumien, "\%d", &time1 );
               fclose( strumien );
               
              return time1;
       }

       else if ( level == 2 )
       {
               strumien = fopen( "rekord1p2.txt", "r+t" );
               fscanf( strumien, "\%d", &time2 );
               fclose( strumien );
              
             return time2;
       }

       else if ( level == 3 )
       {
               strumien = fopen( "rekord1p3.txt", "r+t" );
               fscanf( strumien, "\%d", &time3 );
               fclose( strumien );
               
             return time3;
       }

       else if ( level == 4 )
       {
               strumien = fopen( "rekord1p4.txt", "r+t" );
               fscanf( strumien, "\%d", &time4 );
               fclose( strumien );
            
              return time4;
       }


}

