#pragma once
#include "Figura.h"
class CStozek : public CFigura  //klasa odpowiedzialna za stworzenie stozka, z dwoch polaczonych stozkow bedzie stworzony bonus/pulapka i beda rozmieszczone w roznych miejscach planszy
{
public:
	CStozek(void);
	CStozek(double radius, double height,int x, int y, int z, float r, float g, float b);
	~CStozek(void);

	void loadTextureFromFile(char *filename);
	void Rysuj(void);
	double promien;
	double wysokosc;
};

