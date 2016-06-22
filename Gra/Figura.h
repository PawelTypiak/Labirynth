#pragma once
#include "RgbImage.h"
#include<gl\glut.h>
class CFigura
{
public:
	CFigura(void);
	~CFigura(void);
	
	virtual void Rysuj()=0;//rysuje figure
	virtual void loadTextureFromFile(char *filename)=0;
	void Przesun(int dx, int dy, int dz);//ustawia zmienna odpowiedzialna za przesuniecie figury
	void Obroc(double alfa, double beta, double gamma);

public:
	float kolor[3]; //kolor figury
	double translacja[3]; // przechowuje wspolrzedne przesuniecia w trzech osiach
	double rotacja[3]; //przechowuje wspolrzedne obrotow w trzech osiach
};

